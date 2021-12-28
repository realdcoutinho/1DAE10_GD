#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	CreateTextures();
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawTextures();
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
	DeleteTextures();
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_s:
		Shuffle(9999);
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
void CreateTextures()
{
	{
		const std::string fileType{ ".png" };
		const std::string path{ "Resources/Cards/" };
		for (int suite = 0; suite < g_Rows; suite++)
		{
			for (int card{ 0 }; card < g_Columns; card++)
			{
				int index{ GetLinearIndex(suite, card, g_Columns) };
				std::string fullPath{ path + std::to_string(100 * (suite + 1) + card + 1) + fileType };
				std::cout << "Index: " << index << " Path: " << fullPath << std::endl;
				//TextureFromFile(fullPath, g_Cards[index]);

				bool succesfull = TextureFromFile(fullPath, g_Cards[index]);
				if (!succesfull) std::cout << "Loading PNG Failed";
			}
		}
	}
}

void DeleteTextures()
{
	for (int i{}; i < g_NrCards; ++i)
	{
		DeleteTexture(g_Cards[i]);
	}
}

void DrawTextures()
{
	const float height = g_WindowHeight / g_Rows;
	const float width = g_WindowWidth / g_Columns;
	for (int row{ 0 }; row < g_Rows; row++)
	{
		for (int column{ 0 }; column < g_Columns; column++)
		{
			int index{ GetLinearIndex(row, column, g_Columns) };
			Rectf cardBase{ width * column, height * row, width, height };
			DrawTexture(g_Cards[index], cardBase);
		}
	}
}

void Shuffle(int nrOfShuffles)
{
	int idx1{  };
	int idx2{};
	for (int i{ 0 }; i < nrOfShuffles; i++)
	{
		do
		{
			idx1 = (int)GetRandomNumber(0, 51);
			idx2 = (int)GetRandomNumber(0, 51);
		} while (idx1 == idx2);
		Texture temporaryLocation{ g_Cards[idx1] };
		g_Cards[idx1] = g_Cards[idx2];
		g_Cards[idx2] = temporaryLocation;
	}
}

int GetLinearIndex(int rowIndex, int columnIndex, int nrOfColumns)
{
	return rowIndex * nrOfColumns + columnIndex;
}


#pragma endregion ownDefinitions