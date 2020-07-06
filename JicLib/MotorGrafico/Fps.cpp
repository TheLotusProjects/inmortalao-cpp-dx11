#include "Fps.h"


Fps::Fps()
{

}

void Fps::Initialize()
{
	m_fps = 0;
	m_count = 0;
	m_startTime = timeGetTime();
	return;
}

void Fps::Frame()
{
	

	if (timeGetTime() >= (m_startTime + 1000))
	{
		m_fps = m_count;
		m_count = 0;

		m_startTime = timeGetTime();
	}
	else{ m_count++; }
}

int Fps::GetFps()
{
	return m_fps;
}

Fps::~Fps()
{
}
