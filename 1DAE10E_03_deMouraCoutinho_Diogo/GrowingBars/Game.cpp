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

	//common variables
	float border_left = g_oneUnit_Width;
	float border_width = g_oneUnit_Width * 18;
	float border_height = g_oneUnit_Height * 4;
	
	//YELLOW bar border
	float yellow_bottom = g_oneUnit_Height * 5.5f;
	float yellow_limit = g_oneUnit_Width * 19;

	//Yellow bar
	

	//RED bar border
	float red_bottom = g_oneUnit_Height;



	SetColor(255 / 255.0f, 255 / 255.0f, 255 / 255.0f, 255 / 255.0f); // white
	DrawRect(border_left, yellow_bottom, g_borderWidth, border_height, 3.0f); //border for yellow
	DrawRect(border_left, red_bottom, g_borderWidth, border_height, 3.0f); // border for red
	


	SetColor(255 / 255.0f, 255 / 255.0f, 0 / 255.0f, 255 / 255.0f);// yellow
	FillRect(border_left, yellow_bottom, g_yellow_Growing, border_height);


	SetColor(255 / 255.0f, 0 / 255.0f, 0 / 255.0f, 255 / 255.0f); // red
	FillRect(border_left, red_bottom, g_red_Growing, border_height);

	// Put your own draw statements here

	std::cout << "I have drawn " << g_NrFrames << '\n';

}

void Update(float elapsedSec)
{
	g_NrFrames++;

	g_yellow_Growing += 2;
	g_red_Growing++;

	g_yellow_Growing = float(int(g_yellow_Growing) % int(g_WindowWidth - (g_oneUnit_Width * 2)));
	g_red_Growing = float(int(g_red_Growing) % int(g_WindowWidth - (g_oneUnit_Width * 2)));


	/*
	while (g_yellow_Growing != g_borderWidth);
		g_yellow_Growing += 2;
	if (g_yellow_Growing == g_borderWidth);
		g_yellow_Growing = g_borderWidth;;
	*/




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

#pragma endregion ownDefinitions