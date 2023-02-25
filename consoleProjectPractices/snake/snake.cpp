#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>
using namespace std;

#define NUM_ROWS 10
#define NUM_COLUMNS 10
#define MAX 100

// c++ snake program 10 * 10 map

enum direction {UP, DOWN, LEFT, RIGHT};
struct position
{
	int x, y;
};

struct food
{
	position fpos;
	bool eaten;

	position generate();
};

position food::generate()
{
	fpos.x = rand() % NUM_ROWS;
	fpos.y = rand() % NUM_COLUMNS;
	return fpos;
}

struct snake
{
	position spos;
	direction sdir;

	direction move();
	void addPos(); // this'll recieve move, so that it can know at wich direction add position
};

direction move()
{
	char input;
	cout << "\n\n" << endl;
	cin >> input;
	switch (input)
	{
	case 'w':
		return UP;
		break;
	case 's':
		return DOWN;
		break;
	case 'a':
		return LEFT;
		break;
	case 'd':
		return RIGHT;
		break;
	default:
		break;
	}
}
void addPos(direction d, snake &s)
{
	switch (d)
	{
	case UP:
		s.spos.y--;
		break;
	case DOWN:
		s.spos.y++;
		break;
	case LEFT:
		s.spos.x--;
		break;
	case RIGHT:
		s.spos.x++;
		break;
	default:
		break;
	}
}

struct board
{
	char map[NUM_ROWS][NUM_COLUMNS];

	void drawandInitialize(snake s[], food f, int currentsize);
};

void board::drawandInitialize(snake s[], food f, int currentsize)
{
	// asign board
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLUMNS; j++)
		{
			for (int x = 0; x < currentsize; x++)
			{
				if (s[x].spos.x == i && s[x].spos.y == j)
					map[i][j] = 'x';
			}
	
			if (f.fpos.x == i && f.fpos.y == j)
				map[i][j] = 'o';
			else
				map[i][j] = ' ';
		}
	}
	// draw board
	for (int i = 0; i < NUM_ROWS; i++)
	{
		cout << "|";
		for (int j = 0; j < NUM_COLUMNS; j++)
			cout << map[i][j];
		cout << "|" << endl;
	}
}


int main()
{
	srand(time(NULL));
	snake sparts[MAX];
	food f;
	board map;
	int currentsize = 1;

	// initialize snake and food
	while (true)
	{
		position p;
		p.x = 5;
		p.y = 5;
		sparts[0].spos.x = p.x;
		sparts[0].spos.y = p.y;
		for (int i = 0; i < currentsize; i++)
		{
			switch (sparts->sdir)
			{
			case UP:
				sparts[i].spos.y = sparts[0].spos.y;
				sparts[i].spos.y += i;
				break;
			case DOWN:
				sparts[i].spos.y = sparts[0].spos.y;
				sparts[i].spos.y -= i;
				break;
			case LEFT:
				sparts[i].spos.x = sparts[0].spos.x;
				sparts[i].spos.x += i;
				break;
			case RIGHT:
				sparts[i].spos.x = sparts[0].spos.x;
				sparts[i].spos.x -= i;
			default:
				break;
			}
		}
		// colision of snake: gameOver, and eating wich increases currentsize // bool eat; & currentsize++;
		if (sparts[0].spos.x == f.fpos.x && sparts[0].spos.y == f.fpos.y)
		{
			// ...
		}

		map.drawandInitialize(sparts, f, currentsize);

		direction next = sparts->move();
		sparts->addPos(next, sparts[0]);

		f.fpos = f.generate();

	}


}