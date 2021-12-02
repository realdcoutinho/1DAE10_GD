#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	void GenerateThreeRects(float sideSize, float xCoordinate, float loops);
	void GenerateTriangles(const Point2f & V1, const Point2f & V2, const Point2f & V3);

}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawThreeRects();
	DrawTriangles();
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
void GenerateThreeRects(float sideSize, float xCoordinate, float loops) {

	float turns{ 1 }; // How many squares to draw?
	float squareLenght{ sideSize }; // Lenght for original square
	float left{ xCoordinate }; //X for original Square
	float bottom{ g_WindowLenght - g_border - (500/4)  }; // Y for original square


	for (turns = 1; turns <= loops; ++turns) { // How many turns does it performe? While the number of turns is not equal to the number chosen by the user draw another rect

		float margin = (squareLenght / 2) / loops; // the spac ing between each line is decided by this line
													// we take the lenght of the square and divided by 2. Then we divide by the number chosen by the user
													// this way, we always get the same average distance independently of the user choice number

		float y = margin * turns; // based on the number turns, y will return the difference between the previous square bottom and this bottom 
								  //or previous left and this new squares left

		SetColor(0, 0, 0, 1);
		DrawRect(left, bottom, squareLenght, squareLenght); // big outside square only once
		DrawRect(left + y, bottom + y, squareLenght - 2 * y, squareLenght - 2 * y); // squareLenght-2*y double the margin at the end to compensate for the addition of that same margin
																		// at the left and bottom coordinates of the squares
	}
}

void DrawThreeRects() {

	float oneSideSize{ g_WindowLenght / 4 };
	float oneXCoordinate{ g_border };
	float oneLoops{ 10 };

	GenerateThreeRects(oneSideSize, oneXCoordinate, oneLoops);

	float twoSideSize{ g_WindowLenght / 6 };
	float twoXCoordinate{ g_border + oneSideSize + g_border };
	float twoLoops{ 5 };

	GenerateThreeRects(twoSideSize, twoXCoordinate, twoLoops);

	float threeSideSize{ g_WindowLenght / 8 };
	float threeXCoordinate{ twoXCoordinate + twoSideSize + g_border  };
	float threeLoops{ 3 };

	GenerateThreeRects(threeSideSize, threeXCoordinate, threeLoops);
}


void GenerateTriangles(const Point2f& V1, const Point2f& V2, const Point2f& V3) {

	//Draw    void DrawTriangle(const Point2f & p1, const Point2f & p2, const Point2f & p3, float lineWidth = 1);
	
	FillTriangle(V1, V2, V3);
}

void DrawTriangles() 
{

	for (int i{0}; i < 3; i++) {

		float sideLenght{ (g_WindowLenght / 4) };

		float sideLenghtReal{ sideLenght - (sideLenght / 10) * (i*2) };
		float xV1(g_WindowWidth / 2 + (sideLenght / 10) * i);
		float yV1(g_WindowHeight - (g_WindowHeight / 4) + (sideLenght / 10) * (i/2));
		Point2f vOne(xV1, yV1);

		float xV2(float(cos(0) * sideLenghtReal) + xV1);
		float yV2(float(sin(0) * sideLenghtReal) + yV1);
		Point2f vTwo(xV2, yV2);

		float xV3(float(cos(1.04719755) * sideLenghtReal) + xV1);
		float yV3(float(sin(1.04719755) * sideLenghtReal) + yV1);
		Point2f vThree(xV3, yV3);


		switch (i)
		{
		case 0:
			SetColor(1, 0, 0, 1);
			GenerateTriangles(vOne, vTwo, vThree);
			break;
		case 1:
			SetColor(0, 1, 0, 1);
			GenerateTriangles(vOne, vTwo, vThree);
			break;
		case 2:
			SetColor(0, 0, 1, 1);
			GenerateTriangles(vOne, vTwo, vThree);
			break;
		default:
			break;
		}
	}


}


#pragma endregion ownDefinitions