load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

# Stages of compilation:

# Preprocessing: 

# This is the first stage of compilation. It is responsible for expanding the source code by copying the contents of headers into the source file, replacing macros with their defined values, handling conditional compilation directives, and removing comments. The output of this stage is a single expanded source file per .cpp file, which is still in C++ syntax but not yet executable - this is typically stored in memory.

# Compile and assemble: 

# The compiler parses the preprocessed C++ source. It needs DECLARATIONS (from headers) to understand what functions/classes exist and their signatures, but it doesn't need DEFINITIONS (implementations).

# When compiling a .cpp file that calls a function from another file, the compiler only needs to see the declaration (from a header) to know: "there's a function called X() with signature Y". It generates a CALL instruction with an "unresolved symbol" (a placeholder saying "find function X() later").

# The compiler then generates assembly code, and the assembler converts that to machine code, producing a .o file. The .o file contains: compiled code + a symbol table listing what symbols it defines (functions/variables in this file) and what symbols it needs from elsewhere (unresolved references).

# Example: file_a.o contains compiled code that calls functionX() + a note "I need functionX()" but doesn't have the actual functionX() implementation. file_b.o contains the compiled functionX() implementation + a note "I define functionX()". The linker will match these up later.

# Link: 

# This is where function DEFINITIONS are found and connected to their usages. The linker reads all the .o files and their symbol tables. It matches up unresolved symbols ("I need functionX()") with defined symbols ("I define functionX()") across all object files.

# Process: The linker collects all .o files, extracts their symbol tables, and creates a global symbol map. For each unresolved reference, it searches for a matching definition. Once found, it patches the CALL instruction in the calling code to point to the actual address of the function definition.

# If the linker can't find a definition for a needed symbol, you get a "undefined reference" error.  If multiple definitions exist for the same symbol, you get a "multiple definition" error. After resolving all symbols, the linker combines all the .o files into a single executable or library, with all function calls properly connected to their implementations.

# Creating Libraries vs Executables:

# Static Library (.a): The linker (or more accurately, the 'ar' archive tool) packages .o files into an archive.
#   - No actual linking happens - unresolved symbols remain unresolved
#   - Just bundles .o files together for later use
#   - When someone uses the library, their linker extracts needed .o files and links them into their executable
#   When to use: When you want code to be copied into the final executable (self-contained, no runtime dependencies).
#     Good for: Small libraries, avoiding DLL hell, single-executable deployment, embedded systems.
#     Trade-off: Larger executables, can't update library without recompiling the program.
#   DLL Hell: A problem (primarily on Windows) where multiple applications require different versions of the same
#     shared library (DLL). Installing one application may overwrite a DLL with a newer/older version, breaking
#     other applications that depend on a specific version. Static libraries avoid this by bundling code directly
#     into each executable, making each program self-contained.
#   Examples: OpenSSL (when statically linked), zlib, libpng, small utility libraries, embedded system libraries.

# Shared Library (.so/.dylib): The linker DOES link the .o files together, but creates a library instead of an executable.
#   - Resolves symbols within the library itself
#   - May still have unresolved symbols that will be resolved when the library is loaded
#   - Creates a loadable library file that can be shared between multiple programs
#   When to use: When you want code to be loaded at runtime and shared between multiple programs.
#     Good for: Large libraries used by many programs (saves disk/memory), updating libraries without recompiling,
#     plugin systems, system libraries. Trade-off: Requires library file at runtime, version compatibility concerns.
#   Examples: OpenSSL (libssl.so/libcrypto.so), standard C library (libc.so), C++ standard library (libstdc++.so),
#     GUI frameworks (libgtk.so, Qt libraries), system libraries (libpthread.so, libdl.so).

# Executable: The linker fully resolves all symbols and creates a runnable program.
#   - All symbols must be resolved (either from .o files or libraries)
#   - Creates a file with an entry point (main function) that can be executed
#   When to use: For the final program that users run. This is what you create when you want a standalone
#     application. Can link against both static and shared libraries as needed.
#   Examples: Command-line tools (ls, grep, git), applications (web browsers, text editors), games, your HTTP client
#     program, any program with a main() function that users execute directly.

# HTTP client library - can be used by other C++ programs
# This creates a STATIC LIBRARY (.a file) by default. The library code will be copied into any executable
# that links against it, making the final program self-contained with no runtime library dependencies.
cc_library(
    name = "http_client",
    srcs = ["http_client.cpp"],
    hdrs = ["http_client.h"],
    copts = ["-std=c++17"],
    visibility = ["//visibility:public"],  # Allows other packages to depend on this
)

# Example binary using the library
cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    copts = ["-std=c++17"],
    deps = [":http_client"],
)

# Tests for the HTTP client library
cc_test(
    name = "http_client_test",
    srcs = ["http_client_test.cpp"],
    copts = ["-std=c++17"],
    deps = [":http_client"],
)

