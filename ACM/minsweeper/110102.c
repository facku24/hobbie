#include <stdio.h>

char matrix[101][101];
//void initMatrix(int matrix[101][101], int n, int m);
void addMine(int n, int m, int row, int col);

int
main(int argc, char *argv[])
{
	char c; //save the value readed
	int m, n, field = 0; // n, m the values readed / field is a counter
	int row, col; // aux variables for the row and col positions

	scanf("%d %d", &n, &m);
	getchar();
	while (n != 0 && m != 0)
	{
		field++;
		if(field > 1)
			printf("\n");

		/* Initialize the positions to use */
		for(row = 1; row <= n; row++){
			for (col = 1; col <= m; col++){
				matrix[row][col] = '0';
			}
		}

		/* Scan the values and operate with them*/
		for(row=1; row <= n; row++){
			for(col=1; col <= m; col++){
				c = getchar();
				if (c == '*')
					addMine(n, m, row, col);
			}
			getchar();
		}

		/* Print the result */
		printf("Field #%d:\n", field);
		for(row = 1; row <= n; row++){
			for (col = 1; col <= m; col++){
				printf("%c", matrix[row][col]);
			}
			printf("\n");
		}

		/* Clean the positions used */
		for(row = 1; row <= n; row++){
			for (col = 1; col <= m; col++){
				matrix[row][col] = '0';
			}
		}
		//printf("\n");
		scanf("%d %d", &n, &m);
		getchar();
	}
}

void
addMine(int n, int m, int row, int col)
{
	int index, currRow;

	matrix[row][col] = '*';

	for(index = -1; index <= 1; index++){
		currRow = row + index;

		if(currRow < 1 || currRow > n )
			continue;
		if (currRow != row && matrix[currRow][col] != '*')
			matrix[currRow][col] +=1;
		if (col - 1 >= 1 && matrix[currRow][col-1] != '*')
			matrix[currRow][col-1] +=1;
		if (col + 1 <= m && matrix[currRow][col+1] != '*')
			matrix[currRow][col+1] +=1;
	}
}