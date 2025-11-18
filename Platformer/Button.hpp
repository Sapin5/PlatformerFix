#ifndef BUTTON_H
#define BUTTON_H
#include "raylib.h"
#include "Screen.hpp"

namespace Platformer{
	class Button {
	private:
		char buttonValue{ ' ' };
		Color normal{ RED };
		Color hovered{ BLUE };
		Color C;

		int width{ 150 };
		int height{ 150 };
		int xPos{ 150 };
		int yPos{ 150 };
		
	public:
		Button() = default;

		Button(int width, int height, int xPos, int yPos, Color normal,Color hovered) {
			 
			 this->width = width;
			 this->height = height;
			 this->xPos = xPos;
			 this->yPos = yPos;

			 this->normal = normal;
			 this->hovered = hovered;
			 this->C = normal;
			 this->buttonValue = buttonValue;
		}
		
		/// <summary>
		/// Checks if mouse is hovering over button
		/// </summary>
		/// <returns></returns>
		bool hoveredOver();


		/// <summary>
		/// Draws button on screen
		/// </summary>
		/// <returns></returns>
		bool drawButton() ;
	};
}

#endif // !BUTTON_H
