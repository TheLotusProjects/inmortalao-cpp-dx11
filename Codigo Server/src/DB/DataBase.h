/*
 * dataBase.h
 *
 *  Created on: 23/03/2015
 *      Author: lotus
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include <iostream>

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

#include "../jsoncpp/json.h"

#include <vector>

using mongocxx::client;
using mongocxx::database;
using mongocxx::collection;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::document;
using mongocxx::uri;
using std::cout;
using std::endl;

class DataBase {
private:
	database db;
	client* conn;
	collection collection;
public:
	DataBase();
	void cargar();
	void setTabla(std::string nombreTabla);
	void insertar(std::string jsonConsulta);
	std::vector<std::string>* buscar(std::string jsonConsulta);
	void borrar();
	virtual ~DataBase();
};

#endif /* DATABASE_H_ */
