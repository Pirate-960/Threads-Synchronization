#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <sys/time.h>
#include <time.h>

// Structure to hold start and end values for each thread's range
struct ThreadInfo {
    long long int start;
    long long int end;
};

// Global variables
long long int a;
long long int b;
int num_threads;
int method;
pthread_mutex_t mutex;
double global_sqrt_sum = 0;

// Function prototype
void* calculate_sqrt_sum(void* arg);

int main(int argc, char* argv[]) {
    // Check if the correct number of command-line arguments is provided
    if (argc != 5) {
        printf("Usage: %s <a> <b> <num_threads> <method>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Parse command-line arguments
    a = atoll(argv[1]);
    b = atoll(argv[2]);
    num_threads = atoi(argv[3]);
    method = atoi(argv[4]);

    // Check if the number of threads is valid
    if (num_threads <= 0) {
        printf("Number of threads must be greater than 0.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Array to hold thread IDs
    pthread_t threads[num_threads];

    // Timing variables
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    printf("Main Thread ID: %lu\n", pthread_self());

    // Create threads
    for (int i = 0; i < num_threads; ++i) {
        // Allocate memory for thread-specific information
        struct ThreadInfo* thread_info = malloc(sizeof(struct ThreadInfo));
        // Calculate the start and end values for the thread's range
        thread_info->start = a + i * ((b - a) / num_threads);
        thread_info->end = (i == num_threads - 1) ? b : (a + (i + 1) * ((b - a) / num_threads));
        // Print information about the thread being created
        printf("Creating Thread %d with ID %lu\n", i + 1, pthread_self());
        // Create the thread and pass the thread-specific information
        pthread_create(&threads[i], NULL, calculate_sqrt_sum, thread_info);
    }

    // Join threads
    for (int i = 0; i < num_threads; ++i) {
        pthread_join(threads[i], NULL);
        // Print information about the thread being joined
        printf("Joined Thread %d\n", i + 1);
    }

    // Record end time
    gettimeofday(&end_time, NULL);

    // Print Results
    printf("\nResults:\n");
    printf("Sum: %e\n", global_sqrt_sum);
    printf("User time: %.2f seconds\n", (double)(end_time.tv_sec - start_time.tv_sec) +
                                           (double)(end_time.tv_usec - start_time.tv_usec) / 1e6);
    printf("System time: %.2f seconds\n", (double)(end_time.tv_sec - start_time.tv_sec) +
                                             (double)(end_time.tv_usec - start_time.tv_usec) / 1e6);
    printf("Total time: %.2f seconds\n", (double)(end_time.tv_sec - start_time.tv_sec) +
                                           (double)(end_time.tv_usec - start_time.tv_usec) / 1e6);

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}

// Thread function to calculate the square root sum for a given range
void* calculate_sqrt_sum(void* arg) {
    // Extract thread-specific information
    struct ThreadInfo* thread_info = (struct ThreadInfo*)arg;
    long long int start = thread_info->start;
    long long int end = thread_info->end;
    free(arg); // Free the allocated memory

    // Print information about the thread's range
    printf("Thread ID %lu calculating sqrt sum for range [%lld, %lld]\n", pthread_self(), start, end);

    double local_sqrt_sum = 0;

    // Loop to calculate square roots and update local sum
    for (long long int x = start; x <= end; ++x) {
        double sqrt_x = sqrt(x);
        local_sqrt_sum += sqrt_x;
        // Print information about the individual contributions to local sqrt sum
        printf("Thread ID %lu: x = %lld, sqrt(x) = %e, local_sqrt_sum = %e\n", pthread_self(), x, sqrt_x, local_sqrt_sum);
    }

    // Update global sum based on the selected method
    if (method == 1) {
        // Method 1: No mutex, concurrent updates
        global_sqrt_sum += local_sqrt_sum;
        printf("Thread ID %lu updated global_sqrt_sum without mutex. Final local_sqrt_sum = %e\n", pthread_self(), local_sqrt_sum);
    } else if (method == 2 || method == 3) {
        // Method 2 and 3: Use mutex for serial or local updates
        pthread_mutex_lock(&mutex);
        global_sqrt_sum += local_sqrt_sum;
        printf("Thread ID %lu updated global_sqrt_sum with mutex. Final local_sqrt_sum = %e\n", pthread_self(), local_sqrt_sum);
        pthread_mutex_unlock(&mutex);
    }

    // Exit the thread
    pthread_exit(NULL);
}
