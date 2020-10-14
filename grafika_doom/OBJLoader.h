#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>

#include<glew.h>
#include<glfw3.h>

#include<glm.hpp>
#include<vec3.hpp>
#include<vec4.hpp>
#include<mat4x4.hpp>
#include<gtc/matrix_transform.hpp>
#include<gtc/type_ptr.hpp>

#include"Vertex.h"

static std::vector<Vertex> OBJLoad(const char* fileName)
{
	std::vector<glm::fvec3> verrtex_positions;
	std::vector<glm::fvec2> verrtex_texcords;
	std::vector<glm::fvec3> verrtex_normals;

	//faces
	std::vector<GLint> vertex_position_indicies;
	std::vector<GLint> vertex_texcord_indicies;
	std::vector<GLint> vertex_normal_indicies;

	//vertex array
	std::vector<Vertex> vertices;

	std::stringstream stringStream;
	std::ifstream inFile(fileName);
	std::string line = "";
	std::string prefix = "";
	glm::vec3 temp_vec3;
	glm::vec2 temp_vec2;
	GLint temp_GLint = 0;



	if (!inFile.is_open())
	{

		throw "ERROR:: OBJLOADER: Could not open file "; 

	}

	while (std::getline(inFile, line))
	{
		stringStream.clear();
		stringStream.str(line);
		stringStream >> prefix;

		if (prefix == "#")
		{

		}
		if (prefix == "o")
		{

		}
		if (prefix == "s")
		{

		}
		if (prefix == "use_mtl")
		{

		}
		if (prefix == "v")
		{
			stringStream >> temp_vec3.x >> temp_vec3.y >> temp_vec3.z;
			verrtex_positions.push_back(temp_vec3);
		}
		else if (prefix == "vt")
		{
			stringStream >> temp_vec2.x >> temp_vec2.y;
			verrtex_texcords.push_back(temp_vec2);
		}
		else if (prefix == "vn")
		{
			stringStream >> temp_vec3.x >> temp_vec3.y >> temp_vec3.z;
			verrtex_normals.push_back(temp_vec3);
		}
		else if (prefix == "f")
		{
			int counter = 0;
			while (stringStream >> temp_GLint)
			{
				if (counter == 0)
					vertex_position_indicies.push_back(temp_GLint);
				else if (counter == 1)
					vertex_texcord_indicies.push_back(temp_GLint);
				else if (counter == 2)
					vertex_normal_indicies.push_back(temp_GLint);

				if (stringStream.peek() == '/')
				{
					++counter;
					stringStream.ignore(1, '/');
				}
				else if (stringStream.peek() == ' ')
				{
					++counter;
					stringStream.ignore(1, ' ');
				}

				if (counter > 2)
					counter = 0;

			}

		}
		else
		{

		}
		
	}
	//build vertex array
	vertices.resize(vertex_position_indicies.size(), Vertex());

	//load in all indices
	for (size_t i = 0; i < vertices.size(); i++)
	{
		vertices[i].position = verrtex_positions[vertex_position_indicies[i] - 1];
		vertices[i].texcord = verrtex_texcords[vertex_texcord_indicies[i] - 1];
		vertices[i].normal = verrtex_normals[vertex_normal_indicies[i] - 1];
		vertices[i].color = glm::vec3(1.0f, 1.0f, 1.0f);
	}

	//std::cout << line << "\n";
	std::cout << "Nr of vertices " << vertices.size() << "\n";

	std::cout << "OBJ File loaded" << "\n";

	return vertices;
}
