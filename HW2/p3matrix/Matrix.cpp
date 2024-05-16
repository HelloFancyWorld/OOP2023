#include "Matrix.h"

Matrix::Matrix(){}

Matrix::Matrix(int _row, int _col) : row(_row), col(_col)
{
    elem = new int *[row];
    for(int i = 0; i < row; i++)
    {
        elem[i] = new int[col]; 
    }
}
Matrix::~Matrix()
{}

Matrix Matrix::operator+(const Matrix& b)
{
    Matrix c(row, col);
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            c.elem[i][j] = this->elem[i][j] + b.elem[i][j];
        }
    }
    return c;
}
Matrix Matrix::operator-(const Matrix& b)
{
    Matrix c(row, col);
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            c.elem[i][j] = this->elem[i][j] - b.elem[i][j];
        }
    }
    return c;
}
Matrix Matrix::operator*(const int b)
{
    Matrix c(row, col);
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            c.elem[i][j] = this->elem[i][j] * b;
        }
    }
    return c;
}
Matrix Matrix::operator*(const Matrix& b)
{
    int temp;
    Matrix c(this->row, b.col);
    for(int i = 0; i < this->row; i++)
    {
        for(int j = 0; j < b.col; j++)
        {
            temp = 0;
            for(int k = 0; k < this->col; k++)
            {
                temp += this->elem[i][k] *  b.elem[k][j];
            }
            c.elem[i][j] = temp;
        }
    }
    return c;
}
Matrix transpose(const Matrix& b)
{
    Matrix c(b.col, b.row);
    for(int i = 0; i < b.col; i++)
    {
        for(int j = 0; j < b.row; j++)
        {
            c.elem[i][j] = b.elem[j][i];
        }
    }
    return c;
}
int* Matrix::operator[](int i) const
{
    return this->elem[i];
}
ostream& operator<<(ostream& out, const Matrix& matrix)
{
    for(int i = 0; i < matrix.row; i++)
    {
        for(int j = 0; j < matrix.col; j++)
        {
            out << matrix[i][j] << ' ';
        }
        out << endl;
    }
    return out;
}
istream& operator>>(istream& in, Matrix& matrix)
{
    int _row, _col;
    in >> _row >> _col;
    matrix.col = _col;
    matrix.row = _row;
    matrix.elem = new int *[_row];
    for(int i = 0; i < _row; i++)
    {
        matrix.elem[i] = new int[_col]; 
    }
    for(int i = 0; i < matrix.row; i++)
    {
        for(int j = 0; j < matrix.col; j++)
        {
            in >> matrix[i][j];
        }
    }
    return in;
}