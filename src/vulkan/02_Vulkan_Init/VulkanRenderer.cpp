#include "VulkanRenderer.h"

// ======================
// === INIT & CLEANUP ===
// ======================

VulkanRenderer::VulkanRenderer() {

}

VulkanRenderer::~VulkanRenderer() {

}

int VulkanRenderer::init(GLFWwindow* window) {
	this->window = window;

	try {
		create_instance();
		get_physical_device();
		create_logical_device();
	}
	catch (std::runtime_error& e) {
		printf("Error during vulkan instance creation: %s\n", e.what());
		return EXIT_FAILURE;
	}

	return 0;
}

void VulkanRenderer::clean_up() {
	vkDestroyDevice(main_device.logical_device, nullptr);
	vkDestroyInstance(instance, nullptr);
}


// ==============
// === CREATE ===
// ==============
void VulkanRenderer::create_instance() {
	// information about the application itself
	//    -> most likely only for the developer
	VkApplicationInfo app_info = {};
	app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	app_info.pApplicationName = "Vulkan App";
	app_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	app_info.pEngineName = "No Engine";
	app_info.engineVersion = VK_MAKE_VERSION(0, 0, 0);
	app_info.apiVersion = VK_API_VERSION_1_4;    // this property will influence your code!

	// creation info for vulkan instance as struct to pass multiple parameters
	VkInstanceCreateInfo create_info = {};
	create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	// create_info.pNext = 
	// create_info.flags = 
	create_info.pApplicationInfo = &app_info;
	
	// create list to hold instance extensions
	std::vector<const char*> instance_extensions = std::vector<const char*>();

	uint32_t glfw_extension_counter = 0;
	const char** glfw_extensions;
	glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_counter);

	for (size_t i = 0; i < glfw_extension_counter; ++i) {
		instance_extensions.push_back(glfw_extensions[i]);
	}

	// check all extension
	if (!check_instance_extensions_support(&instance_extensions)) {
		throw std::runtime_error("At least one extension is not supported from the current Vulkan system!");
	}

	create_info.enabledExtensionCount = static_cast<uint32_t>(instance_extensions.size());
	create_info.ppEnabledExtensionNames = instance_extensions.data();

	// validation
	create_info.enabledLayerCount = 0;
	create_info.ppEnabledLayerNames = nullptr;

	//creation instance
	VkResult result = vkCreateInstance(&create_info, nullptr, &instance);
	if (result != VK_SUCCESS) {
		throw std::runtime_error("Failed to create a Vulkan Instance!");
	}
}

void VulkanRenderer::create_logical_device() {
	// get all used queues of the choosen physical device
	QueueFamilyIndices indices = get_queue_families(main_device.physical_device);

	// create info about queues for logical device
	VkDeviceQueueCreateInfo queue_create_info = {};
	queue_create_info.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
	queue_create_info.queueFamilyIndex = indices.graphics_family;
	queue_create_info.queueCount = 1;
	float priority = 1.0f;
	queue_create_info.pQueuePriorities = &priority;    // multiple queues gets handled by priority, 1 = highest and -1 = lowest

	// information to create logical device (also called "device")
	VkDeviceCreateInfo device_create_info = {};
	device_create_info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	device_create_info.queueCreateInfoCount = 1;
	device_create_info.pQueueCreateInfos = &queue_create_info;
	device_create_info.enabledExtensionCount = 0;
	device_create_info.ppEnabledExtensionNames = nullptr;
	device_create_info.enabledLayerCount = 0;
	device_create_info.ppEnabledLayerNames = nullptr;

	VkPhysicalDeviceFeatures device_features = {};
	// get device features
	device_create_info.pEnabledFeatures = &device_features;

	// create & check the logical device
	VkResult result = vkCreateDevice(main_device.physical_device, &device_create_info, nullptr, &main_device.logical_device);
	if (result != VK_SUCCESS) {
		throw std::runtime_error("Failed to create the logical device!");
	}

	// saving queues for handling them -> logical device is created so handling is now possible
	vkGetDeviceQueue(main_device.logical_device, indices.graphics_family, 0, &graphics_queue);
}



// ==============
// === GETTER ===
// ==============
void VulkanRenderer::get_physical_device() {
	// enumerate physical devices the vulkan instance can access -> to find out how big our array must be
	uint32_t device_counter = 0;
	vkEnumeratePhysicalDevices(instance, &device_counter, nullptr);

	// check if there is at least one supported device
	if (device_counter <= 0) {
		throw std::runtime_error("Can't find a GPU for Vulkan Instance!");
	}

	// get list of physical devices
	std::vector<VkPhysicalDevice> device_list(device_counter);
	vkEnumeratePhysicalDevices(instance, &device_counter, device_list.data());

	// device picking
	//// TEMP: just pick first device
	//main_device.physical_device = device_list[0];

	for (const auto &device:device_list) {
		if (check_device_suitable(device)) {
			main_device.physical_device = device;
			break;
		}
	}
}



// ==============
// === HELPER ===
// ==============
bool VulkanRenderer::check_instance_extensions_support(std::vector<const char*>* extensions_to_check) {
	// get number of extensions
	uint32_t extension_counter = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extension_counter, nullptr);

	// create Extension list
	std::vector<VkExtensionProperties> extensions(extension_counter);
	vkEnumerateInstanceExtensionProperties(nullptr, &extension_counter, extensions.data());

	// check if extensions are available
	for (const auto &extension_to_check:*extensions_to_check) {
		bool extension_exist = false;
		for (const auto &extension:extensions) {
			if (strcmp(extension_to_check, extension.extensionName)) {
				extension_exist = true;
				break;
			}
		}

		if (!extension_exist) {
			return false;
		}
	}

	return true;
}

bool VulkanRenderer::check_device_suitable(VkPhysicalDevice device) {
	/*
	// Get Information about the device (ID, name, type, vendor, etc.)
	VkPhysicalDeviceProperties device_properties;
	vkGetPhysicalDeviceProperties(device, &device_properties);

	// informations about the features of the device
	VkPhysicalDeviceFeatures device_features;
	vkGetPhysicalDeviceFeatures(device, &device_features);
	*/

	QueueFamilyIndices indices = get_queue_families(device);

	return indices.is_valid();
}

QueueFamilyIndices VulkanRenderer::get_queue_families(VkPhysicalDevice device) {
	QueueFamilyIndices indices;
	
	// get number of queue families
	uint32_t queue_family_counter = 0;
	vkGetPhysicalDeviceQueueFamilyProperties(device, &queue_family_counter, nullptr);

	// get all queue families
	std::vector<VkQueueFamilyProperties> queue_family_list(queue_family_counter);
	vkGetPhysicalDeviceQueueFamilyProperties(device, &queue_family_counter, queue_family_list.data());

	// check if every queue have at least one of the required queues
	int i = 0;
	for (const auto &queue_family:queue_family_list) {
		// see -> VkQueueFlagBits
		// first check if queue family has at least 1 queue in that family
		// Queue can be multiple types defined through bitfield. Need to bitwise AND VK_QUEUE_*_BIT to check if it has required type
		if (queue_family.queueCount > 0 && queue_family.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
			indices.graphics_family = i;    // if queue family is valid, it gets index
		}

		// check if all families are now valid
		if (indices.is_valid()) {
			break;
		}

		i++;
	}

	return indices;
}





