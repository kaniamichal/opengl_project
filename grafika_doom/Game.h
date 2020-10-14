#pragma once

#include"libs.h"
#include"Camera.h"


//enumerators
enum shader_enum { SHADER_CORE_PROGRAM = 0 };
enum texture_enum { TEXTURE0, TEXTURE0_SPECULAR, TEXTURE1, TEXTURE1_SPECULAR};
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
	//delta time
	float deltaTime;
	float currentTime;
	float lastTime;
	//mouse
	double lastMouseX;
	double lastMouseY;
	double mouseX;
	double mouseY;
	double mouseOffsetX;
	double mouseOffsetY;
	bool firstMouse;
	//camera
	Camera camera;
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

	//model	
	std::vector<Model*> models;

	//lights
	std::vector<PointLight*> pointLights;

//private functions
	
	void initGLFW();
	void initWindow(const char* title, bool resizable);
	void initGlew();
	void initOpenglOptions();
	void initMatrices();
	void initShaders();
	void initTextures();
	void initMaterials();
	void initObjModels();
	void initModels();
	void initPointLights();
	void initLights();
	void initUniforms();

	void updateUniforms();

//static variables


public:
	Game(const char* title, const int width, const int height, int GL_VERSION_MAJOR, int GL_VERSION_MINOR, bool resizable);
	
	virtual ~Game();

//accesors
	int getWindowShouldClose();

//modifiers
	void setWindowShouldClose();

//functions
	void updateDeltaTime();
	void mouseInput();
	void keyboard();
	void updateInput();
	void update();
	void render();

//static functions
	static void framebuffer_resize_callback(GLFWwindow* window, int fbW, int fbH);
	static void ErrorCallback(GLint error, const char* err_str);
};

