#include "NonDetTMExecution.h"
#include "NonDetTM.h"
#include <iostream>

using namespace std;

NonDetTMExecution::NonDetTMExecution() {
	branches.push_back(NonDetTMExecBranch());
}

void NonDetTMExecution::step(const NonDetTM& tm) {
	//cout << "#branches " << branches.size();
	removeFinals(tm.stateCount);
	
	size_t oldBranchCount = branches.size(), c = 0;
	//cout << ", #b " << oldBranchCount;
	for(std::list<NonDetTMExecBranch>::iterator i = branches.begin(); c < oldBranchCount; ++i, ++c) {
		i->step(tm, branches);
	}
	//cout << ", after #b " << branches.size();

	removeDuplicateBranches();
}

void NonDetTMExecution::removeDuplicateBranches() {
	// TODO
	//cout << ", cleaned #b " << branches.size();
}

void NonDetTMExecution::removeFinals(Number stateCount) {
	size_t count = 0;
	for(std::list<NonDetTMExecBranch>::iterator i = branches.begin(); i != branches.end(); ) {
		if(i->state >= stateCount - 1) {
			count++;
			i = branches.erase(i);
		} else
			++i;
	}
	
	//cout << ", #final " << count << "";
}
