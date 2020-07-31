# CMakeList.txt : CMake project for TorchSmart, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(project_name pthreads4w_test)
project(${project_name})

include_directories(
${CMAKE_CURRENT_SOURCE_DIR}
${CMAKE_SOURCE_DIR}/pthreads4w-code-v3.0.0
)
link_directories(
${CMAKE_BINARY_DIR}/pthreads4w-code-v3.0.0
)
set(PTHREADS_LIBS pthreads4w)
set(MSVC_LIBS)
# Add source to this project's executable.
add_executable(${project_name} "pthreads4w-test.cpp")

set_property(TARGET ${project_name} PROPERTY CXX_STANDARD 11)

target_link_libraries(${project_name} PRIVATE ${PTHREADS_LIBS} ${MSVC_LIBS})


# TODO: Add tests and install targets if needed.
