# Threads-Synchronization

Welcome to the **Threads-Synchronization** project! This program is designed to efficiently compute the sum of square roots within a specified range using multithreading in C, employing various synchronization methods to ensure both accuracy and speed.

## Project Overview:
This project showcases the power of threading and synchronization in concurrent programming. By utilizing the PThread library, the program can distribute tasks across multiple threads, improving performance while demonstrating the importance of proper synchronization.

### Features:
- **Multithreaded Execution:** Speed up calculations using multiple threads.
- **Synchronization Methods:** Choose from three distinct methods for handling shared resources:
  - **Method 1:** No synchronization (high risk of race conditions).
  - **Method 2:** Mutex-protected critical sections (ensures correctness with potential delays).
  - **Method 3:** Local variable storage for parallel computation (best performance and scalability).
- **Flexible Input:** Easily input your range, number of threads, and desired method.

## How To Run:
To run this project, follow these steps:

### Step 1: Compile the Program
Use the following command to compile the C code with the necessary libraries:
```bash
gcc Code_#.c -o Code_#.o -lm -pthread
