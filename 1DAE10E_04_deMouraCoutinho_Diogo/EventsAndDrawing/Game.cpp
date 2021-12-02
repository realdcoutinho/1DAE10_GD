#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	GenerateRect();
	GenerateLine();
	// initialize game resources here
}

void Draw()
{
	ClearBackground();
	InitialBorder();
	DrawRect();
	DrawLine();
}

void Update(float elapsedSec)
{


	if (g_FlipEndLineX)
	{
		if (--g_End.x <= 0)
			g_FlipEndLineX = false;
	}
	else
	{
		if (g_WindowWidth <= ++g_End.x)
			g_FlipEndLineX = true;
	}
	if (g_FlipStartLineX)
	{
		if (--g_Start.x <= 0)
			g_FlipStartLineX = false;
	}
	else
	{
		if (g_WindowWidth <= ++g_Start.x)
			g_FlipStartLineX = true;
	}
	if (g_FlipEndLineY)
	{
		if (--g_End.y <= 0)
			g_FlipEndLineY = false;
	}
	else
	{
		if (g_WindowHeight <= ++g_End.y)
			g_FlipEndLineY = true;
	}
	if (g_FlipStartLineY)
	{
		if (--g_Start.y <= 0)
			g_FlipStartLineY = false;
	}
	else
	{
		if (g_WindowHeight <= ++g_Start.y)
			g_FlipStartLineY = true;
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
		case SDLK_l:
			std::cout << "You pressed L" << '\n';
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

}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	
	int mouseX = int(e.x);
	int mouseY = int(g_WindowHeight - e.y);


	if (mouseX >= g_RandomRect.left && mouseX <= g_RandomRect.left + g_RandomRect.width) {
		if (mouseY >= g_RandomRect.bottom && mouseY <= g_RandomRect.bottom + g_RandomRect.height) {
			if (e.button == SDL_BUTTON_LEFT) {
				GenerateRect();
			}
		}
	}


	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		std::cout << "Left mouse button pressed\n";
		Point2f mousePos{ float(e.x), float(g_WindowHeight - e.y) };
		break;


	}
	case SDL_BUTTON_RIGHT:{
		std::cout << "Right mouse button pressed\n";
		break;
	}
	case SDL_BUTTON_MIDDLE:{
		std::cout << "Middle mouse button pressed\n";
		break;
	}
	}

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//bool g_Pressed = false ;
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		std::cout << "Left mouse button released\n";
		break;
	case SDL_BUTTON_RIGHT:
		std::cout << "Right mouse button released\n";
		break;
	case SDL_BUTTON_MIDDLE:
		std::cout << "Middle mouse button released\n";
		break;
	}



}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here


void InitialBorder() 
{
	SetColor			(g_red);
	DrawRect			(g_border, g_border, g_WindowWidth - g_border * 2, g_WindowHeight - g_border * 2);
}




void GenerateRect() {

	float border		{ g_border };
	float minimumWidth	{ 60 };
	float minimumHieght	{ 40 };
	float maxX			{ g_WindowWidth - border - minimumWidth };
	float minX			{ border };
	float maxY			{ g_WindowHeight - border - minimumHieght };
	float minY			{ border };


	float randomX		{ minX + (rand() % (int(maxX) - int(minX) + 1)) };
	float randomY		{ minY + (rand() % (int(maxY) - int(minY) + 1)) };

	float maxWidth		{ g_WindowWidth - border - randomX + 1 };
	float maxHeight		{ g_WindowHeight - border - randomY + 1 };

	float randomWidth	{ minimumWidth + (rand() % (int(maxWidth) - int(minimumWidth) + 1)) };
	float randomHeight	{ minimumHieght + (rand() % (int(maxHeight) - int(minimumHieght) + 1)) };

	g_RandomRect = Rectf(randomX, randomY, randomWidth, randomHeight);
	
}

void DrawRect() 
{
	//SetColor(1,0,0);
	//FillRect(100, 100, 100, 100);
	SetColor(g_grey);
	FillRect(g_RandomRect);
	//FillRect(100, 100, 100, 100);
}


void GenerateLine() {

	float startLineX = GenerateRandomFloat(0, g_WindowWidth);
	float startLineY = GenerateRandomFloat(0, g_WindowHeight);
	g_Start = Point2f{ startLineX, startLineY };


	float endLineX = GenerateRandomFloat(0, g_WindowWidth);
	float endLineY = GenerateRandomFloat(0, g_WindowHeight);
	g_End = Point2f{ endLineX, endLineY };

}

void DrawLine() {

	SetColor(1, 0, 0, 1);
	DrawLine(g_Start, g_End, 5);

}


float GenerateRandomFloat(float min, float max)
{
	return (float)((rand() % (int)max) + min);
}



#pragma endregion ownDefinitions