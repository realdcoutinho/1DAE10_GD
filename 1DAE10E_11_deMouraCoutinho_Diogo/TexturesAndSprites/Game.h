#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "TexturesAndSprites - deMouraCoutinho, firstname - 1DAE10E" };

// Change the window dimensions here
float g_WindowWidth{ 1000 };
float g_WindowHeight{ 600 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

class Sprite; // Class forward declaration

const int g_AmountOfKnights{ 3 };
Sprite* g_pSpritesKnights[g_AmountOfKnights];

const int g_AmountOfTibos{ 3 };
Sprite* g_pSpritesTibos[g_AmountOfTibos];

const int g_AmountOfDAE{ 2 };
Sprite* g_pSpritesDAE[g_AmountOfDAE];

const int g_AmountOfHello{ 6 };
Sprite* g_pSpritesHello[g_AmountOfHello];
std::string g_Hello{ "Hello World" };
int g_textSize{ 20 };


const std::string g_FilePathKnight{ "Sprites/RunningKnight.png" };
const std::string g_FilePathTibo{ "Sprites/Tibo.png" };
const std::string g_FilePathDAE{ "Sprites/DAE.png" };
const std::string g_FilePathHello{ "Sprites/DIN-Light.otf" };

float g_speedKnight{ 1 / 20.0f };
float g_speedTibo{ 1 / 10.0f };
float g_speedDAE{ 1 / 10.0f };


Point2f g_knightPos{ 0, 0 };
Point2f g_tiboPos{ 300, 0 };
Point2f g_daePos{ 100, 200 };
Point2f g_helloPos{ 50, 400 };

Color4f g_Red{ 1,0,0,1 };

bool g_isScalable{ true };
bool g_notScalabe{ false };



//TEST PRACTISE
bool g_PositiveDirectionX{ true };
bool g_PositiveDirectionY{ true };
const float g_bouncingSpeed{ 100.0 };
float g_elapsedSec{};

// Declare your own functions here
void InitialiseSprites(Sprite* pSprite[], int indexMax, const std::string& filePath, int nrCols, int nrRows, int nrOfFrames, float frameSec, float scale, bool scalable);
void InitialiseSpritesText(Sprite* pSprite[], int indexMax, const std::string& filePath, std::string& text, int textSize, Color4f textColor);

void DrawSprites(Sprite* pSprite[], int index, Point2f pos, bool scalable = 0, float scale = 1);
void DrawSpritesText(Sprite* pSprite[], int index, Point2f pos);
void UpdateSprites(Sprite* pSprite[], int index, float elapsed);
void DeleteSprites(Sprite* pSprite[], int index);

void BoucingSprite(Sprite* pSprite[], int index, Point2f pos, float elapsed, float speed);

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
