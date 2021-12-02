#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "LoopedDrawings - deMouraCoutinho, Diogo - 1DAE10E" };

// Change the window dimensions here
float g_WindowLenght{ 500 };
float g_WindowWidth{ g_WindowLenght };
float g_WindowHeight{ g_WindowLenght };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
float g_border{ g_WindowLenght/50 };

float g_choice{ 5 }; // How many squares has the user chosen?

Color4f g_red{ 1,0,0.2f,1 };
Color4f g_blue{ 0.2f,0,1,1 };
Color4f g_green{ 0, 0.9f, 0.1f, 1 };
Color4f g_yellow{ 0.9f, 0.9f, 0.1f,1 };

// Declare your own functions here
void Borders();

void GenerateGreenRect();

void GenerateStairs();

void GenerateSpiral();

void GenerateSpiralLines();

void Plus();
void Minus();
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
