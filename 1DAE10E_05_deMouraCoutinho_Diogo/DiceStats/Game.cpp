
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
	ClearBackground();
	DrawDieOne();
	DrawDice();
	// Put your own draw statements here

}

void Update(float elapsedSec)
{
	DieOne();
	Dice();
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
void DieOne() {
		
g_rolledDie =  rand() % (7 - 1) + 1;
		


if (g_rolledDie == 1) {
	g_die1++;
}
else if (g_rolledDie == 2) {
	g_die2++;
}
else if (g_rolledDie == 3) {
	g_die3++;
}
else if (g_rolledDie == 4) {
	g_die4++;
}
else if (g_rolledDie == 5) {
	g_die5++;
}
else if (g_rolledDie == 6) {
	g_die6++;
}



}

void DrawDieOne() {


	SetColor(1, 0, 0.2f, 1);
	FillRect(10, 10, g_die1, g_barHeight);
	FillRect(10, 10 + 28, g_die2, g_barHeight);
	FillRect(10, 10 + 28 * 2, g_die3, g_barHeight);
	FillRect(10, 10 + 28 * 3, g_die4, g_barHeight);
	FillRect(10, 10 + 28 * 4, g_die5, g_barHeight);
	FillRect(10, 10 + 28 * 5, g_die6, g_barHeight);
}

void Dice() {

	g_rolledDice1 = rand() % (7 - 1) + 1;
	g_rolledDice2 = rand() % (7 - 1) + 1;

	if (g_rolledDice1 + g_rolledDice2 == 2) {
		g_dice2++;
	}
	else if (g_rolledDice1 + g_rolledDice2 == 3) {
		g_dice3++;
	}
	else if (g_rolledDice1 + g_rolledDice2 == 4) {
		g_dice4++;
	}
	else if (g_rolledDice1 + g_rolledDice2 == 5) {
		g_dice5++;
	}
	else if (g_rolledDice1 + g_rolledDice2 == 6) {
		g_dice6++;
	}
	else if (g_rolledDice1 + g_rolledDice2 == 7) {
		g_dice7++;
	}
	else if (g_rolledDice1 + g_rolledDice2 == 8) {
		g_dice8++;
	}
	else if (g_rolledDice1 + g_rolledDice2 == 9) {
		g_dice9++;
	}
	else if (g_rolledDice1 + g_rolledDice2 == 10) {
		g_dice10++;
	}
	else if (g_rolledDice1 + g_rolledDice2 == 11) {
		g_dice11++;
	}
	else if (g_rolledDice1 + g_rolledDice2 == 12) {
		g_dice12++;
	}

	std::cout << g_rolledDice1 + g_rolledDice2 << '\n';
}

void DrawDice() {

	SetColor(0.5f, 0, 0.8f, 0.8f);
	FillRect(10, 10 + 28 * 6, g_dice2, g_barHeight);
	FillRect(10, 10 + 28 * 7, g_dice3, g_barHeight);
	FillRect(10, 10 + 28 * 8, g_dice4, g_barHeight);
	FillRect(10, 10 + 28 * 9, g_dice5, g_barHeight);
	FillRect(10, 10 + 28 * 10, g_dice6, g_barHeight);
	FillRect(10, 10 + 28 * 11, g_dice7, g_barHeight);
	FillRect(10, 10 + 28 * 12, g_dice8, g_barHeight);
	FillRect(10, 10 + 28 * 13, g_dice9, g_barHeight);
	FillRect(10, 10 + 28 * 14, g_dice10, g_barHeight);
	FillRect(10, 10 + 28 * 15, g_dice11, g_barHeight);
	FillRect(10, 10 + 28 * 16, g_dice12, g_barHeight);

}
#pragma endregion ownDefinitions