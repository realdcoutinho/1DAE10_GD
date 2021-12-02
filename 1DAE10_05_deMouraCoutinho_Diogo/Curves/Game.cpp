#include "pch.h"
#include "Game.h"
#include <cmath>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	ClearBackground();
}

void Draw()
{
	ClearBackground();
	GenerateEllipse();
	GenerateCrosier();
	// Put your own draw statements here

}

void Update(float elapsedSec)
{
	// process input, do physics 
	g_Angle += 0.01f;
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
void GenerateEllipse() {
	
	SetColor(g_Black);
	float scale{ 5 };
	const float step(g_Pi * 2 / 10);
	
	for (float angle{}; angle < g_Pi * 2; angle = angle + step) {


		float Vx1{ g_EllipseCenter.x + (/*measurment of a*/scale * g_AE) * cos(angle) }; //vx = cx + a * cos θ
		float Vy1{ g_EllipseCenter.y + (/*measurment of b*/scale * g_BE) * sin(angle) }; //vy = cy + b * sin θ

		float Vx2{ g_EllipseCenter.x + (/*measurment of a*/scale * g_AE) * cos(float(angle + step)) };
		float Vy2{ g_EllipseCenter.y + (/*measurment of b*/scale * g_BE) * sin(float(angle + step)) };

		DrawLine(Vx1, Vy1, Vx2, Vy2);
	}
	
}
void GenerateCrosier() {

	SetColor(g_Black);
	float scale{ 5 };
	const float step(g_Pi * 2 / 360);
	float b{ 8 };

	//    𝑟=𝑎/√θ
	// [π/2, b * 2π+ π/2[


	for (float g_Angle{ g_Pi / 2 }; g_Angle < b * 2 * g_Pi + g_Pi / 2; g_Angle = g_Angle + step) {

		float r = g_CA / sqrt(g_Angle);

		float Vx1{ g_CrosierCenter.x + (r) * cos(g_Angle) }; //Vx = Cx + r * cos θ
		float Vy1{ g_CrosierCenter.y + (r) * sin(g_Angle) }; //Vy = Cy + r * sin θ

		float Vx2{ g_CrosierCenter.x + (r) * cos(float(g_Angle + step)) };
		float Vy2{ g_CrosierCenter.y + (r) * sin(float(g_Angle + step)) };

		DrawLine(Vx1, Vy1, Vx2, Vy2);
	}


}
#pragma endregion ownDefinitions