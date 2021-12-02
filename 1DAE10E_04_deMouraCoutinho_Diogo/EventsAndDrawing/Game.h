#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "EventsAndDrawing - deMouraCoutinho, Diogo - 1DAE10E" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
float g_NrFrames	{};
bool g_Pressed		{};
float g_border		{ 50 };

int mouseX{};
int mouseY{};

bool g_FlipStartLineX{ false };
bool g_FlipStartLineY{ false };
bool g_FlipEndLineX{ false };
bool g_FlipEndLineY{ false };


Point2f g_Start;
Point2f g_End;


Color4f g_red		(1, 0, 0, 1);
Color4f g_green(0, 1, 0, 1);
Color4f g_grey		(0.5f, 0.5f, 0.5f, 1);

Color4f g_Square;
Rectf g_RandomRect	{};


// Declare your own functions here
void InitialBorder();
void GenerateRect();
void DrawRect();
bool IsSquareClicked(float mouseX, float mouseY);


float GenerateRandomFloat(float min, float range);

void GenerateLine();
void DrawLine();


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
