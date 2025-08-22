# Ultra Low Latency Trading System Simulator

This project is a C++ simulator for an ultra-low latency trading system. It provides a basic framework for an order book and order management.

## Building the Project

The project uses CMake for building. To build the project, follow these steps:

1. Clone the repository.
2. Create a build directory: `mkdir build`
3. Change into the build directory: `cd build`
4. Run CMake to generate the build files: `cmake ..`
5. Compile the project: `make`

## Running the Tests

The project uses GoogleTest for unit testing. To run the tests, first build the project, then run the following command from the `build` directory:

```bash
ctest
```
