// === Imports ===
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <vector>
#include <iostream>

#include "VulkanRenderer.h"



// === Global variables ===
GLFWwindow* window;
VulkanRenderer renderer;



// === Function Helper ===
void init_window(std::string window_name="Test Window", const int width=800, const int height=600) {
	// init GLFW
	glfwInit();

	// set GLFW to not work with OpenGL
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	// create window
	window = glfwCreateWindow(width, height, window_name.c_str(), nullptr, nullptr);
}


// === Main ===
int main() {
	// create window
	init_window();

	// create Vulkan renderer
	// renderer = new VulkanRenderer();
	if (renderer.init(window) == EXIT_FAILURE) {
		return EXIT_FAILURE;
	}

	// window loop
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}

	// cleaning & destroy window
	renderer.clean_up();
	glfwDestroyWindow(window);
	glfwTerminate();
	
	return 0;
}



