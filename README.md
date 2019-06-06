# C++ example 1 for PyTorch

by [Damir Cavar], June 2019



# Introduction

Using PyTorch or LibTorch with C++ comes with some minor complications. This example solves some of the issues.

Follow the instructions at: [Installing C++ Distributions of PyTorch](https://pytorch.org/cppdocs/installing.html)

You might face two problems:

- You cannot find `torch/torch.h` and you get compiler errors.
- CMake does not find the LibTorch config files

In the following, I will provide solutions that use the path of *LibTorch* relative to my home directory, indicated by the `~`. I also use simply the CPU-version of *LibTorch*.

The location of `torch/torch.h` is in the folder:

    ~/libtorch/include/torch/csrc/api/include/

This folder would be added to the `$TORCH_INCLUDE_DIRS` variable by CMake, if correctly configured.

To allow CMake to find this configuration file, make sure that this line in your CMakeLists.txt points to the directory `~/libtorch/share/cmake/Torch/`:

    set(CMAKE_PREFIX_PATH "~/libtorch/share/cmake/Torch")

The complete *CMakeLists.txt* in this example is:

    cmake_minimum_required(VERSION 3.14)
    project(TorchCPP1)
    
    set(CMAKE_CXX_STANDARD 11)
    
    set(CMAKE_PREFIX_PATH "~/libtorch/share/cmake/Torch")
    find_package(Torch REQUIRED)
    
    add_executable(TorchCPP1 main.cpp)
    target_link_libraries(TorchCPP1 "${TORCH_LIBRARIES}")
    target_include_directories(TorchCPP1 PRIVATE ${TORCH_LIBRARIES})
    set_property(TARGET TorchCPP1 PROPERTY CXX_STANDARD 11)
 
The C++ source is taken from [Installing C++ Distributions of PyTorch](https://pytorch.org/cppdocs/installing.html). To compile the code, create a *build* folder:

    mkdir build

Change into this folder:

    cd build

Let CMake generate the make-file by providing an extra parameter that points to *libtorch*, in this case, as mentioned, in my home directory:

    cmake -DCMAKE_PREFIX_PATH=~/libtorch ..

Now compile the code:

    make

You should see a binary *TorchCPP1* in the directory. Running the binary `./TorchCPP1` should show some output similar to the following:

     0.5393  0.5165  0.8186
     0.8735  0.4660  0.6906
    [ Variable[CPUFloatType]{2,3} ]



[Damir Cavar]: http://damir.cavar.me/ "Damir Cavar"
