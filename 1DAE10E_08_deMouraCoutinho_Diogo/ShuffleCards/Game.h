#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "ShuffleCards - deMouraCoutinho, Diogo - 1DAE10" };

// Change the window dimensions here
float g_WindowWidth{ 1000 };
float g_WindowHeight{ 600 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
//const variables
const int g_Rows	{ 4 };
const int g_Columns	{ 13 };
const int g_NrCards{ g_Rows * g_Columns };


//Arrays
Texture g_Cards[g_NrCards]{};
Texture temporaryLocation[g_NrCards]{};
// Declare your own functions here
void CreateTextures();
void DeleteTextures();
void Shuffle(int nrOfShuffles);
void DrawTextures();



int GetLinearIndex(int rowIndex, int columnIndex, int nrOfColumns);
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
