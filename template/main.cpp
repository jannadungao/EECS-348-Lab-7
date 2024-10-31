
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Matrix {
public:
    int matrix_size;
    double** matrix_data;

    Matrix(int size = 0) : matrix_size(size) {
        matrix_data = new double*[matrix_size];
        for (int i = 0; i < matrix_size; ++i) {
            matrix_data[i] = new double[matrix_size];
        }
    }

    Matrix& operator=(const Matrix& other) {
        if (this == &other) {
            return *this;
        }

        for (int i = 0; i < matrix_size; ++i) {
            delete[] matrix_data[i];
        }
        delete[] matrix_data;

        matrix_size = other.matrix_size;

        matrix_data = new double*[matrix_size];
        for (int i = 0; i < matrix_size; ++i) {
            matrix_data[i] = new double[matrix_size];
            for (int j = 0; j < matrix_size; ++j) {
                matrix_data[i][j] = other.matrix_data[i][j];
            }
        }

        return *this;
    }

    ~Matrix() {
        for (int i = 0; i < matrix_size; ++i) {
            delete[] matrix_data[i];
        }
        delete[] matrix_data;
    }
};

void read_matrix_from_file(const string& file_name, Matrix& matrix_1, Matrix& matrix_2) {
    // TODO: Read matrix data from the file
    // Make sure to handle potential errors and invalid input

    // read in initial file
    ifstream file(file_name); 

    // get size of matrices
    string line;
    int count;
    while(getline(file, line)) {
        count++;
    }
    matrix_1.matrix_size = matrix_2.matrix_size = count/2; 

    // read in matrix 1
    string matrix1[matrix_1.matrix_size];
    for (int i = 0; i < matrix_1.matrix_size; i++) {
        string line;
        getline(file, line);
        string row[matrix_1.matrix_size];
        for (int j = 0; j < matrix_1.matrix_size; j++) {
            row[j] = line[j];
        }
        matrix1[i] = row[i];
    }
    
    matrix_1.matrix_data = matrix1;

    file.close();
}

void print_matrix(const Matrix& matrix) {
    // TODO: Print the matrix to the console
}

void print_matrix(const Matrix& matrix_1, const Matrix& matrix_2) {
    // TODO: Print both matrices to the console
}

Matrix add_matrices(const Matrix& matrix_1, const Matrix& matrix_2) {
    // TODO: Implement matrix addition
}

Matrix multiply_matrices(const Matrix& matrix_1, const Matrix& matrix_2) {
    // TODO: Implement matrix multiplication
}

// Overloaded + operator for matrix addition
Matrix operator+(const Matrix& matrix_1, const Matrix& matrix_2);

// Overloaded * operator for matrix multiplication
Matrix operator*(const Matrix& matrix_1, const Matrix& matrix_2);

void get_diagonal_sum(const Matrix& matrix) {
    // TODO: Calculate and print the sum of the diagonal elements
}

void swap_matrix_row(Matrix& matrix, int row1, int row2) {
    // TODO: Swap the rows 'row1' and 'row2' in the matrix
    //    Handle invalid row indices
}

int main(int argc, char* argv[]) {
    Matrix matrix_1, matrix_2;
    read_matrix_from_file("matrix.txt", matrix_1, matrix_2);

    cout << "print_matrix" << endl;
    print_matrix(matrix_1, matrix_2);

    cout << "add_matrices result:" << endl;
    Matrix add_result_1 = add_matrices(matrix_1, matrix_2);
    Matrix add_result_2 = matrix_1 + matrix_2;
    print_matrix(add_result_1);
    print_matrix(add_result_2);

    cout << "multiply_matrices result:" << endl;
    Matrix multiply_result_1 = multiply_matrices(matrix_1, matrix_2);
    Matrix multiply_result_2 = matrix_1 * matrix_2;
    print_matrix(multiply_result_1);
    print_matrix(multiply_result_2);

    cout << "get matrix diagonal sum" << endl;
    get_diagonal_sum(matrix_1);

    cout << "swap matrix rows" << endl;
    swap_matrix_row(matrix_1, 0, 1);

    return 0;
}