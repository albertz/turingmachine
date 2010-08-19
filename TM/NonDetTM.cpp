#include "NonDetTM.h"
#include <iostream>

using namespace std;

NonDetTM::NonDetTM() : stateCount(1) {
	for(TMActionInput actIn; actIn.state < stateCount; ++actIn) {
		transitions[actIn].insert(TMAction());
	}
}

static bool incActionSet( const std::list<TMAction>& allActions, std::set<TMAction>& acts ) {
	for(std::list<TMAction>::const_iterator i = allActions.begin(); i != allActions.end(); ++i) {
		if(acts.find(*i) == acts.end()) {
			acts.insert(*i);
			return true;
		}

		//cout << "act: " << i->debugStr() << endl;
		acts.erase(*i);
	}
	
	return false;
}

NonDetTM& NonDetTM::operator++() {
	std::list<TMAction> allActions;
	buildActionList(stateCount, allActions);

	TMActionInput actIn;
	for(; actIn.state < stateCount; ++actIn) {
		//cout << "actIn: " << actIn.debugStr() << endl;
		if(incActionSet(allActions, transitions[actIn]))
			return *this;
		
		// we want to have at least one action in the set
		transitions[actIn].insert(TMAction());
	}
	// we get here if we need to increment the state count
	
	stateCount++;
	// fill initial action for new actioninputs
	for(; actIn.state < stateCount; ++actIn) {
		transitions[actIn].insert(TMAction());
	}
	
	return *this;
}

void NonDetTM::dump() {
	cout << "#states " << stateCount << endl;	
}
