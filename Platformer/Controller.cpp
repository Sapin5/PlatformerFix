#include "raylib.h"
#include <iostream>

namespace Platformer {
	char getKeyPressed() {
		return static_cast<char>(GetCharPressed());
	}
}

