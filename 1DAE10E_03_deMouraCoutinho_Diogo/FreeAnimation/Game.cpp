#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here

}

float Cos_Spoke1(float a_Spoke1_X) {

	return float(cos(-2.0 * a_Spoke1_X * M_PI));
}

float Sin_Spoke1(float a_Spoke1_Y) {

	return float(sin(-2.0 * a_Spoke1_Y * M_PI));
}

float Cos_Spoke2(float a_Spoke2_X) {

	return float(cos((-2.0 * a_Spoke2_X * M_PI) - 0.78f));
}

float Sin_Spoke2(float a_Spoke2_Y) {

	return float(sin((-2.0 * a_Spoke2_Y * M_PI) - 0.78f));
}

float Cos_Spoke3(float a_Spoke3_X) {

	return float(cos((-2.0 * a_Spoke3_X * M_PI) - 1.57f));
}

float Sin_Spoke3(float a_Spoke3_Y) {

	return float(sin((-2.0 * a_Spoke3_Y * M_PI) - 1.57f));
}

float Cos_Spoke4(float a_Spoke4_X) {

	return float(cos((-2.0 * a_Spoke4_X * M_PI) - 2.35f));
}

float Sin_Spoke4(float a_Spoke4_Y) {

	return float(sin((-2.0 * a_Spoke4_Y * M_PI) - 2.35f));
}

float Cos_Spoke5(float a_Spoke5_X) {

	return float(cos((-2.0 * a_Spoke5_X * M_PI) - 3.14f));
}

float Sin_Spoke5(float a_Spoke5_Y) {

	return float(sin((-2.0 * a_Spoke5_Y * M_PI) - 3.14f));
}

float Cos_Spoke6(float a_Spoke6_X) {

	return float(cos((-2.0 * a_Spoke6_X * M_PI) - 3.92f));
}

float Sin_Spoke6(float a_Spoke6_Y) {

	return float(sin((-2.0 * a_Spoke6_Y * M_PI) - 3.92f));
}

float Cos_Spoke7(float a_Spoke7_X) {

	return float(cos((-2.0 * a_Spoke7_X * M_PI) - 4.7f));
}

float Sin_Spoke7(float a_Spoke7_Y) {

	return float(sin((-2.0 * a_Spoke7_Y * M_PI) - 4.7f));
}

float Cos_Spoke8(float a_Spoke8_X) {

	return float(cos((-2.0 * a_Spoke8_X * M_PI) - 5.48f));
}

float Sin_Spoke8(float a_Spoke8_Y) {

	return float(sin((-2.0 * a_Spoke8_Y * M_PI) - 5.48f));
}

float Cos_Center1(float a_Center_X) {

	return float(cos(-2.0 * a_Center_X * M_PI));
}

float Sin_Center1(float a_Center_Y) {

	return float(sin(-2.0 * a_Center_Y * M_PI));
}


void Draw()
{
	ClearBackground(0, 0, 0);

	LeftWheel();
	RightWheel();
	Static();
	Rods();

}

