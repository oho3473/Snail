#include<iostream>

int main()
{
	const int SIZE{ 5 };
	int snail[SIZE][SIZE]{};
	
	enum Direction
	{
		Right, Down, Left, Up
	};
	
	Direction dir{ Right };

	int value{ 1 };
	int x{}, y{};

	while (value <= SIZE * SIZE)
	{
		snail[y][x] = value;
		value++;

		switch (dir)
		{
			case Right:
				x++;
				if (x == SIZE || snail[y][x] != 0)
				{
					x--;
					y++;

					dir = Down;
				}
				break;

			case Down:
				y++;
				if (y == SIZE || snail[y][x] != 0)
				{
					y--;
					x--;

					dir = Left;
				}
				break;
			case Left:
				x--;
				if (x < 0 || snail[y][x] != 0)
				{
					x++;
					y--;

					dir = Up;
				}
				break;
			case Up:
				y--;
				if (y < 0 || snail[y][x] != 0)
				{
					y++;
					x++;

					dir = Right;
				}
				break;
		}
	}
	
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			std::cout.width(2);
			std::cout << snail[i][j] << ' ';
		}
		std::cout << std::endl;
	}

}