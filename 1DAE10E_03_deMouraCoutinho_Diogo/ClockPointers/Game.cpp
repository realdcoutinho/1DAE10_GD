#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here


}

double Sin1(double angleY) { // angle between 0.0 and 1.0

	return sin(2.0 * angleY * M_PI);
} 
//////////////////////////////////////////// //////////////////////




float CosGf(float angleG_X) {

	return float(cos(-2.0 * angleG_X * M_PI));
}

float SinGf(float angleG_Y) {

	return float(sin(-2.0 * angleG_Y * M_PI));
}

float CosHf(float angleH_X) {

	return float(cos((-2.0 * angleH_X * M_PI)- 0.436332313f));
}

float SinHf(float angleH_Y) {

	return float(sin((-2.0 * angleH_Y * M_PI)- 0.436332313f));
}

float CosFf(float angleF_X) {

	return float(cos((-2.0 * angleF_X * M_PI) + 0.436332313f));
}

float SinFf(float angleF_Y) {

	return float(sin((-2.0 * angleF_Y * M_PI) + 0.436332313f));
}



float CosCf(float angleC_X) {

	return float(cos(-2.0 * angleC_X * M_PI));
}

float SinCf(float angleC_Y) {

	return float(sin(-2.0 * angleC_Y * M_PI));
}

float CosBf(float angleB_X) {
	return float(cos((-2.0 * angleB_X * M_PI)- 0.3490658504));
}
// SMALL POINTER POINT B X
float SinBf(float angleB_Y) {
	return float(sin((-2.0 * angleB_Y * M_PI)- 0.3490658504));
}
// SMALL POINTER POINT B Y
float CosDf(float angleD_X) {
	return float(cos((-2.0 * angleD_X * M_PI) + 0.3490658504));
}

float SinDf(float angleD_Y) {
	return float(sin((-2.0 * angleD_Y * M_PI) + 0.3490658504));

}







void Draw()
{
	ClearBackground();
	SmallPointer();
	LargerPointer();

	

}

void LargerPointer() {

	const int bigFrames{ 240 };

	const int maxG_XWidth{ 200 };
	const int maxG_YHeight{ 200 };

	const int maxFH_XWidth{ 80 };
	const int maxFH_YHeigh{ 80 };



	float angleG_X{ float(g_NrFrames) / bigFrames };
	float G_X{ g_middleWidth + maxG_XWidth * CosGf(angleG_X) }; // G_X

	float angleG_Y{ float(g_NrFrames) / bigFrames };
	float G_Y{ g_middleHeight + maxG_YHeight * SinGf(angleG_Y) }; // G_Y

	float angleH_X{ float(g_NrFrames) / bigFrames };
	float H_X{ g_middleWidth + maxFH_XWidth * CosHf(angleH_X) }; // H_X

	float angleH_Y{ float(g_NrFrames) / bigFrames };
	float H_Y{ g_middleHeight + maxFH_YHeigh * SinHf(angleH_Y) }; // H_Y

	SetColor(0.5f, 1, 1, 0.7f);
	DrawLine(g_middleWidth, g_middleHeight, H_X, H_Y, 3); // LINE EH

	float angleF_X{ float(g_NrFrames) / bigFrames };
	float F_X{ g_middleWidth + maxFH_XWidth * CosFf(angleF_X) }; // F_X

	float angleF_Y{ float(g_NrFrames) / bigFrames };
	float F_Y{ g_middleHeight + maxFH_YHeigh * SinFf(angleF_Y) }; // F_Y

	DrawLine(g_middleWidth, g_middleHeight, F_X, F_Y, 3); // LINE MIDDLE EG
	DrawLine(F_X, F_Y, G_X, G_Y, 3); // LINE FG
	DrawLine(H_X, H_Y, G_X, G_Y, 3); //LINE HG
}

void SmallPointer() {



	SetColor(0.5f, 1, 1, 0.7f);
	const int framesSmall{ 2880 }; // SMALL POINTER SPEED
	const int maxBD_XWidth{ 50 }; //BD
	const int maxBD_YHeight{ 50 }; //BD
	const int maxC_HeightY{ 150 }; //C
	const int maxC_WidthX{ 150 }; //C

	float angleB_X{ float(g_NrFrames) / framesSmall }; // B
	float B_X{ g_middleWidth + maxBD_XWidth * CosBf(angleB_X) }; // B

	float angleB_Y{ float(g_NrFrames) / framesSmall };
	float B_Y{ g_middleHeight + maxBD_YHeight * SinBf(angleB_Y) }; // B

	
	DrawLine(g_middleWidth, g_middleHeight, B_X, B_Y, 3); // line AB

	float angleD_X{ float(g_NrFrames) / framesSmall };
	float D_X{ g_middleWidth + maxBD_XWidth * CosDf(angleB_X) }; // D

	float angleD_Y{ float(g_NrFrames) / framesSmall };
	float D_Y{ g_middleHeight + maxBD_YHeight * SinDf(angleB_Y) }; // D

	DrawLine(g_middleWidth, g_middleHeight, D_X, D_Y, 3); // Line AD


	float angleC_X{ float(g_NrFrames) / framesSmall };
	float C_X{ g_middleWidth + maxC_WidthX * CosCf(angleC_X) }; // C

	float angleC_Y{ float(g_NrFrames) / framesSmall };
	float C_Y{ g_middleHeight + maxC_HeightY * SinCf(angleC_Y) }; // C


	DrawLine(D_X, D_Y, C_X, C_Y, 3); // LINE DC

	DrawLine(B_X, B_Y, C_X, C_Y, 3); // LINE BC

}


void Update(float elapsedSec)
{
	g_NrFrames++;
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

#pragma endregion ownDefinitions