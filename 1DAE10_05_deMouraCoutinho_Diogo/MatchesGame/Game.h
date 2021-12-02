#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "MatchesGame - deMouraCoutinho, Diogo - 1DAE10E" };

// Change the window dimensions here
float g_WindowWidth{ 600 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
float g_border{15};

float g_spacing{ 7 };

float g_ChoiceSum{};

float g_NrMatchesTop{ 21 };
float g_NrMatchesLeft{ 0 };
float g_NrMatchesRight{ 0 };


Color4f g_R(1, 0, 0, 1);
Color4f g_Y(1, 1, 0, 1);


// Declare your own functions here
void Borders();

void GenerateMatchesTop();
void GenerateMatchesLeft();
void GenerateMatchesRight();

void ComputerChoice();
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
