#ifndef NONDETTM_H
#define NONDETTM_H

#include "Number.h"
#include "TMActionInput.h"
#include "TMAction.h"
#include <map>
#include <set>

struct NonDetTM
{
	Number stateCount;
	std::map< TMActionInput, std::set<TMAction> > transitions;
	
	NonDetTM() : stateCount(0) {}
};

#endif // NONDETTM_H
