
#include "FallingSand.h"

namespace Simulations
{
	FallingSand::FallingSand(int boardWidth, int boardHeight) : BaseSim(),
		board(boardWidth + 1, std::vector<bool>(boardHeight + 1))
	{
		this->boardWidth = boardWidth;
		this->boardHeight = boardHeight;

		Reset();
	}

	FallingSand::~FallingSand() {}

	const char* FallingSand::GetTitle() const
	{
		return "Falling Sand";
	}

	void FallingSand::Simulate()
	{
		for (int x = boardWidth - 1; x > 0; x--)
		{
			for (int y = boardHeight - 1; y > 0; y--)
			{
				bool isSand = board[x][y]; 
				if (!isSand)
				{
					continue;
				}

				if (y == boardHeight - 1)
				{
					continue;
				}

				bool isSandBelow = board[x][y + 1];
				if (!isSandBelow)
				{
					board[x][y] = false;
					board[x][y + 1] = true;
					continue;
				}
				bool isSandBelowLeft = board[x - 1][y + 1] == true;
				if (!isSandBelowLeft)
				{
					board[x][y] = false;
					board[x - 1][y + 1] = true;
					continue;
				}
				bool isSandBelowRight = board[x + 1][y + 1] == true;
				if (!isSandBelowRight)
				{
					board[x][y] = false;
					board[x + 1][y + 1] = true;
					continue;
				}
			}
		}
	}

	void FallingSand::Reset()
	{
		for (int x = 0; x < boardWidth; x++)
		{
			for (int y = 0; y < boardHeight; y++)
			{
				board[x][y] = false;
			}
		}
	}

	void FallingSand::Interact(int x, int y)
	{
		if (x > 0 && y > 0 && x <= boardWidth && y <= boardHeight)
		{
			board[x][y] = true;
		}
	}

	uint8_t FallingSand::GetPixel(int x, int y)
	{
		return board[x][y];
	}
}