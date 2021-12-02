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

	// Put your own draw statements here
	
	SetColor(1, 1, 1, 1);
	//horizontal line going up
	DrawLine(0, float(int(g_NrFrames) % int(g_WindowHeight)), g_WindowWidth, float(int(g_NrFrames) % int(g_WindowHeight))); // the values go from 0 to 500
	//horizantal line going down
	DrawLine(0, g_WindowHeight - float(int(g_NrFrames) % int(g_WindowHeight)), g_WindowWidth, g_WindowHeight - float(int(g_NrFrames) % int(g_WindowHeight))); // vales from 500 to 0

	//vertical line going right
	DrawLine(float(int(g_NrFrames) % int(g_WindowWidth)), 0, float(int(g_NrFrames) % int(g_WindowWidth)), g_WindowHeight);// the values go from 0 to 500
	//vertical line going back
	DrawLine(g_WindowWidth - float(int(g_NrFrames) % int(g_WindowWidth)), 0, g_WindowWidth - float(int(g_NrFrames) % int(g_WindowWidth)), g_WindowHeight);
	

	SetColor(1, 1, 0, 0.7f);
	DrawLine(g_WindowWidth - float(int(g_NrFrames) % int(g_WindowWidth)), 0, 0, float(int(g_NrFrames) % int(g_WindowHeight)), 3); // left line of the square
	DrawLine(0, float(int(g_NrFrames) % int(g_WindowHeight)), float(int(g_NrFrames) % int(g_WindowWidth)), g_WindowHeight, 3); // upward line of the square
	DrawLine(float(int(g_NrFrames) % int(g_WindowWidth)), g_WindowHeight, g_WindowWidth, g_WindowHeight - float(int(g_NrFrames) % int(g_WindowHeight)), 3);
	DrawLine(g_WindowWidth, g_WindowHeight - float(int(g_NrFrames) % int(g_WindowHeight)), g_WindowWidth - float(int(g_NrFrames) % int(g_WindowWidth)), 0, 3);
	

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