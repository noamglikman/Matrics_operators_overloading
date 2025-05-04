//noamglikman1@gmail.com
#ifndef SQUAREMAT_H
#define SQUAREMAT_H

#include <stdexcept>
#include <iostream>
#include <iomanip>
#include "helpobj.hpp"
namespace matrix {
/// SquareMat class represents a square matrix of size n x n.
class SquareMat {
private:
    /// size is the dimension of the square matrix.
    int size; 
    /// mat is a pointer to a 2D array representing the matrix.      
    double** mat;  

public:
    /// Constructor: Initializes a square matrix of size n x n with all elements set to 0.
    SquareMat(int n);
    /// Destructor: Releases memory allocated for the matrix.
    ~SquareMat();
    //Setters and Getters
    /// Sets the value at position (i, j) in the matrix.
    void set(int i, int j, double value);
    /// Gets the value at position (i, j) in the matrix.
    double get(int i, int j) const;
    //Printing
    void print() const;

    double& at(int row, int col);
    const double& at(int row, int col) const;

    int getSize() const;
    //////////////////////////////////////////////////////////////////////
    //OPERATORS
    SquareMat(const SquareMat& other); // Copy constructor
    friend SquareMat operator+(const SquareMat& a, const SquareMat& b);
    SquareMat operator*(const SquareMat& other) const;
    bool operator==(const SquareMat& other) const;
    SquareMat operator-(const SquareMat& other) const;
    SquareMat& operator*=(const SquareMat& other);
    SquareMat operator-() const;
    // Define scalar multiplication as a non-member function
    friend SquareMat operator*(int scalar, const SquareMat& mat);
    SquareMat operator*(int scalar) const;
    SquareMat operator%(const SquareMat& other) const;
    SquareMat operator/(int scalar) const;
    SquareMat operator%(int scalar) const;
    bool operator!=(const SquareMat& other) const;
    SquareMat operator^(int power) const;
    static SquareMat identity(int size);
    SquareMat& operator=(const SquareMat& other);
    SquareMat operator~() const;
    SquareMat& operator++();
    SquareMat operator++(int);
    SquareMat& operator--();
    SquareMat operator--(int);

    helpobj operator[](int row);
    const double* operator[](int row) const;
    double totalSum() const;
    bool operator<(const SquareMat& other) const;
    bool operator<=(const SquareMat& other) const;
    bool operator>(const SquareMat& other) const;
    bool operator>=(const SquareMat& other) const;
    double operator!() const; 
    SquareMat& operator+=(const SquareMat& other);
    SquareMat& operator-=(const SquareMat& other);
    SquareMat& operator/=(const SquareMat& other);
    SquareMat& operator%=(const SquareMat& other);
    SquareMat& operator%=(int scalar);
    friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);
};

}

#endif // SQUAREMAT_H
