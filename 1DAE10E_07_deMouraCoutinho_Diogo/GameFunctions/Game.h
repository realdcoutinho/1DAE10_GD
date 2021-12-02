#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Game Functions - deMouraCoutinho, Diogo - 1DAE10E" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
float g_Radius{ 50 };
float g_RadiusMouse{ 25 };

//Colors
Color4f g_Green{ 0, 1, 0, 0.5f };
Color4f g_HalfRed {1, 0, 0, 0.5f };
Color4f g_Red{ 1, 0, 0, 1 };
Color4f g_White{ 1, 1, 1, 1 };

//mouse coordinates
Point2f g_Mouse{};

//constructs
Point2f g_CircleCenter{ g_WindowWidth / 2, g_WindowHeight / 2 };
Ellipsef g_Circle{ g_CircleCenter, g_Radius, g_Radius };
Ellipsef g_CircleMouse{};

Rectf g_Rect{ 350, 200, 80, 30 };
Rectf g_RectMouse{};


//conditions
bool g_IsPointInCircle{};
bool g_IsOverlaping{};
bool g_IsPointInRect{};
bool g_IsOverlapingRect{};

// Declare your own functions here
void DrawCircle();
void DrawCircleMouse();

void DrawRect();
void DrawRectMouse();
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
