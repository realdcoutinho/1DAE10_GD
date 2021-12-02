#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	GenerateRectOne();
	GenerateRectTwo();
	PlayerOne();
	PlayerTwo();

	GenerateBall();

}

void Draw()
{
	ClearBackground(0,0,0);

	// Put your own draw statements here
	MidLine();
	DrawBall();

	PlayerOne();
	PlayerTwo();

}

void Update(float elapsedSec)
{
	if (IsLeftPressed) {
		if (g_PlayerOneRect.x >= 0) {
			g_PlayerOneRect.x = g_PlayerOneRect.x - 2;
			std::cout << '\n' << "hello" << '\n';
			std::cout << '\n' << g_PlayerOneRect.x << '\n';
		}
	}
	if (IsRightPressed) {
		if (g_PlayerOneRect.x < g_WindowWidth - g_RectWidth){
			g_PlayerOneRect.x = g_PlayerOneRect.x + 2;
			std::cout << '\n' << "bye" << '\n';
			std::cout << '\n' << g_PlayerOneRect.x << '\n';
		}
	}

	if (IsAPressed) {
		if (g_PlayerTwoRect.x >= 0) {
			g_PlayerTwoRect.x = g_PlayerTwoRect.x - 2;
			std::cout << '\n' << "hello" << '\n';
			std::cout << '\n' << g_PlayerTwoRect.x << '\n';
		}
	}
	if (IsDPressed) {
		if (g_PlayerTwoRect.x < g_WindowWidth - g_RectWidth) {
			g_PlayerTwoRect.x = g_PlayerTwoRect.x + 2;
			std::cout << '\n' << "bye" << '\n';
			std::cout << '\n' << g_PlayerTwoRect.x << '\n';
		}
	}
	/*
	if (g_StartOne) {
		if (!(g_BallStarted)) {
			g_BallStartOne.x = g_PlayerOneRect.x + g_RectWidth / 2;
		}
	}
	if (g_StartTwo) {
		if (!(g_BallStarted)) {
			g_BallStartTwo.x = g_PlayerTwoRect.x + g_RectWidth / 2;
		}
	}
	*/

	if (g_PlayerOneBegin == true && g_PlayerTwoBegin == false) {
		if (g_ToLeft) {
			++g_BallStartOne.y;
			--g_BallStartOne.x;
		}
	}
	if (g_PlayerOneBegin == true && g_PlayerTwoBegin == false) {
		if (g_ToRight) {
			++g_BallStartOne.y;
			++g_BallStartOne.x;
		}
	}
	if (g_PlayerTwoBegin == true && g_PlayerOneBegin == false) {
		if (g_ToLeft) {
			std::cout << "Hello" << '\n';
			--g_BallStartOne.y;
			--g_BallStartOne.x;
		}
	}
	if (g_PlayerTwoBegin == true && g_PlayerOneBegin == false) {
		if (g_ToRight) {
			std::cout << "Bye" << '\n';
			--g_BallStartOne.y;
			++g_BallStartOne.x;
		}
	}




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
	switch (key)
	{
	case SDLK_LEFT:
		std::cout << "Left arrow key pressed\n";
		IsLeftPressed = true;
		break;
	case SDLK_RIGHT:
		std::cout << "Left arrow key pressed\n";
		IsRightPressed = true;
		break;
	case SDLK_a:
		std::cout << "a key pressed\n";
		IsAPressed = true;
		break;
	case SDLK_d:
		std::cout << "d key pressed\n";
		IsDPressed = true;
		break;
	case SDLK_w:
		std::cout << "w key pressed\n";
		g_PlayerTwoBegin = true;
		g_PlayerOneBegin = false;
		//g_StartTwo = false;
		break;
	case SDLK_UP:
		std::cout << "arrow up key pressed\n";
		g_PlayerOneBegin = true;
		g_PlayerTwoBegin = false;
		//g_StartOne = false;
		break;

	}




}

void OnKeyUpEvent(SDL_Keycode key)
{
	
	switch (key)
	{
	case SDLK_LEFT:
		std::cout << "Left arrow key released\n";
		IsLeftPressed = false;
		break;
	case SDLK_RIGHT:
		std::cout << "Left arrow key released\n";
		IsRightPressed = false;
		break;
	case SDLK_a:
		std::cout << "a key pressed\n";
		IsAPressed = false;
		break;
	case SDLK_d:
		std::cout << "d key pressed\n";
		IsDPressed = false;
		break;
	}
	

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
void GenerateRectOne() {

	g_PlayerOneRect = Point2f{ g_RectInitialX, g_Border };

}
void PlayerOne() {


	SetColor(1, 1, 1, 1);
	FillRect(g_PlayerOneRect, g_RectWidth, g_RectHeight);
}

void GenerateRectTwo() {

	g_PlayerTwoRect = Point2f{ g_RectInitialX, g_WindowHeight - g_Border - g_RectHeight };

}

void PlayerTwo() {

	SetColor(1, 1, 1, 1);
	FillRect(g_PlayerTwoRect, g_RectWidth, g_RectHeight);
}

void MidLine() {

	float n = -2.5f;

	for (n; n <= 500; n = n + 10) {

		SetColor(1, 1, 1, 1);
		DrawLine(n, g_WindowHeight / 2, n-5, g_WindowHeight / 2, 2);

	}

	DrawEllipse(g_WindowWidth / 2, g_WindowHeight / 2, 60, 50);
}

void GenerateBall() {

	float g_ballRadius{ 5 };
	float ballOneY{ g_Border + g_RectHeight + g_ballRadius };
	float ballTwoY{ g_WindowHeight - g_Border - g_RectHeight - g_ballRadius };
	float ballX{ g_WindowWidth / 2 };

	g_BallStartOne = Point2f(ballX, ballOneY);
	g_BallStartTwo = Point2f(ballX, ballTwoY);

	int startPosition = rand() % 2 + 1;

	if (startPosition == 1) {
		g_StartOne = true;
		g_StartTwo = false;
	}
	else if (startPosition == 2) {
		g_StartTwo = true;
		g_StartOne = false;
	}

	int sideBall = rand() % 2 + 1;

	if (sideBall == 1) {
		g_ToLeft = true;
		g_ToRight = false;
	}
	else if (sideBall == 2) {
		g_ToRight = true;
		g_ToLeft = false;
	}



}

void DrawBall() {


	if (g_StartOne == true) {
		FillEllipse(g_BallStartOne, g_ballRadius, g_ballRadius);
	}
	else if (g_StartTwo == true) {
		FillEllipse(g_BallStartTwo, g_ballRadius, g_ballRadius);
	}

	


}

#pragma endregion ownDefinitions