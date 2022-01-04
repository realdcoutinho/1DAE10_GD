#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "StaticDrawing - deMouraCoutinho, Diogo - 1DAE10E" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 800 };
#pragma endregion gameInformation


#pragma region Drawings
void Start();
void DrawHouse();
void DrawFlag();
void DrawChekerPattern();
void DrawColorBand();
void DrawPentagram();
void DrawColumnChart();
#pragma endregion Drawings


#pragma region ownDeclarations
// Declare your own global variables here

// Declare your own functions here

#pragma endregion ownDeclarations

#pragma region gameFunctions	

void Start();
void Draw();
void Update(float elapsedSec);
void End();

/////////////////////////////////////////
void DrawHouse();
void DrawFlag();
void DrawChekerPattern();
void DrawColorBand();
void DrawPentagram();
void DrawColumnChart();



#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
