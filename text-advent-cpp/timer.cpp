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

void Timer::Start(float seconds)
{
	this -> time = seconds;
	this -> remaining = time;
	this -> active = true;
	this -> loops = false;
	this -> numLoops = 0;
}


void Timer::StartLoop(float seconds)
{
	this -> time = seconds;
	this -> remaining = time;
	this -> active = true;
	this -> loops = true;
	this -> numLoops = 0;
}


void Timer::Reset()
{
	if (time > 0)
		this -> remaining = time;
	else
		return;
	this -> active = true;
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
			numLoops++;
			Reset();
			return;
		}
		this -> active = false;
	}
	remaining -= seconds;
}

int Timer::GetNumLoops()
{
	return numLoops;
}
