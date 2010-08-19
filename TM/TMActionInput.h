#ifndef TMACTIONINPUT_H
#define TMACTIONINPUT_H

#include "Number.h"
#include "TMAlphabet.h"

struct TMActionInput {
	Number state;
	TMAlphabet currentChar;
};

#endif // TMACTIONINPUT_H
