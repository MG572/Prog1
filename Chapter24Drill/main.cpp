//g++ main.cpp -o main

#include "Matrix.h"
#include "MatrixIO.h"
#include <iostream>
#include <complex>
#include <numeric>
#include <iomanip>

using Numeric_lib::Matrix;

void sqrt()
{
    int a;
    std::cin >> a;
    if (a < 0)
    {
        std::cout << "Bad input! No square root, the number has to be positive or 0!" << std::endl;
    }
    else
    {
        std::cout << sqrt(a) << std::endl;
    }
}

int main()
{
    std::cout << "Printing out the sizes: " << std::endl;
    std::cout << "char: " << sizeof(char) << std::endl;
    std::cout << "short: " << sizeof(short) << std::endl;
    std::cout << "int: " << sizeof(int) << std::endl;
    std::cout << "long: " << sizeof(long) << std::endl;
    std::cout << "float: " << sizeof(float) << std::endl;
    std::cout << "double: " << sizeof(double) << std::endl;
    std::cout << "int*: " << sizeof(int*) << std::endl;
    std::cout << "double*: " << sizeof(double*) << std::endl;
    std::cout << std::endl;

    Matrix<int> a(10);
    Matrix<int> b(100);
    Matrix<double> c(10);
    Matrix<int,2> d(10,10);
    Matrix<int,3> e(10,10,10);
    std::cout << "Size of: "<< std::endl;
    std::cout << "Matrix <int>(10): " << sizeof(a) << std::endl;
    std::cout << "Matrix <int>(100): " << sizeof(b) << std::endl;
    std::cout << "Matrix <double>(10): " << sizeof(c) << std::endl;
    std::cout << "Matrix <int,2>(10,10): " << sizeof(d) << std::endl;
    std::cout << "Matrix <int,3>(10,10,10): " << sizeof(e) << std::endl;
    std::cout << std::endl;

    std::cout << "Elements: " << std::endl;
    std::cout << "Matrix <int>(10): " << a.size() << std::endl;
    std::cout << "Matrix <int>(100): " << b.size() << std::endl;
    std::cout << "Matrix <double>(10): " << c.size() << std::endl;
    std::cout << "Matrix <int,2>(10,10): " << d.size() << std::endl;
    std::cout << "Matrix <int,3>(10,10,10): " << e.size() << std::endl;
    std::cout << std::endl;

    std::cout << "Enter ints for sqrt: "<< std::endl;
    for (int i = 0; i < 5; ++i)
    {
        sqrt();
    }

    std::cout << "Enter 10 floats for the Matrix: " << std::endl;
    const int s = 10;

    Matrix<double> fm(s);
    for (int i = 0; i < s; ++i)
        std::cin >> fm[i];

    std::cout << fm << std::endl;

    std::cout << "Enter the table's dimensions with space between the two numbers: ";
    int n, m;
    std::cin >> n >> m;
    std::cout << std::endl;

    Matrix<double,2> table(n,m);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            table(i,j) = i == 0 || j == 0 ? i + j : i * j;
        }
    }

    for (int i = 0; i < table.dim1(); ++i) 
    {
        for (int j = 0; j < table.dim2(); ++j)
        {
            std::cout << std::setw(5) << table(i,j);
        }
        std::cout << std::endl;
    }

    std::cout << "Type in 10 complex numbers: "<< std::endl;
    Matrix<std::complex<double>> cm (10);
    for (int i = 0; i < cm.size(); ++i) 
    {
        std::cin >> cm[i];
    }
	std::cout << "Total: "<< std::accumulate(cm.data(), cm.data() + cm.size(),std::complex<double>{}) << std::endl;

    std::cout << "Enter six integers for the 2x3 matrix" << std::endl;
    Matrix<int,2> lm (2,3);
    for (int i = 0; i < lm.dim1(); ++i)
    {
        for (int j = 0; j < lm.dim2(); ++j)
        {
            std::cin >> lm[i][j];
        }
    }

    std::cout << lm << std::endl;
}