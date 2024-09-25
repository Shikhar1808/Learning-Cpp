#include <iostream>
using namespace std;

int main(){

    int arr[5][5];

    for(int i =0;i<5;i++){
        for(int j =0; j<5; j++){
            if(i == j){
                arr[i][j] = 1;
            }
            else if(i == j-1){
                arr[i][j] = 2;
            }
            else if(i == j+1){
                arr[i][j] = 3;
            }
            else{
                arr[i][j] = 0;

            }
        }
    }

    for(int i =0;i<5;i++){
        for(int j =0; j<5; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}