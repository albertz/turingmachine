#include "TMAction.h"
#include "StringUtils.h"

void buildActionList( Number stateCount, std::list<TMAction>& acts ) {
	for(Number nextState = 0; nextState < stateCount; ++nextState)
		for(int tapeMove = -1; tapeMove <= 1; ++tapeMove)
			for(TMAlphabet c = TMA0; (int)c <= TMAx; ++((int&)c))
			{
				TMAction act;
				act.nextState = nextState;
				act.writeChar = c;
				act.tapeMove = tapeMove;
				acts.push_back(act);
			}
}

std::string TMAction::debugStr() const {
	return
			"{#" + itoa(debugNum()) +
			", s:" + itoa(nextState) +
			", m:" + itoa(tapeMove) +
			", c:" + itoa(writeChar) + "}";
}

Number TMAction::debugNum() const {
	Number n = Number(int(writeChar));
	n += (tapeMove + 1) * 3;
	n += nextState * 9;
	return n;
}
