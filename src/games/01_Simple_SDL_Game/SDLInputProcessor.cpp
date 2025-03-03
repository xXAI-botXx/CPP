#include <SDL3/SDL.h>

#include "Event.h"
#include "SDLInputProcessor.h"



SDLInputProcessor::SDLInputProcessor() {

}

SDLInputProcessor::~SDLInputProcessor() {

}

bool SDLInputProcessor::poll_event(Event*& event_to_store_new_event) {
	if (event_to_store_new_event) {
		delete event_to_store_new_event;
		event_to_store_new_event = nullptr;
	}

	SDL_Event event;

	bool there_is_an_event = SDL_PollEvent(&event);

	if (there_is_an_event) {
		switch (event.type) {
		case SDL_EVENT_QUIT:
			event_to_store_new_event = new Event(EVENT_TYPE::QUIT);
			break;
		case SDL_EVENT_WINDOW_RESIZED:
			event_to_store_new_event = new Event(EVENT_TYPE::WINDOW_RESIZING);
			break;
		}
		return true;
	}
	else {
		std::vector<KEY> pressed_keys;

		// get keyboard inputs
		const bool* state = SDL_GetKeyboardState(nullptr);

		if (state[SDL_SCANCODE_ESCAPE]) {
			pressed_keys.push_back(KEY::ESC);
		}

		if (state[SDL_SCANCODE_A]) {
			pressed_keys.push_back(KEY::A);
		}

		if (state[SDL_SCANCODE_B]) {
			pressed_keys.push_back(KEY::B);
		}

		if (state[SDL_SCANCODE_C]) {
			pressed_keys.push_back(KEY::C);
		}

		if (state[SDL_SCANCODE_D]) {
			pressed_keys.push_back(KEY::D);
		}

		if (state[SDL_SCANCODE_E]) {
			pressed_keys.push_back(KEY::E);
		}

		if (state[SDL_SCANCODE_F]) {
			pressed_keys.push_back(KEY::F);
		}

		if (state[SDL_SCANCODE_G]) {
			pressed_keys.push_back(KEY::G);
		}

		if (state[SDL_SCANCODE_H]) {
			pressed_keys.push_back(KEY::H);
		}

		if (state[SDL_SCANCODE_I]) {
			pressed_keys.push_back(KEY::I);
		}

		if (state[SDL_SCANCODE_J]) {
			pressed_keys.push_back(KEY::J);
		}

		if (state[SDL_SCANCODE_K]) {
			pressed_keys.push_back(KEY::K);
		}

		if (state[SDL_SCANCODE_L]) {
			pressed_keys.push_back(KEY::L);
		}

		if (state[SDL_SCANCODE_M]) {
			pressed_keys.push_back(KEY::M);
		}

		if (state[SDL_SCANCODE_N]) {
			pressed_keys.push_back(KEY::N);
		}

		if (state[SDL_SCANCODE_O]) {
			pressed_keys.push_back(KEY::O);
		}

		if (state[SDL_SCANCODE_P]) {
			pressed_keys.push_back(KEY::P);
		}

		if (state[SDL_SCANCODE_Q]) {
			pressed_keys.push_back(KEY::Q);
		}

		if (state[SDL_SCANCODE_R]) {
			pressed_keys.push_back(KEY::R);
		}

		if (state[SDL_SCANCODE_S]) {
			pressed_keys.push_back(KEY::S);
		}

		if (state[SDL_SCANCODE_T]) {
			pressed_keys.push_back(KEY::T);
		}

		if (state[SDL_SCANCODE_U]) {
			pressed_keys.push_back(KEY::U);
		}

		if (state[SDL_SCANCODE_V]) {
			pressed_keys.push_back(KEY::V);
		}

		if (state[SDL_SCANCODE_W]) {
			pressed_keys.push_back(KEY::W);
		}

		if (state[SDL_SCANCODE_X]) {
			pressed_keys.push_back(KEY::X);
		}

		if (state[SDL_SCANCODE_Y]) {
			pressed_keys.push_back(KEY::Y);
		}

		if (state[SDL_SCANCODE_Z]) {
			pressed_keys.push_back(KEY::Z);
		}

		if (state[SDL_SCANCODE_1]) {
			pressed_keys.push_back(KEY::ONE);
		}

		if (state[SDL_SCANCODE_2]) {
			pressed_keys.push_back(KEY::TWO);
		}

		if (state[SDL_SCANCODE_3]) {
			pressed_keys.push_back(KEY::THREE);
		}

		if (state[SDL_SCANCODE_4]) {
			pressed_keys.push_back(KEY::FOUR);
		}

		if (state[SDL_SCANCODE_5]) {
			pressed_keys.push_back(KEY::FIVE);
		}

		if (state[SDL_SCANCODE_6]) {
			pressed_keys.push_back(KEY::SIX);
		}

		if (state[SDL_SCANCODE_7]) {
			pressed_keys.push_back(KEY::SEVEN);
		}

		if (state[SDL_SCANCODE_8]) {
			pressed_keys.push_back(KEY::EIGHT);
		}

		if (state[SDL_SCANCODE_9]) {
			pressed_keys.push_back(KEY::NINE);
		}

		if (state[SDL_SCANCODE_0]) {
			pressed_keys.push_back(KEY::ZERO);
		}

		if (pressed_keys.size() > 0) {
			event_to_store_new_event = new Event(EVENT_TYPE::PRESSED_KEY, pressed_keys);
			return true;
		}
		else {
			event_to_store_new_event = nullptr;
			return false;
		}
	}
}



