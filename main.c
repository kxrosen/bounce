#include <stdio.h>
#include <unistd.h>

#define SCREEN_WIDTH 20
#define SCREEN_HEIGHT 10

struct object
{
	int x;
	int y;
	int x_speed;
	int y_speed;
	char look;
};

void screen_draw(struct object obj)
{
	for(int i = 1; i <= SCREEN_HEIGHT; i++)
	{
		for(int j = 1; j <= SCREEN_WIDTH; j++)
		{
			if(j == 1 || j == SCREEN_WIDTH || i == 1 || i == SCREEN_HEIGHT)
			{
				printf("#");
			}
			else if(j == obj.x && i == obj.y)
			{
				printf("%c", obj.look);
			}
			else
			{
				printf(" ");
			}
		}

		printf("\n");
	}
}

void screen_clrscr()
{
	printf("\033[H\033[2J");
}

void logic_physics(struct object *obj)
{
	obj->x += obj->x_speed;
	obj->y += obj->y_speed;

	if(obj->x >= SCREEN_WIDTH)
	{
		obj->x = SCREEN_WIDTH - 1;
		obj->x_speed *= -1;
	}
	if(obj->x <= 1)
	{
		obj->x = 2;
		obj->x_speed *= -1;
	}
	if(obj->y >= SCREEN_HEIGHT)
	{
		obj->y = SCREEN_HEIGHT - 1;
		obj->y_speed *= -1;
	}
	if(obj->y <= 1)
	{
		obj->y = 2;
		obj->y_speed *= -1;
	}
}

void debug_information(struct object obj)
{
	printf("screen max width                    : %d\n", SCREEN_WIDTH);
	printf("screen max height                   : %d\n", SCREEN_HEIGHT);

	printf("\n");

	printf("obj x position                      : %d\n", obj.x);
	printf("obj y position                      : %d\n", obj.y);
	printf("obj x speed                         : %d\n", obj.x_speed);
	printf("obj y speed                         : %d\n", obj.y_speed);
	printf("obj look                            : %d\n", obj.look);
}

int main()
{
	struct object obj;
	obj.x = 10;
	obj.y = 8;
	obj.x_speed = 2;
	obj.y_speed = 4;
	obj.look = '@';

	for(;;)
	{
		screen_clrscr();
		screen_draw(obj);

		logic_physics(&obj);

		debug_information(obj);

		sleep(1);
	}

	return 0;
}
