#pragma once

#include "Vector.hpp"

//--------------------

class Vertex
{
public:
	Vertex();
	Vertex(const Vector3& local);
	Vertex(const Vector3& local, const Vector3& origin);
	Vertex(const Vector3& local, const Vector3& origin, const Vector3& normal);

	Vector3 m_origin_position;
	Vector3 m_local_position;
	Vector3 m_normal_vector;
};