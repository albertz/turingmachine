#include "TMActionInput.h"

TMActionInput& TMActionInput::operator++() {
	((int&)currentChar)++;
	(int&)currentChar %= int(TMAx) + 1;
	
	if(currentChar == TMA0)
		state++;
	
	return *this;
}
