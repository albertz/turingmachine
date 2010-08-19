#ifndef TMACTION_H
#define TMACTION_H

#include "TMAlphabet.h"
#include "Number.h"
#include <list>
#include <string>

struct TMAction {
	Number nextState;
	int tapeMove; // -1, 0, 1
	TMAlphabet writeChar;
	
	TMAction() : nextState(0), tapeMove(-1), writeChar(TMA0) {}	
	bool operator<(const TMAction& act) const {
		if(nextState != act.nextState) return nextState < act.nextState;
		if(tapeMove != act.tapeMove) return tapeMove < act.tapeMove;
		if(writeChar != act.writeChar) return writeChar < act.writeChar;
		return false;
	}	
	std::string debugStr() const;
	Number debugNum() const;
};

void buildActionList( Number stateCount, std::list<TMAction>& acts );

#endif // TMACTION_H
