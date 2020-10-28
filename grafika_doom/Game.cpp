#include "Game.h"



using namespace std;

//private functions

void Game::initGLFW()
{
	glfwInit();

	// init GLFW
	if (!glfwInit()) 
	{
		std::cout << "ERROR! game.cpp - GLFW init failed" << "\n";
		glfwTerminate();
	}
	
}

void Game::initWindow(const char* title, bool resizable)
{

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, this->GL_VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, this->GL_VERSION_MINOR);
	glfwWindowHint(GLFW_RESIZABLE, resizable);

	this->window = glfwCreateWindow(this->WINDOW_WIDTH, this->WINDOW_HEIGHT, title, NULL, NULL);

	if (this->window == nullptr)
	{
		std::cout << "ERROR: game.cpp: Create winodw function : GLFW initWindow failed" << "\n";
		glfwTerminate();
	}

	
	glfwGetFramebufferSize(this->window, &this->framebufferWidth, &this->framebufferHeight);
	glfwSetFramebufferSizeCallback(this->window, Game::framebuffer_resize_callback);
	//glViewport(0, 0, framebufferWIdth, framebufferHeight);

	glfwMakeContextCurrent(this->window);
}

void Game::initGlew()
{
	//init GLEW (need window and opengl context)
	glewExperimental = GL_TRUE;
    glewInit();

	//error
	if (glewInit() != GLEW_OK)
	{
		std::cout << "ERROR::GAME.CPP::GLEW INIT FAILED" << "\n";
		glfwTerminate();
	}
	
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	
	}
	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
}

void Game::initOpenglOptions()
{
	//opengl options
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //only lines of tgriangles

	glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Game::initMatrices()
{
	this->ViewMatrix = glm::mat4(1.0f);
	this->ViewMatrix = glm::lookAt(this->cameraPosition, this->cameraPosition + this->cameraFront, this->cameraUp);

	this->ProjectionMatrix = glm::mat4(1.0f);
	this->ProjectionMatrix = glm::perspective(glm::radians(this->fov), static_cast<float>(this->framebufferWidth) / this->framebufferHeight, this->nearPlane, this->farPlane);

}

void Game::initShaders()
{
	this->shaders.push_back(new Shader(this->GL_VERSION_MAJOR, this->GL_VERSION_MINOR, "vertex_core.glsl", "fragment_core.glsl"));

}

void Game::initTextures()
{
	//texture0
	this->textures.push_back(new Texture("Images/rocks2.png", GL_TEXTURE_2D));
	this->textures.push_back(new Texture("Images/rocks2_specular.png", GL_TEXTURE_2D));
	//texture1
	this->textures.push_back(new Texture("Images/rock.png", GL_TEXTURE_2D));
	this->textures.push_back(new Texture("Images/rock_specular.png", GL_TEXTURE_2D));

}

void Game::initMaterials()
{
	this->materials.push_back(new Material(glm::vec3(0.1f), glm::vec3(1.0f), glm::vec3(1.0f), 0, 1));

}

void Game::initObjModels()
{
	/*std::vector<Vertex> temp;
	temp = OBJLoad("obj / people / FinalBaseMesh.obj");*/
}

void Game::initModels()
{
	std::vector<Mesh*>meshes;
	std::vector<Mesh*>meshes2;

	
	meshes.push_back(new Mesh(&Pyramid(), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f), glm::vec3(0.0f), glm::vec3(1.0f)));
	meshes.push_back(new Mesh(&Triangle(), glm::vec3(2.0f, 0.0f, 0.0f), glm::vec3(0.0f), glm::vec3(0.0f), glm::vec3(1.0f)));
	meshes2.push_back(new Mesh(&Triangle(), glm::vec3(2.0f, 0.0f, 0.0f), glm::vec3(0.0f), glm::vec3(-90.0f, 0.0f, 0.0f), glm::vec3(100.0f)));

	this->models.push_back(new Model(glm::vec3(0.0f), this->materials[0], this->textures[TEXTURE1], this->textures[TEXTURE1_SPECULAR], meshes));
	
	this->models.push_back(new Model(glm::vec3(0.0f, 1.f, 0.0f), this->materials[0], this->textures[TEXTURE0], this->textures[TEXTURE0_SPECULAR], meshes));
	
	this->models.push_back(new Model(glm::vec3(1.0f, 1.0f, 0.0f), this->materials[0], this->textures[TEXTURE1], this->textures[TEXTURE1_SPECULAR], meshes));
	
	this->models.push_back(new Model(glm::vec3(1.0f, -3.0f, 0.0f), this->materials[0], this->textures[TEXTURE1], this->textures[TEXTURE1_SPECULAR], meshes2));
	
	this->models.push_back(new Model(glm::vec3(14.0f, 0.0f, 4.0f), this->materials[0], this->textures[TEXTURE1], this->textures[TEXTURE1_SPECULAR], "obj/mac10.obj"));

	for (auto*& i : meshes)
		delete i; 
	
	for (auto*& i : meshes2)
		delete i;
}

