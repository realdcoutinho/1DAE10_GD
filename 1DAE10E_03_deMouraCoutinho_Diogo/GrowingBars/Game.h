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

float g_borderWidth = 50;
float g_borderHeight = 50;

float g_barLenght = g_WindowWidth - g_borderWidth * 2;
float g_barHeight = 50;

float g_redLenght = { 0 };
float g_yellowLenght = { 0 };

Color4f g_white{ 1, 1, 1, 1 };
Color4f g_red{ 1, 0, 0, 1 };
Color4f g_yellow{ 1, 1, 0, 1 };
// Declare your own functions here
void DrawYellow();
void DrawRed();
void GetLenght();
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
