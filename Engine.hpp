#pragma once

#include "Graphics.hpp"
#include "Input.hpp"
#include "Raymarcher.hpp"

class Engine
{
public:
	bool m_is_running = true;

	unsigned int frame_start;

	double m_fps = 0.;
	double m_frame_time = 0.;

	Graphics_System m_graphics;
	Input_System m_input;
	Raymarcher_Renderer m_raymarcher;

	Engine();

	void update();
	double delta_time();
};
