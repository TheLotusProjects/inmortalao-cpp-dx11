/*
 * dataBase.cpp
 *
 *  Created on: 23/03/2015
 *      Author: lotus
 */

#include "DataBase.h"



DataBase::DataBase() {
    uri uri("mongodb://localhost:27017");
    conn = new mongocxx::client(uri);
    db = (*conn)["inmortalAO"];
}


void DataBase::setTabla(std::string nombreTabla)
{
    collection = db[nombreTabla];
}

void DataBase::cargar()
{
    //La idea es abrir la DB aca, guardar la instancia y crear los metodos Update,insert y delete.
    //La onda es pasar este metodo a los objetos y cada uno de ellos obteniendo el collection como resultado sabra mapearlo a su objeto
}


void DataBase::insertar(std::string jsonConsulta)
{
    bsoncxx::document::value doc = bsoncxx::from_json(jsonConsulta);

    Json::Value root;
    Json::Reader reader;
    //bool parsedSuccess = reader.parse(jsonConsulta, root, false);
    reader.parse(jsonConsulta, root, false);
    std::string key = root["_id"].asString();

    std::string consultaExistencia = "{ \"_id\":\""+key+"\" }";

    if (this->buscar(consultaExistencia)->size()==0){
        collection.insert_one(doc.view());
    }

    /*doc = bsoncxx::from_json(R"( { "_id": "dbm", "children": [] })");
    collection.insert_one(doc.view());
    doc = bsoncxx::from_json(R"({"_id": "Databases", "children": [ "MongoDB", "dbm" ] })");
    collection.insert_one(doc.view());
    doc = bsoncxx::from_json(R"({ "_id": "Languages", "children": [] })");
    collection.insert_one(doc.view());
    doc = bsoncxx::from_json(R"({ "_id": "Programming", "children": [ "Databases", "Languages" ] })");
    collection.insert_one(doc.view());
    doc = bsoncxx::from_json(R"({ "_id": "Books", "children": [ "Programming" ] })");
    collection.insert_one(doc.view());*/
}


std::vector<std::string>* DataBase::buscar(std::string jsonConsulta)
{
    bsoncxx::document::value doc = bsoncxx::from_json(jsonConsulta);
    auto cursor = collection.find(doc.view());

    
    std::vector<std::string>* rows = new std::vector<std::string>();

    std::string asda;
    for (auto&& doc : cursor) {
        //std::string name = doc["name"].get_utf8().value.to_string();
        rows->push_back(bsoncxx::to_json(doc));
        //bsoncxx::document::value docValue = bsoncxx::from_json(bsoncxx::to_json(doc));
        //asda= docValue.view()["name"].get_utf8().value.to_string();
        //std::string id = doc["_id"].get_utf8().value.to_string();
    }

    return rows;
}


void DataBase::borrar()
{
    collection.delete_many({});
}


DataBase::~DataBase() {
	delete conn;
}

