#include "TMActionInput.h"
#include "StringUtils.h"

TMActionInput& TMActionInput::operator++() {
	((int&)currentChar)++;
	(int&)currentChar %= int(TMAx) + 1;
	
	if(currentChar == TMA0)
		state++;
	
	return *this;
}

std::string TMActionInput::debugStr() const {
	return "{s:" + itoa(state) + ", c:" + itoa(currentChar) + "}";
}
