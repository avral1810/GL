#include <iostream>
#include <string>
#include <vector>
#include "display.h"


int main()
{
	Display window("Aviral", 800, 600);
	
	std::vector<float> colors(4, 0.1f);
	long counter = 0;
	float mul = 0.1f;
	while(window.alive())
	{
		if (counter % 10 == 0)
		{
			for(int i = 0; i < 4; i++)
			{
				colors[i] =  colors[i] + mul;

				if (colors[i] > 1.0f || colors[i] < 0.0f)
				{
					mul *= -1;
					
				}
				std::cout<<colors[i]<<" ";
			}
			std::cout<<std::endl;
			counter = 0;
		}
		window.clear(colors[0], colors[1], colors[2], colors[3]);
		counter++;
	}
    window.kill();
}