#include "Rectangle.h"

bool Rectangle::isSquare()
{
	if (width == height) {
		return true;
	}
	else {
		return false;
	}
}

Rectangle::Rectangle() {
	width = height;
}

Rectangle::Rectangle(int a) {
	width = a;
	height = a;
}

Rectangle::Rectangle(int a, int b) {
	width = a;
	height = b;
}
