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
	ClearBackground(0 / 255.0f, 0 / 255.0f, 0 / 255.0f);
	
	DrawYellow();
	DrawRed();
}

void Update(float elapsedSec)
{
	GetLenght();
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
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	////std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//{
	//	//std::cout << "Left mouse button released\n";
	//	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	//	break;
	//}
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void DrawYellow()
{
	float left = g_borderWidth;
	float bottom = g_borderHeight * 5;


	Point2f yellowXY{ left , bottom };
	SetColor(g_yellow);
	FillRect(yellowXY, g_yellowLenght, g_barHeight);
	SetColor(g_white);
	DrawRect(yellowXY, g_barLenght, g_barHeight);
}

void DrawRed()
{
	float left = g_borderWidth;
	float bottom = g_borderHeight;
	

	Point2f redXY{ left , bottom };
	SetColor(g_red);
	FillRect(redXY, g_redLenght, g_barHeight);
	SetColor(g_white);
	DrawRect(redXY, g_barLenght, g_barHeight);
}
void GetLenght()
{
	g_NrFrames++;

	g_yellowLenght = float(int(g_NrFrames*2) % int(g_barLenght));
	g_redLenght = float(int(g_NrFrames) % int(g_barLenght));

	std::cout << "I have drawn " << g_NrFrames << '\n';
}
#pragma endregion ownDefinitions