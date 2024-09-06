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
## Thank You!
Thank you for trying out the Threads-Synchronization project! If you have any questions, suggestions, or improvements, feel free to reach out. We hope this project helps you gain a deeper understanding of threading and synchronization concepts in concurrent programming.
