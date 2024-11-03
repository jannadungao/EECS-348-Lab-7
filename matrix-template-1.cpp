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
    // loop for 4 x 4 matrix
    for (int i = 0; i < SIZE; i++) { // row
        for (int j = 0; j < SIZE; j++) { // column
            cin >> data[i][j]; // save input to matrix
        }
    }
  }

  // 2. Display a matrix
  void display() {
    for (int i = 0; i < SIZE; i++) { // row
        for (int j = 0; j < SIZE; j++) { // column
            cout << data[i][j] << ' '; // print data in matrix
        }
        cout << endl; // new line after each row
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
                sum += data[i][k] * other.data[k][j]; // perform matrix multiplication
            }
            matrix.data[i][j] = sum;
        }
    }
    return matrix;
  }

  // 5. Compute the sum of matrix diagonal elements
  void sumOfDiagonals() {
    // compute sum of main diagonal
    int main_sum = 0;
    for(int i = 0; i < SIZE; i++) {
        main_sum += data[i][i];
    }

    // compute sum of secondary diagonal
    int sec_sum = 0;
    for (int j = SIZE - 1; j >= 0; j--) {
        sec_sum += data[j][j];
    }
    stringstream ss;
    ss << "Main Sum: " << main_sum << endl << "Secondary Sum: " << sec_sum; // store string of sums
    string result = ss.str(); // store string in result
    cout << result << endl; // print resulting sums
  }

  // 6. Swap matrix rows
  void swapRows(int row1, int row2) {
    // check if input is valid
    if ((row1 >= 0 && row1 <= SIZE) && (row2 >= 0 && row2 <= SIZE) && (row1 != row2)) {
        int temp[SIZE]; // temporary array to hold values in first row
        for (int i = 0; i < SIZE; i++) { // temporarily hold values of first row
            temp[i] = data[row1][i]; 
        }
        for (int j = 0; j < SIZE; j++) { // swap row2 and row1
            data[row1][j] = data[row2][j];
        }
        for (int k = 0; k < SIZE; k++) { // assign values in temp (original row1) to row2 to complete swap
            data[row2][k] = temp[k];
        }
        cout << "Matrix 1 after swapping rows:" << endl;
    } else if (row1 == row2) {
        cout << "Cannot swap row with itself.\nOriginal Matrix 1: " << endl;
    } else if ((row1 < 0) || (row1 > SIZE) || (row2 < 0) || (row2 > SIZE)) {
        cout << "Invalid rows indices.\nOriginal Matrix 1: " << endl;
    }

  }
};

int main() {
  // Example usage:
  Matrix mat1;
  cout << "Enter values for Matrix 1 (in one line with numbers separated by spaces):" << endl;
  mat1.readFromStdin();
  cout << "Matrix 1:" << endl;
  mat1.display();

  Matrix mat2;
  cout << "Enter values for Matrix 2 (in one line with numbers separated by spaces):" << endl;
  mat2.readFromStdin();
  cout << "Matrix 2:" << endl;
  mat2.display();

  Matrix sum = mat1 + mat2;
  cout << "Sum of matrices:" << endl;
  sum.display();

  Matrix product = mat1 * mat2;
  cout << "Product of matrices:" << endl;
  product.display();

  cout << "Sum of diagonals of Matrix 1: " << endl;
  mat1.sumOfDiagonals();

  mat1.swapRows(0, 2);
  mat1.display();

  return 0;
}
