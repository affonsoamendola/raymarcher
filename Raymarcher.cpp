#include <iostream>

#include "Vector.hpp"
#include "Raymarcher.hpp"

#include "Engine.hpp"

using namespace std;

Raymarcher_Renderer::Raymarcher_Renderer(Engine * parent_engine) : Engine_System(parent_engine)
{
	this->m_camera_position = Vector3(0., 0., -2.);
	this->test_point = Vector3(0., 0., 0.);
	this->light_point = Vector3(2., 1., 0.);
} 

void Raymarcher_Renderer::update()
{
	for(int x = 0; x < this->m_parent_engine->m_graphics.m_screen_width; x++)
	{
		for(int y = 0; y < this->m_parent_engine->m_graphics.m_screen_height; y++)
		{
			Ray current_ray(	this->m_camera_position + (Vector3(0., 0., 1.) *  this->m_camera_focus_point), 
								this->ss_to_ws(x, y),
								this);

			for(int i = 0; i < this->MAX_MARCHES; i++)
			{
				current_ray.march();

				if(current_ray.m_closest_object_distance <= 0.01)
				{
					Vector3 light_vector = this->light_point - current_ray.m_position;
					
					double light_intensity = 1. - light_vector.abs()/ 3.;

					if(light_intensity < 0.) light_intensity = 0.;

					this->m_parent_engine->m_graphics.set_pixel(x, y, Color(255 * light_intensity, 165 * light_intensity, 0));
					break;
				}
			}
		}
	}
}

Vector3 Raymarcher_Renderer::ss_to_ws(int x, int y)
{
	Vector3 world_position;

	int screen_width = this->m_parent_engine->m_graphics.m_screen_width;
	int screen_height = this->m_parent_engine->m_graphics.m_screen_height;

	world_position.x = this->m_camera_position.x + (x - screen_width/2) * this->m_screen_plate_width / (double)(screen_width);
	world_position.y = this->m_camera_position.y + (screen_height/2 - y) * this->m_screen_plate_height / (double)(screen_height);
	world_position.z = this->m_camera_position.z + this->m_z_hither;

	return world_position;
}

Ray::Ray(Vector3 start, Vector3 towards, Raymarcher_Renderer * raymarcher_context)
	: 	m_position(start),
		m_raymarcher_context(raymarcher_context)
{
	this->m_direction = (towards - start).unit();
	this->m_closest_object_distance = (this->m_raymarcher_context->test_point - this->m_position).abs();
}

void Ray::march()
{
	this->m_position += this->m_direction * (this->m_closest_object_distance);
	this->m_travelled += this->m_closest_object_distance;
			
	this->m_closest_object_distance = (this->m_raymarcher_context->test_point - this->m_position).abs() - 1.;
}