void Game::initPointLights()
{
	this->pointLights.push_back(new PointLight(glm::vec3(0.0f, 0.0f, 0.0f)));

}

void Game::initLights()
{
	this->initPointLights();
}

void Game::initUniforms()
{
	//init uniform
	this->shaders[SHADER_CORE_PROGRAM]->setMat4fv(this->ViewMatrix, "ViewMatrix");
	this->shaders[SHADER_CORE_PROGRAM]->setMat4fv(this->ProjectionMatrix, "ProjectionMatrix");

	for (PointLight * pl : this->pointLights)
	{
		pl->sendToShader(*this->shaders[SHADER_CORE_PROGRAM]);
	}
	
}

void Game::updateUniforms()
{
	//update viewMatrix
	this->ViewMatrix = this->camera.grtViewMatrx();
	this->shaders[SHADER_CORE_PROGRAM]->setMat4fv(this->ViewMatrix, "ViewMatrix");
	this->shaders[SHADER_CORE_PROGRAM]->setVec3fv(this->camera.getPosition(), "cameraPosition");

	for (PointLight* pl : this->pointLights)
	{
		pl->sendToShader(*this->shaders[SHADER_CORE_PROGRAM]);
	}

	//update framebuffersize and projection matrix
	glfwGetFramebufferSize(this->window, &this->framebufferWidth, &this->framebufferHeight);

	this->ProjectionMatrix = glm::perspective(glm::radians(this->fov), static_cast<float>(this->framebufferWidth) / this->framebufferHeight, this->nearPlane, this->farPlane);
	this->shaders[SHADER_CORE_PROGRAM]->setMat4fv(this->ProjectionMatrix, "ProjectionMatrix");

}

//constuctors
Game::Game(const char* title, const int WINDOW_WIDTH, const int WINDOW_HEIGHT, int GL_VERSION_MAJOR, int GL_VERSION_MINOR, bool resizable)
	:WINDOW_WIDTH(WINDOW_WIDTH), WINDOW_HEIGHT(WINDOW_HEIGHT), GL_VERSION_MAJOR(GL_VERSION_MAJOR), GL_VERSION_MINOR(GL_VERSION_MINOR),
	camera(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f))
{
	//init variables
	this->window = nullptr;
	this->framebufferWidth = this->WINDOW_WIDTH;
	this->framebufferHeight = this->WINDOW_HEIGHT;

	this->cameraPosition = glm::vec3(0.0f, 0.0f, 1.0f);
	this->cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	this->cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);

	this->fov = 90.0f;
	this->nearPlane = 0.1f;
	this->farPlane = 1000.0f;

	this->deltaTime = 0.0f;
	this->currentTime = 0.0f;
	this->lastTime = 0.0f;

	this->lastMouseX = 0.0;
	this->lastMouseY = 0.0;
	this->mouseX = 0.0;
	this->mouseY = 0.0;
	this->mouseOffsetX = 0.0;
	this->mouseOffsetY = 0.0;
	this->firstMouse = true;

	//glfwSetErrorCallback(ErrorCallback);

	this->initGLFW();
	this->initWindow(title, resizable);
	this->initGlew();
	this->initOpenglOptions();
	
	this->initMatrices();
	this->initShaders();
	this->initTextures();
	this->initMaterials();
	this->initObjModels();
	this->initModels();
	this->initLights();
	this->initUniforms();

}

