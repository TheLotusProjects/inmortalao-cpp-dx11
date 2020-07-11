/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "InputTeclas.h"


InputTeclas::InputTeclas()
{
}


InputTeclas::InputTeclas(const InputTeclas& other)
{
}


InputTeclas::~InputTeclas()
{
}


void InputTeclas::Initialize()
{
	int i;


	// Initialize all the keys to being released and not pressed.
	for (i = 0; i<256; i++)
	{
		m_keys[i] = false;
	}

	return;
}


void InputTeclas::KeyDown(unsigned int input)
{
	// If a key is pressed then save that state in the key array.
	m_keys[input] = true;
	return;
}


void InputTeclas::KeyUp(unsigned int input)
{
	// If a key is released then clear that state in the key array.
	m_keys[input] = false;
	return;
}


bool InputTeclas::IsKeyDown(unsigned int key)
{
	// Return what state the key is in (pressed/not pressed).
	return m_keys[key];
}