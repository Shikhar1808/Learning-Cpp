#include <iostream>
using namespace std;

int main(){

    int arr[3][3] = {{0,0,1},{4,0,5},{0,0,0}};
    int zCount = 0;
    int nzCount = 0;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(arr[i][j] == 0){
                zCount++;
            }else{
                nzCount++;
            }
        }
    }

    if(zCount > nzCount){
        cout<<"The matrix is sparce"<<endl;
    }else{
        cout<<"The matrix is not sparce"<<endl;
    }

    return 0;
}