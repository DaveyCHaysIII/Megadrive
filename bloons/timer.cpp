#include "timer.h"
#include <iostream>


Timer::Timer()
{
	this -> time = 0;
	this -> remaining = time;
	this -> active = false;
	this -> loops = false;
	this -> numLoops = 0;
}

Timer::Start(float seconds)
{
	this -> time = seconds;
	this -> remaining = time;
	this -> active = true;
	this -> loops = false;
	this -> numloops = 0;
}

void Timer::Reset()
{
	if (time > 0)
		this -> remaining = time;
	else
		return;
	this -> active = true;
}

void Timer::Loops()
{
	this -> loops = true;
}


bool Timer::Expired()
{
	return !active;
}

float Timer::Remaining()
{
	if (active)
		return (remaining);
	else
		return (0);
}


void Timer::Update(float seconds)
{
	if (!active)
		return;
	if (remaining <= 0)
	{
		if (loops)
		{
			numloops++;
			Reset();
			return;
		}
		this -> active = false;
	}
	remaining -= seconds;
}

