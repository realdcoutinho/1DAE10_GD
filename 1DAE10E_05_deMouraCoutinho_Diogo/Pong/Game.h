#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Pong - deMouraCoutinho, Diogo - 1DAE10E" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
float g_Border{ 50 };

Point2f g_PlayerOneRect{};
Point2f g_PlayerTwoRect{};

Point2f g_BallStartOne{};
Point2f g_BallStartTwo{};

float g_RectWidth{ 75 };
float g_RectHeight{ 10 };
float g_RectInitialX{ g_WindowWidth / 2 - g_RectWidth / 2 };

float g_ballRadius{ 5 };

bool IsLeftPressed{ false };
bool IsRightPressed{ false };

bool IsAPressed{ false };
bool IsDPressed{ false };

bool g_StartOne{ false };
bool g_StartTwo{ false };

bool g_BallStarted{ false };
bool g_ToLeft{ false };
bool g_ToRight{ false };

bool g_PlayerOneBegin{ false };
bool g_PlayerTwoBegin{ false };
// Declare your own functions here

void GenerateRectOne();
void PlayerOne();
void GenerateRectTwo();
void PlayerTwo();

void MidLine();
void GenerateBall();
void DrawBall();
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
