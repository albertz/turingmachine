#ifndef NONDETTMEXECBRANCH_H
#define NONDETTMEXECBRANCH_H

#include "TMTape.h"
#include "Number.h"
#include <list>

struct NonDetTM;

struct NonDetTMExecBranch {
	TMTape tape;
	Number state;
	
	void step(const NonDetTM& tm, std::list<NonDetTMExecBranch>& branches);
};

#endif // NONDETTMEXECBRANCH_H
