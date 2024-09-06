# Threads-Synchronization

Welcome to the **Threads-Synchronization** project! This program is designed to efficiently compute the sum of square roots within a specified range using multithreading in C, employing various synchronization methods to ensure both accuracy and speed.

## Project Overview

This project demonstrates the power of threading and synchronization in concurrent programming. By utilizing the PThread library, the program can distribute tasks across multiple threads, improving performance while ensuring proper synchronization.

### Features

- **Multithreaded Execution:** Speed up calculations using multiple threads.
- **Synchronization Methods:** Choose from three distinct methods for handling shared resources:
  1. **No synchronization** – High risk of race conditions.
  2. **Mutex-protected critical sections** – Ensures correctness but may introduce delays.
  3. **Local variable storage for parallel computation** – Provides the best performance and scalability.
- **Flexible Input:** Easily specify the range, number of threads, and synchronization method.

## How to Run

### Step 1: Compile the Program

Use the following command to compile the C code with the necessary libraries:

```bash
gcc Code_#.c -o Code_#.o -lm -pthread
```

This command includes the math (`-lm`) and pthread (`-pthread`) libraries needed for multithreading and square root calculations.

### Step 2: Execute the Program

After compilation, run the program using the following command format:

```bash
./Code_#.o <start_range> <end_range> <num_threads> <method>
```

Where:
- `start_range`: The starting point of the range (e.g., 880130203012).
- `end_range`: The ending point of the range (e.g., 922823372203).
- `num_threads`: The number of threads to use (e.g., 1, 2, 4, etc.).
- `method`: The synchronization method to use:
  1. No synchronization (may result in inconsistent outputs due to race conditions).
  2. Use of a mutex to protect critical sections (ensures correctness, but may lead to increased execution time).
  3. Local computation per thread with a mutex-protected global sum update (best performance with accurate results).

Example Usage:

```bash
./Code_#.o 880130203012 922823372203 4 3
```

To measure execution time, you can use the Linux `time` command:

```bash
time ./Code_#.o 880130203012 922823372203 4 3
```

### Step 3: Analyze Results

The program will output:
- The computed sum of square roots.
- Timing information including user time, system time, and total execution time.

This information can be used to compare the performance of the three different synchronization methods across various input parameters.

## Performance Insights

- **Method 1:** May result in incorrect results due to lack of synchronization. Avoid for critical computations.
- **Method 2:** Ensures accuracy but sacrifices some performance due to thread blocking on mutex access.
- **Method 3:** Achieves the best balance between performance and accuracy by allowing parallel computation before a synchronized final update.

## Dependencies

- PThread Library: Required for handling multithreading.
- Math Library: Required for square root calculations.

## Thank You!

Thank you for trying out the Threads-Synchronization project! If you have any questions, suggestions, or improvements, feel free to reach out. We hope this project helps you gain a deeper understanding of threading and synchronization concepts in concurrent programming.
