#include "ConnectUser.h"
#include <stdio.h>
#include <string.h>

ConnectUser::ConnectUser()
{
	header=CLIENT_CONNECTCHARACTER;
}


void ConnectUser::SetSharedFilesByJson(Json::Value& root)
{
    unsigned int i=0;
    //for (unsigned int index = 0; index < root.size(); ++index ){
    Json::Value& ja = root[i];
    string asd = ja["nombre"].asString();
    //}
}

string ConnectUser::action(char* mensaje,string identifier)
{
	string* cadena = new string();

	Cuenta* cuenta = (*recursos->cuentas)[identifier];
	string jsonCuenta = (cuenta->getJsonCuenta());


	//Json::Value root;
   	//Json::Reader reader;
    //string asd =(cuenta->getJsonCuenta());
    //bool parsedSuccess = reader.parse(asd, root, false);

    bsoncxx::document::value docValue = bsoncxx::from_json(jsonCuenta);
    //idStr= docValue.view()["_id"].get_utf8().value.to_string();
    
    
    unsigned int i=0;
    //Json::Value& personaje = root["personajes"][i];
    
    bsoncxx::v_noabi::array::element personaje = docValue.view()["personajes"].get_array().value[i];
    
    
    string nombre = personaje["nombre"].get_utf8().value.to_string();
    int head = personaje["head"].get_double().value;
    int body = personaje["body"].get_double().value;
    int casco = personaje["casco"].get_double().value;
    int arma = personaje["weapon"].get_double().value;
    int escudo = personaje["shield"].get_double().value;
    int nivel = personaje["nivel"].get_double().value;
    int map=personaje["map"].get_double().value;
    int clase=personaje["clase"].get_double().value;
    
    int slot;
    int objindex;
    int amount;
    int equipped;
    int grhindex;
    int objType;
    int maxHit;
    int minHit;
    int def;
    int precio;
    int puedeUsar;
    
    
    for (bsoncxx::v_noabi::array::element item : personaje["items"].get_array().value)
    {
        //WriteChangeInventorySlot
        //1,1601,1,0,707,49,0,0,0,0,1
        slot= item["slot"].get_double().value;
        objindex = item["objindex"].get_double().value;
        amount = item["amount"].get_double().value;
        
        //Json::Value objetoJson;
        //Json::Reader reader;
        string objetoStr = (*recursos->objetos)[objindex];
        //bool parsedSuccess = reader.parse(objetoStr, objetoJson, false);
        bsoncxx::document::value objetoJson = bsoncxx::from_json(objetoStr);
        
        equipped = 0;//atoi(objetoJson.view()["equipped"].get_utf8().value.to_string().c_str());
        grhindex = atoi(objetoJson.view()["grhIndex"].get_utf8().value.to_string().c_str());
        objType = atoi(objetoJson.view()["objType"].get_utf8().value.to_string().c_str());
        maxHit = atoi(objetoJson.view()["maxHit"].get_utf8().value.to_string().c_str());
        minHit = atoi(objetoJson.view()["minHit"].get_utf8().value.to_string().c_str());
        def = atoi(objetoJson.view()["minDef"].get_utf8().value.to_string().c_str());
        precio = atoi(objetoJson.view()["valor"].get_utf8().value.to_string().c_str());
        puedeUsar = 1;//atoi(objetoJson.view()["puedeUsar"].get_utf8().value.to_string().c_str());
        
        cadena->append(this->updateInventorySlot(slot,objindex,amount,equipped,grhindex,objType,maxHit,minHit,def,precio,puedeUsar));
    }
    
    
    /*
    for (const Json::Value& hechizo : personaje["hechizos"])
    {
        char slot = hechizo["slot"].asInt();
        int hIndex = hechizo["hIndex"].asInt();;
        //WriteChangeSpellSlot
        //1,2
        cadena->append(this->updateHechizoSlot(slot,hIndex));
    }*/

    
    
    cadena->append(this->MensajesBasicos());

    //3179,3,50,54,0,999,1,1,0
    
    int charIndex = 3179;//personaje["charIndex"].get_double().value;
    int heading = personaje["heading"].get_double().value;
    int x= personaje["x"].get_double().value;
    int y= personaje["y"].get_double().value;
    int fx =0;
    int fxloops =999;
    int privilegies=personaje["privilegies"].get_double().value;
    int account = personaje["account"].get_double().value;
    int bandera=personaje["bandera"].get_double().value;
    
    //CARGAR MAPAS-NPCS y cargarlos para enviar los mapas,npcs y objetos de la poss del pj //checkupdateneededuser
    cadena->append(this->createNpc(charIndex,body,head,heading,x, y, arma, escudo, casco, fx, fxloops, nombre, privilegies,account, bandera));
    
    cadena->append(this->MensajesPosteriores());

	return (*cadena);
}


