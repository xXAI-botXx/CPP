#pragma once

#include "Event.h"

class InputProcessor {
public:
	/*InputProcessor() = default;
	virtual ~InputProcessor();*/

	virtual bool poll_event(Event*& event_to_store_new_event) = 0;
};

