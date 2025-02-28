[go back](../README.md)

# Vulkan

Knowledge about graphics rendering with Vulkan is collected here.



Contents:
- [Installation](#installation)
- [The First Program](#the-first-program)
- ...







---
### Installation

It is recommended to install all external C++ libs in one folder (CPPlibs or cpplibs or something like that). So create such a folder and install the following libs in this folder.

1. Go to the [Vulkan Downloading Page from Lunar](https://vulkan.lunarg.com/) ([for windows you can also directly click this](https://vulkan.lunarg.com/sdk/home#windows)). Download the SDK installer and run the setup. 
2. Download the *64-bit Windows binaries* from [GLFW](https://www.glfw.org/download.html) -> Windows pre-compiled binaries. Unzip it into your external lib folder.
3. Download the latest zip from [GLM](https://github.com/g-truc/glm/releases/tag/1.0.1). Unzip it and add to your C++ external lib folder



---

### The First Program

Open your Visual Studio (or install it described like [here](../README.md#vs_)) and create an new empty C++ project. Create a main.cpp.

**AdditionalIncludeDirectories**<br>Right click on your project name in the explorer of visual studio: *Properties* \> *C/C++* \> *General* \> *Additional Including Paths* and add there the path to the including folder (to the folder where the header files are). <br>Example:

``````
D:\CPPlibs\GLFW\include
D:\CPPlibs\GLM
D:\CPPlibs\VulkanSDK\1.4.304.1\Include
``````



**AdditionalLibraryDirectories**<br>Staying in the project properties go to *Properties* \> *Linker* \> *Input* \> *Additional External Libraries Paths* and there the path to the folder where the .lib, .dll, .a files are stored.<br>Example:

``````
D:\CPPlibs\VulkanSDK\1.4.304.1\Lib
D:\CPPlibs\GLFW\lib-vc2022
``````



**AdditionalDependencies**<br>Lastly click on *Properties* \> *Linker* \> *General* \> *Additional Dependencies* and add just the name of the lib files.<br>Example:

``````
vulkan-1.lib
glfw3.lib
``````



The specific names can vary due to language or updates, but the meaning stays the same.

Now you are ready to program!





---







