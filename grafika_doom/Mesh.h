#pragma once

#include<iostream>
#include<vector>

#include"Vertex.h"
#include"Primitives.h"
#include"shader.h"
#include"Texture.h"
#include"Material.h" 

class Mesh
{
private:
	Vertex* vertexArray;
	unsigned nrOfVertices;
	GLuint* indexArray;
	unsigned nrOfIndices;

	GLuint VAO;
	GLuint VBO;
	GLuint EBO;

	glm::vec3 position;
	glm::vec3 origin;
	glm::vec3 rotation;
	glm::vec3 scale;

	glm::mat4 ModelMatrix;


	//from primitive
	void initVAO()
	{
		//VAO, VBO, EBO
		glCreateVertexArrays(1, &this->VAO);
		glBindVertexArray(this->VAO);

		//generate VBO and bind and send data
		glGenBuffers(1, &this->VBO);
		glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
		glBufferData(GL_ARRAY_BUFFER, this->nrOfVertices * sizeof(Vertex), this->vertexArray, GL_STATIC_DRAW);

		//generate EBO and bind and send data
		if (this->nrOfIndices > 0)
		{
			glGenBuffers(1, &this->EBO);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->nrOfIndices * sizeof(GLuint), this->indexArray, GL_STATIC_DRAW);
		}

		//set vertex atribpointer and enable
		//position
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));
		glEnableVertexAttribArray(0);
		//color
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color));
		glEnableVertexAttribArray(1);
		//texcord
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texcord));
		glEnableVertexAttribArray(2);
		//normal
		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
		glEnableVertexAttribArray(3);

		//bind VAO 0
		glBindVertexArray(0);
	}

	void updateUniforms(Shader* shader)
	{
		shader->setMat4fv(this->ModelMatrix, "ModelMatrix");

	}

	void updateModelMatrix()
	{
		this->ModelMatrix = glm::mat4(1.0f);
		this->ModelMatrix = glm::translate(this->ModelMatrix, this->origin);
		this->ModelMatrix = glm::rotate(this->ModelMatrix, glm::radians(this->rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		this->ModelMatrix = glm::rotate(this->ModelMatrix, glm::radians(this->rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		this->ModelMatrix = glm::rotate(this->ModelMatrix, glm::radians(this->rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
		this->ModelMatrix = glm::translate(this->ModelMatrix, this->position - this->origin);
		this->ModelMatrix = glm::scale(this->ModelMatrix, this->scale);

	}

public:
	// from primitive
	Mesh(Primitives* primitive,
		glm::vec3 position = glm::vec3(0.0f),
		glm::vec3 origin = glm::vec3(0.0f),  
		glm::vec3 rotation = glm::vec3(0.0f),
		glm::vec3 scale = glm::vec3(1.0f))
	{
		this->position = position;
		this->origin = origin; 
		this->rotation = rotation;
		this->scale = scale;
		this->nrOfVertices = primitive->getNrOfVertices();
		this->nrOfIndices = primitive->getNrOfIndecies();

		this->vertexArray = new Vertex[this->nrOfVertices];
		for (size_t i = 0; i < this->nrOfVertices; i++)
		{
			this->vertexArray[i] = primitive->getVertices()[i];

		}

		this->indexArray = new GLuint[this->nrOfIndices];
		for (size_t i = 0; i < this->nrOfIndices; i++)
		{
			this->indexArray[i] = primitive->getIndecies()[i];

		}

		this->initVAO();
		this->updateModelMatrix();

	}
	//oryginal
	Mesh(Vertex* vertexArray, const unsigned& nrOfVertices, GLuint* indexArray, const unsigned& nrOfIndices,
		glm::vec3 position = glm::vec3(0.0f),
		glm::vec3 origin = glm::vec3(0.0f),
		glm::vec3 rotation = glm::vec3(0.0f),
		glm::vec3 scale = glm::vec3(1.0f))
	{
		this->position = position;
		this->origin = origin;
		this->rotation = rotation;
		this->scale = scale;

		this->nrOfVertices = nrOfVertices;
		this->nrOfIndices = nrOfIndices;
		
		this->vertexArray = new Vertex[this->nrOfVertices];
		for (size_t i = 0; i < this->nrOfVertices; i++)
		{
			this->vertexArray[i] = vertexArray[i];

		}

		this->indexArray = new GLuint[this->nrOfIndices];
		for (size_t i = 0; i < this->nrOfIndices; i++)
		{
			this->indexArray[i] = indexArray[i];

		}

		this->initVAO();
		this->updateModelMatrix();

	}

	Mesh(const Mesh& obj)
	{
		this->position = obj.position;
		this->origin = obj.origin;
		this->rotation = obj.rotation;
		this->scale = obj.scale;

		this->nrOfVertices = obj.nrOfVertices;
		this->nrOfIndices = obj.nrOfIndices;

		this->vertexArray = new Vertex[this->nrOfVertices];
		for (size_t i = 0; i < this->nrOfVertices; i++)
		{
			this->vertexArray[i] = obj.vertexArray[i];

		}

		this->indexArray = new GLuint[this->nrOfIndices];
		for (size_t i = 0; i < this->nrOfIndices; i++)
		{
			this->indexArray[i] = obj.indexArray[i];

		}

		this->initVAO();
		this->updateModelMatrix();

	}

	~Mesh()
	{
		glDeleteVertexArrays(1, &this->VAO);
		glDeleteBuffers(1, &this->VBO);
		if (nrOfIndices > 0)
		{
			glDeleteBuffers(1, &this->EBO);
		}

		delete[] this->vertexArray;
		delete[] this->indexArray;
	}

	//accesors


	//modifiers
	void setPosition(const glm::vec3& position)
	{
		this->position = position;
	}

	void setOrigin(const glm::vec3& origin)
	{
		this->origin = origin;
	}

	void setRotation(const glm::vec3& rotation)
	{
		this->rotation = rotation;
	}

	void setScale(const glm::vec3& scale)
	{
		this->scale = scale;
	}

	//functions
	void move(const glm::vec3& position)
	{
		this->position += position;
	}
	void rotate(const glm::vec3& rotation)
	{
		this->rotation += rotation;
	}

	void scaleUp(const glm::vec3& scale)
	{
		this->scale += scale;
	}

	void update()
	{


	}

	void render(Shader* shader)
	{
		//update uniforms
		this->updateModelMatrix();
		this->updateUniforms(shader);

		shader->use();

		//bind vertex array object
		glBindVertexArray(this->VAO);

		//render
		if (nrOfIndices ==0)
		{
			glDrawArrays(GL_TRIANGLES, 0, nrOfVertices);
		}
		else
			glDrawElements(GL_TRIANGLES, this->nrOfIndices, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);
		glUseProgram(0);
		glActiveTexture(0);
		glBindTexture(GL_TEXTURE_2D, 0);
	}


};