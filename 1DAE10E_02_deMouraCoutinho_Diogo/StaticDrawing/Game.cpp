#include "pch.h"
#include "Game.h"
#define _USE_MATH_DEFINES
#include <cmath>
//include <math.h>
#include <time.h>



#pragma region Drawings


#pragma endregion Drawings



//Basic game functions
#pragma region gameFunctions											

void Start()
{
	// initialize game resources here





}










void Draw()
{
	ClearBackground(51 / 255.0f, 17 / 255.0f, 36 / 255.0f);
	DrawHouse();
	DrawFlag();
	DrawChekerPattern();
	DrawColorBand();
	DrawPentagram();

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
// Define your own functions here
void DrawHouse()
{
	const float oneUnit = g_WindowWidth / 40;



	// variables for white border 
	// variables for red House
	float house_leftBorder = oneUnit; // same for all
	float house_bottomBorder = oneUnit * 29;
	float houseWidth = oneUnit * 18;
	float houseHeigh = oneUnit * 6;

	//variables for Triangles roof
	const float roof_P1X = oneUnit;
	//const float roof_P1Y = 


	SetColor(255 / 255.0f, 0 / 255.0f, 0 / 255.0f, 255 / 255.0f); //red
	FillRect(house_leftBorder, house_bottomBorder, houseWidth, houseHeigh); //border

	SetColor(255 / 255.0f, 255 / 255.0f, 255 / 255.0f, 255 / 255.0f); //white
	DrawRect(house_leftBorder, house_bottomBorder, houseWidth, houseHeigh); //border





}

void DrawFlag() {

	const float oneUnit = g_WindowWidth / 40;



	// variables for white border 
	// variables for black fill
	float leftBorder = oneUnit; // same for all
	float bottomBorder = oneUnit * 14;
	float flagWidth = oneUnit * 18;
	float flagHeigh = oneUnit * 14;

	// variables for yellow area
	float yellowBorder_left = oneUnit * 7;
	float yellowBorder_bottom = oneUnit * 14;
	float yellowWidth = oneUnit * 12;
	float yellowHeigh = oneUnit * 14;

	//variables for red area
	float redBorder_left = oneUnit * 13;
	float redBorder_bottom = oneUnit * 14;
	float redWidth = oneUnit * 6;
	float redHeigh = oneUnit * 14;


	SetColor(0 / 255.0f, 0 / 255.0f, 0 / 255.0f, 255 / 255.0f);// black
	FillRect(leftBorder, bottomBorder, flagWidth, flagHeigh); // black area

	SetColor(255 / 255.0f, 255 / 255.0f, 0 / 255.0f, 255 / 255.0f);// yellow
	FillRect(yellowBorder_left, yellowBorder_bottom, yellowWidth, yellowHeigh); // red

	SetColor(255 / 255.0f, 0 / 255.0f, 0 / 255.0f, 255 / 255.0f);// yellow
	FillRect(redBorder_left, redBorder_bottom, redWidth, redHeigh); // red area


	SetColor(255 / 255.0f, 255 / 255.0f, 255 / 255.0f, 255 / 255.0f); //white
	DrawRect(leftBorder, bottomBorder, flagWidth, flagHeigh); //border


}

void DrawChekerPattern() {

	const float oneUnit = g_WindowWidth / 40;
	const float checkers_Measure = oneUnit * 4;


	//variables for white border
	//variables for black background
	float leftBorder_Checkers = oneUnit;
	float bottomBorder_Checkers = oneUnit;
	float checkersHeight = oneUnit * 12;
	float checkersWidthh = oneUnit * 12;

	//variables for first white square /// LEFT LEFT LEFT
	float leftBorder_Checkers_left = oneUnit;
	float bottomBorder_Checkers_left = oneUnit * 5;
	//float checkersHeight_White_left = oneUnit * 4;
	//float checkersWidth_White_left = oneUnit * 4;

	// variables for the second white square counting from the right //// TOP TOP TOP
	float leftBorder_Checkers_top = oneUnit * 5;
	float bottomBorder_Checkers_top = oneUnit * 9;
	//float checkersHeight_White_top = oneUnit * 4;
	//float checkersWidth_White_top = oneUnit * 4;

	//Variables for third square // BOTTOM BOTTOM BOTTOM
	float leftBorder_Checkers_bottom = oneUnit * 5;
	float bottomBorder_Checkers_bottom = oneUnit;
	//float checkersHeight_White_bottom = oneUnit * 4;
	//float checkersWidth_White_bottom = oneUnit * 4;

	//Variabels for fourth square // RIGHT RIGHT RIGHT
	float leftBorder_Checkers_right = oneUnit * 9;
	float bottomBorder_Checkers_right = oneUnit * 5;
	//float chekcersHieght_White_right = oneUnit * 4;
	//float checkersWidth_White_right = oneUnit * 4;



	SetColor(0 / 255.0f, 0 / 255.0f, 0 / 255.0f, 255 / 255.0f); //black
	FillRect(leftBorder_Checkers, bottomBorder_Checkers, checkersHeight, checkersWidthh); // black background


	SetColor(255 / 255.0f, 255 / 255.0f, 255 / 255.0f, 255 / 255.0f); //white
	FillRect(leftBorder_Checkers_left, bottomBorder_Checkers_left, checkers_Measure, checkers_Measure); // LEFT white square
	FillRect(leftBorder_Checkers_top, bottomBorder_Checkers_top, checkers_Measure, checkers_Measure); // TOP white square
	FillRect(leftBorder_Checkers_bottom, bottomBorder_Checkers_bottom, checkers_Measure, checkers_Measure); // BOTTOM white square
	FillRect(leftBorder_Checkers_right, bottomBorder_Checkers_right, checkers_Measure, checkers_Measure); // RIGHT white square
	DrawRect(leftBorder_Checkers, bottomBorder_Checkers, checkersHeight, checkersWidthh); //white border
}

void DrawColorBand() {

	const float oneUnit = g_WindowWidth / 40;
	const float band_width = oneUnit * 2;
	const float band_height = oneUnit * 10;
	const float band_bottom = oneUnit * 29;

	//variables for the box border
	float leftBorder_Band = oneUnit * 21;
	float bottomBorder_Band = oneUnit * 29;
	float bandWidth = oneUnit * 18;
	float bandHeight = oneUnit * 10;

	//black band stripe
	float blackBand_height = oneUnit * 5;


	//variables for dark grey band
	float darkGrey_left = oneUnit * 21;

	//varaibles for red band
	float red_left = oneUnit * 23;

	//variables for green band
	float green_left = oneUnit * 25;

	//variables for blue band
	float blue_left = oneUnit * 27;

	//float for pink band
	float pink_left = oneUnit * 29;

	//float for yellow band
	float yellow_left = oneUnit * 31;

	//variables for green band 02
	float green_02_left = oneUnit * 33;

	//variables for baby blue band
	float babyBlue_left = oneUnit * 35;

	//variables for white band
	float white_left = oneUnit * 37;


	SetColor(127 / 255.0f, 127 / 255.0f, 127 / 255.0f, 255 / 255.0f); //grey
	FillRect(darkGrey_left, band_bottom, band_width, band_height); // darkb grey band

	SetColor(255 / 255.0f, 0 / 255.0f, 0 / 255.0f, 255 / 255.0f); //red
	FillRect(red_left, band_bottom, band_width, band_height); // red band

	SetColor(0 / 255.0f, 255 / 255.0f, 0 / 255.0f, 255 / 255.0f); //green
	FillRect(green_left, band_bottom, band_width, band_height); //green band

	SetColor(0 / 255.0f, 0 / 255.0f, 255 / 255.0f, 255 / 255.0f); //blue
	FillRect(blue_left, band_bottom, band_width, band_height); //blue band

	SetColor(238 / 255.0f, 21 / 255.0f, 238 / 255.0f, 255 / 255.0f); //Pink
	FillRect(pink_left, band_bottom, band_width, band_height); //Pink band

	SetColor(243 / 255.0f, 240 / 255.0f, 19 / 255.0f, 255 / 255.0f); //Yellow
	FillRect(yellow_left, band_bottom, band_width, band_height); //Yellow band

	SetColor(0 / 255.0f, 255 / 255.0f, 0 / 255.0f, 255 / 255.0f); //pink
	FillRect(green_02_left, band_bottom, band_width, band_height); //Pink band

	SetColor(0 / 255.0f, 255 / 255.0f, 255 / 255.0f, 255 / 255.0f); //baby blue
	FillRect(babyBlue_left, band_bottom, band_width, band_height); //baby blue band

	SetColor(255 / 255.0f, 255 / 255.0f, 255 / 255.0f, 255 / 255.0f); //white
	FillRect(white_left, band_bottom, band_width, band_height); //baby blue band

	SetColor(0 / 255.0f, 0 / 255.0f, 0 / 255.0f, 150 / 255.0f); // black
	FillRect(leftBorder_Band, bottomBorder_Band, bandWidth, blackBand_height); //black band stripe


	SetColor(243 / 255.0f, 240 / 255.0f, 19 / 255.0f, 255 / 255.0f); //Yellow
	DrawRect(leftBorder_Band, bottomBorder_Band, bandWidth, bandHeight, 3.0f); //border





	SetColor(0 / 255.0f, 255 / 255.0f, 255 / 255.0f, 255 / 255.0f); //baby blue


}


void DrawPentagram() 
{
	Point2f center{650, g_WindowHeight / 2 };
	float radius{ 100.f };

	float angle = float(2 * M_PI)/5;
	Point2f p1{ center.x + radius * cos(angle),center.y + radius * sin(angle) };
	Point2f p2{ center.x + radius * cos(angle*2),center.y + radius * sin(angle * 2) };
	Point2f p3{ center.x + radius * cos(angle * 3),center.y + radius * sin(angle * 3) };
	Point2f p4{ center.x + radius * cos(angle * 4),center.y + radius * sin(angle * 4) };
	Point2f p5{ center.x + radius * cos(angle * 5),center.y + radius * sin(angle * 5) };

	DrawLine(p1, p3);
	DrawLine(p1, p4);
	DrawLine(p2, p5);
	DrawLine(p2, p4);
	DrawLine(p3, p5);


}
#pragma endregion ownDefinitions