
#include "GameOfLife.h"
#include <random>
#include <olcPixelGameEngine.h>
#include <iostream>

namespace Simulations
{
	GameOfLife::GameOfLife(int boardWidth, int boardHeight) : BaseSim(),
		currentBoard(boardWidth + 1, std::vector<bool>(boardHeight + 1)),
		tempBoard(boardWidth + 1, std::vector<bool>(boardHeight + 1))
	{
		this->boardWidth = boardWidth;
		this->boardHeight = boardHeight;

		Reset();
	}

	GameOfLife::~GameOfLife() {}

	const char* GameOfLife::GetTitle() const
	{
		return "Game of Life";
	}

	void GameOfLife::Simulate()
	{
		int neighborCounts = 0;
		bool isAlive = false;

		// clear temp board
		for (int x = 0; x < boardWidth; x++)
		{
			for (int y = 0; y < boardHeight; y++)
			{
				tempBoard[x][y] = false;
			}
		}

		// Flag cells as either alive or dead
		for (int x = 0; x < boardWidth; x++)
		{
			for (int y = 0; y < boardHeight; y++)
			{
				// get the number of neighbors
				neighborCounts = getNeighborCount(x, y);

				// check if this cell is alive
				isAlive = currentBoard[x][y];

				// Process this cells results based on the game of life rules.
				tempBoard[x][y] = (isAlive && (neighborCounts == 2 || neighborCounts == 3)) || (!isAlive && neighborCounts == 3);
			}
		}

		// copy temp board to currentboard
		for (int x = 0; x < boardWidth; x++)
		{
			for (int y = 0; y < boardHeight; y++)
			{
				currentBoard[x][y] = tempBoard[x][y];
			}
		}
	}

	void GameOfLife::Reset()
	{
		randomizeBoard();
	}

	void GameOfLife::Interact(int x, int y)
	{
		addCell(x, y);
	}

	uint8_t GameOfLife::GetPixel(int x, int y)
	{
		return getCell(x, y);
	}

	bool GameOfLife::getCell(int x, int y)
	{
		return currentBoard[x][y];
	}

	void GameOfLife::addCell(int x, int y)
	{
		if (x > 0 && y > 0 && x <= boardWidth && y <= boardHeight)
		{
			currentBoard[x][y] = true;
		}
	}

	uint8_t GameOfLife::getNeighborCount(int xPos, int yPos)
	{
		uint8_t count = 0;
		for (int x = xPos - 1; x <= xPos + 1 && xPos > 0 && xPos <= boardWidth; x++)
		{
			for (int y = yPos - 1; y <= yPos + 1 && yPos > 0 && yPos <= boardHeight; y++)
			{
				count += currentBoard[x][y] ? 1 : 0;
			}
		}

		return count;
	}

	void GameOfLife::randomizeBoard()
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(0,1);

		for (int x = 0; x < boardWidth; x++)
		{
			for (int y = 0; y < boardHeight; y++)
			{
				bool result = static_cast<bool>(dis(gen));
				currentBoard[x][y] = result;
			}
		}
	}
}