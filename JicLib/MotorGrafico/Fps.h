/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#pragma once

#pragma comment(lib, "winmm.lib")

#include <windows.h>
#include <mmsystem.h>

class Fps
{
public:
	Fps();
	void Initialize();
	void Frame();
	int GetFps();
	~Fps();
private:
	int m_fps, m_count;
	unsigned long m_startTime;

};

