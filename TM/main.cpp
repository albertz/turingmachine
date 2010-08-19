#include "NonDetTMExecution.h"
#include "NonDetTM.h"
#include <vector>
#include <iostream>

using namespace std;

struct TMPair {
	size_t index;
	NonDetTM tm;
	NonDetTMExecution exec;	
};

int main(int argc, char *argv[])
{
	size_t tmIndex = 0;
	NonDetTM tm;
	const size_t Count = 10;
	std::list<TMPair> tms;
	while(true) {
		while(tms.size() < Count) {
			tms.push_back(TMPair());
			tms.back().index = tmIndex;
			tms.back().tm = tm;
			cout << "new TM#" << tmIndex << ": "; tm.dump();
			++tmIndex; ++tm;
		}
	
		for(std::list<TMPair>::iterator i = tms.begin(); i != tms.end();) {
			cout << "TM#" << i->index << ": ";
			i->exec.step(i->tm);
			cout << endl;
			
			if(i->exec.branches.size() == 0) {
				cout << "killing TM#" << i->index << endl;
				i = tms.erase(i);
			}
			else
				++i;
		}
	}
	
    return 0;
}
