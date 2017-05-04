#include "curses.h"
#include "ground.hpp"

//this is where lines, cols, base_height_divisor, and max_heigh_divisor are created
int lines = 40;
int cols = 120;
int base_height_divisor = 8;
int max_height_divisor = 2;

//ground was initialized in ground.hpp
void Ground::InitializeGround()
{
	int current_height = lines - lines / base_height_divisor;
	int maximum_height = lines / max_height_divisor;

	for (int i = 1; i < cols - 1; i++) {
		int h = current_height;
		int r = rand() % 10000;
		if (r < 800) {
			current_height++;
			if (current_height >= lines - 2)
				current_height = lines - 2;
		}
		else if (r < 1600) {
			current_height--;
			if (current_height < 1)
				current_height = 1;
		}

		ground.push_back(h);
	}
}

void Ground::Draw()
{
	//goes from left to right. + rows and cols
	mvaddch(ground.at(0), 1, '_');
	for (size_t i = 1; i < ground.size(); i++) 
	{
		if (ground.at(i) > ground.at(i-1))
		{
			mvaddch(ground.at(i), i + 1, '\\');
		}
		
		else if (ground.at(i) < ground.at(i-1))
		{
			mvaddch(ground.at(i)+1 , i + 1, '/');
		}
		
		else
		mvaddch(ground.at(i), i + 1, '_');

		//make one for straight up '|'
		//to do this you have to make sure that they are on the same "line"
		//if you come across one of these you can't move past
	}
}

