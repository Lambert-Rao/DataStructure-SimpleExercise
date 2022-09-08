#include "Matrix.h"


Matrix::Matrix(int row, int col, int num) {
    this->row = row;
    this->col = col;
    this->data_ptr = new int *[row];
    for (int i = 0; i < this->row; i++) {
        data_ptr[i] = new int[this->col];
    }
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->row; j++) {
            this->data_ptr[i][j] = num;
        }
    }
}


Matrix::~Matrix() {
    for (int i = 0; i < this->row; i++) {
        if (data_ptr[i] != nullptr) {
            delete[] data_ptr[i];
            data_ptr[i] = nullptr;
        }
    }
    if (data_ptr != nullptr) {
        delete[] data_ptr;
        data_ptr = nullptr;
    }
}

Matrix::Matrix(const Matrix &rhs) {
    row = rhs.row;
    col = rhs.col;
    data_ptr = new int *[row];
    for (int i = 0; i < row; i++) {
        data_ptr[i] = new int[col];
        memcpy(data_ptr[i], rhs.data_ptr[i], sizeof(int) * col);
    }
}

Matrix Matrix::operator*(const Matrix &rhs) const {
    if (this->col != rhs.row) {
        cerr << "shape error" << endl;
        exit(0);
    }
    Matrix m(this->row, rhs.col);
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < rhs.col; j++) {
            int sum = 0;
            for (int k = 0; k < this->col; k++) {
                sum += this->data_ptr[i][k] * rhs.data_ptr[k][j];
            }
            m.data_ptr[i][j] = sum;
        }
    }
    return m;
}

Matrix Matrix::operator+(const Matrix &rhs) const {
    if (this->col != rhs.col || this->row != rhs.row) {
        cerr << "shape error" << endl;
    }
    Matrix m(this->row, this->col);
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->col; j++) {
            m.data_ptr[i][j] = this->data_ptr[i][j] + rhs.data_ptr[i][j];
        }
    }
    return m;
}

Matrix Matrix::operator-(const Matrix &rhs) const {
    if (this->col != rhs.col or this->row != rhs.row) {
        cout << "shape error" << endl;
    }
    Matrix m(this->row, this->col);
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->col; j++) {
            m.data_ptr[i][j] = this->data_ptr[i][j] - rhs.data_ptr[i][j];
        }
    }
    return m;
}

string Matrix::shape() const {
    string s = "(" + to_string(this->row) + "," + to_string(this->col) + ")";
    return s;
}

void Matrix::print_all(std::ostream& os) const {
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->col; j++) {
            os << this->data_ptr[i][j] << " ";
        }
        os << endl;
    }
}

Matrix::Matrix(int row, int col, std::initializer_list<int> il) {
    this->row = row;
    this->col = col;
    if (row * col != il.size()) {
        cerr << "shape error" << endl;
    }
    this->data_ptr = new int *[row];
    for (int i = 0; i < this->row; i++) {
        data_ptr[i] = new int[this->col];
    }
    int i = 0;
    for (auto it = il.begin(); it != il.end(); it++, i++) {
        this->data_ptr[i / this->col][i % this->col] = *it;

    }

}

Matrix &Matrix::operator+=(const Matrix &rhs) {
    *this = this->operator+(rhs);
    return *this;
}

Matrix &Matrix::operator=(const Matrix &rhs) {
    if (this == &rhs) {
        return *this;
    }
    this->row = rhs.row;
    this->col = rhs.col;
    this->data_ptr = new int *[row];
    for (int i = 0; i < row; i++) {
        data_ptr[i] = new int[col];
        memcpy(data_ptr[i], rhs.data_ptr[i], sizeof(int) * col);
    }
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &rhs) {
    *this = this->operator-(rhs);
    return *this;
}

Matrix Matrix::transpose() const {
    Matrix m(this->col, this->row);
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->col; j++) {
            std::swap(m.data_ptr[j][i],this->data_ptr[i][j]) ;
        }
    }
    return m;
}



