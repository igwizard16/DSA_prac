/*Write a simple C program on a 32-bit compiler to understand the concept of array storage, 
size of a word. The program shall be written illustrating the concept of row major and 
column major storage. Find the address of element and verify it with the theoretical value. 
Program may be written for arrays up to 4-dimensions. */

#include <iostream>
using namespace std;

int main() {
    cout << "size of integer = " << sizeof(int);

    int A[5];
    cout << "1D Array:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Address of A : " << i << &A[i] << " " << "Theoretical = " << (A + i) << "\n";
    }
    cout << "\n";

    int B[3][4];
    cout << "2D Array \n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << "Address of B : [" << i << "][" << j << "] = " << &B[i][j] << " Theoretical = " << ( (int*)B + (i*4 + j) ) << "\n";
        }
    }
    cout << "\n";

    int C[2][3][4];
    cout << "3D Array:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                cout << "Address of C : [" << i << "][" << j << "][" << k << "] = " << &C[i][j][k] << " Theoretical = " << ( (int*)C + (i*3*4 + j*4 + k) ) << "\n";
            }
        }
    }
    cout << "\n";

    int D[2][2][2][3];
    cout << "4D Array:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 3; l++) {
                    cout << "Address of D: [" << i << "][" << j << "][" << k << "][" << l << "] = " << &D[i][j][k][l] << " Theoretical = " << ( (int*)D + (i*2*2*3 + j*2*3 + k*3 + l) ) << "\n";
                }
            }
        }
    }

    return 0;
}
