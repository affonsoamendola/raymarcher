#include "Vertex.hpp"

#include "Vector.hpp"

Vertex::Vertex()
				: 	m_local_position(),
					m_origin_position(),
					m_normal_vector()
{}

Vertex::Vertex( const Vector3& local) 
				: 	m_local_position(local),
					m_origin_position(),
					m_normal_vector(local)
{}

Vertex::Vertex(	const Vector3& local, const Vector3& origin)
				: 	m_local_position(local),
					m_origin_position(origin),
					m_normal_vector(local)
{}

Vertex::Vertex( const Vector3& local, const Vector3& origin, const Vector3& normal)
				: 	m_local_position(local),
					m_origin_position(origin),
					m_normal_vector(normal)
{}

