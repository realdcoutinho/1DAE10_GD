#include "pch.h"
//#include <boost/lexical_cast.hpp>
#include "Game.h"
#include <cmath>
#include <stdio.h>      /* printf */
#include <math.h>       /* atan2 */
#include <iostream>
#include <sstream>

#define PI 3.14159265


//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	TestVectorToString();
	TestDotProduct();
	TestCrossProduct();

	TestLenght();
	TestNormalize();
	TestScalar();
	TestAngleBetween();
	TestAreEqual();


	

}

void Draw()
{
	ClearBackground(0, 0, 0);
	TestDrawVector();
	TestAddVector();
	TestSubtractVector();

	MovingVector();

	// Put your own draw statements here


	//DrawVector(g_VectorTwo, g_PointTwo);
	//DrawVector(g_VectorThree, g_PointThree);

	//Point2f startPoint{ g_VectorFour.x, g_VectorFour.y };
	//DrawVector(g_VectorTwo, startPoint);

	//Vector2f sum = Add(g_VectorTwo, g_VectorThree);
	//Point2f startPoint2{ g_PointThree.x + g_VectorThree.x, g_PointThree.y + g_VectorThree.y };
	//DrawVector(sum, startPoint2);

}

void Update(float elapsedSec)
{
	g_VectorAngle += g_Speed * elapsedSec;
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
// Define your own functions here
void MovingVector()
{

	const float vectorLength{ 70.0f };
	Point2f center{ g_WindowWidth / 2, g_WindowHeight / 2 };
	Point2f coordinates{ GetCoordinatesFromRadians(vectorLength, ConvertDegreesToRadians(g_VectorAngle)) };
	Vector2f vector{ coordinates.x, coordinates.y };
	DrawVector(vector, center);

	Vector2f toNormalize{ 50.0f, 90.0f };
	Vector2f normalized{ Normalize(toNormalize) };
	float dotProduct{ DotProduct(vector, normalized) };
	Vector2f projection{ Scalar(normalized, dotProduct) };
	DrawVector(projection, center);

}

void TestDrawVector() {

	SetColor(0, 1, 0, 1);
	Vector2f vectorOne{ 120, 70 };
	Point2f pointOne{ 60, 20 };
	Point2f pointTwo{ 30, 30 };
	DrawVector(vectorOne); // from origin
	DrawVector(vectorOne, pointOne);
	DrawVector(vectorOne, pointTwo);
}

void TestVectorToString()
{
	Vector2f vectorOne{ 120, 70 };
	Vector2f vector{ vectorOne };
	std::cout << ToString(vector) << std::endl;
	std::cout << std::endl;
}

void TestAddVector()
{
	Vector2f vectorOne{ 100, 30 };
	Vector2f vectorTwo{ 40, 75 };
	Vector2f addedVector{ Add(vectorOne, vectorTwo) };
	Point2f startingPoint{ 300, 30 };
	DrawVector(vectorOne, startingPoint);
	DrawVector(vectorTwo, Transform(vectorOne, startingPoint));
	DrawVector(addedVector, startingPoint);

}

void TestSubtractVector()
{
	Vector2f vectorOne{ 60, 60 };
	Vector2f vectorTwo{ 40, 10 };
	Vector2f subVector{ Subtract(vectorOne, vectorTwo) };
	Point2f startingPoint{ 20, 180  };
	DrawVector(vectorOne, startingPoint);
	DrawVector(vectorTwo, startingPoint);
	DrawVector(subVector, Transform(vectorTwo, startingPoint));

}

void TestDotProduct()
{
	Vector2f vectorOne{ 80.0f, 0.0f };
	Vector2f vectorTwo{ 0.0f, 50.0f };
	float dotProductResult{ DotProduct(vectorOne, vectorTwo) };
	std::cout << "hor = " << ToString(vectorOne) << "\tver = " << ToString(vectorTwo) << "\tDot Product: " << std::to_string(dotProductResult) << '\n';
	Vector2f parallel{ 0.0f, 25.0f };
	dotProductResult = DotProduct(vectorTwo, parallel);
	std::cout << "hor = " << ToString(vectorTwo) << "\tver = " << ToString(parallel) << "\tDot Product: " << std::to_string(dotProductResult) << '\n';
	std::cout << '\n';
}

void TestCrossProduct()
{
	Vector2f vectorOne{ 80.0f, 0.0f };
	Vector2f vectorTwo{ 0.0f, 50.0f };
	float crossProductResult{ CrossProduct(vectorOne, vectorTwo) };
	std::cout << "hor = " << ToString(vectorOne) << "\tver = " << ToString(vectorTwo) << "\tCross Product: " << std::to_string(crossProductResult) << '\n';

	float crossProductResultTwo{ CrossProduct(vectorTwo, vectorOne) };
	std::cout << "hor = " << ToString(vectorOne) << "\tver = " << ToString(vectorTwo) << "\tCross Product: " << std::to_string(crossProductResultTwo) << '\n';
}

void TestLenght()
{
	Vector2f vectorOne{ 100, 30 };
	float vectorLenght{ Lenght(vectorOne) };

	std::cout << '\n';
	std::cout << "Lenght of " << ToString(vectorOne) << " is " << vectorLenght << '\n';
	std::cout << '\n';
}

void TestNormalize()
{
	Vector2f vectorOne{ 100.0f, 3.0f };
	Vector2f normalizeVector{ Normalize(vectorOne) };
	float vectorLenght{ Lenght(vectorOne) };

	std::cout << "Normalized " << ToString(vectorOne) << " is " << ToString(normalizeVector) << " its lenght is: " << vectorLenght;
	std::cout << '\n';
}

void TestScalar()
{
	Vector2f vectorOne{ 100.0f, 3.0f };
	float scale{ 0.1f };
	Vector2f scaledVector{ Scalar(vectorOne, scale) };
	std::cout << '\n';
	std::cout << "Scaled " << ToString(vectorOne) << " is " << ToString(scaledVector) << " its scale is: " << scale;
	std::cout << '\n';

}

void TestAngleBetween()
{
	Vector2f vectorA{ 10.0f, 0.0f };
	Vector2f vectorB{ 10.0f, 10.0f };
	float angle{ AngleBetween(vectorA, vectorB) };
	std::cout << '\n';
	std::cout << "Angle between " << ToString(vectorA) << " and " << ToString(vectorB) << " is: "
		<< std::to_string(angle) << ", or " << std::to_string(angle * 180 / PI) << " degrees." << std::endl;
	std::cout << std::endl;
}

void TestAreEqual()
{
	Vector2f vectorA{ 10.0f, 0.0f };
	Vector2f vectorB{ 10.0f, 0.0f };
	bool areEqual{ AreEqual(vectorA, vectorB) };
	std::cout << areEqual << std::endl;
	vectorA = Vector2f{ 10.0f, 0.0f };
	vectorB = Vector2f{ 0.0f, 10.0f };
	areEqual = AreEqual(vectorA, vectorB);
	std::cout << areEqual << std::endl;
	vectorA = Vector2f{ 10.0f, 0.0f };
	vectorB = Vector2f{ -10.0f, 0.0f };
	areEqual = AreEqual(vectorA, vectorB);
	std::cout << areEqual << std::endl;
	std::cout << std::endl;
}
#pragma endregion ownDefinitions