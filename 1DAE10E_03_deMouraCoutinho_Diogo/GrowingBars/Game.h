#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Growing Bars - deMouraCoutinho, Diogo - 1DAE10E" };

// Change the window dimensions here
float g_WindowWidth{ 1000 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
int g_NrFrames = { 0 };

float g_oneUnit_Width = g_WindowWidth / 20;
float g_oneUnit_Height = g_WindowHeight / 10;

float g_yellow_Growing = { 0 };
float g_red_Growing = { 0 };

float g_borderWidth = { g_oneUnit_Width * 18};

// Declare your own functions here

#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
