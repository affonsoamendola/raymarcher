#include <iostream>

#include "Engine.hpp"
#include "SDL2/SDL.h"

using namespace std;

Engine::Engine()
	:	m_graphics(this),
		m_input(this),
		m_raymarcher(this)
{
}

void Engine::update()
{
	this->frame_start = SDL_GetPerformanceCounter();

	this->m_raymarcher.update();
	this->m_graphics.update();
	this->m_input.update();

    this->m_frame_time = this->delta_time();
    this->m_fps = 1. / this->m_frame_time;
}

double Engine::delta_time()
{
	const unsigned int frame_end = SDL_GetPerformanceCounter();
    const static unsigned int freq = SDL_GetPerformanceFrequency();
    
	return (frame_end - this->frame_start) / static_cast<double>(freq);
}
