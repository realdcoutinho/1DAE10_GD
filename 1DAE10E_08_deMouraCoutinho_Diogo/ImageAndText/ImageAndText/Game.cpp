//Shergelashvili, Mariam - 1DAE11
#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	LoadTextures();
}

void Draw()
{
	ClearBackground(0,0,0.3f);
	DrawTextures();

}

void Update(float elapsedSec)
{
	// process input, do physics 

	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
}

void End()
{
	// free game resources here
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	////std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//{
	//	//std::cout << "Left mouse button released\n";
	//	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	//	break;
	//}
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
void LoadTextures()
{
	bool load;
	load = TextureFromFile("resources/DAE.png", g_Image);

	int fontSize = 40;
	Color4f fontColor{ 1,1,0,1 };
	load = TextureFromString("Hello world!", "resources/DIN-Light.otf",fontSize, fontColor, g_Text);
}

void DrawTextures()
{	
	Point2f position{};
	float margin{ 10 };

	position = {margin, g_WindowHeight-margin-g_Image.height};
	DrawTexture(g_Image, position);

	position.y -= g_Image.height;
	DrawTexture(g_Text,position);
}
#pragma endregion ownDefinitions


//#using namespace utils
//
//
//Texture g_Text;
//float g_Scale{ 0.5f };
//
//
//
//TextureFromString("Text to print", "resources/DIN-Light.otf", int fontSize, Color4f, g_Text);
//
//
//
//float border{ 10 };
//Rectf destRect{ border, border, 70, 20 };
//Rectf destRect{ border, border, g_Scale * g_Image.width, g_Scale * g_Image.height };
//DrawTexture(g_Image, destRect);
//
//DrawTexture(g_Text, position);
//
//DeleteTexture(g_Image);
//DeleteTexture(g_Text);