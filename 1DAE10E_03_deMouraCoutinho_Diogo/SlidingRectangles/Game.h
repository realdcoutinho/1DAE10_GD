#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "SlidingRectangles - deMouraCoutinho, Diogo - 1DAE10E" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
float g_SideLenght{ 100 };
int g_SideLenghtInt{ int(g_SideLenght) };
int g_NrFrames{};
int g_WindowWidthInt{ int(g_WindowWidth) };
int g_WindowHeightInt{ int(g_WindowHeight) };

Color4f g_Black{ 0, 0, 0, 1 };
Color4f g_Red{ 1, 0, 0, 0.5f };
Color4f g_Green{ 0, 1, 0, 0.5f };
Color4f g_Blue{ 0, 0, 1, 0.5f };
Color4f g_Yellow{ 1, 1, 0, 0.5f };

////float sideSize{ 100 };
////float g_NrFrames{};


// Declare your own functions here
void DrawSquares();
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
