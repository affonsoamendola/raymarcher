#pragma once

#include "Engine_System.hpp"
#include "Vector.hpp"

class Raymarcher_Renderer : public Engine_System
{
private:
	
	double m_screen_plate_width = 3.2;
	double m_screen_plate_height = 2.4;

	double m_camera_focus_point = -2.2;
	double m_z_hither = 0.1;
	double m_z_yon = 10.0;

	const int MAX_MARCHES = 3;

public:
	Vector3 m_camera_position;
	Vector3 test_point;
	Vector3 light_point;
	Raymarcher_Renderer(Engine * parent_engine);

	void update();

	Vector3 ss_to_ws(int ss_x, int ss_y);
};

class Ray
{
public:
	Ray(Vector3 start, Vector3 end, Raymarcher_Renderer * raymarcher_context);

	Raymarcher_Renderer * m_raymarcher_context;

	Vector3 m_position;
	Vector3 m_direction;

	double m_closest_object_distance;
	double m_travelled = 0.;

	void march();
};
