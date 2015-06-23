#include <iostream>
#include <fstream>

#define SIZE 100

std::ifstream input("input.txt");
std::ofstream output("output.txt");
int matrix1[SIZE][SIZE];
int matrix2[SIZE][SIZE];
int result[SIZE][SIZE];

/* Function that does the multiplication of two matrices */
void multiplication(int m, int n, int p){

	int k;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < p; j++){
			k = 0; 
			for (int l = 0; l < n; l++)
				k = k + matrix1[i][l] * matrix2[l][j];
			result[i][j] = k;
		}
}

/* Function that displays a matrix */
void display(int matrix[SIZE][SIZE], int m, int n){

	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++)
			output << matrix[i][j] << " ";
		output << "\n";
	}
}

int main(void){

	int m, n, p;

	input >> m >> n >> p;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			input >> matrix1[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < p; j++)
			input >> matrix2[i][j];

	output << "Display the first matrix\n";
	display(matrix1, m, n);
	output << "Display the second matrix\n";
	display(matrix2, n, p);
	multiplication(m, n, p);
	output << "Display the result\n";
	display(result, m, p);

	return 0;
}
