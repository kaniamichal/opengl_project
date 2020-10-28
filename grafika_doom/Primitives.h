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
			4, 0, 3 //up
			
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
			/*0*/	glm::vec3(-1.f, 1.f, 0.0f),			glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(0.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*1*/	glm::vec3(-1.f, -1.f, 0.0f),		glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(0.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*2*/	glm::vec3(1.f, -1.f, 0.0f),			glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(1.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*3*/	glm::vec3(1.f, 1.f, 0.0f),		    glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*4*/	glm::vec3(-1.f, 1.f, -1.0f),		glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*5*/	glm::vec3(-1.f, -1.f, -1.0f),		glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*6*/	glm::vec3(1.f, -1.f, -1.0f),		glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*7*/	glm::vec3(1.f, 1.f, -1.0f),		    glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f)
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
			/*0*/	glm::vec3(-1.f, 1.f, 0.0f),			glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(0.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*1*/	glm::vec3(-1.f, -1.f, 0.0f),		glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(0.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*2*/	glm::vec3(1.f, -1.f, 0.0f),			glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(1.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*3*/	glm::vec3(1.f, 1.f, 0.0f),		    glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*4*/	glm::vec3(-1.f, 1.f, -1.0f),		glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*5*/	glm::vec3(-1.f, -1.f, -1.0f),		glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*6*/	glm::vec3(1.f, -1.f, -1.0f),		glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*7*/	glm::vec3(1.f, 1.f, -1.0f),		    glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f)
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
			/*0*/	glm::vec3(-1.f, 1.f, 0.0f),			glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(0.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*1*/	glm::vec3(-1.f, -1.f, 0.0f),		glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(0.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*2*/	glm::vec3(1.f, -1.f, 0.0f),			glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(1.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*3*/	glm::vec3(1.f, 1.f, 0.0f),		    glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*4*/	glm::vec3(-1.f, 1.f, -1.0f),		glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*5*/	glm::vec3(-1.f, -1.f, -1.0f),		glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*6*/	glm::vec3(1.f, -1.f, -1.0f),		glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*7*/	glm::vec3(1.f, 1.f, -1.0f),		    glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f)
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
			/*0*/	glm::vec3(-1.f, 1.f, 0.0f),			glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(0.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*1*/	glm::vec3(-1.f, -1.f, 0.0f),		glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(0.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*2*/	glm::vec3(1.f, -1.f, 0.0f),			glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(1.0f, 0.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*3*/	glm::vec3(1.f, 1.f, 0.0f),		    glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*4*/	glm::vec3(-1.f, 1.f, -1.0f),		glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*5*/	glm::vec3(-1.f, -1.f, -1.0f),		glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*6*/	glm::vec3(1.f, -1.f, -1.0f),		glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f),
			/*7*/	glm::vec3(1.f, 1.f, -1.0f),		    glm::vec3(0.0f, 0.0f, 0.0f),		glm::vec2(1.0f, 1.0f),				glm::vec3(0.0f, 0.0f, 1.0f)
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

class Wall : public Primitives
{
public:
	Wall()
		:Primitives()
	{
		Vertex vertices[] =
		{
			//Position								//Color							//Texcoords					//Normals
			//wall 1
			glm::vec3(10.f, 0.0f, -5.0f),			glm::vec3(1.f, 1.f, 1.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(10.f, 50.f, -5.0f),			glm::vec3(1.f, 1.f, 1.f),		glm::vec2(0.f, 2.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(12.f, 50.f, -5.0f),			glm::vec3(1.f, 1.f, 1.f),		glm::vec2(2.f, 2.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(12.f, 0.0f, -5.f),			glm::vec3(1.f, 1.f, 1.f),		glm::vec2(2.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			//wall 2
			glm::vec3(12.f, 0.0f, -5.0f),			glm::vec3(0.6f, 0.6f, 0.6f),	glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(12.f, 50.f, -5.0f),			glm::vec3(0.6f, 0.6f, 0.6f),	glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(12.f, 50.f, -12.0f),			glm::vec3(0.6f, 0.6f, 0.6f),	glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(12.f, 0.0f, -12.f),			glm::vec3(0.6f, 0.6f, 0.6f),	glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			//wall 3
			glm::vec3(12.f, 0.0f, -12.0f),			glm::vec3(1.f, 1.f, 1.f),	glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(30.f, 50.f, -12.0f),			glm::vec3(1.f, 1.f, 1.f),	glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(66.f, 50.f, -12.0f),			glm::vec3(1.f, 1.f, 1.f),	glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(84.f, 0.0f, -12.f),			glm::vec3(1.f, 1.f, 1.f),	glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			
			//wall 4 
			glm::vec3(120.f, 0.0f, -12.0f),			glm::vec3(0.7f, 0.7f, 0.7f),	glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(120.f, 50.f, -12.0f),			glm::vec3(0.7f, 0.7f, 0.7f),	glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(120.f, 50.f, -5.f),			glm::vec3(0.7f, 0.7f, 0.7f),	glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(120.f, 0.0f, -5.f),			glm::vec3(0.7f, 0.7f, 0.7f),	glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			//wall 5
			glm::vec3(120.f, 0.0f, -5.0f),			glm::vec3(1.f, 1.f, 1.f),	glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(120.f, 50.f, -5.0f),			glm::vec3(1.f, 1.f, 1.f),	glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(140.f, 50.f, -5.0f),			glm::vec3(1.f, 1.f, 1.f),	glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(140.f, 0.0f, -5.f),			glm::vec3(1.f, 1.f, 1.f),	glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),


		};

		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		this->set(vertices, nrOfVertices, nullptr, 0);
	}
	

};






class Wall2 : public Primitives
{
public:
	Wall2()
		:Primitives()
	{
		Vertex vertices[] =
		{
			//Position								//Color							//Texcoords					//Normals
			//wall 1
			glm::vec3(-10.f, 0.0f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.f, 0.f, 20.f),			    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(0.f, 0.0f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(10.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(10.f, 0.f, 20.f),			    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(10.f, 0.0f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(10.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(20.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(20.f, 0.f, 20.f),			    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			
			glm::vec3(20.f, 0.0f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(20.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(30.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(30.f, 0.f, 20.f),			    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(30.f, 0.0f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(30.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(40.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(40.f, 0.f, 20.f),			    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(40.f, 0.0f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(40.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(50.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(50.f, 0.f, 20.f),			    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(50.f, 0.0f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(50.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(60.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(60.f, 0.f, 20.f),			    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(60.f, 0.0f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(60.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(70.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(70.f, 0.f, 20.f),			    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(70.f, 0.0f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(70.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(80.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(80.f, 0.f, 20.f),			    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(80.f, 0.0f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(80.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(90.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(90.f, 0.f, 20.f),			    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(90.f, 0.0f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(90.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(100.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(100.f, 0.f, 20.f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(100.f, 0.0f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(100.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(110.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(110.f, 0.f, 20.f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(110.f, 0.0f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(110.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(120.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(120.f, 0.f, 20.f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(120.f, 0.0f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(120.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(130.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(130.f, 0.f, 20.f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(130.f, 0.0f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(130.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(140.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(140.f, 0.f, 20.f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(140.f, 0.0f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(140.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(150.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(150.f, 0.f, 20.f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(150.f, 0.0f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(150.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(160.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(160.f, 0.f, 20.f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(160.f, 0.0f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(160.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(170.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(170.f, 0.f, 20.f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			//wall 2
			glm::vec3(180.f, 0.0f, 0.0f),			glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, 0.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, 20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 0.f, 20.f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(180.f, 0.0f, -20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, 0.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 0.f, 0.f),		    	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(180.f, 0.0f, -40.0f),			glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -40.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -20.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 0.f, -20.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(180.f, 0.0f, -60.0f),			glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -60.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -40.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 0.f, -40.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(180.f, 0.0f, -80.0f),			glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -80.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -60.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 0.f, -60.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(180.f, 0.0f, -100.0f),		glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -100.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -80.0f),			glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 0.f, -80.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(180.f, 0.0f, -120.0f),		glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -120.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -100.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 0.f, -100.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(180.f, 0.0f, -140.0f),		glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -140.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -120.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 0.f, -120.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(180.f, 0.0f, -160.0f),		glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -160.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -140.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 0.f, -140.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(180.f, 0.0f, -180.0f),		glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -180.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -160.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 0.f, -160.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(180.f, 0.0f, -200.0f),		glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -200.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -180.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 0.f, -180.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(180.f, 0.0f, -220.0f),		glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -220.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -200.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 0.f, -200.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(180.f, 0.0f, -240.0f),		glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -240.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -220.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 0.f, -220.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(180.f, 0.0f, -260.0f),		glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -260.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -240.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 0.f, -240.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(180.f, 0.0f, -280.0f),		glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -280.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -260.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 0.f, -260.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(180.f, 0.0f, -300.0f),		glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -300.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -280.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 0.f, -280.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(180.f, 0.0f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -300.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 0.f, -300.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			//wall 3
			glm::vec3(180.f, 0.0f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(180.f, 50.f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(170.f, 50.f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(170.f, 0.f, -320.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(170.f, 0.0f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(170.f, 50.f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(160.f, 50.f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(160.f, 0.f, -320.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(160.f, 0.0f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(160.f, 50.f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(150.f, 50.f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(150.f, 0.f, -320.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(150.f, 0.0f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(150.f, 50.f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(140.f, 50.f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(140.f, 0.f, -320.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(140.f, 0.0f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(140.f, 50.f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(130.f, 50.f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(130.f, 0.f, -320.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(130.f, 0.0f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(130.f, 50.f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(120.f, 50.f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(120.f, 0.f, -320.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			
			glm::vec3(120.f, 0.0f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(120.f, 50.f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(110.f, 50.f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(110.f, 0.f, -320.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(110.f, 0.0f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(110.f, 50.f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(100.f, 50.f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(100.f, 0.f, -320.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
				
			glm::vec3(100.f, 0.0f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(100.f, 50.f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(90.f, 50.f, -320.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(90.f, 0.f, -320.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
				
			glm::vec3(90.f, 0.0f, -320.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(90.f, 50.f, -320.0f),		    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(80.f, 50.f, -320.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(80.f, 0.f, -320.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
				
			glm::vec3(80.f, 0.0f, -320.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(80.f, 50.f, -320.0f),		    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(70.f, 50.f, -320.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(70.f, 0.f, -320.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(70.f, 0.0f, -320.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(70.f, 50.f, -320.0f),		    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(60.f, 50.f, -320.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(60.f, 0.f, -320.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			
			glm::vec3(60.f, 0.0f, -320.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(60.f, 50.f, -320.0f),		    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(50.f, 50.f, -320.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(50.f, 0.f, -320.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			
			glm::vec3(50.f, 0.0f, -320.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(50.f, 50.f, -320.0f),		    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(40.f, 50.f, -320.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(40.f, 0.f, -320.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
				
			glm::vec3(40.f, 0.0f, -320.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(40.f, 50.f, -320.0f),		    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(30.f, 50.f, -320.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(30.f, 0.f, -320.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			
			glm::vec3(30.f, 0.0f, -320.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(30.f, 50.f, -320.0f),		    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(20.f, 50.f, -320.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(20.f, 0.f, -320.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			
			glm::vec3(20.f, 0.0f, -320.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(20.f, 50.f, -320.0f),		    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(10.f, 50.f, -320.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(10.f, 0.f, -320.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			
			glm::vec3(10.f, 0.0f, -320.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(10.f, 50.f, -320.0f),		    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.f, 50.f, -320.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.f, 0.f, -320.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
				
			glm::vec3(0.f, 0.0f, -320.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.f, 50.f, -320.0f),		    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -320.0f),	    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -320.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),


			//wall 4 
			glm::vec3(-10.f, 0.0f, 10.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, 10.0f),		    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, 20.0f),	        glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, 20.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			
			glm::vec3(-10.f, 0.0f, 0.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, 0.0f),		    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, 10.0f),	        glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, 10.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
				
			glm::vec3(-10.f, 0.0f, -30.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -30.0f),		    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -20.0f),	        glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -20.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			
			glm::vec3(-10.f, 0.0f, -40.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -40.0f),		    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -30.0f),	        glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -30.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			
			glm::vec3(-10.f, 0.0f, -50.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -50.0f),		    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -40.0f),	        glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -40.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
				
			glm::vec3(-10.f, 0.0f, -60.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -60.0f),		    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -50.0f),	        glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -50.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
				
			glm::vec3(-10.f, 0.0f, -70.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -70.0f),		    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -60.0f),	        glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -60.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
				
			glm::vec3(-10.f, 0.0f, -80.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -80.0f),		    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -70.0f),	        glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -70.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
				
			glm::vec3(-10.f, 0.0f, -90.0f),	    	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -90.0f),		    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -80.0f),	        glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -80.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			
			glm::vec3(-10.f, 0.0f, -100.0f),	   	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -100.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -90.0f),	        glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -90.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
				
			glm::vec3(-10.f, 0.0f, -110.0f),	   	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -110.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -100.0f),	    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -100.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			
			glm::vec3(-10.f, 0.0f, -120.0f),	   	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -120.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -110.0f),	    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -110.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			
			glm::vec3(-10.f, 0.0f, -130.0f),	   	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -130.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -120.0f),	    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -120.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
				
			glm::vec3(-10.f, 0.0f, -140.0f),	   	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -140.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -130.0f),	    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -130.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
				
			glm::vec3(-10.f, 0.0f, -150.0f),	   	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -150.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -140.0f),	    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -140.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			
			glm::vec3(-10.f, 0.0f, -160.0f),	   	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -160.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -150.0f),	    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -150.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			
			glm::vec3(-10.f, 0.0f, -170.0f),	   	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -170.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -160.0f),	    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -160.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			
			glm::vec3(-10.f, 0.0f, -180.0f),	   	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -180.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -170.0f),	    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -170.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			
			glm::vec3(-10.f, 0.0f, -190.0f),	   	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -190.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -180.0f),	    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -180.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			
			glm::vec3(-10.f, 0.0f, -200.0f),	   	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -200.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -190.0f),	    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -190.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			
			glm::vec3(-10.f, 0.0f, -210.0f),	   	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -210.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -200.0f),	    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -200.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
				
			glm::vec3(-10.f, 0.0f, -220.0f),	   	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -220.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -210.0f),	    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -210.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			
			glm::vec3(-10.f, 0.0f, -230.0f),	   	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -230.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -220.0f),	    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -220.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
				
			glm::vec3(-10.f, 0.0f, -240.0f),	   	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -240.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -230.0f),	    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -230.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			
			glm::vec3(-10.f, 0.0f, -250.0f),	   	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -250.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -240.0f),	    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -240.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
				
			glm::vec3(-10.f, 0.0f, -260.0f),	   	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -260.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -250.0f),	    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -250.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
				
			glm::vec3(-10.f, 0.0f, -270.0f),	   	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -270.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -260.0f),	    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -260.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			
			glm::vec3(-10.f, 0.0f, -280.0f),	   	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -280.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -270.0f),	    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -270.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			
			glm::vec3(-10.f, 0.0f, -290.0f),	   	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -290.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -280.0f),	    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -280.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
				
			glm::vec3(-10.f, 0.0f, -300.0f),	   	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -300.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -290.0f),	    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -290.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			
			glm::vec3(-10.f, 0.0f, -310.0f),	   	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -310.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -300.0f),	    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -300.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
				
			glm::vec3(-10.f, 0.0f, -320.0f),	   	glm::vec3(0.7f, 0.7f, 0.5f),	    glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -320.0f),		glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 50.f, -310.0f),	    glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-10.f, 0.f, -310.f),		   	glm::vec3(0.7f, 0.7f, 0.5f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

		};

		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		this->set(vertices, nrOfVertices, nullptr, 0);
	}


};
