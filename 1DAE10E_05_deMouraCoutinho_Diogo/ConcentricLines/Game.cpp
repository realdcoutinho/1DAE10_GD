#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground();
	Lines();

}

void Update(float elapsedSec)
{
	// process input, do physics 

	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
}

void End()
{
	// free game resources here
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{
	switch (key) {
	case SDLK_RIGHT:
	std::cout << "Right arrow key Pressed\n";

	}
}

void OnKeyUpEvent(SDL_Keycode key)
{
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	std::cout << "  [" << e.x << ", " << e.y << "]\n";
	Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };

	g_X = int(e.x);
	g_Y = int(g_WindowHeight - e.y);
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	std::cout << "  [" << e.x << ", " << e.y << "]\n";
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		std::cout << "Left mouse button released\n";
		Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
		g_ColorVariable++;
		SwitchColor();
		break;
	}
	case SDL_BUTTON_RIGHT:
		std::cout << "Right mouse button released\n";
		break;
	case SDL_BUTTON_MIDDLE:
		std::cout << "Middle mouse button released\n";
		break;
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here




void SwitchColor() {

	if (g_ColorVariable >= 3) {
		g_color = Color4f(1,0,0,1);
		
		
		g_ColorVariable = Red;
		std::cout << "RED" << '\n';
	}
	else if (g_ColorVariable == 0) {
		g_color = Color4f(1, 0, 0, 1);


		std::cout << "RED" << '\n';
	}
	else if (g_ColorVariable == 1) {
		g_color = Color4f(0, 1, 0, 1);


		std::cout << " GREEN" << '\n';
	}
	else if (g_ColorVariable == float(ColorLines::Blue)) {
		g_color = g_Blue1;


		std::cout << "BLUE" << '\n';
	}
}


void Lines() {
	

	SetColor(g_color);
	//Lines Left
	float yLeft{};

	for (yLeft ; yLeft <= g_WindowHeight; yLeft += 9) {
		DrawLine(0, yLeft, float(g_X), float(g_Y));
	}

	//Lines Top
	float xTop{};

	for (xTop; xTop <= g_WindowWidth; xTop += 9) {
		DrawLine(xTop, g_WindowHeight, float(g_X), float(g_Y));
	}

	//Lines Right
	float yRight{};

	for (yRight; yRight <= g_WindowHeight; yRight += 9) {
		DrawLine(g_WindowWidth, yRight, float(g_X), float(g_Y));
	}

	float xBottom{};

	for (xBottom; xBottom <= g_WindowWidth; xBottom += 9) {
		DrawLine(xBottom, 0, float(g_X), float(g_Y));
	}
}


#pragma endregion ownDefinitions