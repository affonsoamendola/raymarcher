#pragma once

#include <vector>
#include <string>

#include "Vertex.hpp"

class OBJ_File
{
private:
	
public:
	OBJ_File();

	std::vector<Vertex> m_vertexes;
	int m_v_count = 0;

	Vertex get_Vertex(int index);
	void set_Vertex(int index, const Vertex& vertex);

	void load(std::string file_location);
};