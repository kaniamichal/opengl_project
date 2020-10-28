#include "Game.h"
#include"Texture.h"

using namespace std;

int main()
{
	Game game("Opengl - zaliczenie ;)", 1024, 900, 4, 4, true);

	//main loop
	while (!game.getWindowShouldClose())
	{
		//update input
		game.update();
		game.render();
	}

	return 0;
}