#include <stdio.h>

/* @BEGIN _OF_SOURCE_CODE */
int main(int argc, char *argv[])
{
	int i, j, index, n, aux_i, aux_j; 
	int maxValue, cycle;

	while( scanf("%d %d", &i, &j) != EOF ){
		maxValue = 0;

		aux_i = i;
		aux_j = j;

		if (i > j)
		{
			i = j;
			j = aux_i;
		}
			
		for(index = i; index<=j; index++)
		{
			cycle = 1;
			n = index;

			while(n != 1)
			{
				if(n % 2 == 0)
					n = n >> 1;
				else
					n = 3*n +1;
				cycle++;
			}

			if (cycle > maxValue)
				maxValue = cycle; 
		}

		printf("%d %d %d\n", aux_i, aux_j, maxValue);
	}
}
/* @END_OF_SOURCE_CODE */