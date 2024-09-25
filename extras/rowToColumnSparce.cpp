#include <iostream>
using namespace std;

int main() {
    // Original matrix
    int matrix[6][6] = {
        {15,  0,  0, 22,  0, -15},
        { 0, 11,  3,  0,  0,   0},
        { 0,  0,  0, -6,  0,   0},
        { 0,  0,  0,  0,  0,   0},
        {91,  0,  0,  0,  0,   0},
        { 0,  0, 28,  0,  0,   0}
    };

    int colMajorSparse[36][3]; 
    int numElements = 0; 

    for (int j = 0; j < 6; j++) {  
        for (int i = 0; i < 6; i++) { 
            if (matrix[i][j] != 0) {
                colMajorSparse[numElements][0] = i; 
                colMajorSparse[numElements][1] = j; 
                colMajorSparse[numElements][2] = matrix[i][j];
                numElements++;
            }
        }
    }

    // Print column-major sparse matrix
    cout << "Column-Major Sparse Matrix:" << endl;
    for (int i = 0; i < numElements; i++) {
        cout << colMajorSparse[i][0] << " " << colMajorSparse[i][1] << " " << colMajorSparse[i][2] << endl;
    }

    return 0;
}
