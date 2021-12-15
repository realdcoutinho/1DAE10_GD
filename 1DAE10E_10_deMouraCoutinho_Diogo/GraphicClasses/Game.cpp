#include "pch.h"
#include "Game.h"
#include "Fraction.h"
#include "Light.h"
#include "DaeEllipse.h"

#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	CreateFunctions();
	PrintFractionsSum();
	CreateLights();
	CreateEllipse();
}

void Draw()
{
	
	ClearBackground();
	// Put your own draw statements here

	DrawFractions();
	DrawLights();
	DrawEllipse();
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
	DeleteFractions();
	DeleteLights();
	DeleteEllipse();
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

	Point2f mousePos{ float(e.x), float(g_WindowHeight - e.y) };
	CheckOverlaping(mousePos);
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };

	MouseClicks(mousePos);
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
void CreateFunctions()
{
	g_pFraction1 = new Fraction{3, 5};
	g_pFraction2 = new Fraction{ 4, 6 };
	g_pFraction3 = new Fraction{ 5, 5 };
	g_pFraction4 = new Fraction{ 1, 3 };
	g_pFraction5 = new Fraction{ 4, 4 };
	g_pFraction6 = new Fraction{ 1, 2 };
}

void PrintFractionsSum()
{
	float sum{};
	sum += g_pFraction1->GetValue();
	sum += g_pFraction2->GetValue();
	sum += g_pFraction3->GetValue();
	sum += g_pFraction4->GetValue();
	sum += g_pFraction5->GetValue();
	sum += g_pFraction6->GetValue();

	std::cout << "Total value of created Fraction objects: " << sum << '\n';
}
void DrawFractions()
{
	float size{ 20 };
	Point2f one{ 10, 10 };
	Point2f two{ 10, 40 };
	Point2f three{ 10, 70 };
	Point2f four{ 10, 100 };
	Point2f five{ 10, 130 };
	Point2f six{ 10, 160 };

	g_pFraction1->Draw(one, size);
	g_pFraction2->Draw(two, size);
	g_pFraction3->Draw(three, size);
	g_pFraction4->Draw(four, size);
	g_pFraction5->Draw(five, size);
	g_pFraction6->Draw(six, size);
}

void DeleteFractions()
{
	delete g_pFraction1;
	g_pFraction1 = nullptr;
	delete g_pFraction2;
	g_pFraction2 = nullptr;
	delete g_pFraction3;
	g_pFraction3 = nullptr;
	delete g_pFraction4;
	g_pFraction4 = nullptr;
	delete g_pFraction5;
	g_pFraction5 = nullptr;
	delete g_pFraction6;
	g_pFraction6 = nullptr;
}

void CreateLights()
{
	float height{ 40 };
	float difference{ 10 };
	float width{};

	for (int row{ 0 }; row < g_Rows; row++)
	{
		width = 0;
		for (int column{ 0 }; column < g_Columns; column++)
		{

			float x{200 + (width  * column) + (difference * column) };
			float y{ 10 + (row * height) + (row * difference) };
			Point2f pOne{ x, y };
			width = GetRandomFloat(30, 60) ;
			Rectf rect{ pOne.x, pOne.y, width, height };
			int index{ GetIndex(row, column, g_Columns) };

			g_RectsArray[index] = rect;

		}
	}

	Color4f color{ GetRandomColour() };

	g_pLight1 = new Light{ g_RectsArray[0], color };
	g_pLight2 = new Light{ g_RectsArray[1], color };
	g_pLight3 = new Light{ g_RectsArray[2], color };
	g_pLight4 = new Light{ g_RectsArray[3], color };
	g_pLight5 = new Light{ g_RectsArray[4], color };
	g_pLight6 = new Light{ g_RectsArray[5], color };
	g_pLight7 = new Light{ g_RectsArray[6], color };
	g_pLight8 = new Light{ g_RectsArray[7], color };
}

void DrawLights()
{
	for (int i{}; i < g_RectArraySize; ++i) {
		DrawRect(g_RectsArray[i]);
	}

	g_pLight1->Draw();
	g_pLight2->Draw();
	g_pLight3->Draw();
	g_pLight4->Draw();
	g_pLight5->Draw();
	g_pLight6->Draw();
	g_pLight7->Draw();
	g_pLight8->Draw();
}


void MouseClicks(Point2f mousePos)
{
	g_pLight1->IsHit(mousePos);
	g_pLight1->IsOn();
	g_pLight2->IsHit(mousePos);
	g_pLight2->IsOn();
	g_pLight3->IsHit(mousePos);
	g_pLight3->IsOn();
	g_pLight4->IsHit(mousePos);
	g_pLight4->IsOn();
	g_pLight5->IsHit(mousePos);
	g_pLight5->IsOn();
	g_pLight6->IsHit(mousePos);
	g_pLight6->IsOn();
	g_pLight7->IsHit(mousePos);
	g_pLight7->IsOn();
	g_pLight8->IsHit(mousePos);
	g_pLight8->IsOn();
}

int GetIndex(int rowIndex, int columnIndex, int nrOfColumns)
{
	return rowIndex * nrOfColumns + columnIndex;
}

void DeleteLights()
{
	delete g_pLight1;
	g_pLight1 = nullptr;
	delete g_pLight2;
	g_pLight2 = nullptr;
	delete g_pLight3;
	g_pLight3 = nullptr;
	delete g_pLight4;
	g_pLight4 = nullptr;
	delete g_pLight5;
	g_pLight5 = nullptr;
	delete g_pLight6;
	g_pLight6 = nullptr;
	delete g_pLight7;
	g_pLight7 = nullptr;
	delete g_pLight8;
	g_pLight8 = nullptr;

}


void CreateEllipse()
{
	const Color4f color1 {GetRandomColour() };
	const Color4f color2{ GetRandomColour() };
	const Color4f color3{ GetRandomColour() };

	const Point2f center1 { 400, 130};
	const Point2f center2{ 50, 150 };
	const Point2f center3{ 250, 220 };
	
	g_pDaeEllipse1 = new DaeEllipse{ center1, 30, 70, color1 };
	g_pDaeEllipse2 = new DaeEllipse{ center2, 50, 20, color2 };
	g_pDaeEllipse3 = new DaeEllipse{ center3, 20, 80, color3 };
}

void DrawEllipse()
{
	g_pDaeEllipse1->Draw();
	g_pDaeEllipse2->Draw();
	g_pDaeEllipse3->Draw();
}

void CheckOverlaping(Point2f mousePos)
{
	g_pDaeEllipse1->ActiveTest(mousePos);
	g_pDaeEllipse2->ActiveTest(mousePos);
	g_pDaeEllipse3->ActiveTest(mousePos);
}

void DeleteEllipse()
{
	delete g_pDaeEllipse1;
	g_pDaeEllipse1 = nullptr;
	delete g_pDaeEllipse2;
	g_pDaeEllipse2 = nullptr;
	delete g_pDaeEllipse3;
	g_pDaeEllipse3 = nullptr;
}

#pragma endregion ownDefinitions