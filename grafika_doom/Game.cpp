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
		std::cout << "ERROR: Create winodw : GLFW init window failed" << "\n";
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
	glewInit();
	glewExperimental = GL_TRUE;
	

	//error
	if (!glewInit())
	{
		std::cout << "ERROR::GAME.CPP::GLEW INIT FAILED" << "\n";
		glfwTerminate();
	}
	
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
	this->textures.push_back(new Texture("Images/rocks2.png", GL_TEXTURE_2D, 0));
	//texture1
	this->textures.push_back(new Texture("Images/rock.png", GL_TEXTURE_2D, 0));

}

void Game::initMaterials()
{
	this->materials.push_back(new Material(glm::vec3(0.1f), glm::vec3(1.0f), glm::vec3(1.0f), this->textures[TEXTURE0]->getTextureUnit(), this->textures[TEXTURE1]->getTextureUnit()));

}

void Game::initMeshes()
{
	this->meshes.push_back(new Mesh(&Triangle(), glm::vec3(0.0f), glm::vec3(0.0f), glm::vec3(1.0f)));

}

void Game::initLights()
{
	this->lights.push_back(new glm::vec3 (0.0f, 0.0f, 2.0f));

}

void Game::initUniforms()
{
	//init uniform
	this->shaders[SHADER_CORE_PROGRAM]->setMat4fv(ViewMatrix, "ViewMatrix");
	this->shaders[SHADER_CORE_PROGRAM]->setMat4fv(ProjectionMatrix, "ProjectionMatrix");

	this->shaders[SHADER_CORE_PROGRAM]->setVec3fv(*this->lights[0], "lightPos0");
	this->shaders[SHADER_CORE_PROGRAM]->setVec3fv(this->cameraPosition, "cameraPosition");

}

//constuctors
Game::Game(const char* title, const int WINDOW_WIDTH, const int WINDOW_HEIGHT, int GLmajoGL_VERSION_MAJOR, int GL_VERSION_MINOR, bool resizable)
	:WINDOW_WIDTH(WINDOW_WIDTH), WINDOW_HEIGHT(WINDOW_HEIGHT), GL_VERSION_MAJOR(GL_VERSION_MAJOR), GL_VERSION_MINOR(GL_VERSION_MINOR)
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

	this->initGLFW();
	this->initWindow(title, resizable);
	this->initGlew();
	this->initOpenglOptions();

	this->initMatrices();
	this->initShaders();
	this->initTextures();
	this->initMaterials();
	this->initMeshes();
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

	for (size_t i = 0; i < this->meshes.size(); i++)
		delete this->meshes[i];

	for (size_t i = 0; i < this->lights.size(); i++)
		delete this->lights[i];

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
void Game::update()
{
	//update input
	glfwPollEvents();
}

void Game::render()
{
	//update
	
	 //clear
	glClearColor(0.f, 1.0f, 1.0f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	//update uniforms
	this->shaders[SHADER_CORE_PROGRAM]->set1i(this->textures[TEXTURE0]->getTextureUnit(), "texture0");
	this->shaders[SHADER_CORE_PROGRAM]->set1i(this->textures[TEXTURE1]->getTextureUnit(), "texture1");
	this->materials[MATERIAL0]->sendToShader(*this->shaders[SHADER_CORE_PROGRAM]);

	//update framebuffersize and projection matrix
	glfwGetFramebufferSize(this->window, &this->framebufferWidth, &this->framebufferHeight);

	ProjectionMatrix = glm::perspective(glm::radians(fov), static_cast<float>(framebufferWidth) / framebufferHeight, nearPlane, farPlane);

	this->shaders[SHADER_CORE_PROGRAM]->setMat4fv(ProjectionMatrix, "ProjectionMatrix");

	//use program
	this->shaders[SHADER_CORE_PROGRAM]->use();

	//activate texture
	this->textures[TEXTURE0]->bind();
	this->textures[TEXTURE1]->bind();

	//draw
	this->meshes[MESH_TRIANGLES]->render(this->shaders[SHADER_CORE_PROGRAM]);

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

