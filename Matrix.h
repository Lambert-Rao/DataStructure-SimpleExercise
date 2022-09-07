#include<iostream>
#include<memory>
using namespace std;

class Matrix {
public:
    Matrix(int row = 0, int col = 0);   //构造函数
    Matrix(int row, int col, int num);//构造函数重载
    Matrix(int row, int col,std::initializer_list<int> il);//构造函数重载
    ~Matrix();                  //析构函数
    Matrix(const Matrix &rhs); //赋值函数
    Matrix operator*(const Matrix &rhs);      //矩阵相乘
    Matrix operator+(const Matrix &rhs);      //矩阵相加
    Matrix operator-(const Matrix &rhs);      //矩阵相减
    Matrix& operator=(const Matrix &rhs);      //矩阵赋值
    Matrix& operator+=(const Matrix &rhs);     //矩阵相加赋值
    Matrix& operator-=(const Matrix &rhs);     //矩阵相减赋值
    Matrix transpose();                       //矩阵转置
    Matrix inverse()=delete;                  //矩阵求逆
    int **data_ptr = nullptr;          //初始化一共空指针
    int row, col;

    string shape();               //打印矩阵形状
    void print_all();              //打印矩阵
};