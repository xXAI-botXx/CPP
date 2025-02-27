#pragma once


#include <vector>
#include <string>
#include <map>




enum COLOR_REPRESENTATION{
	RGBA = 4,
	RGB = 3
};




class GraphicsData{
public:
	virtual ~GraphicsData() = default;
	// need a abstract method! then the class is abstract

	// virtual SendDataResult send_data() = 0;

//	void say_important(){
//		std::cout << "ich liebe tobia" << std::endl;
//	}
protected:
	int z_index = 0; // Layer for Rendering-Priority
};





