#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground();

	float widthRight = float(int(g_NrFrames) % int(g_WindowWidth - sideSize)); // delete the inner sideSize of the range so that the new sqaure reapears when hiden behind the window
	float widthLeft = g_WindowWidth - float(int(g_NrFrames) % int(g_WindowWidth - sideSize)) - sideSize; // delete the inner sideSize of the range so that the new sqaure reapears when hiden behind the window


	float heightUp = float(int(g_NrFrames) % int(g_WindowHeight - sideSize)); // delete the inner sideSize of the range so that the new sqaure reapears when hiden behind the window
	float heightDown = g_WindowHeight - float(int(g_NrFrames) % int(g_WindowHeight - sideSize)) - sideSize; // delete the inner sideSize of the range so that the new sqaure reapears when hiden behind the window

	SetColor(0, 0, 0); //black
	DrawRect(widthRight, heightUp, sideSize, sideSize, 3); // rect left to right, down upwards
	DrawRect(widthRight, heightDown, sideSize, sideSize, 3); // rect left to right, up downwards
	DrawRect(widthLeft, heightUp, sideSize, sideSize, 3); // rect right to left, down upwards
	DrawRect(widthLeft, heightDown, sideSize, sideSize, 3); //rect right to left, up downwards

	SetColor(1, 0, 0, 0.5f); //red
	FillRect(widthRight, heightUp, sideSize, sideSize); // rect left to right, down upwards

	SetColor(0, 1, 0, 0.5f); // green
	FillRect(widthRight, heightDown, sideSize, sideSize); // rect left to right, up downwards
	
	SetColor(0, 0, 1, 0.5f); // blue
	FillRect(widthLeft, heightDown, sideSize, sideSize); //rect right to left, up downwards

	SetColor(1, 1, 0, 0.5f); // yellow
	FillRect(widthLeft, heightUp, sideSize, sideSize); // rect right to left, down upwards
	// Put your own draw statements here

}

void Update(float elapsedSec)
{
	g_NrFrames++;

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