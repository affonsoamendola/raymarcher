#pragma once

#include <memory>

#include "SDL2/SDL.h"

#include "Engine_System.hpp"

class Engine;

class Input_System : public Engine_System
{
private:
	SDL_Event m_event;

public:
	Input_System(Engine * parent_engine);

	void update();
};


