#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "FrameTime - deMouraCoutinho, Diogo - 1DAE10" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
int g_NrFrames{};
float g_AccumulatedTime{};
float g_elapsedSec{};

//constants
const float g_CircleSpeedXPerSecond{ 100.0 };
const float g_CircleSpeedYPerSecond{ 100.0 };

const float g_CircleXStartValue{ 50.0 };
const float g_CircleYStartValue{ 50.0 };

const float g_CircleRadius{ 30.0 };

const float g_Gravity{ -9.81f };

//variables
float g_CircleX{ g_CircleXStartValue };
float g_CircleY{ g_CircleYStartValue };

float g_SquareSide{ 30 };
float g_FallSpeed{ 0 };

//conditions
bool g_CirclePositiveDirectionX{ true };
bool g_CirclePositiveDirectionY{ true };

bool IsSPressed{ false };
bool IsRectOver{ false };

//constructs
Rectf g_Square{ g_WindowWidth / 10, g_WindowHeight - g_SquareSide, g_SquareSide, g_SquareSide};

// Declare your own functions here
void DrawBall(float circleX, float circleY, float radiusX, float radiusY);
void GenerateBall();
void BallPosition();

void DrawFreeFall();
void UpdateFreeFall();


void FramesInformation();
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
