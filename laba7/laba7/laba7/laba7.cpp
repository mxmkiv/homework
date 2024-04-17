#include<crtdbg.h>
#include<iostream>
using namespace std;

int main() {

	int rows;
	cout << "n (matrix size): ";
	cin >> rows;

	int** matrix{ new int*[rows] };

	for (int p = 0; p < rows; p++) {
		matrix[p] = new int[rows];
	}

	for (int i = 0; i < rows; i++) {
		cout << i + 1 << " row: ";
		for (int j = 0; j < rows; j++) {
			cin >> matrix[i][j];
		}
	}

	int main_summ = 0, side_summ = 0;

	for (int i = 0; i < rows; i++) {
		main_summ += matrix[i][i];
	}

	for (int k = 0; k < rows; k++) {
		for (int j = rows; j > -1; j--) {
			if (k + j == rows - 1) {
				side_summ += matrix[k][j];
			}
		}
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
	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}

	delete[] matrix;

	return 0;
}