#ifndef TMACTIONINPUT_H
#define TMACTIONINPUT_H

#include "Number.h"
#include "TMAlphabet.h"

struct TMActionInput {
	Number state;
	TMAlphabet currentChar;
	
	TMActionInput() : state(0), currentChar(TMA0) {}
	bool operator<(const TMActionInput& in) const {
		if(state != in.state) return state < in.state;
		if(currentChar != in.currentChar) return currentChar < in.currentChar;
		return false;
	}
	TMActionInput& operator++();
};

#endif // TMACTIONINPUT_H
