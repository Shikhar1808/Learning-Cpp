#include <iostream>
using namespace std;

//matrix to sparse matrix

int main(){

    int dMatrix[3][3] = {{0,2,5},{1,0,2},{0,0,3}};
    int sMatrix[5][3];

    int k = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(dMatrix[i][j] != 0){
                sMatrix[k][0] = i;
                sMatrix[k][1] = j;
                sMatrix[k][2] = dMatrix[i][j];
                k++;
            }
        }
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<3; j++){
            cout << sMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}