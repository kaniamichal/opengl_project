#pragma once

#include"libs.h"

//enumerators
enum shader_enum { SHADER_CORE_PROGRAM = 0 };
enum texture_enum { TEXTURE0 = 0, TEXTURE1 = 0 };
enum materials_enum {MATERIAL0 = 0};
enum mesh_enum { MESH_TRIANGLES = 0 };

class Game
{
private:
//veriables
	//window
	GLFWwindow* window;
	const int WINDOW_WIDTH;
	const int WINDOW_HEIGHT;
	int framebufferWidth;
	int framebufferHeight;
	//opengl context
	const int GL_VERSION_MAJOR;
	const int GL_VERSION_MINOR;
	//matrices
	glm::mat4 ViewMatrix;
	glm::vec3 cameraPosition;
	glm::vec3 cameraUp;
	glm::vec3 cameraFront;

	glm::mat4 ProjectionMatrix;
	float fov;
	float nearPlane;
	float farPlane;

	//shaders
	std::vector<Shader*> shaders;

	//textures
	std::vector<Texture*> textures;

	//material
	std::vector<Material*> materials;

	//meshes
	std::vector<Mesh*> meshes;

	//lights
	std::vector<glm::vec3*> lights;

//private functions
	void initGLFW();
	void initWindow(const char* title, bool resizable);
	void initGlew();
	void initOpenglOptions();
	void initMatrices();
	void initShaders();
	void initTextures();
	void initMaterials();
	void initMeshes();
	void initLights();
	void initUniforms();

//static variables


public:
	Game(const char* title, const int width, const int height, int GLmajoGL_VERSION_MAJOR, int GL_VERSION_MINOR, bool resizable);
	virtual ~Game();

//accesors
	int getWindowShouldClose();

//modifiers
	void setWindowShouldClose();

//functions
	void update();
	void render();
//static functions
	static void framebuffer_resize_callback(GLFWwindow* window, int fbW, int fbH);

};

