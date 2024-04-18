
# README

## Preparation and Installation

### Protocol Buffers
Installation was initiated following the guidelines from [Protocol Buffers Installation](https://grpc.io/docs/protoc-installation/). Additional insights were gained from the [gRPC GitHub repository](https://github.com/grpc/grpc/).

### gRPC Libraries for C++
Implemented as per the instructions provided at [gRPC C++ Quickstart](https://grpc.io/docs/languages/cpp/quickstart/). Resolved installation issues by referencing [grpc/grpc#24660](https://github.com/grpc/grpc/issues/24660) and addressing common errors such as the missing header file on [Stack Overflow](https://stackoverflow.com/questions/70239051/fatal-error-grpcpp-grpcpp-h-file-not-found-c).

## Testing Framework and Challenges
Transitioned to Google Test for C++ code testing, encountered compatibility issues on ARM64 as detailed in [protobuf#5868](https://github.com/protocolbuffers/protobuf/issues/5868) and [gtest#3208](https://github.com/google/googletest/issues/3208). Due to these challenges, switched to the Catch2 framework for more flexible behavior-driven development (BDD), detailed on [Catch2 GitHub](https://github.com/catchorg/Catch2).

## Build Tools and Execution
### Installation with Homebrew:
```bash
brew install grpc
brew install abseil
brew install protobuf
```

### Compilation:
Run `make` in the project directory to compile the applications.

### Execution:
- Start the server with `./bin/server`.
- Run the client with `./bin/main` in a separate terminal to begin data transfer.

### Testing:
- Test executables are located in `bin/tests`.
- Modify the file path in test cases as needed for correct file transfers.
- Run `./bin/tests/client_tests` for manual tests or `./bin/tests/catch_tests` for Catch2 library tests.

### Protocol Buffers Rebuild:
If you need to modify the protocol buffer definitions, rebuild them with:
```bash
protoc --grpc_out=. --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` file_exchange.proto
protoc --cpp_out=. file_exchange.proto
```
