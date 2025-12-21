# Mini HTTP Client

A simple HTTP client implementation using C++ and Bazel.

## Building

### Building the library
To build just the HTTP client library:
```bash
cd mini-http-client
bazel build :http_client
```

### Building and running the example binary
```bash
cd mini-http-client
bazel build :main
bazel run :main
```

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

## Structure

- `http_client.h` / `http_client.cpp` - HTTP client library implementation
- `main.cpp` - Example program using the library
- `BUILD` - Bazel build configuration
- `MODULE.bazel` - Bazel module configuration

