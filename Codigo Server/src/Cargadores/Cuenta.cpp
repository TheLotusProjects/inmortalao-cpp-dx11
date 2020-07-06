#include "Cuenta.h"


Cuenta::Cuenta(string _jsonCuenta)
{
	jsonCuenta = _jsonCuenta;
}

string Cuenta::getJsonCuenta()
{
    return jsonCuenta;
}
