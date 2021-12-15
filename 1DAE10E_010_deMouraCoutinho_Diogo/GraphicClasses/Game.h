#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Graphic Classes - deMouraCoutinho, Diogo - 1DAE10E" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
class Fraction;
Fraction* g_pFraction1{};
Fraction* g_pFraction2{};
Fraction* g_pFraction3{};
Fraction* g_pFraction4{};
Fraction* g_pFraction5{};
Fraction* g_pFraction6{};



class Light;
Light* g_pLight1{};
Light* g_pLight2{};
Light* g_pLight3{};
Light* g_pLight4{};
Light* g_pLight5{};
Light* g_pLight6{};
Light* g_pLight7{};
Light* g_pLight8{};


class DaeEllipse;
DaeEllipse* g_pDaeEllipse1{};
DaeEllipse* g_pDaeEllipse2{};
DaeEllipse* g_pDaeEllipse3{};


const int g_Rows{ 4 };
const int g_Columns{ 2 };

const int g_RectArraySize{ g_Rows * g_Columns };
Rectf g_RectsArray[g_RectArraySize]{};


// Declare your own functions here
void CreateFunctions();
void PrintFractionsSum();
void DrawFractions();
void DeleteFractions();


void CreateLights();
void DrawLights();
void MouseClicks(Point2f mousePos);
void DeleteLights();
int GetIndex(int rowIndex, int columnIndex, int nrOfColumns);




void CreateEllipse();
void DrawEllipse();
void CheckOverlaping(Point2f mousePos);
void DeleteEllipse();

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
