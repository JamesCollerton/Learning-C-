# Mini HTTP Client

A simple HTTP client implementation using C++ and Bazel.

## Building

To build the project:
```bash
bazel build //mini-http-client:main
```

To run:
```bash
bazel run //mini-http-client:main
```

## Structure

- `http_client.h` / `http_client.cpp` - HTTP client implementation
- `main.cpp` - Main entry point
- `BUILD` - Bazel build configuration
- `MODULE.bazel` - Bazel module configuration

