# Specify the range of CMake versions we support
cmake_minimum_required(VERSION 3.29)

# Give some information about the project including
# its name, version and the language it's written in
# (CXX is C++)
project(
  HelloWorld
  VERSION 1.0
  LANGUAGES CXX)


# Create an executable called 'hello-world' from
# the hello-world C++ source file.
add_executable(hello-world main/hello-world.cpp)
