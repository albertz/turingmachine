#include "NonDetTMExecution.h"
#include <iostream>

using namespace std;

NonDetTMExecution::NonDetTMExecution() {
	branches.push_back(NonDetTMExecBranch());
}

void NonDetTMExecution::step(const NonDetTM& tm) {
	size_t oldBranchCount = branches.size(), c = 0;
	cout << "step, #branches " << oldBranchCount;
	for(std::list<NonDetTMExecBranch>::iterator i = branches.begin(); c < oldBranchCount; ++i, ++c) {
		i->step(tm, branches);
	}
	cout << ", after #b " << branches.size();

	removeDuplicateBranches();
}

void NonDetTMExecution::removeDuplicateBranches() {
	// TODO
	cout << ", cleaned #b " << branches.size();
}
