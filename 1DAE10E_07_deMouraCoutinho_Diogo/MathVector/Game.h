#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Math Vector - deMouraCoutinho, Diogo - 1DAE10" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
const float g_Speed{ 100.0f };
float g_VectorAngle{};


//Colors
Color4f g_yellow(1, 1, 0, 1);


// Declare your own functions here
void TestDrawVector();
void TestVectorToString();
void TestAddVector();
void TestSubtractVector();
void TestDotProduct();
void TestCrossProduct();
void TestLenght();
void TestNormalize();
void TestScalar();
void TestAngleBetween();
void TestAreEqual();

void MovingVector();

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
