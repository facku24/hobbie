#include <stdio.h>
#define N 30

void counter(int *, int *, int values[]);

int main(int argc, char *argv[])
{
	FILE *myFile;
    
    myFile = fopen("somenumbers.txt", "r");

    //read file into array
    int numberArray[N];
    int i, j, result, count;

    for (j = 1; j<= 327; j++)
    {

        for (i = 0; i < N; i++)
            fscanf(myFile, "%d", &numberArray[i]);

        counter(&result, &count, numberArray);

        printf("%d\t%d\n", result, count);
    }
    //printf("\n");
}

void counter(int *result, int *count, int values[])
{

    //int values[15] = {23, 2, 23, 45, 12, 23, 45, 2, 16, 23, 45, 1, 34, 12, 23};
    int resaux, countaux, i, j, aux;
    
    *count = 0;

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

        if(*count < countaux)
        {
            *count = countaux;
            *result = resaux;
        }
    }
}