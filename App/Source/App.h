#pragma once

#include "olcPixelGameEngine.h"
#include "Simulations/BaseSim.h"
#include "Simulations/FallingSand.h"
#include "Simulations/GameOfLife.h"
#include "Simulations/LangtonsAnt.h"

class App : public olc::PixelGameEngine
{
public:
	App(int maxWidth, int maxHeight);
	~App();
	

public:
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;

	Simulations::BaseSim* CreateSimulation(Simulations::BaseSim* sim);
	void HandleInput();
	void Tick(float fElapsedTime);
	void Render();

private:
	int mMaxWidth = 0;
	int mMaxHeight = 0;
	Simulations::BaseSim* mSimulation = nullptr;
	float mElapsedTime = 0.0f;
	bool mIsPaused = false;
};