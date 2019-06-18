#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "obj_parser.hpp"

using namespace std;

OBJ_File::OBJ_File()
{
	this->m_vertexes.reserve(3000000);
}

void OBJ_File::load(std::string file_location)
{
	ifstream file(file_location, ios::in);
	int v_count = 0;

	string current_line;

	Vector3 current_local_position(0., 0., 0.);

	if(file.is_open())
	{
		while(std::getline(file, current_line))
		{
			if(current_line[0] != '#')
			{
				if(current_line[0] == 'v')
				{					
					stringstream ss_line(current_line);

					ss_line.ignore(2, ' ');
					ss_line >> current_local_position.x;
					ss_line.ignore(1, ' ');
					ss_line >> current_local_position.y;
					ss_line.ignore(1, ' ');
					ss_line >> current_local_position.z;
	
					Vertex current_vertex(current_local_position);

					this->m_vertexes.push_back(current_vertex);
					v_count ++;
				}
			}
		}
		
		this->m_v_count = v_count;

		file.close();
	}
}
