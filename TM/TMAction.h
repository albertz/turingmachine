#ifndef TMACTION_H
#define TMACTION_H

#include "TMAlphabet.h"
#include "Number.h"

struct TMAction {
	TMAlphabet writeChar;
	int tapeMove; // -1, 0, 1
	Number nextState;
};

#endif // TMACTION_H
