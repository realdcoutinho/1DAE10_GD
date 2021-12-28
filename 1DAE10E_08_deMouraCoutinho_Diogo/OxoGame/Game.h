#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
//Window
float g_Border{ 20 };

//Game
const int g_Rows{ 3 };
const int g_Columns{ 3 };
const int g_GameArraySize{ g_Rows * g_Columns };
Game g_GameArray[g_GameArraySize]{};
float g_CellLenght{ 50 };

//turns
bool g_IsPlayerOne{ false };
bool g_IsPlayerTwo{ true };

//Choice
bool g_PlayerOneChoice{ false };
bool g_PlayerTwoChoice{ false };


////Distance between Cells
float g_Distance{ 5 };

Player playerOne;
Player playerTwo;



//Points
////Players
Point2f g_PlayerOne{ g_Border, g_Border };
Point2f g_PlayerTwo{ g_WindowWidth - g_Border - g_CellLenght, g_Border };
////Game Grid
Point2f g_GridBottomLeft{ (g_WindowWidth / 2) - g_Distance - g_CellLenght - (g_CellLenght / 2), g_CellLenght + g_Distance  * 3};


//Colors
Color4f g_Green{ 0, 1, 0, 1 };
Color4f g_Grey{ 0.5, 0.5, 0.5, 1 };
Color4f g_GreyLight { 0.75, 0.75, 0.75, 1 };
Color4f g_Black{ 0, 0, 0, 1 };

//



// Declare your own functions here
void DrawGrid();
void ToggleCell(Point2f MousePoint);
void DrawPlayerOne();
void DrawPlayerTwo();
int GetIndex(int rowIndex, int columnIndex, int nrOfColumns);

void StartGame();

void DeBug(int index);
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
