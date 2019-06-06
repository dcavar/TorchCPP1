cmake_minimum_required(VERSION 3.14)
project(TorchCPP1)

set(CMAKE_CXX_STANDARD 11)

# this is necessary to tell the C++ compiler where the CMake configuration file is
set(CMAKE_PREFIX_PATH "~/libtorch/share/cmake/Torch")
find_package(Torch REQUIRED)

add_executable(TorchCPP1 main.cpp)
target_link_libraries(TorchCPP1 "${TORCH_LIBRARIES}")
# this is the location of torch/torch.h:
# ~/libtorch/include/torch/csrc/api/include/
target_include_directories(TorchCPP1 PRIVATE ${TORCH_LIBRARIES})
set_property(TARGET TorchCPP1 PROPERTY CXX_STANDARD 11)
