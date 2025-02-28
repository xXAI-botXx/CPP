#pragma once

#include <vector>
#include <string>
#include <map>

#include "GraphicsData.h"

struct Transform3D {
    double x = 0.0;  // Center Position X
    double y = 0.0;  // Center Position Y
    double z = 0.0;  // Center Position Z
    double rotation_x = 0.0; // Rotation around X-axis in degrees
    double rotation_y = 0.0; // Rotation around Y-axis in degrees
    double rotation_z = 0.0; // Rotation around Z-axis in degrees
    double scale_x = 1.0; // Scale X
    double scale_y = 1.0; // Scale Y
    double scale_z = 1.0; // Scale Z
};

struct BoundingBox3D {
    double min_x = 0.0;
    double min_y = 0.0;
    double min_z = 0.0;
    double max_x = 0.0;
    double max_y = 0.0;
    double max_z = 0.0;
};

struct BoundingSphere {
    double center_x = 0.0;
    double center_y = 0.0;
    double center_z = 0.0;
    double radius = 0.0;
};

//struct Animation3D{
//    std::vector<std::string> paths;
//    std::vector<double> times;
//};

class Shape3D : public GraphicsData {
public:
    virtual ~Shape3D() = default;
    // virtual SendDataResult send_data() = 0;

protected:
    Transform3D transform;
    BoundingBox3D bounding_box;
    BoundingSphere bounding_sphere;

    // bool have_animation = false;
    // Animation3D animation;

    bool has_texture = false;
    std::string texture_path;

    // If animation and texture -> first animation, then show texture

    bool has_fill_color = false;
    COLOR_REPRESENTATION fill_color_format = COLOR_REPRESENTATION::RGBA;
    std::vector<double> fill_color;

    bool has_border_color = false;
    COLOR_REPRESENTATION border_color_format = COLOR_REPRESENTATION::RGBA;
    std::vector<double> border_color;
};







