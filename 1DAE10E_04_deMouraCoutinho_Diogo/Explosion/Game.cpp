#include "pch.h"
#include "Game.h"
#include "iostream"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	InitialBomb();
}

void Draw()
{
	ClearBackground();
	IsExploding();
	DrawBomb();

}

void Update(float elapsedSec)
{
	UpdateExplosion();
	// process input, do physics 
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

}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{

}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	if (IsBombClicked((float)e.x, (float)e.y) && e.button == SDL_BUTTON_LEFT)
	{
		g_Black.a = 0.5f;
		g_IsExploding = true;
	}
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{

}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

bool IsBombClicked(float mouseX, float mouseY)
{
	mouseY = g_WindowHeight - mouseY;
	bool inBomb{ g_InitialBomb.left <= mouseX && mouseX <= g_InitialBomb.width + g_InitialBomb.left };
	if (inBomb == true){
		inBomb = g_InitialBomb.bottom <= mouseY && mouseY <= g_InitialBomb.height + g_InitialBomb.bottom;
	}
	std::cout << inBomb << '\n';
	return inBomb;
}

void InitialBomb() {

	float left = (g_WindowWidth / 2) - (g_sideLenght / 2);
	float bottom = (g_WindowHeight / 2) - (g_sideLenght / 2);
	g_InitialBomb = Rectf{ left, bottom, g_sideLenght, g_sideLenght };
}

void DrawBomb() {

	SetColor(g_Black);
	FillRect(g_InitialBomb);

}

void IsExploding() 
{	
	if (g_IsExploding)
	{
		SetColor(g_Red);
		FillRect(g_InitialBomb.left + g_NrFrames, g_InitialBomb.bottom + g_NrFrames, g_sideLenght, g_sideLenght);
		FillRect(g_InitialBomb.left - g_NrFrames, g_InitialBomb.bottom - g_NrFrames, g_sideLenght, g_sideLenght);
		FillRect(g_InitialBomb.left + g_NrFrames, g_InitialBomb.bottom - g_NrFrames, g_sideLenght, g_sideLenght);
		FillRect(g_InitialBomb.left - g_NrFrames, g_InitialBomb.bottom + g_NrFrames, g_sideLenght, g_sideLenght);
	}
}

void UpdateExplosion()
{
	if (g_IsExploding)
	{
		g_NrFrames++;
		if (g_NrFrames == g_WindowWidth / 2)
		{
			g_IsExploding = false;
			g_Black.a = 1;
			g_NrFrames = 0;
		}
	}
}
#pragma endregion ownDefinitions


