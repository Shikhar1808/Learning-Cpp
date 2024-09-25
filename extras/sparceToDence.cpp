#include <iostream>
using namespace std;

int main(){

    int sMatrix[][3] = {{5, 5, 5},{0, 1, 5},{0, 2, 18},{2, 1, 14},{3, 1, 15},{3, 3, 4}};

    int dMatrix[6][6];

    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            dMatrix[i][j] = 0;
        }
    }

    for(int i=0; i<6; i++){
        dMatrix[sMatrix[i][0]][sMatrix[i][1]] = sMatrix[i][2];
    }

    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            cout << dMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}