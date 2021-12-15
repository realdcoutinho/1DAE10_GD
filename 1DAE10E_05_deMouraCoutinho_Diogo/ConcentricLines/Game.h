#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
int g_X{};
int g_Y{};

//float g_ColorVariable{};

const Color4f g_Red1(1, 0, 0, 1);
const Color4f g_Green1(0, 1, 0, 1);
const Color4f g_Blue1(0, 0, 1, 1);

enum class ColorLines 
{ 
	Red = 0, 
	Green = 1, 
	Blue = 2 
};

ColorLines g_ColorState{};

float g_ColorVariable{};
Color4f g_color;


// Declare your own functions here
void Lines();
void SwitchColor();
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