string ConnectUser::MensajesBasicos()
{
    string* cadena = new string();
    
    
    //WriteUserIndexinServer
    cadena->push_back(SERVER_USERINDEXINSERVER);
    int userIndex=1;
    cadena->push_back(userIndex);
    cadena->push_back(0);
    
    //WriteChangeMap
    cadena->push_back(SERVER_CHANGEMAP);
    
    int num=248;
    char mapa = num;
    cadena->push_back(mapa);
    cadena->push_back(0);
    
    int version=0;
    cadena->push_back(version);
    cadena->push_back(0);
    
    //WritePlayMidi
    cadena->push_back(SERVER_WRITEPLAYMIDI);
    char numeroMidi = 7;
    cadena->push_back(numeroMidi);
    
    
    num=-1;
    char b1 = num & 0x00ff;
    char b2 = (num & 0xff00) >> 8;
    cadena->push_back(b1);
    cadena->push_back(b2);
    
    
    //MakeUserChar
    cadena->push_back(SERVER_WRITEAREACHANGED); //writeareachanged
    cadena->push_back(50);
    cadena->push_back(50);

    return (*cadena);
}

string ConnectUser::MensajesPosteriores()
{
    string * cadena =new string();
    
    
    
    //WriteUserCharIndexInServer
    cadena->push_back(SERVER_WRITEUSERCHARINDEXINSERVER);
    int charIndex=3179;
    char b1 = charIndex & 0x00ff;
    char b2 = (charIndex & 0xff00) >> 8;
    cadena->push_back(b1);
    cadena->push_back(b2);
    
    
    //WriteUpdateUserStats
    cadena->push_back(59);
    int maxHp=353;
    b1 = maxHp & 0x00ff;
    b2 = (maxHp & 0xff00) >> 8;
    cadena->push_back(b1);
    cadena->push_back(b2);
    
    
    int minHp=353;
    b1 = minHp & 0x00ff;
    b2 = (minHp & 0xff00) >> 8;
    cadena->push_back(b1);
    cadena->push_back(b2);
    
    int maxMan=1807;
    b1 = maxMan & 0x00ff;
    b2 = (maxMan & 0xff00) >> 8;
    cadena->push_back(b1);
    cadena->push_back(b2);
    
    int minMan=1807;
    b1 = minMan & 0x00ff;
    b2 = (minMan & 0xff00) >> 8;
    cadena->push_back(b1);
    cadena->push_back(b2);
    
    int maxSta=790;
    b1 = maxSta & 0x00ff;
    b2 = (maxSta & 0xff00) >> 8;
    cadena->push_back(b1);
    cadena->push_back(b2);
    
    int minSta=0;
    b1 = minSta & 0x00ff;
    b2 = (minSta & 0xff00) >> 8;
    cadena->push_back(0);
    cadena->push_back(0);
    
    long numlong=1;
    cadena->push_back(numlong); //GLD
    cadena->push_back(0);
    cadena->push_back(0);
    cadena->push_back(0);
    
    char level=50;
    cadena->push_back(level); //LVL
    
    
    //ELU
    numlong=0;
    cadena->push_back(numlong);
    cadena->push_back(0);
    cadena->push_back(0);
    cadena->push_back(0);
    
    //EXP
    numlong=0;
    cadena->push_back(numlong);
    cadena->push_back(0);
    cadena->push_back(0);
    cadena->push_back(0);
   
    
    //WriteUpdateHungerAndThirst
    cadena->push_back(SERVER_WRITEUPDATEHUNGERANDTHIRST);
    char minAgua = 100;
    cadena->push_back(minAgua);
    char minHam = 100;
    cadena->push_back(minHam);
    
    //WriteSafeModeOff
    cadena->push_back(SERVER_SAFEMODEOFF);
    
    //WriteLoggedMessage
    cadena->push_back(SERVER_LOGGEDMESSAGE);
    char redundance=123;
    cadena->push_back(redundance); //Redundance
    
    
    //WriteFuerza
    cadena->push_back(SERVER_WRITEFUERZA);
    char fuerza=6;
    cadena->push_back(fuerza);
    
    //WriteAgilidad
    cadena->push_back(SERVER_WRITEAGILIDAD);
    char agilidad=20;
    cadena->push_back(agilidad);
    
    //WriteMensageSigno
    cadena->push_back(SERVER_WRITEMESAGESIGNO);
    char cVer =0;
    cadena->push_back(cVer);
    
    //WriteHora
    cadena->push_back(SERVER_HORA);
    cadena->push_back(4);
    cadena->push_back(18);
    
    return (*cadena);
}

