#include "Button.hpp"

namespace Platformer {

	bool Button::hoveredOver() {
		
		if (GetMousePosition().x >= xPos && GetMousePosition().x <= xPos + width &&
			GetMousePosition().y >= yPos && GetMousePosition().y <= yPos + height) {
			
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				C = GREEN;
				return true;
			}
			else {
				C = hovered;
				return false;
			}
		}
		else {
			C = normal;
			return false;
		}
	}

	bool Button::drawButton() {
		bool hovering = hoveredOver();
		DrawRectangle(xPos, yPos, width, height, C);
		DrawText(text.c_str(), xPos + (width * 0.25), yPos + (height * 0.15), width * 0.25, BLACK);
		return hovering;
	}
}