
---
<h1 align="center">🧵 Threads-Synchronization</h1>

<p align="center">
  <img src="https://img.shields.io/badge/language-C-blue?style=for-the-badge&logo=c" alt="C">
  <img src="https://img.shields.io/badge/feature-Multithreading-orange?style=for-the-badge&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABgAAAAYCAYAAADgdz34AAAABmJLR0QA/wD/AP+gvaeTAAAACXBIWXMAAA3XAAAN1wFCKJt4AAAAB3RJTUUH4QQQEwksSS9ZWwAAAk1JREFUSMedlEuT0zAQhN+M7JiK7iBPUxPiuYgDJFZyjULIqRKpIjf2hVcUXBlXDrD3gg7Eefqu/PrSpwMlHnjWF/VueQRjG89SOqqpd2j/AEZg1jsCwAKIX+dFS43DdxvAYCGiTwJp+LZJpmzgpffauxLC4hLFPcmBLOqnjTF64+yjAUExEZBlccgir+mqRKZb/Ab2VAhSSVe37DOu4G4+qwCOS5aO7J+Kg+vE8M+5RBq4liZVlpqUVpwue0r4Dh6dZMsVi6gL/8ooKKXnoCkwrQYf9zM6s7kjLnEp/Qre+2LoofESRHdIFKxFu30RC9cGYUXyJHv3xafLuIGxBWjF3KO+SC+krmv3c7F9QQ2b65kQ25odIC0S2oa+wV4KXzszZC7XvqnLCa6b5QYZFW4fRgt9m5JulwSpHACySWFhvKtEGIPSMXHm+rt7NWprRhOA3LoD88S0CMvueT4pglWCqBgP4jsxO1ErMQVfewZRR+yTlCrWE3ba9CWrhz6gm5Fsx2GCvNhbI39xcnlLVK8HmkBJ+kRilLz4LpS1AGr6FUAX1Mq8hAh1sAMVBfYJ70EyKnK/5M9oFvSzRBQAem6Y7QcfIWXCLaOSRgS0n0XFPQ0vqEE6Ki3AFCBDLmzDFQ98dX3xffv+StELV7uq3yrJRWGXTzzeTfd++FE73+EH9BvuAM1Bo+9/CszSBKb6Q5wAAAAASUVORK5CYII=" alt="Multithreading">
  <img src="https://img.shields.io/badge/library-PThread-green?style=for-the-badge&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABgAAAAYCAYAAADgdz34AAAABmJLR0QA/wD/AP+gvaeTAAAACXBIWXMAAA3XAAAN1wFCKJt4AAAAB3RJTUUH4QQQEwksSS9ZWwAAAk1JREFUSMedlEuT0zAQhN+M7JiK7iBPUxPiuYgDJFZyjULIqRKpIjf2hVcUXBlXDrD3gg7Eefqu/PrSpwMlHnjWF/VueQRjG89SOqqpd2j/AEZg1jsCwAKIX+dFS43DdxvAYCGiTwJp+LZJpmzgpffauxLC4hLFPcmBLOqnjTF64+yjAUExEZBlccgir+mqRKZb/Ab2VAhSSVe37DOu4G4+qwCOS5aO7J+Kg+vE8M+5RBq4liZVlpqUVpwue0r4Dh6dZMsVi6gL/8ooKKXnoCkwrQYf9zM6s7kjLnEp/Qre+2LoofESRHdIFKxFu30RC9cGYUXyJHv3xafLuIGxBWjF3KO+SC+krmv3c7F9QQ2b65kQ25odIC0S2oa+wV4KXzszZC7XvqnLCa6b5QYZFW4fRgt9m5JulwSpHACySWFhvKtEGIPSMXHm+rt7NWprRhOA3LoD88S0CMvueT4pglWCqBgP4jsxO1ErMQVfewZRR+yTlCrWE3ba9CWrhz6gm5Fsx2GCvNhbI39xcnlLVK8HmkBJ+kRilLz4LpS1AGr6FUAX1Mq8hAh1sAMVBfYJ70EyKnK/5M9oFvSzRBQAem6Y7QcfIWXCLaOSRgS0n0XFPQ0vqEE6Ki3AFCBDLmzDFQ98dX3xffv+StELV7uq3yrJRWGXTzzeTfd++FE73+EH9BvuAM1Bo+9/CszSBKb6Q5wAAAAASUVORK5CYII=" alt="PThread">
