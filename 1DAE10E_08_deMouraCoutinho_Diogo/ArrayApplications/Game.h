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
//const for Array sizes
const int g_maxClicked{ 10 };
const int g_MaxInterval{ 4 };
const int g_MaxTracing{ 10 };

const int g_CellRows{ 3 };
const int g_CellColumns{ 4 };
const int g_CellArraySize{ g_CellRows * g_CellColumns };

float g_GridBorder{ 10 };
float g_GridCellLenght{ 50 };
Point2f g_GridBottomLeft{ g_GridBorder, g_GridBorder };

//Textures
std::string g_Numbers{};
Texture g_DAELogo{}, g_SomeText{};
Point2f g_FramePos{ 150, 150 };
//------------------------







//colors
Color4f g_White(1, 1, 1, 1);
Color4f g_Grey(0.5f, 0.5f, 0.5f, 1);
Color4f g_Red(1, 0, 0, 1);
Color4f g_Green(0, 1, 0, 1);
Color4f g_Blue(0, 0, 1, 1);
Color4f g_Orange(1, 0.5f, 0.2f, 1);

//Arrays
Point2f g_TracingPoint[g_MaxTracing]{};
Point2f g_clickedPoints[g_maxClicked]{};


int g_ArrayInt[g_MaxInterval]{};
bool g_CellsArray[g_CellArraySize]{};

//conditions
bool g_IsClicked{ false };

//MousePosition Coordinates
Point2f g_MousePos{};
Point2f g_MousePosTracing{};
Point2f g_MousePosToggle{};

// Declare your own functions here
void AddClickedPoints();
void DrawClickedPoints(Point2f* pArray);

void DrawBars(int* pArray, int size);
void UpdateRandStats(int* pArray, int size);
int GetRandom(int maxInterval);

void AddTracingPoints();
void DrawTracingPoints(Point2f* pArray);


void DrawGrid();
void ToggleCell(Point2f MousePoint);


void TwoDArrays();
int GetIndex(int rowIndex, int columnIndex, int nrOfColumns);
void Print2DElements(int* pNumbers, int rows, int columns);

void PrintPointCoordinates(Point2f* pArray, int size);
void SwapPosition(Point2f* pArray, int idx1, int idx2, int size);
void PrintArray(int* pArray, int size);
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
