#include "LogIn.h"
#include <string.h>
#include <iostream>

LogIn::LogIn()
{
	header=CLIENT_LOGIN;
}

string LogIn::action(char* mensaje,string identifier)
{
	int longitud1=mensaje[1];
	int longitud2=mensaje[2];
	int longitudTotal=longitud1+longitud2;

	char sb[longitudTotal];
	memcpy(sb,&mensaje[3],longitudTotal);
	
	std::string nombreCuenta(sb);
	
	int longitud12=int(mensaje[3+longitudTotal]);
	int longitud22=int(mensaje[3+longitudTotal+1]);
	int longitudTotal2=int(longitud12+longitud22);

	char* sb2 = new char[longitudTotal2];
	memcpy(sb2,&mensaje[3+longitudTotal+2],longitudTotal2);
	
	string contrasenia(sb2);
  	
	string jsonInsertarCuenta= "{ \"_id\":\"" + nombreCuenta+ "\", \"password\":\""+ contrasenia+"\" }";


	recursos->baseDeDatos->setTabla("cuentas");
	std::string cuentaJson = (*recursos->baseDeDatos->buscar(jsonInsertarCuenta))[0];
	

    //Json::Value root;
    //Json::Reader reader;
    //bool parsedSuccess = reader.parse(cuentaJson, root, false);
    //reader.parse(cuentaJson, root, false);
    
	std::string nombre;
	int head;
	int body;
	int casco;
	int arma;
	int escudo;
	int nivel;
	int map;
	int clase;
	int color;
	int tipoMascota;


	string* cadena = new string();
	cadena->push_back(99);

	Cuenta* cuenta = new Cuenta(cuentaJson);
	(*recursos->cuentas)[identifier]= cuenta;

    
    
    bsoncxx::document::value docValue = bsoncxx::from_json(cuentaJson);
    //idStr= docValue.view()["_id"].get_utf8().value.to_string();
    
    
    
    
    for (bsoncxx::v_noabi::array::element personaje : docValue.view()["personajes"].get_array().value)
    {
        //docValue.view()["_id"].get_array().value[0];
        nombre = personaje["nombre"].get_utf8().value.to_string();
        
        head = personaje["head"].get_double().value;
        body = personaje["body"].get_double().value;
        casco = personaje["casco"].get_double().value;
        arma = personaje["weapon"].get_double().value;
        escudo = personaje["shield"].get_double().value;
        nivel = personaje["nivel"].get_double().value;
        map=personaje["map"].get_double().value;
        clase=personaje["clase"].get_double().value;
        color=5;
        tipoMascota=personaje["tipPet"].get_double().value;;
        
        cadena->push_back(98);
        cadena->push_back(1);
        //Longitud Nombre
        cadena->push_back(nombre.size());
        cadena->push_back(0);
        cadena->append(nombre);
        cadena->push_back(head);
        cadena->push_back(0);
        cadena->push_back(body);
        cadena->push_back(0);
        cadena->push_back(casco);
        cadena->push_back(arma);
        cadena->push_back(escudo);
        cadena->push_back(nivel);
        cadena->push_back(map);
        cadena->push_back(0);
        cadena->push_back(clase);
        cadena->push_back(color);
        cadena->push_back(tipoMascota);
    }

/*
	for (const Json::Value& personaje : root["personajes"])
	{

		nombre = personaje["nombre"].asString();
		head = personaje["head"].asInt();
		body = personaje["body"].asInt();
		casco = personaje["casco"].asInt();
		arma = personaje["weapon"].asInt();
		escudo = personaje["shield"].asInt();
		nivel = personaje["nivel"].asInt();
		map=personaje["map"].asInt();
		clase=personaje["clase"].asInt();
		color=5;
		tipoMascota=personaje["tipPet"].asInt();

		cadena->push_back(98);
		cadena->push_back(1);
		//Longitud Nombre
		cadena->push_back(nombre.size());
		cadena->push_back(0);
		cadena->append(nombre);
		cadena->push_back(head);
		cadena->push_back(0);
		cadena->push_back(body);
		cadena->push_back(0);
		cadena->push_back(casco);
		cadena->push_back(arma);
		cadena->push_back(escudo);
		cadena->push_back(nivel);
		cadena->push_back(map);
		cadena->push_back(0);
		cadena->push_back(clase);
		cadena->push_back(color);
		cadena->push_back(tipoMascota);
	}*/

	delete[] sb2;

	return (*cadena);
}

/*
 

{ "_id" : "marius", "password" : "1", "personajes" : [ { "nombre" : "Marius", "head" : 102, "body" : 53, "casco" : 2, "weapon" : 2, "shield" : 2, "nivel" : 50, "map" : 49,"x":50,"y":50, "clase" : 2, "tipPet" : 9, "items": [ { "slot":1,"objindex":1601,"amount":1}],"hechizos": [{"slot":1, "hindex":2}],"privilegies":1,"account":1,"bandera":0,"heading":3,"mapHp":353,"minHp":353,"maxMan":1807,"minMan":1807,"maxSta":790,"minSta":0,"gld":123,"elu":0,"exp":0,"minAgua":100,"minHam":100,"fuerza":6,"agilidad":20  } ] }
 
*/

LogIn::~LogIn()
{
	
}
