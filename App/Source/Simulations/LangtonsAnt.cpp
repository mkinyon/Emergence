
#include "LangtonsAnt.h"
#include <random>
#include <olcPixelGameEngine.h>

namespace Simulations
{
	LangtonsAnt::LangtonsAnt(int boardWidth, int boardHeight) : BaseSim(),
        board(boardWidth + 1, std::vector<bool>(boardHeight + 1))
	{
		this->boardWidth = boardWidth;
		this->boardHeight = boardHeight;

        antX = boardWidth / 2;
        antY = boardHeight / 2;

		Reset();
	}

	LangtonsAnt::~LangtonsAnt() {}

	const char* LangtonsAnt::GetTitle() const
	{
		return "Langton's Ant";
	}

	void LangtonsAnt::Simulate()
	{
		if (antX > 0 && antX <= boardWidth && antY > 0 && antY <= boardHeight)
		{
            if (board[antX][antY])
            {
                board[antX][antY] = false;
                moveLeft();
            }
            else
            {
                board[antX][antY] = true;
                moveRight();
            }
		}
	}

	void LangtonsAnt::Reset()
	{
        for (int x = 0; x < boardWidth; x++)
        {
            for (int y = 0; y < boardHeight; y++)
            {
                board[x][y] = false;
            }
        }
	}

	void LangtonsAnt::Interact(int x, int y)
	{
        antX = x;
        antY = y;
	}

	uint8_t LangtonsAnt::GetPixel(int x, int y)
	{
		return board[x][y];
	}

    void LangtonsAnt::moveLeft()
    {
        if (currentDirection == Direction::West)
        {
            currentDirection = Direction::South;
            antY += 1;
        }
        else if (currentDirection == Direction::South)
        {
            currentDirection = Direction::East;
            antX += 1;
        }
        else if (currentDirection == Direction::East)
        {
            currentDirection = Direction::North;
            antY -= 1;
        }
        else
        {
            currentDirection = Direction::West;
            antX -= 1;
        }
    }

    void LangtonsAnt::moveRight()
    {
        if (currentDirection == Direction::West)
        {
            currentDirection = Direction::North;
            antY -= 1;
        }
        else if (currentDirection == Direction::North)
        {
            currentDirection = Direction::East;
            antX += 1;
        }
        else if (currentDirection == Direction::East)
        {
            currentDirection = Direction::South;
            antY += 1;
        }
        else
        {
            currentDirection = Direction::West;
            antX -= 1;
        }
    }
}