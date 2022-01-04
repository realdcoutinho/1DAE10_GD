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
	ClearBackground(0, 0, 0);

	// Put your own draw statements here
	DrawLines();
}

void Update(float elapsedSec)
{
	g_NrFrames++;
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
void DrawLines()
{
	float heightUp{ float((g_NrFrames % g_WindowHeightInt)) };
	Point2f leftUP{ 0.0f, heightUp };
	Point2f rightUp{ g_WindowWidth,  heightUp };

	float heightDown{ g_WindowHeight - float((g_NrFrames % g_WindowHeightInt)) };
	Point2f leftDown{ 0.0f, heightDown };
	Point2f rightDown{ g_WindowWidth, heightDown };

	SetColor(1, 1, 1, 1);
	//horizontal line going up
	DrawLine(leftUP, rightUp);
	//horizantal line going down
	DrawLine(leftDown, rightDown);

	float widthRight{ float(int(g_NrFrames) % int(g_WindowWidth)) };
	Point2f upRight{ widthRight, g_WindowHeight };
	Point2f downRight{ widthRight, 0.0f };

	float widthLeft{ g_WindowWidth - float(int(g_NrFrames) % int(g_WindowWidth)) };
	Point2f upLeft{ widthLeft, g_WindowHeight };
	Point2f downLeft{ widthLeft, 0.0f };

	//vertical line going right
	DrawLine(upRight, downRight);// the values go from 0 to 500
	//vertical line going back
	DrawLine(downLeft, upLeft);

	SetColor(1, 1, 0, 0.7f);
	DrawLine(leftUP, downLeft, 3); // left line of the square
	DrawLine(leftUP, upRight, 3); // upward line of the square
	DrawLine(upRight, rightDown, 3);
	DrawLine(rightDown, downLeft, 3);
}
#pragma endregion ownDefinitions