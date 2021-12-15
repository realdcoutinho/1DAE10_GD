#include "pch.h"
#include "Game.h"
#include <iostream>
#include <chrono>



//Basic game functions
#pragma region gameFunctions											
void Start()
{
	/*
		auto startTime{ steady_clock::now() };

	for(int count{}; count < 1'000'000; ++count)
	{}

	auto endTime{ steady_clock::now() };

	std::cout << duration<float, std::milli>( endTime - startTime ).count() << std::endl;
	*/


	// initialize game resources here

	std::chrono::steady_clock::time_point startTime{ std::chrono::steady_clock::now() };
	for(int count{}; count < 1'000'000; ++count)
	{}



	std::chrono::steady_clock::time_point endTime{ std::chrono::steady_clock::now() };

	std::chrono::duration<float, std::milli> elapsedTime{ endTime - startTime };

	std::cout << elapsedTime.count() << std::endl;

	GenerateBall();



}

void Draw()
{
	ClearBackground();
	GenerateBall();
	DrawFreeFall();
	// Put your own draw statements here

}

void Update(float elapsedSec)
{
	g_elapsedSec = elapsedSec;
	FramesInformation();
	BallPosition();
	UpdateFreeFall();


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
	if (SDLK_s) {
		IsSPressed= true;
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
void FramesInformation()
{
	g_NrFrames++;
	g_AccumulatedTime = g_AccumulatedTime + g_elapsedSec;
	float framerate{ g_NrFrames / g_AccumulatedTime };

	if (g_NrFrames % 100 == 0)
	{
		std::cout << "Number of Frames: " << g_NrFrames << "     Accumulated Time: " << g_AccumulatedTime << "     Framerate: " << framerate << '\n';
	}
}

void DrawBall(float circleX, float circleY, float radiusX, float radiusY)
{
	SetColor(0, 0, 1, 1);
	FillEllipse(circleX, circleY, radiusX, radiusY);
}
void GenerateBall()
{
	float circleX = g_CircleX;
	float circleY = g_CircleY;

	DrawBall(circleX, circleY, g_CircleRadius, g_CircleRadius);

}
void BallPosition() {

	if (g_CircleX + g_CircleRadius >= g_WindowWidth)
	{
		g_CirclePositiveDirectionX = false;
	}
	if (g_CircleX - g_CircleRadius <= 0)
	{
		g_CirclePositiveDirectionX = true;
	}

	if (g_CircleY + g_CircleRadius >= g_WindowHeight)
	{
		g_CirclePositiveDirectionY = false;
	}
	if (g_CircleY - g_CircleRadius <= 0)
	{
		g_CirclePositiveDirectionY = true;
	}
	if (g_CirclePositiveDirectionX == true)
	{
		g_CircleX += g_CircleSpeedXPerSecond * g_elapsedSec;
	}
	else
	{
		g_CircleX -= g_CircleSpeedXPerSecond * g_elapsedSec;
	}

	if (g_CirclePositiveDirectionY == true)
	{
		g_CircleY += g_CircleSpeedXPerSecond * g_elapsedSec;
	}
	else
	{
		g_CircleY -= g_CircleSpeedXPerSecond * g_elapsedSec;
	}

}



void DrawFreeFall() {

	SetColor(1, 0, 0, 1);
	FillRect(g_Square);

	//std::cout << '\n' << '\n' << "s PRESSED?" << IsSPressed << '\n' << '\n';
}

void UpdateFreeFall() {

	

	if (IsSPressed) {
		g_FallSpeed += g_Gravity * g_elapsedSec;
		g_Square.bottom += g_FallSpeed * g_elapsedSec;
		std::cout << "Current velocity: " << g_FallSpeed << '\n';
		if (g_Square.bottom + g_SquareSide < 0) {
			IsSPressed = false;
			g_Square.bottom = g_WindowHeight - g_SquareSide;
			g_FallSpeed = 0.0f;
		}
	}

}
#pragma endregion ownDefinitions