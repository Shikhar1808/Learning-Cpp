#include <iostream>
using namespace std;

int main(){

    int sMatrix[][3] = {{0,2,5},{1,0,2},{0,0,3},{1,2,7},{2,2,10}};

    int dMatrix[3][3];

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            dMatrix[i][j] = 0;
        }
    }

    for(int i=0; i<5; i++){
        dMatrix[sMatrix[i][0]][sMatrix[i][1]] = sMatrix[i][2];
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << dMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}