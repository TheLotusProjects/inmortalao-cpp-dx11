/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#ifndef _PROGRAMA_H
#define _PROGRAMA_H

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include "InputTeclas.h"
#include "Grafica.h"
#include "EditorMapas.h"
#include <iostream>


class Programa
{
public:
	Programa();
	~Programa();
	void InitializeWindows(int& screenWidth, int& screenHeight);
	LRESULT CALLBACK MessageHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam);
	bool Inicializar();
	void Run();
	void Shutdown();

private:
	//void InitializeWindows(int& screenWidth, int& screenHeight);
	bool CreateDXWindows(char* windowTitle, int x, int y, int width, int heigth);	
	void ShutdownWindows();
	bool Frame();
	HWND m_hwnd;
	InputTeclas* inputTeclas;
	Grafica* grafica;

	LPCWSTR nombreAplicacion;
	HINSTANCE instancia;
	//HWND m_hwnd;

	int anchoPictureBox, altoPictureBox;
};


LRESULT CALLBACK WndProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam);

static Programa* ApplicationHandle = 0;

#endif