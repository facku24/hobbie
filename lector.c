#include <stdio.h>
#define N 15

int main(int argc, char *argv[])
{
	int values[15] = {23, 2, 23, 45, 12, 23, 45, 2, 16, 23, 45, 1, 34, 12, 23};
	int result, count = 0;
	int resaux, countaux, i, j, aux;

	for(i = 0; i < N; i++)
	{
		resaux = values[i];
		countaux = 1;

		if(resaux == 0)
			continue;

		for(j = i+1; j < N; j++)
		{
			aux = values[j];

			if(aux == 0 || aux != resaux)
				continue;

			countaux += 1;
			values[j] = 0;
		}

		if(count < countaux)
		{
			count = countaux;
			result = resaux;
		}
	}

	printf("%d %d\n", result, count);
	return 0;
}