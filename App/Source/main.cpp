#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "Simulations/FallingSand.h"
#include "Simulations/GameOfLife.h"
#include "Simulations/LangtonsAnt.h"
#include <thread>

constexpr const int MAX_WIDTH = 300;
constexpr const int MAX_HEIGHT = 300;

Simulations::BaseSim* simulation = new Simulations::GameOfLife(MAX_WIDTH, MAX_HEIGHT);

class App : public olc::PixelGameEngine
{
public:
	App()
	{
		sAppName = "Emergence";
	}

public:
	bool OnUserCreate() override
	{
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		elapsedTime += fElapsedTime;

		// tick simulation
		if (elapsedTime >= 0.001f && !isPaused)
		{
			simulation->Simulate();
			elapsedTime = 0.0f;
		}

		// input
		if (GetMouse(0).bHeld)
		{
			simulation->Interact(float(GetMouseX()), float(GetMouseY()));
		}
		if (GetKey(olc::Key::R).bHeld)
		{
			simulation->Reset();
		}
		if (GetKey(olc::Key::P).bPressed)
		{
			isPaused = !isPaused;
		}
		if (GetKey(olc::Key::C).bPressed)
		{
			static int currentSimIndex = 0;
			currentSimIndex++;
			if (currentSimIndex > 2)
			{
				currentSimIndex = 0;
			}

			switch (currentSimIndex)
			{
			case 0:
				delete simulation;
				simulation = new Simulations::GameOfLife(MAX_WIDTH, MAX_HEIGHT);
				sAppName = simulation->GetTitle();
				break;
			case 1:
				delete simulation;
				simulation = new Simulations::LangtonsAnt(MAX_WIDTH, MAX_HEIGHT);
				sAppName = simulation->GetTitle();
				break;
			case 2:
				delete simulation;
				simulation = new Simulations::FallingSand(MAX_WIDTH, MAX_HEIGHT);
				sAppName = simulation->GetTitle();
				break;
			}
		}

		// draw board
		for (int x = 0; x < ScreenWidth(); x++)
		{
			for (int y = 0; y < ScreenHeight(); y++)
			{
				Draw(x, y, simulation->GetPixel(x, y) ? olc::WHITE : olc::BLACK);
			}
		}

		return true;
	}

private:
	float elapsedTime = 0.0f;
	bool isPaused = false;
};


int main()
{
	App demo;
	if (demo.Construct(MAX_WIDTH, MAX_HEIGHT, 4, 4))
		demo.Start();

	return 0;
}