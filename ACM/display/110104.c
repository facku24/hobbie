#include <stdio.h>
#include <math.h>
#include <string.h>

char numbers[10][5][3] = {
	{" - ", "| |", "   ", "| |", " - "},	// 0
	{"   ", "  |", "   ", "  |", "   "},	// 1
	{" - ", "  |", " - ", "|  ", " - "},	// 2
	{" - ", "  |", " - ", "  |", " - "}, 	// 3
	{"   ", "| |", " - ", "  |", "   "},	// 4
	{" - ", "|  ", " - ", "  |", " - "},	// 5
	{" - ", "|  ", " - ", "| |", " - "},	// 6
	{" - ", "  |", "   ", "  |", "   "},	// 7
	{" - ", "| |", " - ", "| |", " - "}, 	// 8
	{" - ", "| |", " - ", "  |", " - "}		// 9
};

void printRow(char *number, int size, int counter, int last);
int numbers_digits(int number);
void get_digits(int number, int digits[8], int size);


int main(int argc, char *argv[])
{
	char (*number)[3];
	int digits[8];

	int size, num, num_size, i, j, k;

	scanf("%d %d", &size, &num);
	getchar();

	while(size != 0 || num != 0){
		num_size = numbers_digits(num);
		get_digits(num, digits, num_size);

		for(i = 0; i<5; i++){
			if(i % 2 == 0){
				for(j=0; j<num_size; j++){
					number = numbers[digits[j]];	
					printRow(number[i], size, i, j == num_size-1);
				}
				printf("\n");
			}
			else{
				for(k = 1; k<=size; k++){
					for(j=0; j<num_size; j++){
						number = numbers[digits[j]];	
						printRow(number[i], size, i, j == num_size-1);
					}
					printf("\n");
				}
			}
		}
		printf("\n");
		scanf("%d %d", &size, &num);
		getchar();
	}
}

void printRow(char *number, int size, int counter, int last)
{
	int s;

	printf("%c", number[0]);
	for(s = 1; s<=size; s++)
		printf("%c", number[1]);
	printf("%c", number[2]);
	if (!last)
		printf(" ");
}

int numbers_digits(int number)
{
	int counter = 0;

	if (number == 0)
		return 1;
	
	while(number != 0){
		number /= 10;
		counter++;
	}

	return counter;
}

void get_digits(int number, int digits[8], int size)
{
	int num_aux, power, num_elems;
	num_elems = size;

	while(size != 0)
	{
		num_aux = number;
		power = pow(10, size-1);
		num_aux /= power;
		number -= num_aux *power;
		digits[num_elems-size] = num_aux;
		size--;
	}
}