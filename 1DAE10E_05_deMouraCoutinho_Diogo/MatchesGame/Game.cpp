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
	ClearBackground(0,0,0);
	// Put your own draw statements here
	Borders();

	GenerateMatchesTop();
	GenerateMatchesLeft();
	GenerateMatchesRight();

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
	switch (key)
	{
	case SDLK_1:
		std::cout << "1 key released\n";
		if (g_NrMatchesTop > 0) {
			--g_NrMatchesTop;
			if (g_NrMatchesLeft < 21) {
				g_NrMatchesLeft = g_NrMatchesLeft + 1;
			}
			ComputerChoice();
		}

		break;
	case SDLK_2:
		std::cout << "2 key released\n";
		if (g_NrMatchesTop > 0) {
			g_NrMatchesTop = g_NrMatchesTop - 2;
			if (g_NrMatchesLeft < 21) {
				g_NrMatchesLeft = g_NrMatchesLeft + 2;
			}
			ComputerChoice();
		}
		break;
	case SDLK_3:
		std::cout << "3 key released\n";
		if (g_NrMatchesTop > 0) {
			g_NrMatchesTop = g_NrMatchesTop - 3;
			if (g_NrMatchesLeft < 21) {
				g_NrMatchesLeft = g_NrMatchesLeft + 3;
			}
			ComputerChoice();
		}
		break;
	case SDLK_LEFT:
		std::cout << "Left arrow key released\n";
		break;
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
void Borders() {

	SetColor(g_R);
	DrawRect(g_border, g_border, g_WindowWidth - g_border * 2, g_WindowHeight - g_border * 2);
	

	DrawLine(g_WindowWidth / 2, 0, g_WindowWidth / 2, g_WindowHeight);

}

void GenerateMatchesTop() {

	float initialMatches{0 };

	//Tip
	float tipHeight{ 20 };

	//Stick
	float stickHeigh{ 60 };

	//Matche
	float matchWidth{ 7 };
	float matcheX{ g_border };
	float matcheY{ g_WindowHeight - g_border - stickHeigh - tipHeight };

	for (initialMatches = 0; initialMatches <= g_NrMatchesTop - 1; ++initialMatches) {

		float interval{ (matchWidth + g_spacing) * initialMatches  };

		Point2f stickO(matcheX + interval, matcheY);
		Point2f tipO(matcheX + interval, matcheY + stickHeigh);

		SetColor(g_R);
		FillRect(stickO, matchWidth, stickHeigh); // Stick
		SetColor(g_Y);
		FillRect(tipO, matchWidth, tipHeight); // Tip

	}
}

void GenerateMatchesLeft() {

	float initialMatches{ 0 };

	//Tip
	float tipHeight{ 20 };

	//Stick
	float stickHeigh{ 60 };

	//Matche
	float matchWidth{ 7 };
	float matcheX{ g_border };
	float matcheY{ g_border };

	for (initialMatches = 0; initialMatches < g_NrMatchesLeft && initialMatches < 11; ++initialMatches) {

		float interval{ (matchWidth + g_spacing) * initialMatches };

		Point2f stickO(matcheX + interval, matcheY);
		Point2f tipO(matcheX + interval, matcheY + stickHeigh);

		SetColor(g_R);
		FillRect(stickO, matchWidth, stickHeigh); // Stick
		SetColor(g_Y);
		FillRect(tipO, matchWidth, tipHeight); // Tip
	}
}

void GenerateMatchesRight() {

	float initialMatches{ 0 };

	//Tip
	float tipHeight{ 20 };

	//Stick
	float stickHeigh{ 60 };

	//Matche
	float matchWidth{ 7 };
	float matcheX{ g_WindowWidth / 2 };
	float matcheY{ g_border };

	g_NrMatchesRight = g_ChoiceSum;

	for (initialMatches = 0; initialMatches < g_NrMatchesRight; ++initialMatches) {

		float interval{ (matchWidth + g_spacing) * initialMatches };

		Point2f stickO(matcheX + interval, matcheY);
		Point2f tipO(matcheX + interval, matcheY + stickHeigh);

		SetColor(g_R);
		FillRect(stickO, matchWidth, stickHeigh); // Stick
		SetColor(g_Y);
		FillRect(tipO, matchWidth, tipHeight); // Tip
	}
}

void ComputerChoice() {

	if (g_NrMatchesTop > 0) {

		float choice = float(rand() % 3 + 1);
		g_ChoiceSum = g_ChoiceSum + choice;
		std::cout << '\n' << "choice" << choice << '\n';
		std::cout << '\n' << "Sum" << g_ChoiceSum << '\n';

		g_NrMatchesTop = g_NrMatchesTop - choice;
	}
}
#pragma endregion ownDefinitions