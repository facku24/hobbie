#include <stdio.h>
int adjustValue(char ch);
char asciiToChar(int value);

int
main(int argc, char *argv[])
{
	int fst, snd, result = 0;
	char ch1, ch2, value;
	FILE *fp;

	fp = fopen("third.txt", "r");

	while (((ch1 = fgetc(fp)) != EOF) && ((ch2 = fgetc(fp)) != EOF))
	{
		result = 0;
		fst = adjustValue(ch1);
		snd = adjustValue(ch2);

		//printf("%d %d :", fst, snd);
		result += (fst & 8)*16 + (fst & 4)*16 + (fst & 2)*16 + (fst & 1)*16;
		result += (snd & 8) + (snd & 4) + (snd & 2) + (snd & 1);

		printf("%d ", result); 
	}
	printf("\n");
}

int
adjustValue(char ch)
{
    if (ch >= 48 && ch <= 57)
        return ch - 48;
    else if (ch >= 97 && ch <= 102)
        return ch - 87;
    else return -1;
}

char
asciiToChar(int value)
{
	if (0<= value && value <= 9)
		return value + 48;
	if (10<= value && value <=15)
		return value + 87;
}