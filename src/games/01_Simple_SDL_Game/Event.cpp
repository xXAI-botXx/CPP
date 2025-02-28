
#include "Event.h"

Event::Event(EVENT_TYPE type) : type(type) {
	value = "";
}

Event::Event(EVENT_TYPE type, std::string value) : type(type), value(value) {
	
}

Event::Event(EVENT_TYPE type, std::vector<KEY> pressed_keys) : type(type), pressed_keys(pressed_keys) {
	value = "";
}

Event::~Event() {

}

bool contains(std::vector<KEY> keys, KEY search_key) {
	for (KEY cur_key : keys) {
		if (cur_key == search_key) {
			return true;
		}
	}
	return false;
}

