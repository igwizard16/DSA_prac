#include<iostream>
using namespace std;

void polyAdd(int p1[], int p2[], int res[], int maxDegree) {
    for (int i = 0; i <= maxDegree; i++) {
        res[i] = p1[i] + p2[i];
    }
}

void display(int poly[], int maxDegree){
    for(int i = 0; i <= maxDegree; i++){
            cout << poly[i];
            if(i != 0) cout << "x^" << i;
            if(i != maxDegree) cout << "+" ;
        }
        cout << endl;
}

int main(){
int maxDegree = 2;
int p1[100], p2[100], res[100];
cout << "enter coefficents for polynomial1 : " << endl;
for(int i = 0; i <= maxDegree; i++){
    cin >> p1[i];
}
cout << "enter coefficents for polynomial2 : " << endl;
for(int i = 0; i <= maxDegree; i++){
    cin >> p2[i];
}

polyAdd(p1, p2, res, maxDegree);

display(res, maxDegree);
return 0;

}