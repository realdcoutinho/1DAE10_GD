#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Curves - deMouraCoutinho, Diogo - 1DAExx" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

//common variables
float g_Angle{};

//Ellipse Variables
float g_IncreaseEllipse{ 5 };
float g_AE{ 10 };
float g_BE{ 18 };

Color4f g_Black(0, 0, 0, 1);
Point2f g_EllipseCenter(g_WindowWidth / 4, g_WindowHeight / 2);

//Crosier Variables
float g_CA{ g_WindowWidth / 4 };
Point2f g_CrosierCenter(g_WindowWidth / 4 * 3, g_WindowHeight / 2);

// Declare your own functions here
void GenerateEllipse();
void GenerateCrosier();

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
