#include "pch.h"
#include "Game.h"
#include <iostream>
#include <chrono>

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
	DrawCircle();
	DrawRect();


	DrawCircleMouse();
	DrawRectMouse();
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
	Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	
	g_Mouse.x = mousePos.x;
	g_Mouse.y = mousePos.y;

	//std::cout << g_Mouse.x << "         " << g_Mouse.y << '\n';
	g_IsPointInCircle = IsPointInCircle(g_Circle, g_Mouse);
	g_IsOverlaping = IsOverlaping(g_Circle, g_CircleMouse);

	g_IsPointInRect = IsPointInRect(g_Rect, g_Mouse);

	Point2f Pl1{ g_Rect.left, g_Rect.bottom + g_Rect.bottom };
	Point2f Pl2{ g_Rect.left + g_Rect.width, g_Rect.bottom };
	
	
	Point2f Pr1{ mousePos.x - 20, mousePos.y + 10};
	Point2f Pr2{ mousePos.x, mousePos.y };

	g_IsOverlapingRect = IsOverlapingRect(Pl1, Pl2, Pr1, Pr2);



	std::cout << "Result Point: " << g_IsPointInCircle << '\n';
	std::cout << "Result Overlaping: " << g_IsOverlaping << '\n';
	std::cout << "Result Overlaping RECT: " << g_IsOverlapingRect << '\n';
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
void DrawCircle() {

	SetColor(g_White);
	FillEllipse(g_Circle);

	switch (g_IsPointInCircle)
	{
	case 1:
		SetColor(g_Red);
		DrawEllipse(g_Circle, 5);
		break;
	}

}

void DrawRect() {

	SetColor(g_White);
	FillRect(g_Rect);

	switch (g_IsPointInRect)
	{
	case 1:
		SetColor(g_Red);
		DrawRect(g_Rect, 5);
		break;
	}

}

void DrawRectMouse() {

	g_RectMouse.left = g_Mouse.x;
	g_RectMouse.bottom = g_Mouse.y;
	g_RectMouse.width = -20;
	g_RectMouse.height = 10;

	switch (g_IsOverlapingRect)
	{
	case 0: {
		SetColor(g_Green);
		FillRect(g_RectMouse);
		break;
	}
	case 1: {
		SetColor(g_HalfRed);
		FillRect(g_RectMouse);
		break;
	}
	}
}

void DrawCircleMouse() {
	
	g_CircleMouse.center.x = g_Mouse.x + g_RadiusMouse;
	g_CircleMouse.center.y = g_Mouse.y;
	g_CircleMouse.radiusX = g_RadiusMouse;
	g_CircleMouse.radiusY = g_RadiusMouse;

	switch (g_IsOverlaping)
	{
	case 0: {
		SetColor(g_Green);
		FillEllipse(g_CircleMouse);
		break;
	}	
	case 1: {
		SetColor(g_HalfRed);
		FillEllipse(g_CircleMouse);
		break;
		}
	}
}
#pragma endregion ownDefinitions