

#ifndef _PROGRAMA_H
#define _PROGRAMA_H

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include "InputTeclas.h"
#include "Grafica.h"
#include "EditorFrm.h"
#include <iostream>


class Programa
{
public:
	Programa();
	~Programa();

	LRESULT CALLBACK MessageHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam);
	bool Inicializar();
	void Run();
	void Shutdown();

private:
	void InitializeWindows(int& screenWidth, int& screenHeight);
	bool CreateDXWindows(char* windowTitle, int x, int y, int width, int heigth);	
	void ShutdownWindows();
	bool Frame();
	
	InputTeclas* inputTeclas;
	Grafica* grafica;

	LPCWSTR nombreAplicacion;
	HINSTANCE instancia;
	HWND m_hwnd;

	int anchoPictureBox, altoPictureBox;
};


LRESULT CALLBACK WndProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam);

static Programa* ApplicationHandle = 0;

#endif