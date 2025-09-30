[go back](../../README.md)

# VSCode in Linux via Docker Container

On every platform you can start an Ubuntu container and access the container via VSCode (install `Dev Containers Extension`) and therefore you can code C++ in Linux.


1. First you need to create an Image (a virtual environment) from which containers can be started. For that create a file name `Dockfile` (recommended) or `anyname.Dockerfile` or `Dockerfile.anyname`.
    And write this into the file:
    ```docker
    FROM ubuntu:22.04
    
    # Updates & Compiler
    RUN apt-get update && \
        DEBIAN_FRONTEND=noninteractive apt-get install -y \
        build-essential \
        clang \
        cmake \
        ninja-build \
        gdb \
        gcc \
        g++ \
        clang-tidy \
        libgtest-dev \
        libbenchmark-dev \
        git \
        && rm -rf /var/lib/apt/lists/*
    ```
2. Next you have to build the Image. For that open the powershell or the shell in Docker Desktop (in the right bottom) and write:
    ```bash
    docker build -t cpp-dev .
    ```
3. Now you can run/start a new container. This can be typed into any bash/Powershell or again in the shell from Docker Desktop (in the right bottom):
    ```docker
    cd D:\Users\Tobia\cpp-project && D:
    docker run -it --rm -v .:/workspace -v C:\Users\Tobia\external-libs\myLib:/external/myLib ` -w /workspace cpp-dev bash
    ```
    Now you can open VSCode and open your container with navigating to the container section in VSCode and then clicking on the running container -> something like "Attaching in VSCode Window" and then opening the `workspace` folder.

   > You might want (re-)install VSCode extensions in this remote container connection (C/C++ Extension, CMake, C-TestMate)

    You can test via:
    ```bash
    g++ --version
    clang++ --version
    cmake --version
    ```



