#pragma once
#include "Dibujador.h"
#include "../ImGui/imgui.h"
#include "../ImGui/imgui_impl_win32.h"
#include "../ImGui/imgui_impl_dx11.h"

class Console : public Dibujador
{
public:
	Console(Directx11* directx11Param, Recursos* recursosParam);
	void dibujar(std::string mensaje, D3DXMATRIX viewMatrix, D3DXMATRIX projMatrix, D3DXMATRIX worldMatrix);
	void load(int anchoPantalla, int altoPantalla);
	~Console();
private:
	void showExampleConsole();
	Directx11* directx11;
	Recursos* recursos;
	Grafico* slot;
};