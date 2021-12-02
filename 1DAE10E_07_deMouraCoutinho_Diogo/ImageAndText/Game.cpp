#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	bool succesfull{ TextureFromFile("Resources/DAE.png", g_DAELogo) };
	if (!succesfull) std::cout << "Loading PNG Failed";

	succesfull = TextureFromString("Hello World!", "Resources/DIN-Light.otf", 48, Color4f{ 0,1,0,1 }, g_SomeText);
	if (!succesfull) std::cout << "Loading Text Failed";


}

void Draw()
{
	ClearBackground();
	// Put your own draw statements here
	Point2f position{ 10, 10 };
	DrawTexture(g_DAELogo, position);

	Point2f positionTwo{ 10, 150 };
	DrawTexture(g_SomeText, positionTwo);


	Rectf destinationRectangle{};
	destinationRectangle.bottom = 250;
	destinationRectangle.left = 10;
	destinationRectangle.width = 150;
	destinationRectangle.height = 15;

	DrawTexture(g_DAELogo, destinationRectangle);


	destinationRectangle.bottom = 250;
	destinationRectangle.left = 210;
	destinationRectangle.width = g_DAELogo.width / 2;
	destinationRectangle.height = g_DAELogo.height / 2;

	DrawTexture(g_DAELogo, destinationRectangle);

	
	Rectf sourceRectangle{};
	sourceRectangle.left = 55;
	sourceRectangle.bottom = 50;
	sourceRectangle.width = 30;
	sourceRectangle.height = 10;
	DrawTexture(g_DAELogo, g_FramePos, sourceRectangle);


}

void Update(float elapsedSec)
{
	//process input, do physics 
	const float speed{ 250.0f };
	// e.g. Check keyboard state
	const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	if ( pStates[SDL_SCANCODE_RIGHT] )
	{
		std::cout << "Right arrow key is down\n";
		g_FramePos.x += speed * elapsedSec;
	}
	if ( pStates[SDL_SCANCODE_LEFT])
	{
		g_FramePos.x += -speed * elapsedSec;
		std::cout << "Left arrow keys are down\n";
	}
	if (pStates[SDL_SCANCODE_UP])
	{
		g_FramePos.y += speed * elapsedSec;
		std::cout << "up arrow keys are down\n";
	}
	if (pStates[SDL_SCANCODE_DOWN])
	{
		g_FramePos.y += -speed * elapsedSec;
		std::cout << "down arrow keys are down\n";
	}
}

void End()
{
	// free game resources here
	DeleteTexture(g_DAELogo);
	DeleteTexture(g_SomeText);
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