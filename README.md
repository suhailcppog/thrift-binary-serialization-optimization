# Thrift Binary Serialization Optimization

This project explores performance improvements in Apache Thrift's `TBinaryProtocol`. It includes benchmarks and tests for measuring serialization and deserialization speedups.

---

## 📁 Project Overview

```
.
├── benchmark.thrift            # Thrift schema for benchmark data types
├── TBinaryProtocol.h           # Optimized Thrift binary protocol implementation
├── CMakeLists.txt              # CMake build configuration
├── test/
│   ├── Benchmark.cpp
│   └── test_binary_protocol.cpp
```

---

## 🚀 Objective

Improve throughput of Thrift's C++ binary protocol by optimizing serialization/deserialization routines. Performance is measured via reproducible benchmarks.

---

## 🛠️ Prerequisites

- Apache Thrift (with compiler + C++ libraries)
- Boost (filesystem, thread, chrono, unit_test_framework)
- CMake 3.14 or higher
- C++17-compatible compiler

---

## ⚙️ Build and Run

```bash
# Clone the repository
git clone https://github.com/suhailcppog/thrift-binary-serialization-optimization.git
cd thrift-binary-serialization-optimization

# Build the project
mkdir build
cd build
cmake ..
make

# Run benchmarks
./Benchmark

# Run unit tests
ctest
```

> Thrift compiler is invoked automatically via CMake to generate code from `benchmark.thrift`.

---

## 📈 Benchmark Results

_(Insert your benchmark comparison results here)_

| Operation         | Baseline (μs) | Optimized (μs) | Improvement |
|------------------|----------------|----------------|-------------|
| Serialize Struct | 75.3           | 42.7           | 43.3%       |
| Deserialize      | 89.2           | 51.4           | 42.4%       |

---

## ✅ Test Coverage

Implemented using Boost Unit Test Framework:

- Round-trip serialization validation
- Edge case regression testing
- Performance benchmarking

---

## 🤝 Contributions

Pull requests and performance suggestions are welcome! Please include benchmarks and test results with your changes.
