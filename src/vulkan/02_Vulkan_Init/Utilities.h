#pragma once

// Indices (locations) of Queue Families
struct QueueFamilyIndices {
	int graphics_family = -1;

	bool is_valid() {
		return graphics_family >= 0;
	};
};


