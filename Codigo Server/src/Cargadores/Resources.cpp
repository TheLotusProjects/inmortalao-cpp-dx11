/*
 * Resources.cpp
 *
 *  Created on: 23/03/2015
 *      Author: lotus
 */

#include "Resources.h"


Resources::Resources() {
	baseDeDatos = new DataBase();
	cuentas = new map<string,Cuenta*>();
    objetos= new map<int,string>();
    
    
	npcs= new Npcs();
	hechizos= new Hechizos();
	mapas = new Mapas();
}

void Resources::cargar()
{
    baseDeDatos->cargar();
    
    baseDeDatos->setTabla("objetos");
    std::vector<std::string>* objetosJson = baseDeDatos->buscar("{}");
    
    int id;
    string idStr;
    int equipped;
    
    
    for (unsigned int i =0 ;i<objetosJson->size();i++)
    {
        string objeto = (*objetosJson)[i];
        bsoncxx::document::value docValue = bsoncxx::from_json(objeto);
        idStr= docValue.view()["_id"].get_utf8().value.to_string();
        
        id = atoi(idStr.c_str());
       
        (*objetos)[id] = objeto;
    }
    
}


Resources::~Resources() {
	delete(npcs);
	delete(objs);
	delete(hechizos);
	delete(mapas);
	delete(baseDeDatos);
}
