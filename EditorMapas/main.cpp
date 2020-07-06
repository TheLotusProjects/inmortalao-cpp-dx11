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
