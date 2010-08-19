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
	
	NonDetTM();
	NonDetTM& operator++();
	void dump();
};

#endif // NONDETTM_H
