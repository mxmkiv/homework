#include <crtdbg.h>
#include<iostream>
using namespace std;

int main() {

	int rows;
	cout << "n (matrix size): ";
	cin >> rows;

	int** matrix{ new int*[rows] };

	int p = 0;
	while (p < rows) {
		matrix[p] = new int[rows];
		p++;
	}

	// заполнение матрицы
	int t = 0;
	while (t < rows) {
		cout << t + 1 << " row: ";
		int h = 0;

		while (h < rows) {
			cin >> matrix[t][h];
			h++;
		}
		t++;
	}

	int main_summ = 0, side_summ = 0;

	int i = 0;
	while (i < rows) {
		main_summ += matrix[i][i];
		i++;
	}

	int k = 0, j = rows-1;

	while (k < rows) {
		j = rows - 1;
		while (j > -1) {
			if (k + j == rows - 1) {
				side_summ += matrix[k][j];
			}

			j--;
		}
		k++;
	}

	if (main_summ > side_summ) {
		cout << "main more than side" << endl;
		cout << main_summ << " > " << side_summ << endl;

	}
	else if (side_summ > main_summ) {
		cout << "side more than main" << endl;
		cout << side_summ << " > " << main_summ << endl;

	}
	else {
		cout << "sum same" << endl;
		cout << main_summ << " = " << side_summ << endl;
	}

	//memory clear
	int c = 0;
	while (c < rows) {
		delete[] matrix[c];
		c++;
	}

	delete[] matrix;

	return 0;
}