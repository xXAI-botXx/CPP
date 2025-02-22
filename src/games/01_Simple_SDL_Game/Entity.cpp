
#include "Entity.h"

// Destructor implementation
Entity::~Entity() {}

// Implement color_scaling() outside the class
std::vector<int> Entity::color_scaling() {
    std::vector<int> color_scaled;
    for (double cur_element : color) {
        color_scaled.push_back(static_cast<int>(cur_element * color_max));
    }
    return color_scaled;
}


