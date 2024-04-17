#include<crtdbg.h>
#include<iostream>
using namespace std;

int main() {

	int rows;
	cout << "n (matrix size): ";
	cin >> rows;

	int** matrix{ new int*[rows] };

	int p = 0;
	do {
		matrix[p] = new int[rows];
		p++;

	} while (p < rows);

	int i = 0;
	do {
		cout << i + 1 << " row: ";
		int j = 0;

		do {
			cin >> matrix[i][j];
			j++;
		} while (j < rows);
		i++;

	} while (i < rows);

	int main_summ = 0, side_summ = 0;

	int m = 0;
	do {
		main_summ += matrix[m][m];
		m++;

	} while (m < rows);

	int k = 0;
	do {
		int j = rows;
		do {
			if (k + j == rows - 1) {
				side_summ += matrix[k][j];
			}
			j--;

		} while (j > -1);
		k++;

	} while (k < rows);

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
	do {
		delete[] matrix[c];
		c++;
	} while (c < rows);

	delete[] matrix;

	return 0;
}
