#include<iostream>
#include<memory>
#include<list>
#include <initializer_list>

using namespace std;

class Matrix {
public:
    Matrix()=default;
    explicit Matrix(int row = 0, int col = 0, int num=0);//构造函数
    Matrix(int row, int col,std::initializer_list<int> il);//构造函数重载
    ~Matrix();                  //析构函数
    Matrix(const Matrix &rhs); //赋值函数
    Matrix operator*(const Matrix &rhs) const;      //矩阵相乘
    Matrix operator+(const Matrix &rhs) const;      //矩阵相加
    Matrix operator-(const Matrix &rhs) const;      //矩阵相减
    Matrix& operator=(const Matrix &rhs);      //矩阵赋值
    Matrix& operator+=(const Matrix &rhs);     //矩阵相加赋值
    Matrix& operator-=(const Matrix &rhs);     //矩阵相减赋值
    Matrix transpose() const;                       //矩阵转置
    Matrix inverse()=delete;                  //矩阵求逆
    int **data_ptr = nullptr;          //初始化空指针
    int row{}, col{};

    string shape() const;               //打印矩阵形状
    void print_all(std::ostream& os=std::cout) const;              //打印矩阵
};

//附赠一个稀疏矩阵
//非零元素比较少的矩阵
template<typename T>
class SparseMatrix {
    using point= std::pair<std::pair<int, int>, T>;
    friend ostream &operator<<(ostream &os, const SparseMatrix<T> &rhs) {
        if(!std::is_same<T,int>::value)
            cerr<<"暂不支持非int类型的稀疏矩阵"<<endl;
        Matrix m(rhs.row, rhs.col);
        for(auto it=rhs.data.cbegin();it!=rhs.data.cend();it++)
        {
            m.data_ptr[it->first.first][it->first.second]=it->second;
        }
        m.print_all(os);
        return os;
    }
public:
    SparseMatrix transpose();
    SparseMatrix (int row, int col, std::initializer_list<point> il);
private:
    int row{}, col{};
    std::list<point> data;
};
template<typename T>
SparseMatrix<T>::SparseMatrix(int row, int col, initializer_list<point> il) {
    this->row=row;
    this->col=col;
    for (auto it = il.begin(); it != il.end(); it++)
        data.push_back(std::make_pair(it->first, it->second));

}

template<typename T>
SparseMatrix<T> SparseMatrix<T>::transpose() {
    SparseMatrix<T> temp(col,row,{});
    for(auto it=data.begin();it!=data.end();it++){
        temp.data.push_back(std::make_pair(std::make_pair(it->first.second,it->first.first),it->second));
    }
    return temp;
}
