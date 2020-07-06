#include "Timer.h"

Timer::Timer()
{
}


Timer::Timer(const Timer& other)
{
}


Timer::~Timer()
{
}


bool Timer::Initialize()
{
	/*
	// Check to see if this system supports high performance timers.
	QueryPerformanceFrequency((LARGE_INTEGER*)&m_frequency);
	if (m_frequency == 0)
	{
		return false;
	}

	// Find out how many times the frequency counter ticks every millisecond.
	m_ticksPerMs = (float)(m_frequency * 1000);

	QueryPerformanceCounter((LARGE_INTEGER*)&m_startTime);*/


	m_frequency = 0;

	return true;
}


void Timer::Frame()
{
	INT64 currentTime;
	float timeDifference;


	if (m_frequency == 0)
	{
		QueryPerformanceFrequency((LARGE_INTEGER*)&m_frequency);
	}

	QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);

	timeDifference = (float)(currentTime - m_startTime);

	m_frameTime = timeDifference / m_frequency*1000.0;


	//m_startTime = currentTime;

	QueryPerformanceCounter((LARGE_INTEGER*)&m_startTime);

	return;
}


float Timer::GetTime()
{
	return m_frameTime;
}