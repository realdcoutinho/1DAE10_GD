#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	GenerateRect();
}

void Draw()
{
	ClearBackground();
	GenerateBorder();
	DrawRect();
	// Put your own draw statements here

}

void Update(float elapsedSec)
{
	Sleep(1);
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
void GenerateBorder() {

	SetColor(g_Black);
	float left			{ g_Border };
	float bottom		{ g_Border };
	float widthLenght	{ g_WindowWidth - g_Border * 2 };
	float heightLenght	{ g_WindowHeight - g_Border * 2 };
	DrawRect(left, bottom, widthLenght, heightLenght, 3);

}

void GenerateColor() {

	float rand_red{ float(1 + rand() % (255 - 1)) / 255 };
	float rand_green{ float(1 + rand() % (255 - 1)) / 255 };
	float rand_blue{ float(1 + rand() % (255 - 1)) / 255 };

	g_RandColor = Color4f{ rand_red , rand_green, rand_blue, 1 };
}

void GenerateRect() {

	float minLeft			{ g_Border };
	float minBottom			{ g_Border };
	float minWidth			{ 10 };
	float minHeight			{ 10 };

	float maxLeft			{ g_WindowWidth - g_Border - minWidth };
	float maxBottom			{ g_WindowHeight - g_Border - minBottom };

	float randomLeft		{ minLeft + rand() % int(maxLeft - minLeft + 1) };
	float randomBottom		{ minBottom + rand() % int(maxBottom - minBottom + 1) };

	float maxWidth			{ g_WindowWidth - g_Border - randomLeft + 1 };
	float maxHeight			{ g_WindowHeight - g_Border - randomBottom + 1 };

	float randomWidth		{ minWidth + rand() % int(maxWidth - minWidth + 1) };
	float randomHeight		{ minHeight + rand() % int(maxHeight - minHeight + 1) };

	g_RandomRect = Rectf(randomLeft, randomBottom, randomWidth, randomHeight);
}

void DrawRect() {

	int i{};
	while (i < 100) {
		i++;
		SetColor(g_Black);
		DrawRect(g_RandomRect, 2);
		SetColor(g_RandColor);
		FillRect(g_RandomRect);
		GenerateRect();
		GenerateColor();
		std::cout << "I have drawn rects " << i << " times" << '\n';
	}
}

#pragma endregion ownDefinitions