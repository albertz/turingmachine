#ifndef NONDETTMEXECUTION_H
#define NONDETTMEXECUTION_H

#include "NonDetTMExecBranch.h"
#include <list>

struct NonDetTM;

struct NonDetTMExecution
{
	std::list<NonDetTMExecBranch> branches;
	
	NonDetTMExecution();
	void step(const NonDetTM& tm);
	void removeDuplicateBranches();
};

#endif // NONDETTMEXECUTION_H
