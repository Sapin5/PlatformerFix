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
		DrawRectangle(xPos, yPos, width, height, C);
		return hoveredOver();
	}
}