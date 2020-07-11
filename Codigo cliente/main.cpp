/*
	Author: Jose Ignacio Castelli
	Email: joseignaciocastelli@gmail.com
	Github: https://github.com/JicLotus
	Medium Page: https://medium.com/@joseignaciocastelli92
	Date: 01/01/2017
*/

#include "Programa.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{

	Programa* programa = new Programa();

	if (programa->Inicializar())
	{
		programa->Run();
	}

	programa->Shutdown();
	delete programa;

	return 0;
}
