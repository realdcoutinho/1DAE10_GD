#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "DiceStats- deMouraCoutinho, Diogo - 1DAE10E" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
float g_NrFrames{};
float g_barHeight{ (g_WindowHeight - 20) / 17 - 5};


int g_rolledDie{};
int g_rolledDice1{};
int g_rolledDice2{};

float g_die1{};
float g_die2{};
float g_die3{};
float g_die4{};
float g_die5{};
float g_die6{};

float g_dice2{};
float g_dice3{};
float g_dice4{};
float g_dice5{};
float g_dice6{};
float g_dice7{};
float g_dice8{};
float g_dice9{};
float g_dice10{};
float g_dice11{};
float g_dice12{};


// Declare your own functions here
void DieOne();
void DrawDieOne();
void Dice();
void DrawDice();
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
