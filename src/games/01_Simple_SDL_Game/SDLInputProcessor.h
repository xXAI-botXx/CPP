#pragma once

#include "Event.h"
#include "GraphicsHandler.h"
#include "InputProcessor.h"

class SDLInputProcessor :public InputProcessor {
public:
	SDLInputProcessor();
	~SDLInputProcessor();

	bool poll_event(Event*& event_to_store_new_event);
};
