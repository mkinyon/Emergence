#pragma once

#include "BaseSim.h"
#include <stdint.h>
#include <vector>

namespace Simulations
{
	class LangtonsAnt : public BaseSim
	{
	public:
		LangtonsAnt(int boardWidth, int boardHeight);
		~LangtonsAnt();

		const char* GetTitle() const;
		void Simulate();
		void Reset();
		void Interact(int x, int y);
		uint8_t GetPixel(int x, int y);

	private:
		void moveLeft();
		void moveRight();

	private:
		int boardWidth;
		int boardHeight;
		std::vector<std::vector<bool>> board;

		typedef enum 
		{
			North,
			East,
			South,
			West
		} Direction;

		int antX = 0;
		int antY = 0;

		Direction currentDirection;
	};
}