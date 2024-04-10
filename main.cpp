#include<iostream>
using namespace std;

int main(){

    int matrix[4][4] = {
        {4,1,1,1},
        {1,4,1,1},
        {1,1,4,1},
        {1,1,1,4}
    };
    int m_size = 4;

    int main_summ = 0, side_summ = 0;

    for (int i = 0; i < 4; i++){
        main_summ += matrix[i][i];
    }

    for (int k = 0; k < 4; k++){
        for (int j = 3; j > -1; j--){
            if (k + j == m_size - 1){
                side_summ += matrix[k][j];
            }
        }
    }

    if (main_summ > side_summ){
        cout << "main more than side" << endl;
        cout << main_summ << " > " << side_summ << endl;

    } else if (side_summ > main_summ){
        cout << "side more than main" << endl;
        cout << side_summ << " > " << main_summ << endl;

    } else {
        cout << "sum same" << endl;
        cout << main_summ << " = " << side_summ << endl;
    }

    
    /*for (int i = 0; i < 4; i++){
        cout << endl;
        for (int j = 0; j < 4; j++){
            cout << matrix[i][j] << " ";
        }
    }*/

    return 0;
}