Game::~Game()
{
	glfwDestroyWindow(this->window);
	glfwTerminate();

	for (size_t i = 0; i < this->shaders.size(); i++)
		delete this->shaders[i];

	for (size_t i = 0; i < this->textures.size(); i++)
		delete this->textures[i];

	for (size_t i = 0; i < this->materials.size(); i++)
		delete this->materials[i];

	for (auto*& i : this->models)
		delete i;

	for (size_t i = 0; i < this->pointLights.size(); i++)
		delete this->pointLights[i];

}


//accesors
int Game::getWindowShouldClose()
{
	return glfwWindowShouldClose(this->window);
}

//modifier
void Game::setWindowShouldClose()
{
	glfwSetWindowShouldClose(this->window, GLFW_TRUE);
}






//functions

void Game::updateDeltaTime()
{
	this->currentTime = static_cast<float>(glfwGetTime());
	this->deltaTime = this->currentTime - this->lastTime;
	this->lastTime = this->currentTime;

}
void Game::mouseInput()
{
	glfwGetCursorPos(this->window, &this->mouseX, &this->mouseY);

	if (this->firstMouse)
	{
		this->lastMouseX = this->mouseX;
		this->lastMouseY = this->mouseY;
		this->firstMouse = false;
	}

	this->mouseOffsetX = this->mouseX - this->lastMouseX;
	this->mouseOffsetY = this->lastMouseY - this->mouseY;

	this->lastMouseX = this->mouseX;
	this->lastMouseY = this->mouseY;

	if (glfwGetMouseButton(this->window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS)
	{
		this->pointLights[0]->setPosition(this->camera.getPosition());
	}
}

void Game::keyboard()
{
	if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(this->window, GLFW_TRUE);
	}

	if (glfwGetKey(this->window, GLFW_KEY_W) == GLFW_PRESS)
	{
		this->camera.move(deltaTime, FORWARD);
	}
	if (glfwGetKey(this->window, GLFW_KEY_S) == GLFW_PRESS)
	{
		this->camera.move(deltaTime, BACKWARD);
	}
	if (glfwGetKey(this->window, GLFW_KEY_A) == GLFW_PRESS)
	{
		this->camera.move(deltaTime, LEFT);
	}
	if (glfwGetKey(this->window, GLFW_KEY_D) == GLFW_PRESS)
	{
		this->camera.move(deltaTime, RIGHT);
	}
/*	if (glfwGetKey(this->window, GLFW_KEY_C) == GLFW_PRESS)
	{
		this->cameraPosition.y -= 0.05f;
	}
	if (glfwGetKey(this->window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		this->cameraPosition.y += 0.05f;
	}*/
}

void Game::updateInput()
{
	glfwPollEvents();
	this->keyboard();
	this->mouseInput();
	this->camera.updateInput(deltaTime, -1, this->mouseOffsetX, this->mouseOffsetY);
}

void Game::update()
{
	this->updateDeltaTime();
	this->updateInput();
}

void Game::render()
{
	//clear
	glClearColor(0.f, 1.0f, 1.0f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	this->updateUniforms();

	//render models
	for(auto& i: this->models)
		i->render(this->shaders[SHADER_CORE_PROGRAM]);

	//end draw
	glfwSwapBuffers(window);

	glBindVertexArray(0);
	glUseProgram(0);
	glActiveTexture(0);
	glBindTexture(GL_TEXTURE_2D, 0);

}

//static function
void Game::framebuffer_resize_callback(GLFWwindow* window, int fbW, int fbH)
{
	glViewport(0, 0, fbW, fbH);
}

void Game::ErrorCallback(GLint error, const char* err_str)
{
	fputs(err_str, stderr); "\n"; "\n";
	std::cout << "ERROR:: ErrorCallback:: GLFW Error: " << err_str << std::endl;
	
}