</p>

<p align="center">
  <i>Efficient multithreaded computation of square root sums with advanced synchronization methods</i>
</p>

---

## 📌 Table of Contents
- [Project Overview](#-project-overview)
- [Features](#-features)
- [Requirements](#-requirements)
- [Compilation](#-compilation)
- [Usage](#-usage)
- [Synchronization Methods](#-synchronization-methods)
- [Performance Insights](#-performance-insights)
- [Limitations](#-limitations)
- [Contributing](#-contributing)

---

## 🚀 Project Overview

The Threads-Synchronization project is a high-performance C program designed to efficiently compute the sum of square roots within a specified range using multithreading. It demonstrates the power of concurrent programming by utilizing the PThread library to distribute tasks across multiple threads, improving performance while ensuring proper synchronization.

## ✨ Features

- **Multithreaded Execution:** Utilizes up to 32 threads for parallel computation.
- **Flexible Range:** Supports computation for any range within [0, 9223372036854775807].
- **Multiple Synchronization Methods:** Implements three distinct approaches:
  1. 🚫 No synchronization (for demonstration purposes)
  2. 🔒 Mutex-protected critical sections
  3. 🏎️ Local computation with mutex-protected global sum update
- **Performance Metrics:** Provides detailed timing information for analysis.
- **Thread-specific Information:** Displays range and results for each thread.

## 📋 Requirements

- GCC Compiler
- POSIX Threads (PThread) library
- Math library

## 🛠 Compilation

Compile the program using the following command:

```bash
gcc -o threads_sync threads_sync.c -lm -pthread
```

This command includes the math (`-lm`) and pthread (`-pthread`) libraries required for the program.

## 📖 Usage

Run the compiled program with the following command:

```bash
./threads_sync <a> <b> <num_threads> <method>
```

Where:
- `<a>`: Start of the range (must be ≥ 0)
- `<b>`: End of the range (must be ≤ 9223372036854775807)
- `<num_threads>`: Number of threads to use (1-32)
- `<method>`: Synchronization method (1, 2, or 3)

Example:
```bash
./threads_sync 1 1000000 4 3
```

This calculates the sum of square roots from 1 to 1,000,000 using 4 threads and method 3.

## 🔄 Synchronization Methods

1. **No Synchronization (Method 1):**
   - Demonstrates the risks of race conditions.
   - Fastest but potentially inaccurate results.

2. **Mutex-protected Critical Sections (Method 2):**
   - Uses a mutex to protect each update to the global sum.
   - Guarantees accuracy but may introduce significant overhead.

3. **Local Computation with Protected Global Sum (Method 3):**
   - Each thread computes a local sum, then updates the global sum once.
   - Balances performance and accuracy.

## 📊 Performance Insights

| Method | Performance | Accuracy | Use Case |
|--------|-------------|----------|----------|
| 1 | 🚀🚀🚀 | ❌ | Demonstration of race conditions |
| 2 | 🚀 | ✅✅ | When absolute accuracy is critical |
| 3 | 🚀🚀 | ✅ | Best balance of speed and accuracy |

## ⚠️ Limitations

- Maximum range: [0, 9223372036854775807]
- Maximum number of threads: 32 (can be adjusted in the code)
- Potential for floating-point precision issues with very large sums

## 🤝 Contributing

Contributions to improve the project are welcome! Please follow these steps:

1. Fork the repository
2. Create a new branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<hr>
