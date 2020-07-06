#ifndef WALK_H_
#define WALK_H_

#include <string>
#include "Message.h"


using namespace std;

class Walk : public Message
{
	public:
		Walk();
		~Walk();
		string action(char* mensaje,string identifier);
	private:
};

#endif