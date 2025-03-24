#pragma once

#include "Utilities.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <vector>

class VulkanRenderer{
public:
	VulkanRenderer();
	~VulkanRenderer();

	int init(GLFWwindow* window);
	void clean_up();

private:
	GLFWwindow* window;

	// Vulkan Components
	VkInstance instance;
	struct {
		VkPhysicalDevice physical_device;
		VkDevice logical_device;
	} main_device;
	VkQueue graphics_queue;
	
	// Vulkan Functions
	// - create functions
	void create_instance();
	void create_logical_device();

	// -get functions
	void get_physical_device();

	// - support functions
	// - - checker functions
	bool check_instance_extensions_support(std::vector<const char*>* extensions_to_check);
	bool check_device_suitable(VkPhysicalDevice device);

	// - - getter functions
	QueueFamilyIndices get_queue_families(VkPhysicalDevice device);
};

