#include "Dice.h"
#include <cstdlib>

Dice::Dice()
{
	faceValue = 0;
}

void Dice::roll()
{
	faceValue = rand() % 6 + 1;
}


int Dice::getFaceValue()
{
	// TODO: 여기에 구현 코드 추가.
	return faceValue;
}
