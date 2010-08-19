#include "NonDetTMExecution.h"
#include "NonDetTM.h"
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	NonDetTM tm;
	std::vector<NonDetTM> tms(10);
	for(size_t i = 0; i < tms.size(); ++i, ++tm) tms[i] = tm;

	std::vector<NonDetTMExecution> tmExecs(tms.size());
	while(true)
		for(size_t i = 0; i < tms.size(); ++i) {
			cout << "TM#" << i << ": ";
			tmExecs[i].step(tms[i]);
			cout << endl;
		}
	
    return 0;
}
