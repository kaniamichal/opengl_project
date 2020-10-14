#pragma once

#pragma once
#include<iostream>

#include<glew.h>
#include<wglew.h>
#include<glfw3.h>

#include<glm.hpp>
#include<vec3.hpp>
#include<mat4x4.hpp>
#include<gtc\matrix_transform.hpp>

enum direction {FORWARD = 0, BACKWARD, LEFT, RIGHT};

class Camera
{
private:
	glm::mat4 ViewMatrix;
	
	GLfloat movementSpeed;
	GLfloat sensitivity;

	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 right;
	glm::vec3 up;
	
	glm::vec3 worldUp;

	GLfloat pitch; 
	GLfloat yaw;
	GLfloat roll;	

	void updateCameraVector() 
	{
		this->front.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
		this->front.y = sin(glm::radians(this->yaw));
		this->front.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));

		this->front = glm::normalize(this->front);
		this->right = glm::normalize(glm::cross(this->front, this->worldUp));
		this->up = glm::normalize(glm::cross(this->right, this->front));

	}
public:

	Camera(glm::vec3 position, glm::vec3 direction, glm::vec3 worldUp)
	{
		this->ViewMatrix = glm::mat4(1.0f);
		this->movementSpeed = 3.0f;
		this->sensitivity = 5.0f;

		this->worldUp = worldUp;
		this->position = position;
		this->right = glm::vec3(0.0f);
		this->up = worldUp;

		this->pitch = 0.0f;
		this->yaw = -90.0f;
		this->roll = 0.0f;

		this->updateCameraVector();

	}
	~Camera() 	{}

	//accessors
	const glm::mat4 grtViewMatrx()
	{
		this->updateCameraVector();

		this->ViewMatrix = glm::lookAt(this->position, this->position + this->front, this->up);

		return this->ViewMatrix;
	}

	const glm::vec3 getPosition()
	{
		return this->position;
	}


	//functions

	void move(const float& deltaTime, const int direction)
	{
		//update position vector
		switch (direction)
		{
		case FORWARD:
			this->position += this->front * this->movementSpeed * deltaTime;
			break;

		case BACKWARD:
			this->position -= this->front * this->movementSpeed * deltaTime;
			break;
		
		case LEFT:
			this->position -= this->right * this->movementSpeed * deltaTime;
			break;
		
		case RIGHT:
			this->position += this->right * this->movementSpeed * deltaTime;
			break;
		
		default:
			break;
		}
	}

	void updateMouse(const float& deltaTime, const double& mouseOffsetX, const double& mouseOffsetY)
	{
		//update pitch, yaw, roll
		this->pitch += static_cast<GLfloat>(mouseOffsetY) * this->sensitivity * deltaTime;
		this->yaw += static_cast<GLfloat>(mouseOffsetX) * this->sensitivity * deltaTime;
		
		if (this->pitch > 80.0f)
			this->pitch = 80.0f;
		else if (this->pitch < -80.0f)
			this->pitch = -80.0f;
		
		if (this->yaw > 360.0f || this->yaw < -360.0f)
			this->yaw = 0.0f;

		this->roll += static_cast<GLfloat>(mouseOffsetX) * this->sensitivity * deltaTime;
	}

	void updateInput(const float& deltaTime, const int direction, const double& mouseOffsetX, const double& mouseOffsetY)
	{
		this->updateMouse(deltaTime, mouseOffsetX, mouseOffsetY);
	}
};