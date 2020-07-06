#ifndef LOGIN_H_
#define LOGIN_H_

#include "Message.h"



class LogIn : public Message
{
	public:
		LogIn();
		~LogIn();
		string action(char* mensaje,string identifier);
	private:
		
};

#endif
