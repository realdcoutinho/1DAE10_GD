#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	InitKnight();
	InitTibo();
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawKnight();
	DrawTibo();
}

void Update(float elapsedSec)
{

	UpdateKnight(elapsedSec);
	UpdateTibo(elapsedSec);
	//g_TiboPositionHorizontal += g_TiboSpeed * elapsedSec;
}

void End()
{
	// free game resources here
	DeleteTexture(g_KnightSprite.texture);
	DeleteTexture(g_TiboSprite.texture);
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{
		switch (key)
	{
	case SDLK_LEFT:
		g_KnightPositionHorizontal -= g_KnightSpeed;
		g_IsLeftPressed = true;
		g_IsRightPressed =  false;
		break;
	case SDLK_RIGHT:
		g_KnightPositionHorizontal += g_KnightSpeed;
		g_IsLeftPressed = false;
		g_IsRightPressed = true;
		break;
	case SDLK_UP:
		g_KnightPositionVertical += g_KnightSpeed;
		break;
	case SDLK_DOWN:
		g_KnightPositionVertical -= g_KnightSpeed;
		break;
	}
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
// Define your own functions here
void InitKnight()
{
	bool succesfull{ TextureFromFile("Resources/Sprites/RunningKnight.png", g_KnightSprite.texture) };
	if (!succesfull) std::cout << "Loading PNG Failed";
	else {
		std::cout << "It was good!" << '\n';
	}

	g_KnightSprite.cols = 8;
	g_KnightSprite.frames = 8;
	g_KnightSprite.currentFrame = 0;
	g_KnightSprite.accumaltedTime = 0.0f;
	g_KnightSprite.frameTime = 1 / 10.0f;

}

void UpdateKnight(float elapseSec)
{
	g_KnightSprite.accumaltedTime += elapseSec;
	if (g_KnightSprite.accumaltedTime > g_KnightSprite.frameTime)
	{
		//Determine next frame number
		++g_KnightSprite.currentFrame %= g_KnightSprite.frames;
		g_KnightSprite.accumaltedTime -= g_KnightSprite.frameTime;
	}
}

void DrawKnight()
{
	//Part of texture that corresponds with the curretn frame number
	Rectf srcRect{};
	if (g_IsLeftPressed) {

	}
	if (g_IsRightPressed) {

	}

	srcRect.width = (g_KnightSprite.texture.width / g_KnightSprite.cols);
	srcRect.height = g_KnightSprite.texture.height;
	srcRect.left = g_KnightSprite.currentFrame * srcRect.width;
	srcRect.bottom = srcRect.height;

	//Draw it at the top of the window
	const float scale{ 5.0f };
	const float border{ 10.0f };
	Rectf destRect{};
	destRect.left = g_KnightPositionHorizontal;
	destRect.bottom = g_KnightPositionVertical;
	destRect.width = srcRect.width * scale;
	destRect.height = srcRect.height * scale;


	DrawTexture(g_KnightSprite.texture, destRect, srcRect);
}




void InitTibo()
{
	bool succesfull{ TextureFromFile("Resources/Sprites/Tibo.png", g_TiboSprite.texture) };
	if (!succesfull) std::cout << "Loading PNG Failed";
	else {
		std::cout << "It was good!" << '\n';
	}

	g_TiboSprite.cols = 5;
	g_TiboSprite.rows = 5;
	g_TiboSprite.frames = 25;
	g_TiboSprite.currentFrame = 0;
	g_TiboSprite.accumaltedTime = 0.0f;
	g_TiboSprite.frameTime = 1 / 15.0f;



}

void UpdateTibo(float elapseSec)
{
	g_TiboSprite.accumaltedTime += elapseSec;
	if (g_TiboSprite.accumaltedTime > g_TiboSprite.frameTime)
	{
		//Determine next frame number
		++g_TiboSprite.currentFrame %= g_TiboSprite.frames;
		g_TiboSprite.accumaltedTime -= g_TiboSprite.frameTime;
	}



}

void DrawTibo()
{
	//Part of texture that corresponds with the curretn frame number
	Rectf srcRect{};
	srcRect.width = g_TiboSprite.texture.width / g_TiboSprite.cols;
	srcRect.height = g_TiboSprite.texture.height / g_TiboSprite.rows;
	srcRect.left = (float)((g_TiboSprite.currentFrame % g_TiboSprite.cols) * srcRect.width);
	srcRect.bottom = (float)((g_TiboSprite.currentFrame / g_TiboSprite.cols + 1) * srcRect.height);

	//Draw it at the top of the window
	const float scale{ 1.0f };
	const float border{ 10.0f };
	Rectf destRect{};
	destRect.width = srcRect.width * scale;
	//destRect.height = g_TiboSprite.texture.height / (g_TiboSprite.frames/ g_TiboSprite.cols);
	destRect.height = srcRect.width * scale;
	destRect.left = 0;
	destRect.bottom = 0;


	DrawTexture(g_TiboSprite.texture, destRect, srcRect);



}

#pragma endregion ownDefinitions