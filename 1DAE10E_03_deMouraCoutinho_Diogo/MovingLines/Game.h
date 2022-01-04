#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Movinig Lines - deMouraCoutinho, Diogo - 1DAE10E" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here




float g_oneUnit = 5;
int g_NrFrames = { 0 };

int g_WindowWidthInt{ int(g_WindowWidth) };
int g_WindowHeightInt{ int(g_WindowHeight) };

//Line One Horizontal

//Line Two Horizontal Going dowm
float g_HorTwoY = g_WindowHeight;


// Line One Vertical
float g_lineOneX = 0;
float g_lineOne1Y = 0;

// Declare your own functions here
void DrawLines();
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
