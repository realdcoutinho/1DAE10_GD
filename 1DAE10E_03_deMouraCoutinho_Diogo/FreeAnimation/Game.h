#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };

// Change the window dimensions here
float g_windowXY{ 500 };
float g_WindowWidth{ g_windowXY };
float g_WindowHeight{ g_windowXY };

#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
float g_oneUnit				= g_WindowWidth / 20; // 500 / 20 = 25
float g_NrFrames			{};

float g_spoke_Speed			{ 120 }; //Wheel SPEED
float g_spoke_Lenght =		g_windowXY / 10; //lenght of the spoke


float g_l_Px =				g_oneUnit * 4; //Center X coordinate for all the spokes of the left wheel
float g_r_Px =				g_oneUnit * 10; //Center X coordinate for all the spokes of the right wheel

float g_innerRadius = g_spoke_Lenght / 2.5f;

float g_tieRod_divergence = g_innerRadius / 0.7f;
float g_tieRod_Speed = g_spoke_Speed * 0.8f;

// Declare your own functions here

#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void LeftWheel();
void RightWheel();
void Rods();

void Static();
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
