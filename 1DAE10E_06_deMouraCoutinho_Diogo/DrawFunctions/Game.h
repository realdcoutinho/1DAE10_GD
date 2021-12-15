#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "DrawFunction - deMouraCoutinho, Diogo - 1DAE10" };

// Change the window dimensions here
float g_WindowLenght{ 500 };
float g_WindowWidth{ 800 };
float g_WindowHeight{ g_WindowLenght };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
float g_border{ g_WindowLenght / 50 };
float g_choice{};



// Declare your own functions here
void GenerateThreeRects(float sideSize, float xCoordinate, float loops);
void DrawThreeRects();

void GenerateTriangles(const Point2f& V1, const Point2f& V2, const Point2f& V3);
void DrawTriangles();
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