void LeftWheel() {

	SetColor(1, 1, 1);



	float a_Spoke1_X{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 1 X
	float l_Spoke1_X{ g_l_Px + g_spoke_Lenght * Cos_Spoke1(a_Spoke1_X) }; // Moving X coordinate for Spoke One 1

	float a_Spoke1_Y{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 1 Y
	float spoke1_Y{ g_WindowHeight / 2 + g_spoke_Lenght * Sin_Spoke1(a_Spoke1_Y) }; // Moving Y coordinate for Spoke One 1

	DrawLine(g_l_Px, g_WindowHeight / 2, l_Spoke1_X, spoke1_Y, 3); //Spoke One 1 Drawn


	///////////////////////////////////////////////////////

	float a_Spoke2_X{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 2 X
	float l_Spoke2_X{ g_l_Px + g_spoke_Lenght * Cos_Spoke2(a_Spoke2_X) }; // Moving X coordinate for Spoke Two 2

	float a_Spoke2_Y{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 2 Y
	float spoke2_Y{ g_WindowHeight / 2 + g_spoke_Lenght * Sin_Spoke2(a_Spoke2_Y) };// Moving Y coordinate for Spoke Two 2

	DrawLine(g_l_Px, g_WindowHeight / 2, l_Spoke2_X, spoke2_Y, 3); //Spoke Two 2 Drawn

	/// ///////////////////////////////////////////////////////////////

	float a_Spoke3_X{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 3 X
	float l_Spoke3_X{ g_l_Px + g_spoke_Lenght * Cos_Spoke3(a_Spoke3_X) }; // Moving X coordinate for Spoke Three 3

	float a_Spoke3_Y{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 3 Y
	float spoke3_Y{ g_WindowHeight / 2 + g_spoke_Lenght * Sin_Spoke3(a_Spoke3_Y) }; // Moving Y coordinate for Spoke Three 3

	DrawLine(g_l_Px, g_WindowHeight / 2, l_Spoke3_X, spoke3_Y, 3); //Spoke Two 3 Drawn

	///////////////////////////////////////////////////////////////////

	float a_Spoke4_X{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 4 X
	float l_Spoke4_X{ g_l_Px + g_spoke_Lenght * Cos_Spoke4(a_Spoke4_X) }; // Moving X coordinate for Spoke Four 4

	float a_Spoke4_Y{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 4 Y
	float spoke4_Y{ g_WindowHeight / 2 + g_spoke_Lenght * Sin_Spoke4(a_Spoke4_Y) };// Moving Y coordinate for Spoke Four 4

	DrawLine(g_l_Px, g_WindowHeight / 2, l_Spoke4_X, spoke4_Y, 3); //Spoke Two 4 Drawn

	////////////////////////////////////////////////////////////////////

	float a_Spoke5_X{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 5 X
	float l_Spoke5_X{ g_l_Px + g_spoke_Lenght * Cos_Spoke5(a_Spoke5_X) }; // Moving X coordinate for Spoke Five	5

	float a_Spoke5_Y{ float(g_NrFrames) / g_spoke_Speed };//angle for Spoke 5 Y
	float spoke5_Y{ g_WindowHeight / 2 + g_spoke_Lenght * Sin_Spoke5(a_Spoke5_Y) };// Moving Y coordinate for Spoke Five	5

	DrawLine(g_l_Px, g_WindowHeight / 2, l_Spoke5_X, spoke5_Y, 3); //Spoke Five 5 Drawn

	//////////////////////////////////////////////////////////////////

	float a_Spoke6_X{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 6 X
	float l_Spoke6_X{ g_l_Px + g_spoke_Lenght * Cos_Spoke6(a_Spoke6_X) }; // Moving X coordinate for Spoke Six 6

	float a_Spoke6_Y{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 6 Y
	float spoke6_Y{ g_WindowHeight / 2 + g_spoke_Lenght * Sin_Spoke6(a_Spoke6_Y) }; // Moving Y coordinate for Spoke Six 6

	DrawLine(g_l_Px, g_WindowHeight / 2, l_Spoke6_X, spoke6_Y, 3); //Spoke Six 6 Drawn

	////////////////////////////////////////////////////////////////////////

	float a_Spoke7_X{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 7 X
	float l_Spoke7_X{ g_l_Px + g_spoke_Lenght * Cos_Spoke7(a_Spoke7_X) }; // Moving X coordinate for Spoke Seven 7

	float a_Spoke7_Y{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 7 Y
	float spoke7_Y{ g_WindowHeight / 2 + g_spoke_Lenght * Sin_Spoke7(a_Spoke7_Y) }; // Moving Y coordinate for Spoke Seven 7

	DrawLine(g_l_Px, g_WindowHeight / 2, l_Spoke7_X, spoke7_Y, 3); //Spoke Seven 7 Drawn

		/////////////////////////////////////////////////////////////////

	float a_Spoke8_X{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 8 X
	float l_Spoke8_X{ g_l_Px + g_spoke_Lenght * Cos_Spoke8(a_Spoke8_X) }; // Moving X coordinate for Spoke Eight 8

	float a_Spoke8_Y{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 8 Y
	float spoke8_Y{ g_WindowHeight / 2 + g_spoke_Lenght * Sin_Spoke8(a_Spoke8_Y) }; // Moving Y coordinate for Spoke Eight 8

	DrawLine(g_l_Px, g_WindowHeight / 2, l_Spoke8_X, spoke8_Y, 3); //Spoke Eight 8 Drawn

	//////////////////////////

	SetColor(0.3f, 0.3f, 0.3f);
	DrawEllipse(g_l_Px, g_WindowHeight / 2, g_spoke_Lenght, g_spoke_Lenght, 10);
	FillEllipse(g_l_Px, g_WindowHeight / 2, g_innerRadius, g_innerRadius);
}

void RightWheel() {

	SetColor(1, 1, 1);

	//Spoke One Right Wheel
	float a_Spoke1_X{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 1 X
	float r_Spoke1_X{ g_r_Px + g_spoke_Lenght * Cos_Spoke1(a_Spoke1_X) }; // Moving X coordinate for Spoke One 1

	float a_Spoke1_Y{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 1 Y
	float spoke1_Y{ g_WindowHeight / 2 + g_spoke_Lenght * Sin_Spoke1(a_Spoke1_Y) }; // Moving Y coordinate for Spoke One 1

	DrawLine(g_r_Px, g_WindowHeight / 2, r_Spoke1_X, spoke1_Y, 3); //Spoke One 1 Drawn


	///////////////////////////////////////////////////////

	float a_Spoke2_X{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 2 X
	float r_Spoke2_X{ g_r_Px + g_spoke_Lenght * Cos_Spoke2(a_Spoke2_X) }; // Moving X coordinate for Spoke Two 2

	float a_Spoke2_Y{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 2 Y
	float spoke2_Y{ g_WindowHeight / 2 + g_spoke_Lenght * Sin_Spoke2(a_Spoke2_Y) };// Moving Y coordinate for Spoke Two 2

	DrawLine(g_r_Px, g_WindowHeight / 2, r_Spoke2_X, spoke2_Y, 3); //Spoke Two 2 Drawn

	//////////////////////////////////////////////////////

	float a_Spoke3_X{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 3 X
	float r_Spoke3_X{ g_r_Px + g_spoke_Lenght * Cos_Spoke3(a_Spoke3_X) }; // Moving X coordinate for Spoke Three 3

	float a_Spoke3_Y{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 3 Y
	float spoke3_Y{ g_WindowHeight / 2 + g_spoke_Lenght * Sin_Spoke3(a_Spoke3_Y) }; // Moving Y coordinate for Spoke Three 3

	DrawLine(g_r_Px, g_WindowHeight / 2, r_Spoke3_X, spoke3_Y, 3); //Spoke Two 3 Drawn

	///////////////////////////////////////////////////////////////////

	float a_Spoke4_X{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 4 X
	float r_Spoke4_X{ g_r_Px + g_spoke_Lenght * Cos_Spoke4(a_Spoke4_X) };// Moving X coordinate for Spoke Four 4

	float a_Spoke4_Y{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 4 Y
	float spoke4_Y{ g_WindowHeight / 2 + g_spoke_Lenght * Sin_Spoke4(a_Spoke4_Y) };// Moving Y coordinate for Spoke Four 4

	DrawLine(g_r_Px, g_WindowHeight / 2, r_Spoke4_X, spoke4_Y, 3); //Spoke Two 4 Drawn

	////////////////////////////////////////////////////////////////////

	float a_Spoke5_X{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 5 X
	float r_Spoke5_X{ g_r_Px + g_spoke_Lenght * Cos_Spoke5(a_Spoke5_X) };// Moving X coordinate for Spoke Five	5

	float a_Spoke5_Y{ float(g_NrFrames) / g_spoke_Speed };//angle for Spoke 5 Y
	float spoke5_Y{ g_WindowHeight / 2 + g_spoke_Lenght * Sin_Spoke5(a_Spoke5_Y) };// Moving Y coordinate for Spoke Five	5

	DrawLine(g_r_Px, g_WindowHeight / 2, r_Spoke5_X, spoke5_Y, 3); //Spoke Five 5 Drawn

	//////////////////////////////////////////////////////////////////

	float a_Spoke6_X{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 6 X
	float r_Spoke6_X{ g_r_Px + g_spoke_Lenght * Cos_Spoke6(a_Spoke6_X) }; // Moving X coordinate for Spoke Six 6

	float a_Spoke6_Y{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 6 Y
	float spoke6_Y{ g_WindowHeight / 2 + g_spoke_Lenght * Sin_Spoke6(a_Spoke6_Y) }; // Moving Y coordinate for Spoke Six 6

	DrawLine(g_r_Px, g_WindowHeight / 2, r_Spoke6_X, spoke6_Y, 3); //Spoke Six 6 Drawn

	////////////////////////////////////////////////////////////////////////

	float a_Spoke7_X{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 7 X
	float r_Spoke7_X{ g_r_Px + g_spoke_Lenght * Cos_Spoke7(a_Spoke7_X) }; // Moving X coordinate for Spoke Seven 7

	float a_Spoke7_Y{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 7 Y
	float spoke7_Y{ g_WindowHeight / 2 + g_spoke_Lenght * Sin_Spoke7(a_Spoke7_Y) }; // Moving Y coordinate for Spoke Seven 7

	DrawLine(g_r_Px, g_WindowHeight / 2, r_Spoke7_X, spoke7_Y, 3); //Spoke Seven 7 Drawn

	/////////////////////////////////////////////////////////////////

	float a_Spoke8_X{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 8 X
	float r_Spoke8_X{ g_r_Px + g_spoke_Lenght * Cos_Spoke8(a_Spoke8_X) }; // Moving X coordinate for Spoke Eight 8

	float a_Spoke8_Y{ float(g_NrFrames) / g_spoke_Speed }; //angle for Spoke 8 Y
	float spoke8_Y{ g_WindowHeight / 2 + g_spoke_Lenght * Sin_Spoke8(a_Spoke8_Y) }; // Moving Y coordinate for Spoke Eight 8

	DrawLine(g_r_Px, g_WindowHeight / 2, r_Spoke8_X, spoke8_Y, 3); //Spoke Eight 8 Drawn

	SetColor(0.3f, 0.3f, 0.3f);
	DrawEllipse(g_r_Px, g_WindowHeight / 2, g_spoke_Lenght, g_spoke_Lenght, 10);
	FillEllipse(g_r_Px, g_WindowHeight / 2, g_innerRadius, g_innerRadius);

}

void Static() {


}

void Rods() {

	//-------------------------------------------------------
	const float tieRod_divergence = g_innerRadius / 0.7f;
	const float tieRod_Speed = g_spoke_Speed * 0.8f;
	//-------------------------------------------------------

	float a_TieRod_X{ float(g_NrFrames) / tieRod_Speed }; //angle for TieRod X
	float l_TieRod_X{ g_l_Px + tieRod_divergence * Cos_Center1(a_TieRod_X) }; // X coordinate for Tierod on the left
	float r_TieRod_X{ g_r_Px + tieRod_divergence * Cos_Center1(a_TieRod_X) }; // X coordinate for Tierod on the right

	float a_TieRod_Y{ float(g_NrFrames) / tieRod_Speed }; //angle for TieRod Y
	float tieRod_Y{ g_WindowHeight / 2 + tieRod_divergence * Sin_Center1(a_TieRod_Y) }; // Y coordinate for Tierod on both sides
	
	SetColor(1, 1, 1);
	DrawLine(l_TieRod_X, tieRod_Y, r_TieRod_X, tieRod_Y, 6); // Tie Rod
	SetColor(0, 0, 0);
	DrawLine(l_TieRod_X, tieRod_Y, r_TieRod_X, tieRod_Y, 1.5f); //line in the middle of the tie rod

	//-------------------------------------------------------
	float connecting_Rod_X = g_oneUnit * 15;
	float connecting_Rod_movement = tieRod_divergence;
	//-------------------------------------------------------

	float a_ConnectingRod_X{ float(g_NrFrames) / tieRod_Speed }; //angle for connecting Rod on the right
	float connecting_Rod_Movement_X{ connecting_Rod_X + connecting_Rod_movement * Cos_Center1(a_ConnectingRod_X) }; //X cooridnate for Connecting Rod on the right
	


	SetColor(0.8f, 0.8f, 0.8f);
	FillEllipse(l_TieRod_X, tieRod_Y, g_innerRadius / 1.5f, g_innerRadius / 1.5f); // Moving Ellipse in the center left
	FillEllipse(r_TieRod_X, tieRod_Y, g_innerRadius / 1.5f, g_innerRadius / 1.5f); // Moving Ellipse in the center right


	SetColor(0.3f, 0.3f, 0.3f);
	FillEllipse(r_TieRod_X, tieRod_Y, g_innerRadius / 2.5f, g_innerRadius / 2.5f); // Moving Ellipse of the connecting rod right

	SetColor(0.5f, 0.5f, 0.5f);
	DrawLine(l_TieRod_X, tieRod_Y, connecting_Rod_Movement_X, g_WindowHeight / 2, 10); //Connecting Rod
	
	SetColor(0.3f, 0.3f, 0.3f);
	FillEllipse(l_TieRod_X, tieRod_Y, g_innerRadius / 2.5f, g_innerRadius / 2.5f); // Moving Ellipse of the connecting rod left

	SetColor(0.3f, 0.3f, 0.3f);
	DrawLine(connecting_Rod_Movement_X - g_innerRadius, g_WindowHeight / 2, connecting_Rod_Movement_X, g_WindowHeight / 2, 30); // Block at the biggining of the connecting rod


	//Piston
	SetColor(0.3f, 0.3f, 0.3f);
	DrawLine(connecting_Rod_Movement_X, g_WindowHeight / 2, connecting_Rod_Movement_X + g_oneUnit * 2.5f, g_WindowHeight / 2, 3); //Piston rod
	DrawLine(connecting_Rod_Movement_X + g_oneUnit * 2.5f, g_WindowHeight / 2 - g_innerRadius, connecting_Rod_Movement_X + g_oneUnit * 2.5f, g_WindowHeight / 2 + (g_oneUnit * 1.5f / 2), 5); //Piston
	
	
	//FillRect(connecting_Rod_Movement_X + g_oneUnit * 2.5f, g_WindowHeight / 2 - g_innerRadius, g_oneUnit * 2.5f, g_oneUnit * 1.5f);
	
	
	SetColor(0.8f, 0.8f, 0.8f);
	DrawRect(g_oneUnit * 15 + g_innerRadius + 30 / 2, g_WindowHeight / 2 - g_innerRadius, g_oneUnit * 2.5f, g_oneUnit * 1.5f, 3); //Piston box
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