#include "pch.h"
#include "Sprite.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	InitialiseSprites(g_pSpritesKnights, g_AmountOfKnights, g_FilePathKnight, 8, 1, 8, g_speedKnight, 3, g_isScalable);
	InitialiseSprites(g_pSpritesTibos, g_AmountOfTibos, g_FilePathTibo, 5, 5, 25, g_speedTibo, 1, g_notScalabe);
	InitialiseSprites(g_pSpritesDAE, g_AmountOfDAE, g_FilePathDAE, 1, 1, 1, g_speedDAE, 2, g_notScalabe);
	InitialiseSpritesText(g_pSpritesHello, g_AmountOfHello, g_FilePathHello, g_Hello, g_textSize, g_Red);

}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawSprites(g_pSpritesKnights, g_AmountOfKnights, g_knightPos, g_isScalable, 2);
	DrawSprites(g_pSpritesTibos, g_AmountOfTibos, g_tiboPos, g_notScalabe);
	DrawSprites(g_pSpritesDAE, g_AmountOfDAE, g_daePos, g_notScalabe);
	DrawSpritesText(g_pSpritesHello, g_AmountOfHello, g_helloPos);

}

void Update(float elapsedSec)
{
	UpdateSprites(g_pSpritesKnights, g_AmountOfKnights, elapsedSec);
	UpdateSprites(g_pSpritesTibos, g_AmountOfTibos, elapsedSec);
	
	BoucingSprite(g_pSpritesHello, g_AmountOfHello, g_helloPos, elapsedSec, g_bouncingSpeed); //Does work as intended yet
}
void End()
{
	// free game resources here
	DeleteSprites(g_pSpritesKnights, g_AmountOfKnights);
	DeleteSprites(g_pSpritesTibos, g_AmountOfTibos);
	DeleteSprites(g_pSpritesDAE, g_AmountOfDAE);
	DeleteSprites(g_pSpritesHello, g_AmountOfHello);

}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_LEFT:
		g_knightPos.x -= 10;
		break;
	case SDLK_RIGHT:
		g_knightPos.x += 10;

		break;
	case SDLK_UP:
		g_knightPos.y += 10;
		break;
	case SDLK_DOWN:
		g_knightPos.y -= 10;
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
void InitialiseSprites(Sprite* pSprite[], int indexMax, const std::string& filePath, int nrCols, int nrRows, int nrOfFrames, float frameSec, float scale, bool scalable)
{
	for (int i{ 0 }; i < indexMax; ++i)
	{
		if (scalable)
		{
			pSprite[i] = new Sprite{ filePath, nrCols, nrRows, nrOfFrames, frameSec, i * scale };
		}
		else
		{
			pSprite[i] = new Sprite{ filePath, nrCols, nrRows, nrOfFrames, frameSec, scale };
		}

	}
}

void InitialiseSpritesText(Sprite* pSprite[], int indexMax, const std::string& filePath, std::string& text, int textSize, Color4f textColor)
{
	for (int i{ 0 }; i < indexMax; ++i)
	{
			pSprite[i] = new Sprite{ text, filePath, textSize, textColor };

	}
}


void DrawSprites(Sprite* pSprite[], int index, Point2f pos, bool scalable, float scale)
{
	if(scalable)
	{
		for (int i{ 0 }; i < index; ++i)
		{
			pos.x += pSprite[i]->GetFrameWidth();
			pSprite[i]->Draw(Point2f{ pos });
		}
	}
	else {
		for (int i{ 0 }; i < index; ++i)
		{
			pSprite[i]->Draw(Point2f{ pos });
			pos.x += pSprite[i]->GetFrameWidth() + 10;
		}
	}
}

void DrawSpritesText(Sprite* pSprite[], int index, Point2f pos)
{
	for (int i{ 0 }; i < index; ++i)
	{
		pSprite[i]->DrawText(Point2f{ pos });
		pos.x += pSprite[i]->GetFrameWidth() + pSprite[i]->GetFrameWidth()/30;
	}
}


void UpdateSprites(Sprite* pSprite[], int index, float elapsed)
{
	for (int i{ 0 }; i < index; ++i)
	{
		pSprite[i]->Update(elapsed);
	}
}

void DeleteSprites(Sprite* pSprite[], int index)
{
	for (int i{}; i < index; ++i)
	{
		delete pSprite[i];
		pSprite[i] = nullptr;
	}
}

void BoucingSprite(Sprite* pSprite[], int index, Point2f pos, float elapsed, float speed) //in the makiing
{
	float width = pSprite[0]->GetFrameWidth();
	float totalWidth = width * index; 	//- (width /30) * (index-1);
	float height = pSprite[0]->GetFrameHeight();

	if (g_helloPos.x + totalWidth >= g_WindowWidth)
	{
		g_PositiveDirectionX = false;
	}
	if (g_helloPos.x <= 0)
	{
		g_PositiveDirectionX = true;
	}

	if (g_helloPos.y + height >= g_WindowHeight)
	{
		g_PositiveDirectionY = false;
	}
	if (g_helloPos.y <= 0)
	{
		g_PositiveDirectionY = true;
	}
	if (g_PositiveDirectionX == true)
	{
		g_helloPos.x += speed * elapsed;
	}
	else
	{
		g_helloPos.x -= speed * elapsed;
	}

	if (g_PositiveDirectionY == true)
	{
		g_helloPos.y += speed * elapsed;
	}
	else
	{
		g_helloPos.y -= g_bouncingSpeed * elapsed;
	}
}

#pragma endregion ownDefinitions