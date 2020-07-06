#ifndef CUENTA_H_
#define CUENTA_H_

#include <list>
#include "Personaje.h"


#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>

#include "../jsoncpp/json.h"

using namespace std;

class Cuenta
{
public:
	Cuenta(string _jsonCuenta);
    string getJsonCuenta();
private:
	//list<Personaje*>* personajes;
    string jsonCuenta;
};


#endif
