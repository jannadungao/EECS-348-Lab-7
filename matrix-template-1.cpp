#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
  int data[SIZE][SIZE];  // 2D array for matrix data (using int for simplicity)

public:
  // 1. Read values from stdin into a matrix
  void readFromStdin() {
    string matrix;
    cin >> matrix;
    stringstream ss(matrix);

    // loop for 4 x 4 matrix
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            string num;
            ss >> matrix;
            num = matrix;
            int k = stoi(num);
            data[i][j] = k;
        }
    }
  }

  // 2. Display a matrix
  void display() {
    for (int i = 0; i < SIZE; i++) {
        string row;
        for (int j = 0; j < SIZE; j++) {
            row += (char) data[i][j];
        }
        cout << row << endl;
    }
  }

  // 3. Add two matrices (operator overloading for +)
  Matrix operator+(const Matrix& other) {
    Matrix matrix;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return matrix;
  }

  // 4. Multiply two matrices (operator overloading for *)
  Matrix operator*(const Matrix& other) {
    Matrix matrix;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int sum = 0;
            for (int k = 0; k < SIZE; k++) {
                sum += data[i][j] * other.data[j][i];
            }
            matrix.data[i][j] = sum;
        }
    }
    return matrix;
  }

  // 5. Compute the sum of matrix diagonal elements
  int sumOfDiagonals() {
    int sum = 0;
    for(int i = 0; i < SIZE; i++) {
        sum += data[i][i];
    }
    return sum;
  }

  // 6. Swap matrix rows
  void swapRows(int row1, int row2) {
    int temp[SIZE];
    for (int i = 0; i < SIZE; i++) {
        temp[i] = data[row1][i]; 
    }
    for (int j = 0; j < SIZE; j++) {
        data[row1][j] = data[row2][j];
    }
    for (int k = 0; k < SIZE; k++) {
        data[row2][k] = temp[k];
    }
  }
};

int main() {
  // Example usage:
  Matrix mat1;
  cout << "Enter values for Matrix 1:" << endl;
  mat1.readFromStdin();
  cout << "Matrix 1:" << endl;
  mat1.display();

  Matrix mat2;
  cout << "Enter values for Matrix 2:" << endl;
  mat2.readFromStdin();
  cout << "Matrix 2:" << endl;
  mat2.display();

  Matrix sum = mat1 + mat2;
  cout << "Sum of matrices:" << endl;
  sum.display();

  Matrix product = mat1 * mat2;
  cout << "Product of matrices:" << endl;
  product.display();

  cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

  mat1.swapRows(0, 2);
  cout << "Matrix 1 after swapping rows:" << endl;
  mat1.display();

  return 0;
}
