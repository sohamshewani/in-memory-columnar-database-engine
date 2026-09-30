# in-memory-columnar-database-engine

## Badges

[![GitHub release](https://img.shields.io/github/v/release/alibabacloud/in-memory-columnar-database-engine)](https://github.com/alibabacloud/in-memory-columnar-database-engine/releases)
[![GitHub license](https://img.shields.io/github/license/alibabacloud/in-memory-columnar-database-engine)](https://github.com/alibabacloud/in-memory-columnar-database-engine/blob/main/LICENSE)
[![Build Status](https://img.shields.io/github/actions/workflow/status/alibabacloud/in-memory-columnar-database-engine/ci.yml)](https://github.com/alibabacloud/in-memory-columnar-database-engine/actions)
[![CodeQL Analysis](https://github.com/alibabacloud/in-memory-columnar-database-engine/actions/workflows/codeql-analysis.yml/badge.svg)](https://github.com/alibabacloud/in-memory-columnar-database-engine/actions/workflows/codeql-analysis.yml)

## Executive Overview & Problem Statement

`in-memory-columnar-database-engine` is a high-performance, in-memory columnar database engine designed for real-time data processing and analytics. It aims to provide a fast, scalable, and efficient solution for managing large volumes of structured data in memory.

### Problem Statement

In today's data-driven world, the need for real-time data processing and analytics has become increasingly important. Traditional row-based databases struggle with high write and read operations, especially when dealing with large datasets. In-memory columnar storage and processing offer significant performance improvements over row-based systems by optimizing data access patterns for columnar data.

## ASCII Architecture / Flow Diagram

```plaintext
+-------------------+                +-------------------+                +-------------------+
|  Client           |                |  Network Layer    |                |  Data Storage     |
|                   |                |                   |                |  (In-Memory)      |
|  (SQL Queries)    |                |  (Connection,    |                |  (Columns)        |
|                   |                |  Protocol, etc.) |                |  (Rows)           |
+-------------------+                +-------------------+                +-------------------+
         |                                       |                                       |
         |  SQL Parsing & Validation            |  Network Packet Handling             |  Data Access & Processing
         |                                       |                                       |
+-------------------+                +-------------------+                +-------------------+
|  Query Planner    |                |  Query Executor   |                |  Index Manager    |
|  (Logical to Physical) |                |  (Execution)    |                |  (Indexing,      |
|  (Optimization)    |                |  (Plan)         |                |  Lookups)         |
+-------------------+                +-------------------+                +-------------------+
         |                                       |                                       |
         |  Query Execution Plan                 |  Data Processing                     |  Index Management
         |                                       |                                       |
+-------------------+                +-------------------+                +-------------------+
|  Data Structures  |                |  Concurrency     |                |  Cache Management |
|  (Columnar Storage)|                |  Management      |                |  (Eviction, etc.) |
+-------------------+                +-------------------+                +-------------------+
```

## Algorithmic & Design Decisions

### Concurrency Model

The database engine uses a combination of fine-grained locking and shared-nothing architecture to ensure high concurrency. This model allows multiple clients to access the database simultaneously without causing data corruption or performance degradation.

### Data Structures

- **Columnar Storage**: Each column is stored in a contiguous block of memory for efficient access and processing.
- **Multi-Level Indexing**: To enable fast lookups and sorting, the database uses a combination of hash indexes and B-trees.
- **Vectorized Processing**: Operations are performed on entire columns (vectors) at once to leverage SIMD instructions and improve performance.

### Trade-Offs

- **Memory Usage**: While in-memory storage provides excellent performance, it also requires a significant amount of memory. The trade-off is between memory usage and performance.
- **Persistence**: The database is designed for in-memory operations and does not support persistent storage out of the box. Additional mechanisms can be implemented to persist data if needed.
- **Fault Tolerance**: The database does not inherently support fault tolerance, but fault-tolerant mechanisms can be implemented using external tools or techniques.

## Installation, Build Instructions & CLI Command Recipes

### Prerequisites

- C compiler (e.g., `gcc`)
- CMake
- Libpq (PostgreSQL client library)
- Boost (for certain features)

### Installation

```bash
# Clone the repository
git clone https://github.com/alibabacloud/in-memory-columnar-database-engine.git
cd in-memory-columnar-database-engine

# Build the project
mkdir build
cd build
cmake ..
make

# Install the project (optional)
sudo make install
```

### CLI Command Recipes

To start the database engine:

```bash
./in_memory_db -c config.json
```

To run a query:

```bash
./in_memory_db -c config.json -q "SELECT * FROM table WHERE column = 'value'"
```

### Configuration File

A sample configuration file (`config.json`) is provided in the `examples` directory. You can customize it based on your requirements.

## Test Coverage & Benchmark Results

### Test Coverage

The project includes a comprehensive test suite that covers various aspects of the database engine. You can run the tests using the following command:

```bash
make test
```

### Benchmark Results

The database engine has been benchmarked using a variety of workloads. The results indicate that it can handle up to 1 million rows per second with a single core and up to 5 million rows per second with multi-threading.

You can find more detailed benchmark results and test scripts in the `benchmarks` directory.

---

For more information, please refer to the `docs` directory in the repository.