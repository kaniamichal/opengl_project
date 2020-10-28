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

class Triangle : public Primitives
{
public:
	Triangle()
		: Primitives()
	{
		Vertex vertices[] =
		{
			//postion								//color								//texcord							//normal
			glm::vec3(-0.5f, 0.5f, 0.0f),			glm::vec3(1.0f, 0.0f, 0.0f),		glm::vec2(0.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			glm::vec3(-0.5f, -0.5f, 0.0f),			glm::vec3(0.0f, 1.0f, 0.0f),		glm::vec2(0.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			glm::vec3(0.5f, -0.5f, 0.0f),			glm::vec3(0.0f, 0.0f, 1.0f),		glm::vec2(1.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			glm::vec3(0.5f, 0.5f, 0.0f),			glm::vec3(1.0f, 1.0f, 0.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f)
		};

		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] =
		{
			0, 1, 2,
			0, 2, 3
		};

		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};


class Cubus : public Primitives
{
public:
	Cubus()
		: Primitives()
	{
		Vertex vertices[] =
		{
			//postion								//color								//texcord							//normal
		/*0*/	glm::vec3(-1.f, 1.f, 0.0f),			glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
		/*1*/	glm::vec3(-1.f, -1.f, 0.0f),		glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(0.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
		/*2*/	glm::vec3(1.f, -1.f, 0.0f),			glm::vec3(0.0f, 0.0f, 1.0f),		glm::vec2(1.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
		/*3*/	glm::vec3(1.f, 1.f, 0.0f),		    glm::vec3(1.0f, 1.0f, 0.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
		/*4*/	glm::vec3(-1.f, 1.f, -1.0f),		glm::vec3(1.0f, 1.0f, 0.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
		/*5*/	glm::vec3(-1.f, -1.f, -1.0f),		glm::vec3(1.0f, 1.0f, 0.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
		/*6*/	glm::vec3(1.f, -1.f, -1.0f),		glm::vec3(1.0f, 1.0f, 0.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
		/*7*/	glm::vec3(1.f, 1.f, -1.0f),		    glm::vec3(1.0f, 1.0f, 0.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f)
		};

		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] =
		{
			0, 1, 2,//front face
			0, 2, 3,//front face
			4,5,6, //rear
			4,6,7, //rear
			5,2,6, //down
			5, 1,2, //down
			4, 3, 7, //up
			4, 0, 3, //up
			3,2,6,
			3,6,7, 
			0,1,5,
			1,5,4
		};

		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};

class Front : public Primitives
{
public:
	Front()
		: Primitives()
	{
		Vertex vertices[] =
		{
			//postion								//color								//texcord							//normal
			/*0*/	glm::vec3(-1.f, 1.f, 0.0f),			glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(0.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*1*/	glm::vec3(-1.f, -1.f, 0.0f),		glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(0.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*2*/	glm::vec3(1.f, -1.f, 0.0f),			glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(1.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*3*/	glm::vec3(1.f, 1.f, 0.0f),		    glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*4*/	glm::vec3(-1.f, 1.f, -1.0f),		glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*5*/	glm::vec3(-1.f, -1.f, -1.0f),		glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*6*/	glm::vec3(1.f, -1.f, -1.0f),		glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*7*/	glm::vec3(1.f, 1.f, -1.0f),		    glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f)
		};

		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] =
		{
			0, 1, 2,//front face
			0, 2, 3,//front face
			//4,5,6, //rear
			//4,6,7, //rear
			//5,2,6, //down
			//5, 1,2, //down
			//4, 3, 7, //up
			//4, 0, 3 //up

		};

		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
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
			/*0*/	glm::vec3(-1.f, 1.f, 0.0f),			glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(0.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*1*/	glm::vec3(-1.f, -1.f, 0.0f),		glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(0.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*2*/	glm::vec3(1.f, -1.f, 0.0f),			glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(1.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*3*/	glm::vec3(1.f, 1.f, 0.0f),		    glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*4*/	glm::vec3(-1.f, 1.f, -1.0f),		glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*5*/	glm::vec3(-1.f, -1.f, -1.0f),		glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(0.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*6*/	glm::vec3(1.f, -1.f, -1.0f),		glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*7*/	glm::vec3(1.f, 1.f, -1.0f),		    glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f)
		};														

		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] =
		{
			//0, 1, 2,//front face
			//0, 2, 3,//front face
			//4,5,6, //rear
			//4,6,7, //rear
			5,2,6, //down
			5, 1,2, //down
			//4, 3, 7, //up
			//4, 0, 3 //up

		};

		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};

class Left : public Primitives
{
public:
	Left()
		: Primitives()
	{
		Vertex vertices[] =
		{
			//postion								//color								//texcord							//normal
			/*0*/	glm::vec3(-1.f, 1.f, 0.0f),			glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(0.0f, 1.0f),				glm::vec3(-1.0f, 0.0f, 0.0f),
			/*1*/	glm::vec3(-1.f, -1.f, 0.0f),		glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(0.0f, 0.0f),				glm::vec3(-1.0f, 0.0f, 0.0f),
			/*2*/	glm::vec3(1.f, -1.f, 0.0f),			glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(1.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*3*/	glm::vec3(1.f, 1.f, 0.0f),		    glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*4*/	glm::vec3(-1.f, 1.f, -1.0f),		glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(-1.0f, 0.0f, 0.0f),
			/*5*/	glm::vec3(-1.f, -1.f, -1.0f),		glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(1.0f, 0.0f),				glm::vec3(-1.0f, 0.0f, 0.0f),
			/*6*/	glm::vec3(1.f, -1.f, -1.0f),		glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*7*/	glm::vec3(1.f, 1.f, -1.0f),		    glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f)
		};													

		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] =
		{
			0,1,5,
			0,5,4

		};

		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};

class Right : public Primitives
{
public:
	Right()
		: Primitives()
	{
		Vertex vertices[] =
		{
			//postion								//color								//texcord							//normal
			/*0*/	glm::vec3(-1.f, 1.f, 0.0f),			glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(0.0f, 1.0f),				glm::vec3(-1.0f, 0.0f, 0.0f),
			/*1*/	glm::vec3(-1.f, -1.f, 0.0f),		glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(0.0f, 0.0f),				glm::vec3(-1.0f, 0.0f, 0.0f),
			/*2*/	glm::vec3(1.f, -1.f, 0.0f),			glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(0.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*3*/	glm::vec3(1.f, 1.f, 0.0f),		    glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(0.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*4*/	glm::vec3(-1.f, 1.f, -1.0f),		glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(-1.0f, 0.0f, 0.0f),
			/*5*/	glm::vec3(-1.f, -1.f, -1.0f),		glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(1.0f, 0.0f),				glm::vec3(-1.0f, 0.0f, 0.0f),
			/*6*/	glm::vec3(1.f, -1.f, -1.0f),		glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(1.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*7*/	glm::vec3(1.f, 1.f, -1.0f),		    glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f)
		};


		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] =
		{
			3,2,6,
			3,6,7
		
		};

		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};

class Pyramid : public Primitives
{
public:
	Pyramid()
		: Primitives()
	{
		Vertex vertices[] =
		{
			//Position								//Color							//Texcoords					//Normals
			//Triangle front
			glm::vec3(0.f, 0.5f, 0.f),				glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.5f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 1.f, 0.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			//Triangle left
			glm::vec3(0.f, 0.5f, 0.f),				glm::vec3(1.f, 1.f, 0.f),		glm::vec2(0.5f, 1.f),		glm::vec3(-1.f, 0.f, 0.f),
			glm::vec3(-0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(0.f, 0.f),		glm::vec3(-1.f, 0.f, 0.f),
			glm::vec3(-0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(-1.f, 0.f, 0.f),

			//Triangle back
			glm::vec3(0.f, 0.5f, 0.f),				glm::vec3(1.f, 1.f, 0.f),		glm::vec2(0.5f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),

			//Triangles right
			glm::vec3(0.f, 0.5f, 0.f),				glm::vec3(1.f, 1.f, 0.f),		glm::vec2(0.5f, 1.f),		glm::vec3(1.f, 0.f, 0.f),
			glm::vec3(0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(0.f, 0.f),		glm::vec3(1.f, 0.f, 0.f),
			glm::vec3(0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(1.f, 0.f, 0.f),

		};

		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		this->set(vertices, nrOfVertices, nullptr, 0);
	}
};