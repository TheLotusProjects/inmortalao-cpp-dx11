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

