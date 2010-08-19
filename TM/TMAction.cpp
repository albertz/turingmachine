#include "TMAction.h"

void buildActionList( Number stateCount, std::list<TMAction>& acts ) {
	for(Number nextState = 0; nextState < stateCount; ++nextState)
		for(TMAlphabet c = TMA0; (int)c <= TMAx; ++((int&)c))
			for(int tapeMove = -1; tapeMove <= 1; ++tapeMove) {
				TMAction act;
				act.nextState = nextState;
				act.writeChar = c;
				act.tapeMove = tapeMove;
				acts.push_back(act);
			}
}
