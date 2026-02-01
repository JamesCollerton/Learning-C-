# Mini HTTP Client

A simple HTTP client implementation using C++ and Bazel. This is a low-level HTTP client that uses raw POSIX sockets to implement the HTTP protocol over TCP.

## Building

All commands should be run from the `mini-http-client` directory:

```bash
cd mini-http-client
```

### Building the library
To build just the HTTP client library:
```bash
bazel build :http_client
```

### Building and running the example binary
```bash
bazel build :main
bazel run :main
```

Or build and run in one command:
```bash
bazel run :main
```

## Testing

To run the test suite:
```bash
bazel test :http_client_test
```

To see test output:
```bash
bazel test :http_client_test --test_output=all
```

The tests verify URL parsing for both valid and invalid URLs.

## Using as a Library

To use this HTTP client library in another Bazel C++ project, add it as a dependency in your `BUILD` file:

```python
cc_binary(
    name = "your_program",
    srcs = ["your_program.cpp"],
    deps = ["//mini-http-client:http_client"],  # If building from repo root
    # or
    # deps = ["@mini_http_client//:http_client"],  # If using as external dependency
)
```

Then include the header in your code:
```cpp
#include "mini-http-client/http_client.h"
```

Example usage:
```cpp
HttpClient client;
std::string response = client.get("http://example.com");
std::string postResponse = client.post("http://example.com/api", "data=value");
```

## Structure

- `http_client.h` / `http_client.cpp` - HTTP client library implementation
- `main.cpp` - Example program using the library
- `http_client_test.cpp` - Test suite for the library
- `BUILD` - Bazel build configuration
- `MODULE.bazel` - Bazel module configuration

