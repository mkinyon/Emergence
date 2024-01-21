#include "App.h"

App::App(int maxWidth, int maxHeight)
{
	mMaxWidth = maxWidth;
	mMaxHeight = maxHeight;
	sAppName = "Emergence";
}

App::~App() {}

bool App::OnUserCreate()
{
	mSimulation = CreateSimulation(new Simulations::GameOfLife(mMaxWidth, mMaxHeight));
	return true;
}

bool App::OnUserUpdate(float fElapsedTime)
{
	Tick(fElapsedTime);
	HandleInput();
	Render();

	return true;
}

Simulations::BaseSim* App::CreateSimulation(Simulations::BaseSim* newSim)
{
	if (mSimulation != nullptr)
	{
		delete mSimulation;
	}
	mSimulation = newSim;
	sAppName = mSimulation->GetTitle();

	return mSimulation;
}

void App::HandleInput()
{
	if (GetMouse(0).bHeld)
	{
		mSimulation->Interact(float(GetMouseX()), float(GetMouseY()));
	}
	if (GetKey(olc::Key::R).bHeld)
	{
		mSimulation->Reset();
	}
	if (GetKey(olc::Key::P).bPressed)
	{
		mIsPaused = !mIsPaused;
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
				mSimulation = CreateSimulation(new Simulations::GameOfLife(mMaxWidth, mMaxHeight));
				break;
			case 1:
				mSimulation = CreateSimulation(new Simulations::LangtonsAnt(mMaxWidth, mMaxHeight));
				break;
			case 2:
				mSimulation = CreateSimulation(new Simulations::FallingSand(mMaxWidth, mMaxHeight));
				break;
		}
	}
}

void App::Tick(float fElapsedTime)
{
	mElapsedTime += fElapsedTime;
	if (mElapsedTime >= 0.001f && !mIsPaused)
	{
		mSimulation->Simulate();
		mElapsedTime = 0.0f;
	}
}

void App::Render()
{
	for (int x = 0; x < ScreenWidth(); x++)
	{
		for (int y = 0; y < ScreenHeight(); y++)
		{
			Draw(x, y, mSimulation->GetPixel(x, y) ? olc::WHITE : olc::BLACK);
		}
	}
}