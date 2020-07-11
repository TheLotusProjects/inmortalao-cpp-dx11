/*
	Author: Jose Ignacio Castelli
	Email: joseignaciocastelli@gmail.com
	Github: https://github.com/JicLotus
	Medium Page: https://medium.com/@joseignaciocastelli92
	Date: 01/01/2017
*/


#pragma once


#ifndef _PROGRAMA_H
#define _PROGRAMA_H

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include "Graphic.h"
#include "InputTeclas.h"

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
	void ShutdownWindows();
	bool Frame();
	HWND m_hwnd;
	InputTeclas* inputTeclas;
	LPCWSTR m_applicationName;
	HINSTANCE m_hinstance;
	Graphic* graphic;
};

LRESULT CALLBACK WndProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam);

static Programa* ApplicationHandle = 0;

#endif