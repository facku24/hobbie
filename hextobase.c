#include <stdio.h>
int base64[64] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N',
				  'O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b',
				  'c','d','e','f','g','h','i','j','k','l','m','n','o','p','q',
				  'r','s','t','u','v','w','x','y','z', '0','1','2','3','4','5',
				  '6','7','8','9','+','/'};
int
main(int argc, char *argv[])
{
	int a , b;
	int d,e, ch;
	int valores[3];
	int contador = 0;
	FILE *fp;

	fp = fopen("second.txt", "r");

	if (fp == NULL)
		return -1;
	
	while ((ch = fgetc(fp)) != EOF)
	{
		if (ch >= 48 && ch <= 57)
			valores[contador] = ch - 48;
		else if (ch >= 97 && ch <= 102)
			valores[contador] = ch - 87;
		//printf("%d\n", valores[contador]);
		contador = (contador + 1)%3;

		if (contador == 0)
		{
			a = (valores[0]<<2) + (valores[1]>>2);
			b = (valores[1]<<4 & 0x30) + valores[2];
			printf("%c%c", base64[a], base64[b]);
		}
	}
	printf("\n");

	fclose(fp);
	return 0;
}