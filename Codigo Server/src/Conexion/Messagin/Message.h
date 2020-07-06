#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <string>
#include "Messages.h"
#include "../../Cargadores/Resources.h"
#include "../../Common/split.h"

using namespace std;


class Message
{
		protected:
			int header;
			Resources* recursos;
		public:
			Message(){};
			virtual string action(char* mensaje,string identifier) =0;
			int getHeader(){return header;};
			void setRecursos(Resources* recursosParam){recursos=recursosParam;};
			~Message(){};
};

#endif