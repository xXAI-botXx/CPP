#pragma once

#include "Shape3D.h"
#include <vector>
#include <string>

struct Vertex {
    std::vector<double> position;
    std::vector<double> normal;
    std::vector<double> texCoords;    // 2 values
};

class Mesh :public Shape3D {
public:
    Mesh(std::string texture_path);
    ~Mesh();
    // SendDataResult send_data();

protected:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
};








