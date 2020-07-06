/*
 * main.cpp
 *
 *  Created on: 23/03/2015
 *      Author: lotus
 */

#include "Program.h"


int main(int argc, char **argv)
{
    
	Program* programa = new Program();
	programa->run();
	delete(programa);
	return 0;
}
