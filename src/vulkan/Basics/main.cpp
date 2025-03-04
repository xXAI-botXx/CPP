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

