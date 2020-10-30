#pragma once
#include<glew.h>
#include<glfw3.h>

#include<vector>
#include"Vertex.h"


class Primitives
{
private:

	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;


public:
	Primitives() {}

	virtual ~Primitives() {}

	void set(const Vertex* vertices, const unsigned nrOfVertices, const GLuint* indices, const unsigned nrOfIndices)
	{
		for (size_t i = 0; i < nrOfVertices; i++)
		{
			this->vertices.push_back(vertices[i]);
		}

		for (size_t i = 0; i < nrOfIndices; i++)
		{
			this->indices.push_back(indices[i]);
		}
	}

	inline Vertex* getVertices() { return this->vertices.data(); }

	inline GLuint* getIndecies() { return this->indices.data(); }

	inline const unsigned getNrOfVertices() { return this->vertices.size(); }

	inline const unsigned getNrOfIndecies() { return this->indices.size(); }

};
class Cubus : public Primitives
{
public:
	Cubus()
		: Primitives()
	{
		Vertex vertices[] =
		{
			//postion									//color								//texcord							//normal
				//front
			/*0*/	glm::vec3(-1.f, 1.f, 0.0f),			glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(0.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*1*/	glm::vec3(-1.f, -1.f, 0.0f),		glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(0.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*2*/	glm::vec3(1.f, -1.f, 0.0f),			glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(1.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
																  
			/*0*/	glm::vec3(-1.f, 1.f, 0.0f),			glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(0.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*2*/	glm::vec3(1.f, -1.f, 0.0f),			glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(1.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*3*/	glm::vec3(1.f, 1.f, 0.0f),		    glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
																   
				//left											   
			/*4*/	glm::vec3(-1.f, 1.f, -1.0f),		glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(0.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*5*/	glm::vec3(-1.f, -1.f, -1.0f),		glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(0.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*1*/	glm::vec3(-1.f, -1.f, 0.0f),		glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(1.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
																  
			/*4*/	glm::vec3(-1.f, 1.f, -1.0f),		glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(0.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*1*/	glm::vec3(-1.f, -1.f, 0.0f),		glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(1.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*0*/	glm::vec3(-1.f, 1.f, 0.0f),			glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
																  
				//right											  
			/*3*/	glm::vec3(1.f, 1.f, 0.0f),		    glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(0.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*2*/	glm::vec3(1.f, -1.f, 0.0f),			glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(0.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*6*/	glm::vec3(1.f, -1.f, -1.0f),		glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(1.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
																   
			/*3*/	glm::vec3(1.f, 1.f, 0.0f),		    glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(0.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*6*/	glm::vec3(1.f, -1.f, -1.0f),		glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(1.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*7*/	glm::vec3(1.f, 1.f, -1.0f),		    glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
																 
				//back											 
			/*7*/	glm::vec3(1.f, 1.f, -1.0f),		    glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(0.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*6*/	glm::vec3(1.f, -1.f, -1.0f),		glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(0.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*5*/	glm::vec3(-1.f, -1.f, -1.0f),		glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(1.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
																  
			/*7*/	glm::vec3(1.f, 1.f, -1.0f),		    glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(0.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*5*/	glm::vec3(-1.f, -1.f, -1.0f),		glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(1.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*4*/	glm::vec3(-1.f, 1.f, -1.0f),		glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
																 
				//top											 
			/*4*/	glm::vec3(-1.f, 1.f, -1.0f),		glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(0.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*0*/	glm::vec3(-1.f, 1.f, 0.0f),			glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(0.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*3*/	glm::vec3(1.f, 1.f, 0.0f),		    glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(1.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
																  
			/*4*/	glm::vec3(-1.f, 1.f, -1.0f),		glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(0.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*3*/	glm::vec3(1.f, 1.f, 0.0f),		    glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(1.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*7*/	glm::vec3(1.f, 1.f, -1.0f),		    glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
																  
				//bottom										  
			/*1*/	glm::vec3(-1.f, -1.f, 0.0f),		glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(0.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*5*/	glm::vec3(-1.f, -1.f, -1.0f),		glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(0.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*6*/	glm::vec3(1.f, -1.f, -1.0f),		glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(1.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
																  
			/*1*/	glm::vec3(-1.f, -1.f, 0.0f),		glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(0.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*6*/	glm::vec3(1.f, -1.f, -1.0f),		glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(1.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*2*/	glm::vec3(1.f, -1.f, 0.0f),			glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),

		};

		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		this->set(vertices, nrOfVertices, nullptr, 0);
	}
};

class Floor : public Primitives
{
public:
	Floor()
		: Primitives()
	{
		Vertex vertices[] =
		{
			//postion								//color								//texcord							//normal
			/*0*/	glm::vec3(-1.f, 1.f, 0.0f),			glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(0.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*1*/	glm::vec3(-1.f, -1.f, 0.0f),		glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(0.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*2*/	glm::vec3(1.f, -1.f, 0.0f),			glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(1.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*3*/	glm::vec3(1.f, 1.f, 0.0f),		    glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*4*/	glm::vec3(-1.f, 1.f, -1.0f),		glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(0.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*5*/	glm::vec3(-1.f, -1.f, -1.0f),		glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(0.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*6*/	glm::vec3(1.f, -1.f, -1.0f),		glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*7*/	glm::vec3(1.f, 1.f, -1.0f),		    glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),

		};														

		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] =
		{
			5,1,2,
			5,2,6
			//0, 1, 2,//front face
			//0, 2, 3,//front face
			//7,6,5, //rear
			//7,5,4, //rear
			//1,5,6, //down
			//1,6,2, //down
			//4, 3, 7, //up
			//4, 0, 3, //up
			//3,2,6,//rigth
			//3,6,7, //right
			//4,5,1, //left
			//4,1,0  //left
		};	

		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};