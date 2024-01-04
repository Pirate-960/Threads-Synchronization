#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <sys/time.h>
#include <time.h>
#include <stdint.h>

#define MAX_THREADS 32

// Shared variables
double global_sqrt_sum = 0;
long long int a, b;
int num_threads, method;

// Mutex for synchronization
pthread_mutex_t mutex;

// Struct to store thread-specific information
struct ThreadInfo {
    long long int start;
    long long int end;
};

// Function prototypes
void* method1_worker(void* arg);
void* method2_worker(void* arg);
void* method3_worker(void* arg);

typedef void* (*ThreadFunction)(void*);

// Main function
int main(int argc, char *argv[]) {
    // Check for the correct number of arguments
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <a> <b> <num_threads> <method>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Parse command line arguments
    a = atoll(argv[1]);
    b = atoll(argv[2]);
    num_threads = atoi(argv[3]);
    method = atoi(argv[4]);

    // Validate the number of threads
    if (num_threads <= 0 || num_threads > MAX_THREADS) {
        fprintf(stderr, "Invalid number of threads. Must be between 1 and %d.\n", MAX_THREADS);
        exit(EXIT_FAILURE);
    }

    // Initialize mutex only for Method 2 and Method 3
    if (method == 2 || method == 3) {
        if (pthread_mutex_init(&mutex, NULL) != 0) {
            fprintf(stderr, "Mutex initialization failed.\n");
            exit(EXIT_FAILURE);
        }
    }

    // Create threads based on the selected method and thread count
    pthread_t threads[MAX_THREADS];
    struct timeval start, end;

    // Print information about the main thread
    printf("Main Thread ID: %lu\n", (unsigned long)pthread_self());
    printf("Method: %d\n", method);
    printf("Number of Threads: %d\n", num_threads);

    // Record start time
    gettimeofday(&start, NULL);

    // Create and launch threads
    printf("\nStep 1: Creating and launching threads...\n");

    ThreadFunction threadFunction;

    // Select the appropriate thread method based on the chosen method
    switch (method) {
        case 1:
            threadFunction = method1_worker;
            break;
        case 2:
            threadFunction = method2_worker;
            break;
        case 3:
            threadFunction = method3_worker;
            break;
        default:
            fprintf(stderr, "Invalid method selection.\n");
            exit(EXIT_FAILURE);
    }

    // Iterate to create threads with specific ranges
    for (int i = 0; i < num_threads; i++) {
        // Create ThreadInfo struct to pass thread-specific information
        struct ThreadInfo* thread_info = (struct ThreadInfo*)malloc(sizeof(struct ThreadInfo));
        thread_info->start = a + ((b - a) / num_threads) * i;
        thread_info->end = (i == num_threads - 1) ? b : (a + (i + 1) * ((b - a) / num_threads));

        // Print information about each thread's range
        printf("  Creating Thread %d with ID %lu -> [%lld, %lld]\n", i + 1, (unsigned long)pthread_self(), thread_info->start, thread_info->end);

        // Create threads based on the selected method
        pthread_create(&threads[i], NULL, threadFunction, thread_info);
    }

    // Join threads
    printf("\nStep 2: Joining threads...\n");
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);

        // Print information about the joined thread
        struct ThreadInfo* thread_info = (struct ThreadInfo*)malloc(sizeof(struct ThreadInfo));
        thread_info->start = a + ((b - a) / num_threads) * i;
        thread_info->end = (i == num_threads - 1) ? b : (a + (i + 1) * ((b - a) / num_threads));
        printf("(!): Thread ID %lu joined. Method: %d, Range: [%lld, %lld]\n", (unsigned long)threads[i], method, thread_info->start, thread_info->end);
        free(thread_info);
    }

    // Record end time
    gettimeofday(&end, NULL);

    // Destroy mutex only for Method 2 and Method 3
    if (method == 2 || method == 3) {
        if (pthread_mutex_destroy(&mutex) != 0) {
            fprintf(stderr, "Mutex destruction failed.\n");
            exit(EXIT_FAILURE);
        }
    }

    // Calculate time and print results
    printf("\nResults:\n");
    printf("Sum: %e\n", global_sqrt_sum);
    printf("User time: %.4f seconds\n", (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec) / 1e6);
    printf("System time: %.4f seconds\n", (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec) / 1e6);
    printf("Total time: %.4f seconds\n", (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec) / 1e6);

    return 0;
}

// Worker function for Method 1
void* method1_worker(void* arg) {
    // Extract thread-specific information from the ThreadInfo struct
    struct ThreadInfo* thread_info = (struct ThreadInfo*)arg;
    long long int start = thread_info->start;
    long long int end = thread_info->end;
    free(arg);

    // Calculate the square root sum for the specified range
    for (long long int x = start; x <= end; x++) {
        global_sqrt_sum += sqrt(x);
    }

    // Print information about the thread's range
    printf("  #=>Thread ID %lu calculating sqrt sum for range [%lld, %lld]\n", (unsigned long)pthread_self(), start, end);

    // Print local sum for the thread
    printf("###===>>>Thread ID %lu updated global_sqrt_sum without mutex. Final local_sqrt_sum = %e\n", (unsigned long)pthread_self(), global_sqrt_sum);

    pthread_exit(NULL);
}

// Worker function for Method 2
void* method2_worker(void* arg) {
    // Extract thread-specific information from the ThreadInfo struct
    struct ThreadInfo* thread_info = (struct ThreadInfo*)arg;
    long long int start = thread_info->start;
    long long int end = thread_info->end;
    free(arg);
    
    // Calculate and update global sum serially
    for (long long int x = start; x <= end; x++) {
        // Critical section (mutual exclusion) - only one thread can access this code at a time
        // Lock the mutex to ensure exclusive access to shared data
        pthread_mutex_lock(&mutex);
        // Update global_sqrt_sum value
        global_sqrt_sum += sqrt(x);
        // Unlock the mutex to release the lock
        pthread_mutex_unlock(&mutex);
    }

    // Print information about the thread's range
    printf("  #=>Thread ID %lu calculating sqrt sum for range [%lld, %lld]\n", (unsigned long)pthread_self(), start, end);

    // Print the final global_sqrt_sum after the update
    printf("###===>>>Thread ID %lu updated global_sqrt_sum with mutex. Final local_sqrt_sum = %e\n", (unsigned long)pthread_self(), global_sqrt_sum);

    pthread_exit(NULL);
}

// Worker function for Method 3
void* method3_worker(void* arg) {
    // Extract thread-specific information from the ThreadInfo struct
    struct ThreadInfo* thread_info = (struct ThreadInfo*)arg;
    long long int start = thread_info->start;
    long long int end = thread_info->end;
    free(arg);

    // Local sum for the thread
    double local_sum = 0;

    // Calculate local sum
    for (long long int x = start; x <= end; x++) {
        local_sum += sqrt(x);
    }

    // Print information about the thread's range
    printf("  #=>Thread ID %lu calculating sqrt sum for range [%lld, %lld]\n", (unsigned long)pthread_self(), start, end);

    // Print local sum for the thread
    printf("###===>>>Thread ID %lu local_sqrt_sum = %e\n", (unsigned long)pthread_self(), local_sum);

    // Update global sum only once after local computations are complete
    pthread_mutex_lock(&mutex);
    global_sqrt_sum += local_sum;
    pthread_mutex_unlock(&mutex);

    // Return local sum
    pthread_exit(NULL);
}