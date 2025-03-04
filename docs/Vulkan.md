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



The **GLFW** is used to create a window and as an interface to the operating system. There are also other frameworks which also could be used instead...for example SDL.<br>**GLM** is used for mathematics. It is a specific library for math for OpenGL and therefore also can be used for vulkan.<br>And **Vulkan** is the graphic/render library itself.



---

### The First Program

Open your Visual Studio (or install it described like [here](../README.md#vs_)) and create an new empty C++ project. Create a main.cpp.

**AdditionalIncludeDirectories**<br>Right click on your project name in the explorer of visual studio: *Properties* \> *C/C++* \> *General* \> *Additional Including Paths* and add there the path to the including folder (to the folder where the header files are). <br>Example:

``````
D:\CPPlibs\GLFW\include
D:\CPPlibs\GLM
D:\CPPlibs\VulkanSDK\1.4.304.1\Include
``````



> Make sure to hit 'configuration:' on the top-left corner and choose *all*.



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

Now you are ready to program! Following main.cpp code should check if your setup works. The extension count should be about the number 12 it says how much extensions of vulkan are found.



````c++
#include <iostream>

// #include <vulkan/vulkan.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>


int main() {
	// init window with glfw
	glfwInit();
	// init window to no API, because not OpenGL, we use Vulkan
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	GLFWwindow* window = glfwCreateWindow(800, 600, "Test Window", nullptr, nullptr);
	
	// vulkan check
	uint32_t extension_count = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extension_count, nullptr);

	printf("Extension Count:%i\n", extension_count);

	// glm check
	glm::mat4 test_matrix(1.0f);
	glm::vec4 test_vector(1.0f);
	auto test_result = test_matrix * test_vector;


	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}

	// destroying
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
````







---







