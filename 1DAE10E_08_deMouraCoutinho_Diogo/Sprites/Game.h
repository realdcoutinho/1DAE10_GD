#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Sprites - deMouraCoutinho, Diogo - 1DAE10E" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
float g_border{ 10.0f };
float g_scale{ 5.0f };

float g_KnightPositionHorizontal{};
float g_KnightPositionVertical{ 0.0f };
float g_KnightSpeed{15.0f};

//float g_TiboPositionHorizontal{};
//float g_TiboPositionVertical{};
//float g_TiboSpeed{ 15.0f };

struct Sprite
{
	Texture texture;
	int frames;
	int cols;
	float frameTime;
	int currentFrame;
	float accumaltedTime;
};


Sprite g_KnightSprite{};
//Sprite g_TiboSprite{};
// Declare your own functions here
void InitKnight();
void UpdateKnight(float elapseSec);
void DrawKnight();

//void InitTibo();
//void UpdateTibo(float elapseSec);
//void DrawTibo();


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
