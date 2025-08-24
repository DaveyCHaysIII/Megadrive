#pragma once

#include <raylib.h>
#include <iostream>


class Timer {
	public:
		Timer();
		void Start(float seconds);
		void Reset();
		void Pause();
		void Resume();
		bool Expired();
		void Loop();
		void GetNumLoops();
		void Update(float dt);

	private:
		float time;
		float remaining;
		bool active;
		bool loops;
		int numLoops;
};