string ConnectUser::updateInventorySlot(char slot,int objIndex,int amount,char equipped,int grhindex,char objType,int maxHit,int minHit,int def,long precio, char puedeUsar)
{
	string* cadena = new string();
    
	cadena->push_back(SERVER_UPDATEINVENTORYSLOT);

	cadena->push_back(slot);

	char b1 = objIndex & 0x00ff;
	char b2 = (objIndex & 0xff00) >> 8;
	cadena->push_back(b1);
	cadena->push_back(b2);

	b1 = amount & 0x00ff;
	b2 = (amount & 0xff00) >> 8;
	cadena->push_back(b1);
	cadena->push_back(b2);

    cadena->push_back(equipped);

	b1 = grhindex & 0x00ff;
	b2 = (grhindex & 0xff00) >> 8;
	cadena->push_back(b1);
	cadena->push_back(b2);

	cadena->push_back(objType);

    b1 = maxHit & 0x00ff;
	b2 = (maxHit & 0xff00) >> 8;
	cadena->push_back(b1);
	cadena->push_back(b2);

    b1 = minHit & 0x00ff;
	b2 = (minHit & 0xff00) >> 8;
	cadena->push_back(b1);
	cadena->push_back(b2);

    b1 = def & 0x00ff;
	b2 = (def & 0xff00) >> 8;
	cadena->push_back(b1);
	cadena->push_back(b2);

	b1 = precio & 0x00ff;
	b2 = (precio & 0xff00) >> 8;
	cadena->push_back(b1);
	cadena->push_back(b2);
	cadena->push_back(0);
	cadena->push_back(0);

	cadena->push_back(puedeUsar);

	return (*cadena);
}

string ConnectUser::updateHechizoSlot(char slot, int hIndex)
{
	string* cadena = new string();

	cadena->push_back(SERVER_UPDATEHECHIZOSLOT);

	cadena->push_back(slot);

	char b1 = hIndex & 0x00ff;
	char b2 = (hIndex & 0xff00) >> 8;
	cadena->push_back(b1);
	cadena->push_back(b2);

	return (*cadena);
}

string ConnectUser::createNpc(int charindex,int body,int head,char heading,char x, char y, int weapon, int shield, int helmet, int fx, int fxloops, string name, char privileges,char account, char bandera)
{
    
	string* cadena = new string();

	cadena->push_back(SERVER_CREATEPERSONAJE);

	char b1 = charindex & 0x00ff;
	char b2 = (charindex & 0xff00) >> 8;
	cadena->push_back(b1);
	cadena->push_back(b2);

	b1 = body & 0x00ff;
	b2 = (body & 0xff00) >> 8;
	cadena->push_back(b1);
	cadena->push_back(b2);

	b1 = head & 0x00ff;
	b2 = (head & 0xff00) >> 8;
	cadena->push_back(b1);
	cadena->push_back(b2);

	cadena->push_back(heading);
	cadena->push_back(x);
	cadena->push_back(y);

	b1 = weapon & 0x00ff;
	b2 = (weapon & 0xff00) >> 8;
	cadena->push_back(b1);
	cadena->push_back(b2);

	b1 = shield & 0x00ff;
	b2 = (shield & 0xff00) >> 8;
	cadena->push_back(b1);
	cadena->push_back(b2);

	b1 = helmet & 0x00ff;
	b2 = (helmet & 0xff00) >> 8;
	cadena->push_back(b1);
	cadena->push_back(b2);

	b1 = fx & 0x00ff;
	b2 = (fx & 0xff00) >> 8;
	cadena->push_back(b1);
	cadena->push_back(b2);

	b1 = fxloops & 0x00ff;
	b2 = (fxloops & 0xff00) >> 8;
	cadena->push_back(b1);
	cadena->push_back(b2);


	cadena->push_back(name.size());
	cadena->push_back(0);
	cadena->append(name);

	cadena->push_back(privileges);

	cadena->push_back(account);

	cadena->push_back(bandera);

	return (*cadena);
}
