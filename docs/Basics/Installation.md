[go back](../../README.md)

# Installation

Contents
- <a href="#installation_">Installation of GNU Compiler Collection</a>
- <a href="VSCode_Linux_Container.md">Installation via Docker (link)</a>

<br><br>

---
<h3><a href="#top" name="installation_">Installation of GNU Compiler Collection</a></h3>

Most used compiler is the GNU Compiler Collection (GCC). It is used to compile cpp code to executable code.

<!--
- Download a C++ Compiler in **Windows**:
    - https://cygwin.com/install.html
    - make sure to install following extension (use the search bar，choose a version and click that it should get download):
        - cygwin-devel
        - gcc-g++
        - gcc-core
        - make
        - cmake
        - gdb
        - git
        - python39
        - autoconf
        - automake
        - libtool
        - ninja
        - xorg-server
        - libX11-devel
        - libXext-devel
        - libXrandr-devel
        - libXrender-devel
        - libXcursor-devel
        - libXinerama-devel
        - libXi-devel
        - libXss-devel
        - libgcc1
        - libstdc++6
    - Add cygwin to the system path variables. Then you can use the normal cmd or Powershell or the terminal in Visual Studio Code.<br>To do so，you have to search/open the system-variables (environment variables). There you search the entry "Path", there should be already some paths. To these paths you add the path of Cygwin bin folder, probably: **C:\cygwin64\bin** <br>And now it should work. Maybe a restart is requirement, if it doesn't works.
    
    - Testing (in Cygwin and or normal terminal): 
    ```terminal
    make --version
    gdb --version
    gcc --version
    g++ --version
    ```
    
> You can download additional packages by running the setup file again. It will only install the new packages.

-->
    
- Download a C++ Compiler in **Windows**:
    - Download MinGW on: https://winlibs.com/
    - Unzipping in a path you like
    - Add MinGW to the system path variables. Then you can use the normal cmd or Powershell or the terminal in Visual Studio Code.<br>To do so，you have to search/open the system-variables (environment variables). There you search the entry "Path", there should be already some paths. To these paths you add the path of MinGW bin folder, probably: **C:\MinGW\bin** <br>And now it should work. Maybe a restart is requirement, if it doesn't works.
    - Download [Ninja](https://ninja-build.org/) -> download the win-zip file + also add the path to ninja.exe to the system path as decribed before




- Download a C++ Compiler in **Linux**:
    - Installation: 
    ```terminal
    sudo apt-get update
    sudo apt-get upgrade
    sudo apt-get install make
    sudo apt-get install gdb
    sudo apt-get install gcc
    sudo apt-get install g++
    sudo apt-get install git
    sudo apt-get install cmake
    sudo apt-get install autoconf
    sudo apt-get install automake
    sudo apt-get install libtool
    sudo apt-get install ninja
    ```
    - Testing: 
    ```terminal
    gdb --version
    gcc --version
    g++ --version
    ```






