/*
 * Objs.h
 *
 *  Created on: 24/03/2015
 *      Author: lotus
 */

#ifndef OBJS_H_
#define OBJS_H_

#include <map>
#include "Obj.h"

class Objs {
public:
	Objs();
	void cargar();
	virtual ~Objs();
private:
	std::map<int,Obj*>* objetos;
};

#endif /* OBJS_H_ */
