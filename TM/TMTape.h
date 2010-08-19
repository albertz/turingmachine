#ifndef TMTAPE_H
#define TMTAPE_H

#include "TMAlphabet.h"
#include <list>

struct TMTape
{
	std::list<TMAlphabet> left, curAndRight;

	void writeCurrent(TMAlphabet c) {
		if(curAndRight.size() > 0)
			curAndRight.front() = c;
		else
			curAndRight.push_front(c);
	}
	
	TMAlphabet current() const {
		if(curAndRight.size() > 0)
			return curAndRight.front();
		return TMAx;
	}
	
	void moveLeft() {
		if(curAndRight.size() > 0) {
			left.push_back(curAndRight.front());
			curAndRight.pop_front();
		}
		else
			left.push_back(TMAx);			
	}

	void moveRight() {
		if(left.size() > 0) {
			curAndRight.push_front(left.back());
			curAndRight.pop_back();
		}
		else
			left.push_front(TMAx);		
	}

	void move(int m) {
		while(m < 0) { moveLeft(); ++m; }
		while(m > 0) { moveRight(); --m; }
	}
};

#endif // TMTAPE_H
