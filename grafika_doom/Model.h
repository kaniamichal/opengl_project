#pragma once

#include"Mesh.h"
#include"Texture.h"
#include"shader.h"
#include"Material.h"
#include"OBJLoader.h"

class Model
{
private:
	Material* material;
	Texture* overrideTextureDiffuse;
	Texture* overrideTextureSpecular;
	std::vector<Mesh*> meshes;
	glm::vec3 modelPosition;

	void updateUniforms()
	{

	}

public:

	Model(glm::vec3 modelPosition, Material* material, Texture* overrideTextureDiffuse, Texture* overrideTextureSpecular, std::vector<Mesh*> meshes)
	{
		this->modelPosition = modelPosition;
		this->material = material;
		this->overrideTextureDiffuse = overrideTextureDiffuse;
		this->overrideTextureSpecular = overrideTextureSpecular;
		
		for (auto* i : meshes)
		{
			this->meshes.push_back(new Mesh(*i));
		}

		for (auto& i : this->meshes)
		{
			i->move(this->modelPosition);
			i->setOrigin(this->modelPosition);
		}
	}

	//for obj loader
	Model(glm::vec3 modelPosition, Material* material, Texture* overrideTextureDiffuse, Texture* overrideTextureSpecular, const char* objFile)
	{
		this->modelPosition = modelPosition;
		this->material = material;
		this->overrideTextureDiffuse = overrideTextureDiffuse;
		this->overrideTextureSpecular = overrideTextureSpecular;

		std::vector<Vertex> mesh = OBJLoad(objFile);
		this->meshes.push_back(new Mesh(mesh.data(), mesh.size(), NULL, 0, glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f), glm::vec3(0.0f), glm::vec3(1.0f)));

		for (auto& i : this->meshes)
		{
			i->move(this->modelPosition);
			i->setOrigin(this->modelPosition);
		}
	}

	~Model() 
	{
		for (auto*& i : this->meshes)
		{
			delete i;
		}
	}


	//functions
	void rotate(const glm::vec3 rotation)
	{
		for (auto& i : this->meshes)
			i->rotate(rotation);
	}

	void update()
	{

	}

	void render(Shader* shader)
	{
		this->updateUniforms();

		//update uniforms
		this->material->sendToShader(*shader);

		//use program
		shader->use();


		//draw
		for (auto& i : this->meshes)
		{
			//activate texture
			this->overrideTextureDiffuse->bind(0);
			this->overrideTextureSpecular->bind(1);
			
			i->render(shader);
		}

	}
};
