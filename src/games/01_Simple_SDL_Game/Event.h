#pragma once

#include <string>
#include <vector>

enum KEY {
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,
	ESC,
	STRG,
	SPACE,
	ALT_GR,
	ALT,
	WINDOWS,
	SHIFT,
	TAB,
	PLUS,
	MINUS,
	POUNT,
	ENTER,
	REMOVE,
	LEFT_MOUSE,
	RIGHT_MOUSE,
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	ZERO,
	NONE
};

enum EVENT_TYPE {
	QUIT,
	WINDOW_RESIZING,
	PRESSED_KEY,
	// ...
};

bool contains(std::vector<KEY> keys, KEY search_key);

class Event {
public:
	Event(EVENT_TYPE type);
	Event(EVENT_TYPE type, std::string value);
	Event(EVENT_TYPE type, std::vector<KEY> pressed_key);
	~Event();

	EVENT_TYPE type;
	std::string value;
	std::vector<KEY> pressed_keys;
};




