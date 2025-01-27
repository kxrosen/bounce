#include <stdio.h>

int main()
{
	for(;;)
	{
		for(int i = 0; i <= 10; i++)
		{
			for(int j = 0; j <= 20; j++)
			{
				printf("#");
			}

			printf("\n");
		}
	}

	return 0;
}
