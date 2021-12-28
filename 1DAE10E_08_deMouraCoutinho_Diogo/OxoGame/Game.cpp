#include "pch.h"
#include "Game.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	StartGame();
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawGrid();
	DrawPlayerOne();
	DrawPlayerTwo();

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
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	ToggleCell(mousePos);
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

void ToggleCell(Point2f MousePoint)
{
	for (int row{ 0 }; row < g_Rows; row++)
	{
		float differenceRows = g_Distance * row;
		for (int column{ 0 }; column < g_Columns; column++)
		{
			float differenceColumns = g_Distance * column;
			int index{ GetIndex(row, column, g_Columns) };
			Rectf gridCell{ g_GridBottomLeft.x + (column * g_CellLenght) + differenceColumns,
							g_GridBottomLeft.y + (row * g_CellLenght) + differenceRows, g_CellLenght, g_CellLenght };
			if (IsPointInRectangle(gridCell, MousePoint))
			{
				if (g_GameArray[index].IsClicked) { // Does allow the same tile to be selected again
					g_GameArray[index].IsClicked = !g_GameArray[index].IsClicked;
				}
				g_GameArray[index].IsClicked = !g_GameArray[index].IsClicked;
				DeBug(index);
				return;
			}
		}
	}
}



void DrawGrid()
{
	//const Color4f toggleOn{ g_Orange };
	//const Color4f toggleOff{ g_Grey };
	for (int row{ 0 }; row < g_Rows; row++)
	{
		float differenceRows = g_Distance * row;
		for (int column{ 0 }; column < g_Columns; column++)
		{
			float differenceColumns = g_Distance * column;
			Point2f bottomLeft{ g_GridBottomLeft.x + (column * g_CellLenght) + differenceColumns, g_GridBottomLeft.y + (row * g_CellLenght) + differenceRows };
			int index{ GetIndex(row, column, g_Columns) };
			SetColor(g_Grey);
			if (g_GameArray[index].IsClicked)
				SetColor(g_Green);
				
			FillRect(bottomLeft, g_CellLenght, g_CellLenght);
			SetColor(g_Black);
			DrawRect(bottomLeft, g_CellLenght, g_CellLenght);

		}

	}
}

int GetIndex(int rowIndex, int columnIndex, int nrOfColumns)
{
	return rowIndex * nrOfColumns + columnIndex;
}






void DrawPlayerOne()
{
	SetColor(g_Grey);
	if (playerOne.PlayerTurn == TRUE) {
		SetColor(g_Green);
	}
	FillRect(g_PlayerOne, g_CellLenght, g_CellLenght);
	SetColor(g_Black);
	DrawRect(g_PlayerOne, g_CellLenght, g_CellLenght);

}

void DrawPlayerTwo()
{
	SetColor(g_Grey);
	if (playerTwo.PlayerTurn == TRUE) {
		SetColor(g_Green);
	}
	FillRect(g_PlayerTwo, g_CellLenght, g_CellLenght);
	SetColor(g_Black);
	DrawRect(g_PlayerTwo, g_CellLenght, g_CellLenght);

}


void StartGame() 
{
	int random = rand() % 100;
	int side = random % 2;

	if (side == 0) {
		playerOne.PlayerTurn = true;
		playerTwo.PlayerTurn = false;
	}
	if (!(side == 0)) {
		playerOne.PlayerTurn = false;
		playerTwo.PlayerTurn = true;
	}
}




void DeBug(int index)
{
	if (g_GameArray[index].IsClicked) {
		std::cout << "Square " << index << " is clicked" << '\n';
	}
	if (!(g_GameArray[index].IsClicked)) {
		std::cout << "Square " << index << " is not clicked" << '\n';
	}
}





#pragma endregion ownDefinitions