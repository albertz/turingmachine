#ifndef NONDETTMEXECUTION_H
#define NONDETTMEXECUTION_H

#include "NonDetTMExecBranch.h"
#include "Number.h"
#include <list>

struct NonDetTM;

struct NonDetTMExecution
{
	std::list<NonDetTMExecBranch> branches;
	
	NonDetTMExecution();
	void step(const NonDetTM& tm);
	void removeDuplicateBranches();
	void removeFinals(Number stateCount);
};

#endif // NONDETTMEXECUTION_H
