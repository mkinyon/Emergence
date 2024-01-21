#define OLC_PGE_APPLICATION
#include "App.h" 

const int MAX_WIDTH = 300;
const int MAX_HEIGHT = 300;

int main()
{
	App demo(MAX_WIDTH, MAX_HEIGHT);
	if (demo.Construct(MAX_WIDTH, MAX_HEIGHT, 4, 4))
		demo.Start();

	return 0;
}