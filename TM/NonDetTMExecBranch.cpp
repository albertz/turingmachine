#include "NonDetTMExecBranch.h"
#include "NonDetTM.h"
#include <cassert>

void NonDetTMExecBranch::step(const NonDetTM& tm, std::list<NonDetTMExecBranch>& branches) {
	TMActionInput actIn;
	actIn.state = state;
	actIn.currentChar = tape.current();
	std::map<TMActionInput, std::set<TMAction> >::const_iterator transIt = tm.transitions.find(actIn);
	assert(transIt != tm.transitions.end());
	const std::set<TMAction>& actions = transIt->second;
	NonDetTMExecBranch* currentBranch = this;
	
	size_t count = 0;
	assert(actions.size() > 0);
	for(std::set<TMAction>::const_iterator i = actions.begin(); i != actions.end(); ++i) {
		count++;
		if(count > 1) {
			branches.push_back(NonDetTMExecBranch());
			currentBranch = &branches.back();
		}
		
		currentBranch->state = i->nextState;
		currentBranch->tape.writeCurrent(i->writeChar);
		currentBranch->tape.move(i->tapeMove);
	}
}
