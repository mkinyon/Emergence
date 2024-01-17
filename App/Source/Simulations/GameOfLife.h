#pragma once

#include "BaseSim.h"
#include <stdint.h>
#include <vector>

namespace Simulations
{
	class GameOfLife : public BaseSim
	{
	public:
		GameOfLife(int boardWidth, int boardHeight);
		~GameOfLife();

		const char* GetTitle() const;
		void Simulate();
		void Reset();
		void Interact(int x, int y);
		uint8_t GetPixel(int x, int y);

	private:
		void randomizeBoard();
		uint8_t getNeighborCount(int xPos, int yPos);
		bool getCell(int x, int y);
		void addCell(int x, int y);

	private:
		int boardWidth;
		int boardHeight;
		std::vector<std::vector<bool>> currentBoard;
		std::vector<std::vector<bool>> tempBoard;
	};
}