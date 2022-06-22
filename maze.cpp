#include <iostream>
#include <stdlib.h>
#include <time.h>
int my_maze[6][6];
int mCurrentRow = 5;
int mCurrentColumn = 4;
int i = 0;
enum {
	NORTH,
	EAST,
	SOUTH,
	WEST
};

void recurse();
int main()
{
	srand(time(NULL));

	for (int create_row = 0; create_row < 6; create_row++)
		for (int create_counter = 0; create_counter < 6; create_counter++)
			my_maze[create_row][create_counter] = 0;

	my_maze[0][4] = 6;
	my_maze[mCurrentRow][mCurrentColumn] = 5;

		recurse();


}

void recurse(void)
{
	do
	{
		int randvalue = rand() % 4;
		switch(randvalue)\
		{
		case NORTH:
		{
			if (mCurrentRow - 1 >= 0)
			{
				if (my_maze[mCurrentRow - 1][mCurrentColumn] == 0 || my_maze[mCurrentRow - 1][mCurrentColumn] == 5)
				{
					my_maze[mCurrentRow - 1][mCurrentColumn] = 1;

					if (mCurrentColumn - 1 >= 0 && my_maze[mCurrentRow][mCurrentColumn - 1] == 0)
						my_maze[mCurrentRow][mCurrentColumn - 1] = 2;

					if (mCurrentColumn + 1 <= 6 && my_maze[mCurrentRow][mCurrentColumn + 1] == 0)
						my_maze[mCurrentRow][mCurrentColumn + 1] = 2;

					mCurrentRow -= 1;

					recurse();
					mCurrentRow += 1;
				}
			}
		}
		break;
		case SOUTH:
		{
			if (mCurrentRow + 1 <= 8)
			{
				if (my_maze[mCurrentRow + 1][mCurrentColumn] == 0 || my_maze[mCurrentRow + 1][mCurrentColumn] == 5)
				{
					my_maze[mCurrentRow + 1][mCurrentColumn] = 1;

					if (mCurrentColumn - 1 >= 0 && my_maze[mCurrentRow][mCurrentColumn - 1] == 0)
						my_maze[mCurrentRow][mCurrentColumn - 1] = 2;

					if (mCurrentColumn + 1 <= 6 && my_maze[mCurrentRow][mCurrentColumn + 1] == 0)
						my_maze[mCurrentRow][mCurrentColumn + 1] = 2;

					mCurrentRow += 1;

					recurse();

					mCurrentRow -= 1;
				}
			}
		}
		break;
		case WEST:
				{
				if (mCurrentColumn - 1 >= 0)
				{
					if (my_maze[mCurrentRow][mCurrentColumn - 1] == 0 || my_maze[mCurrentRow][mCurrentColumn - 1] == 5)
					{
						my_maze[mCurrentRow][mCurrentColumn - 1] = 1;


						if (mCurrentRow - 1 >= 0 && my_maze[mCurrentRow - 1][mCurrentColumn] == 0)
							my_maze[mCurrentRow - 1][mCurrentColumn] = 2;

						if (mCurrentRow + 1 <= 6 && my_maze[mCurrentRow + 1][mCurrentColumn] == 0)
							my_maze[mCurrentRow + 1][mCurrentColumn] = 2;

						mCurrentColumn -= 1;

						recurse();

						mCurrentColumn += 1;
					}
				}
			
				}
			break;
			case EAST:
			{
			if (mCurrentColumn + 1 <= 8)
			{
				if (my_maze[mCurrentRow][mCurrentColumn + 1] == 0 || my_maze[mCurrentRow][mCurrentColumn + 1] == 5)
				{
					my_maze[mCurrentRow][mCurrentColumn + 1] = 1;

					if (mCurrentRow - 1 >= 0 && my_maze[mCurrentRow - 1][mCurrentColumn] == 0)
						my_maze[mCurrentRow - 1][mCurrentColumn] = 2;

					if (mCurrentRow + 1 <= 6 && my_maze[mCurrentRow + 1][mCurrentColumn] == 0)
						my_maze[mCurrentRow + 1][mCurrentColumn] = 2;

					mCurrentColumn += 1;

					recurse();

					mCurrentColumn -= 1;
				}
			}
			}
			break;
		}
	} 
	while (((my_maze[mCurrentRow][mCurrentColumn + 1] == 0 || my_maze[mCurrentRow][mCurrentColumn + 1] == 5) && mCurrentColumn + 1 <= 6)
		|| ((my_maze[mCurrentRow][mCurrentColumn - 1] == 0 || my_maze[mCurrentRow][mCurrentColumn - 1] == 5) && mCurrentColumn - 1 >= 0)
		|| ((my_maze[mCurrentRow + 1][mCurrentColumn] == 0 || my_maze[mCurrentRow + 1][mCurrentColumn] == 5) && mCurrentRow + 1 <= 6)
		|| ((my_maze[mCurrentRow - 1][mCurrentColumn] == 0 || my_maze[mCurrentRow - 1][mCurrentColumn] == 5) && mCurrentRow - 1 >= 0));
}