# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("pthreads4w")

# Include sub-projects.
add_subdirectory ("pthreads4w-code-v3.0.0")
add_subdirectory ("pthreads4w-test")
