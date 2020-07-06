#ifndef CONNECTUSER_H_
#define CONNECTUSER_H_

#include <string>
#include "Message.h"


using namespace std;

class ConnectUser : public Message
{
	public:
		ConnectUser();
		~ConnectUser();
		string action(char* mensaje,string identifier);
	private:
		string createNpc(int charindex,int body,int head,char heading,char x, char y, int weapon, int shield, int helmet, int fx, int fxloops, string name, char privileges,char account, char bandera);
		string updateInventorySlot(char slot,int objIndex,int amount,char equipped,int grhindex,char objType,int maxHit,int minHit,int def,long precio, char puedeUsar);
		string updateHechizoSlot(char slot, int hIndex);
        string MensajesBasicos();
        string MensajesPosteriores();
        void SetSharedFilesByJson(Json::Value& root);
};

#endif
