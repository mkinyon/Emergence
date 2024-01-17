#pragma once
#include <stdint.h>

namespace Simulations
{
	class BaseSim
	{
	public:
		BaseSim() {}

		virtual const char* GetTitle() const = 0;
		virtual void Simulate() {};
		virtual void Reset() {};
		virtual void Interact(int x, int y) {};
		virtual uint8_t GetPixel(int x, int y) { return 0; };
	};
}