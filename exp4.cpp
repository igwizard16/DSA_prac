
//sparse matrix representation

#include<iostream>
using namespace std;

int main(){
    int r, c;
    cout << "no. of row : " << endl;
    cin >> r;
    cout << "no. of col : " << endl;
    cin >> c;

    int mat[10][10];
    cout << "enter elements of matrix: " << endl;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> mat[i][j];
        }
    }

    int nz = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(mat[i][j] != 0) nz++;
        }
    }

    int s[50][3];
    s[0][0] = r;
    s[0][1] = c;
    s[0][2] = nz;

    int k = 1;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(mat[i][j] != 0){
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = mat[i][j];
                k++;
            }
        }
    }

    cout << "\nSparse Matrix Representation:\n";
    cout << "Row Col Val\n";
    for(int i = 0; i <= nz; i++){
        cout << s[i][0] << "   " 
             << s[i][1] << "   " 
             << s[i][2] << endl;
    }
    return 0;
}
