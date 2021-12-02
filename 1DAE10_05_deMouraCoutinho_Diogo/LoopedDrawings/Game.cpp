#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground(0, 0, 0);
	Borders();

	GenerateGreenRect();
	GenerateStairs();
	GenerateSpiral();
	GenerateSpiralLines();

	// Put your own draw statements here

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
	switch (key)
	{
	case SDLK_LEFT:
		std::cout << "Left arrow key pressed\n";
		Plus();
		break;
	case SDLK_RIGHT:
		std::cout << "Right arrow key pressed\n";
		Minus();
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
void Borders() {

	SetColor(1, 0, 0, 1);
	DrawRect(g_border, g_border, g_WindowWidth - g_border * 2, g_WindowHeight - g_border * 2, 2);
	DrawLine(g_WindowWidth / 2, g_border, g_WindowWidth / 2, g_WindowHeight - g_border, 2);
	DrawLine(g_border, g_WindowHeight / 2, g_WindowWidth - g_border, g_WindowWidth / 2, 2);

}

void GenerateGreenRect() {


	float turns{ 1 }; // How many squares to draw?
	float left{ g_border * 2}; //X for original Square
	float bottom{ g_border *2 }; // Y for original square
	float squareLenght{ g_WindowLenght / 2 - g_border * 3}; // Lenght for original square

	for (turns = 1; turns <= g_choice; ++turns) { // How many turns does it performe? While the number of turns is not equal to the number chosen by the user draw another rect

		float margin = (squareLenght / 2) / g_choice; // the spac ing between each line is decided by this line
													// we take the lenght of the square and divided by 2. Then we divide by the number chosen by the user
													// this way, we always get the same average distance independently of the user choice number

		float y = margin * turns; // based on the number turns, y will return the difference between the previous square bottom and this bottom 
								  //or previous left and this new squares left

		SetColor(0, 1, 0, 1);
		DrawRect(left, bottom, squareLenght, squareLenght); // big outside square only once
		DrawRect(left+y, bottom+y, squareLenght-2*y, squareLenght-2*y); // squareLenght-2*y double the margin at the end to compensate for the addition of that same margin
																		// at the left and bottom coordinates of the squares
	}
}



void GenerateStairs() {

	float turns{ 0 };
	float bottom{ g_WindowLenght / 2 + g_border }; // Y for original line
	float max_LineLenght{ g_WindowLenght / 2 - g_border * 3 }; // Lenght for maximal line

	for (turns = 0; turns <= g_choice - 1; ++turns) {
	
		float lineLenght{ max_LineLenght / g_choice };
		float left{ g_border * 2 + lineLenght * turns}; //X for original line

		if (turns == 0) { // define de the colors
			SetColor(g_blue);
		}
		else if (int(turns) % 2 == 0) {
			SetColor(g_blue);
		}
		else
			SetColor(g_red);


		Point2f initialPointH(left , bottom + lineLenght *turns); 		//horizontal 
		Point2f finalPointH(left + lineLenght, bottom + lineLenght *turns);		//horizontal 

		Point2f initialPointV(left + lineLenght, bottom + lineLenght * turns);// vertical lines
		Point2f finalPointV(left + lineLenght, bottom + lineLenght * turns + lineLenght);// vertical lines

		DrawLine(initialPointH, finalPointH,2); // horizontal horizontal lines
		DrawLine(initialPointV, finalPointV,2); // vertical lines
	}
}

void GenerateSpiral() {

	float turns{ 1 }; // How many lines to draw

	float left{ g_WindowWidth / 2 + g_border}; //X for original Square
	float bottom{ g_border * 2 }; // Y for original square
	float lineLenght{ g_WindowWidth / 2 - g_border * 3 }; // Lenght for original square

	for (turns = 0; turns <= g_choice - 1; ++turns) {

		//float lineLenght{ maxLineLenght - (maxLineLenght/g_choice) };


		SetColor(g_blue);

		float leftMargin{ (lineLenght / 2) / g_choice };

		float left_Y = leftMargin * turns;


		float left_MaxLineLenghtH{ left + lineLenght - left_Y };
		float left_MaxLineLenghtV{ bottom + lineLenght - left_Y };



		Point2f right_InitialPointH(left + left_Y, bottom+ left_Y);
		Point2f right_FinalPointH(left_MaxLineLenghtH, bottom+ left_Y);

		Point2f right_InitialPointV(left_MaxLineLenghtH, bottom + left_Y);
		Point2f right_FinalPointV(left_MaxLineLenghtH, left_MaxLineLenghtV);

		DrawLine(right_InitialPointH, right_FinalPointH); // horizontal
		DrawLine(right_InitialPointV, right_FinalPointV); // vertical

	}
		
	for (turns = 0 ; turns <= g_choice -1; ++turns) {

		SetColor(g_blue);

		float rightMargin{ (lineLenght / 2) / g_choice }; //what each line losses by the addition of another loop. a part of the section

		float right_linelenght{ lineLenght - rightMargin }; // the maximum lenght of the line taken the margin
		float right_Taken = rightMargin * turns; // the total lenght of the portion taken given the number of turns

		float right_MaxLineLenghtH{ left + right_linelenght - right_Taken };
		float right_MaxLineLenghtV{ bottom + right_linelenght + rightMargin - right_Taken };

		Point2f rigth_InitialPointH(left + right_Taken + rightMargin, right_MaxLineLenghtV);
		Point2f right_FinalPointH(right_MaxLineLenghtH + rightMargin, right_MaxLineLenghtV);

		Point2f right_InitialPointV(left + right_Taken + rightMargin, right_MaxLineLenghtV);
		Point2f right_FinalPointV(left + right_Taken + rightMargin, bottom + rightMargin + right_Taken);

		DrawLine(rigth_InitialPointH, right_FinalPointH);
		DrawLine(right_InitialPointV, right_FinalPointV);
	}
}

void GenerateSpiralLines() {

	float lineLenght{ g_WindowLenght / 2 + g_border + g_WindowLenght / 2 - g_border * 2 };
	float turns{ 1 };

	for (turns = 1; turns <= g_choice -1; ++turns) {

		
		float lenghtTaken{ (lineLenght / 2) / (g_choice + 1) };
		float left_Y = lenghtTaken * turns;

		//Yellow
		float y_LowX{ g_WindowLenght / 2 + g_border };
		float y_LowY{ g_WindowLenght / 2 + g_border };

		float y_HighX{ g_WindowLenght / 2 + g_border };
		float y_HighY{ g_WindowLenght - g_border * 2 };

		SetColor(g_yellow);
		Point2f y_LowPoint(y_LowX+ left_Y, y_LowY );
		Point2f y_HighPoint(y_HighX, y_HighY -left_Y);

		DrawLine(y_LowPoint, y_HighPoint);

		//Red
		float r_LowX{ g_WindowLenght / 2 + g_border + left_Y };
		float r_LowY{ g_WindowLenght / 2 + g_border };
		float r_HighX{ lineLenght - g_border };
		float r_HightY{ g_WindowLenght / 2 + g_border + left_Y };

		SetColor(g_red);
		Point2f r_LowPoint(r_LowX, r_LowY);
		Point2f r_HighPoint(r_HighX, r_HightY);

		DrawLine(r_LowPoint, r_HighPoint);


		//Green

		float g_LowX{ g_WindowLenght - g_border * 2 };
		float g_LowY{ g_WindowLenght / 2 + g_border + left_Y };
		float g_HighX{ lineLenght - g_border - left_Y };
		float g_HightY{ g_WindowLenght - g_border * 2 };

		SetColor(g_green);
		Point2f g_LowPoint(g_LowX, g_LowY);
		Point2f g_HighPoint(g_HighX, g_HightY);

		DrawLine(g_LowPoint, g_HighPoint);


		//Blue

		float b_LowX{ lineLenght - g_border - left_Y };
		float b_LowY{ g_WindowLenght - g_border * 2 };
		float b_HighX{ g_WindowLenght / 2 + g_border };
		float b_HightY{ g_WindowLenght - g_border * 2  - left_Y };

		SetColor(g_blue);
		Point2f b_LowPoint(b_LowX, b_LowY);
		Point2f b_HighPoint(b_HighX, b_HightY);

		DrawLine(b_LowPoint, b_HighPoint);
	}

	//Yellow
	float y_OLowX{ g_WindowLenght / 2 + g_border };
	float y_OLowY{ g_WindowLenght / 2 + g_border };

	float y_OHighX{ g_WindowLenght / 2 + g_border };
	float y_OHighY{ g_WindowLenght - g_border * 2 };

	SetColor(g_yellow);
	Point2f y_OLowPoint(y_OLowX, y_OLowY);
	Point2f y_OHighPoint(y_OHighX, y_OHighY);

	DrawLine(y_OLowPoint, y_OHighPoint);

	//Red

	float r_OLowX{ g_WindowLenght / 2 + g_border };
	float r_OLowY{ g_WindowLenght / 2 + g_border };
	float r_OHighX{ lineLenght - g_border };
	float r_OHightY{ g_WindowLenght / 2 + g_border };

	SetColor(g_red);
	Point2f r_OLowPoint(r_OLowX, r_OLowY);
	Point2f r_OHighPoint(r_OHighX, r_OHightY);

	DrawLine(r_OLowPoint, r_OHighPoint);


	//Green

	float g_OLowX{ g_WindowLenght - g_border * 2 };
	float g_OLowY{ g_WindowLenght / 2 + g_border };
	float g_OHighX{ lineLenght - g_border };
	float g_OHightY{ g_WindowLenght - g_border * 2 };

	SetColor(g_green);
	Point2f g_OLowPoint(g_OLowX, g_OLowY);
	Point2f g_OHighPoint(g_OHighX, g_OHightY);

	DrawLine(g_OLowPoint, g_OHighPoint);

	//Blue

	float b_OLowX{ lineLenght - g_border };
	float b_OLowY{ g_WindowLenght - g_border * 2 };
	float b_OHighX{ g_WindowLenght / 2 + g_border };
	float b_OHightY{ g_WindowLenght - g_border * 2 };

	SetColor(g_blue);
	Point2f b_OLowPoint(b_OLowX, b_OLowY);
	Point2f b_OHighPoint(b_OHighX, b_OHightY);

	DrawLine(b_OLowPoint, b_OHighPoint);
}

void Plus() {

	if (g_choice >= 5) {
		if (g_choice < 18)
			g_choice++;
		std::cout << g_choice << '\n';
	};
}

void Minus() {

	if (g_choice > 5) {
		if (g_choice <= 18)
			--g_choice;
		std::cout << g_choice << '\n';
	};
}
#pragma endregion ownDefinitions