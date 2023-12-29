#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <sys/time.h>
#include <time.h>

struct ThreadInfo {
    long long int start;
    long long int end;
};

long long int a;
long long int b;
int num_threads;
int method;
pthread_mutex_t mutex;
double global_sqrt_sum = 0;

void* calculate_sqrt_sum(void* arg);

int main(int argc, char* argv[]) {
    if (argc != 5) {
        printf("Usage: %s <a> <b> <num_threads> <method>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    a = atoll(argv[1]);
    b = atoll(argv[2]);
    num_threads = atoi(argv[3]);
    method = atoi(argv[4]);

    if (num_threads <= 0) {
        printf("Number of threads must be greater than 0.\n");
        exit(EXIT_FAILURE);
    }

    pthread_mutex_init(&mutex, NULL);

    pthread_t threads[num_threads];

    struct timeval start_time, end_time;  // Change struct timespec to struct timeval
    gettimeofday(&start_time, NULL);  // Change clock_gettime to gettimeofday

    for (int i = 0; i < num_threads; ++i) {
        struct ThreadInfo* thread_info = malloc(sizeof(struct ThreadInfo));
        thread_info->start = a + i * ((b - a) / num_threads);
        thread_info->end = (i == num_threads - 1) ? b : (a + (i + 1) * ((b - a) / num_threads));
        pthread_create(&threads[i], NULL, calculate_sqrt_sum, thread_info);
    }

    for (int i = 0; i < num_threads; ++i) {
        pthread_join(threads[i], NULL);
    }

    gettimeofday(&end_time, NULL);  // Change clock_gettime to gettimeofday

    // Print Results
    printf("Sum: %e\n", global_sqrt_sum);
    printf("User time: %.2f seconds\n", (double)(end_time.tv_sec - start_time.tv_sec) +
                                           (double)(end_time.tv_usec - start_time.tv_usec) / 1e6);
    printf("System time: %.2f seconds\n", (double)(end_time.tv_sec - start_time.tv_sec) +
                                             (double)(end_time.tv_usec - start_time.tv_usec) / 1e6);
    printf("Total time: %.2f seconds\n", (double)(end_time.tv_sec - start_time.tv_sec) +
                                           (double)(end_time.tv_usec - start_time.tv_usec) / 1e6);

    pthread_mutex_destroy(&mutex);

    return 0;
}

void* calculate_sqrt_sum(void* arg) {
    struct ThreadInfo* thread_info = (struct ThreadInfo*)arg;
    long long int start = thread_info->start;
    long long int end = thread_info->end;
    free(arg);

    double local_sqrt_sum = 0;

    for (long long int x = start; x <= end; ++x) {
        local_sqrt_sum += sqrt(x);
    }

    if (method == 1) {
        global_sqrt_sum += local_sqrt_sum;
    } else if (method == 2 || method == 3) {
        pthread_mutex_lock(&mutex);
        global_sqrt_sum += local_sqrt_sum;
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}
