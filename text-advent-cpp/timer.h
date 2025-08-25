#pragma once

#include <raylib.h>
#include <iostream>


class Timer {
	public:
		Timer();
		void Start(float);
		void StartLoop(float);
		void Reset();
		void Pause();
		void Resume();
		bool Expired();
		float Remaining();
		int  GetNumLoops();
		void Update(float dt);

	private:
		float time;
		float remaining;
		bool active;
		bool loops;
		int numLoops;
};
