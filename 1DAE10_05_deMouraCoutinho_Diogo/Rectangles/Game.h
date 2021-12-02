#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Rectangles - deMouraCoutinho, Diogo - 1DAE10E" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 500 };
float g_Border{ 10 };



Color4f g_Black	{ 0, 0, 0, 1 };
Color4f g_Red	{ 1, 0, 0, 1 };
Color4f g_RandColor{};

Rectf g_RandomRect{};
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

// Declare your own functions here
void GenerateBorder();
void GenerateRect();
void GenerateColor();
void DrawRect();

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
