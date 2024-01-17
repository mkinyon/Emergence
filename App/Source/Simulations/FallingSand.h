#pragma once

#include "BaseSim.h"
#include <stdint.h>
#include <vector>

namespace Simulations
{
	class FallingSand : public BaseSim
	{
	public:
		FallingSand(int boardWidth, int boardHeight);
		~FallingSand();

		const char* GetTitle() const;
		void Simulate();
		void Reset();
		void Interact(int x, int y);
		uint8_t GetPixel(int x, int y);

	private:

	private:
		int boardWidth;
		int boardHeight;
		std::vector<std::vector<bool>> board;
	};
}