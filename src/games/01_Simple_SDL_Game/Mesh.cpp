#include "Mesh.h"
#include <vector>

Mesh::Mesh(std::string texture path) {
	// FIXME
	vertices = Vertex();
	indices = std::vector<unsigned int>{};

	// Shape 3D
	transform = Transform3D();
	bounding_box = BoundingBox3D();
	bounding_sphere = BoundingSphere();

	//	have_animation = false;
	//	animation = Animation3D();

	has_texture = false;
	texture_path = ;     // std::string

	// If animation and texture -> first animation, then show texture

	has_fill_color = false;
	fill_color_format = COLOR_REPRESENTATION::RGBA;
	fill_color;    // std::vector<double>

	has_border_color = false;
	border_color_format = COLOR_REPRESENTATION::RGBA;
	border_color = ;    // std::vector<double>

	// GraphicData
	z_index = 0;
}


Mesh::~Mesh() {

}

};
