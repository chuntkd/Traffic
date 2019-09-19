#include<stdio.h>
#include<stdlib.h>
int main()
{
	
	int i;
	while (1)
	{
		printf("put number.");
		scanf("%d", &i);

		if (i == 0)
		{
			printf("exit");
			break;
		}

		for (int j = 1; j <= 9; j++)
		{
			printf("%d * %d = %d\n", i, j, i * j);
		}
		
	}

}
