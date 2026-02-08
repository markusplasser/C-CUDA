cmake_minimum_required(VERSION 3.20)

project(CudaTest LANGUAGES C CXX CUDA)

# CUDA standard
set(CMAKE_CUDA_STANDARD 17)
set(CMAKE_CUDA_STANDARD_REQUIRED ON)

# Safer default: build for the local GPU
# Override manually if you want reproducible binaries
set(CMAKE_CUDA_ARCHITECTURES native)

add_executable(CudaTest
        main.cu
        Vector.c
        Object.c
        ObjectArray.c
)

# Ensure C files stay C
set_source_files_properties(
        Vector.c
        Object.c
        ObjectArray.c
        PROPERTIES
        LANGUAGE C
)

# Optional but common when mixing CUDA + C/C++
set_target_properties(CudaTest PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON
)
