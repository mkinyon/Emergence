
#include "GameOfLife.h"
#include <random>
#include <olcPixelGameEngine.h>
#include <iostream>

namespace Simulations
{
	GameOfLife::GameOfLife(int boardWidth, int boardHeight) : BaseSim(),
		board(boardWidth + 1, std::vector<bool>(boardHeight + 1))
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
		std::vector<std::vector<bool>> newBoard = board;

		for (int x = 0; x < boardWidth; x++)
		{
			for (int y = 0; y < boardHeight; y++)
			{
				// get the number of neighbors
				int neighborCount = getNeighborCount(x, y);

				// check if this cell is alive
				bool isAlive = board[x][y];
				if (isAlive)
				{
					// If the cell has 1 or no neighbors, it dies.
					// If the cell has 4 or more neighbors, it dies.
					if (neighborCount < 2 || neighborCount > 3)
					{
						newBoard[x][y] = false;
					}
				}
				else
				{
					// If the empty space has 3 neighbors, the cell is now alive.
					if (neighborCount == 3)
					{
						newBoard[x][y] = true;
					}
				}
			}
		}

		board = newBoard;
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
		return board[x][y];
	}

	void GameOfLife::addCell(int x, int y)
	{
		if (x > 0 && y > 0 && x <= boardWidth && y <= boardHeight)
		{
			board[x][y] = true;
		}
	}

	uint8_t GameOfLife::getNeighborCount(int xPos, int yPos)
	{
		uint8_t count = 0;
		for (int x = -1; x <= 1; x++)
		{
			for (int y = -1; y <= +1; y++)
			{
				// do not count itself
				if (x == 0 && y == 0)
				{
					continue;
				}

				int newRow = xPos + x;
				int newCol = yPos + y;

				if (newRow >= 0 && newRow <= boardWidth && newCol >= 0 && newCol <= boardHeight)
				{
					count += board[newRow][newCol] ? 1 : 0;
				}
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
				board[x][y] = result;
			}
		}
	}
}