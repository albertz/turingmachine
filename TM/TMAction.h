#ifndef TMACTION_H
#define TMACTION_H

#include "TMAlphabet.h"
#include "Number.h"
#include <list>

struct TMAction {
	TMAlphabet writeChar;
	int tapeMove; // -1, 0, 1
	Number nextState;
	
	bool operator<(const TMAction& act) const {
		if(nextState != act.nextState) return nextState < act.nextState;
		if(tapeMove != act.tapeMove) return tapeMove < act.tapeMove;
		if(writeChar != act.writeChar) return writeChar < act.writeChar;
		return false;
	}
};

void buildActionList( Number stateCount, std::list<TMAction>& acts );

#endif // TMACTION_H
