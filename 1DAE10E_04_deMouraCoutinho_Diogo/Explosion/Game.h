#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Explosion - deMouraCoutinho, Diogo - 1DAExx" };

// Change the window dimensions here

float g_WindowLenght{ 500 };
float g_WindowWidth{ g_WindowLenght };
float g_WindowHeight{ g_WindowLenght };

#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
float g_NrFrames{};
float g_IsExploding{ false };
float g_sideLenght{ g_WindowLenght/6 }; // LENGHT OF SQUARE


Color4f g_Black{ 0, 0, 0, 1 };
Color4f g_Red{ 1, 0, 0, 1 };
Rectf g_InitialBomb{};


// Declare your own functions here
bool IsBombClicked(float mouseX, float mouseY);
void InitialBomb();
void DrawBomb();
void IsExploding();
void UpdateExplosion();
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
