//noamglikman1@gmail.com
#include "SquareMat.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cmath>  
#include  "helpobj.hpp"
namespace matrix {
    // Constructor: Initializes a square matrix of size n x n with all elements set to 0.
    SquareMat::SquareMat(int n): size(n) {
        if(n <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        mat = new double*[size];
        for(int i = 0; i < size; ++i){
            mat[i] = new double[size];
            for(int j = 0; j < size; ++j){
                mat[i][j] = 0.0;
            }
        }
    }
    // Copy constructor: Creates a deep copy of another SquareMat.
    SquareMat::SquareMat(const SquareMat& other) {
        size = other.size;
        mat = new double*[size];
        for (int i = 0; i < size; ++i) {
            mat[i] = new double[size];
            for (int j = 0; j < size; ++j) {
                mat[i][j] = other.mat[i][j]; 
            }
        }
    }
    // Assignment operator: Assigns one SquareMat to another,
    // performing deep copy.
    SquareMat& SquareMat::operator=(const SquareMat& other) {
        if (this != &other) { 
            
            for (int i = 0; i < size; ++i) {
                delete[] mat[i];
            }
            delete[] mat;

        
            size = other.size;
            mat = new double*[size];
            for (int i = 0; i < size; ++i) {
                mat[i] = new double[size];
                for (int j = 0; j < size; ++j) {
                    mat[i][j] = other.mat[i][j];
                }
            }
        }
        return *this;
    }

    
    // Destructor: Releases memory allocated for the matrix.
    SquareMat::~SquareMat() {
        for(int i = 0; i < size; ++i){
            delete[] mat[i];
        }
        delete[] mat;
    }
    // Sets the value at position (i, j) in the matrix.
    void SquareMat::set(int i, int j, double value) {
        if(i < 0 || i >= size || j < 0 || j >= size){
            throw std::out_of_range("Index out of range");
        }
        mat[i][j] = value;
    }
    // Gets the value at position (i, j) in the matrix.
    double SquareMat::get(int i, int j) const {
        if(i < 0 || i >= size || j < 0 || j >= size){
            throw std::out_of_range("Index out of range");
        }
        return mat[i][j];
    }
    // Returns the size of the matrix.
    int SquareMat::getSize() const {
        return size;
    }
    // Prints the matrix to the console.
    void SquareMat::print() const {
        for(int i = 0; i < size; ++i){
            for(int j = 0; j < size; ++j){
                std::cout << std::setw(10) << mat[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    // Accessor method to get a reference to the element at (row, col).
    double& SquareMat::at(int row, int col) {
        if (row < 0 || row >= size || col < 0 || col >= size)
            throw std::out_of_range("Index out of bounds.");
        return mat[row][col];
    }
    // Const accessor method to get a reference to the element at (row, col).
    const double& SquareMat::at(int row, int col) const {
        if (row < 0 || row >= size || col < 0 || col >= size)
            throw std::out_of_range("Index out of bounds.");
        return mat[row][col];
    }
    // Creates an identity matrix of size n x n.
    SquareMat SquareMat::identity(int size) {
        SquareMat identityMat(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (i == j) {
                    identityMat.set(i, j, 1);  // כל איבר בדיאגונל הראשי הוא 1
                } else {
                    identityMat.set(i, j, 0);  // כל השאר הם 0
                }
            }
        }
        return identityMat;
    }
    ////////////////////////////////////////////////////////////////////////////
    //OPERATORS
    // Adds two SquareMat objects and returns the result.
    SquareMat operator+(const SquareMat& a, const SquareMat& b) {
        if (a.size != b.size) {
            throw std::invalid_argument("Matrix sizes must match for addition");
        }
    
        SquareMat result(a.size); 
    
        for (int i = 0; i < a.size; ++i) {
            for (int j = 0; j < a.size; ++j) {
                result.mat[i][j] = a.mat[i][j] + b.mat[i][j];
            }
        }
    
        return result;
    }
    // Adds another SquareMat to this one.
    SquareMat SquareMat::operator*(const SquareMat& other) const {
        if (size != other.size) {
            throw std::invalid_argument("Matrix sizes do not match for multiplication.");
        }
    
        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                double sum = 0.0;
                for (int k = 0; k < size; ++k) {
                    sum += mat[i][k] * other.mat[k][j];
                }
                result.mat[i][j] = sum;
            }
        }
        return result;
    }
    // Compares two SquareMat objects for equality.
    bool SquareMat::operator==(const SquareMat& other) const {
        if (this->size != other.size)
            return false;
    
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (this->mat[i][j] != other.mat[i][j])
                    return false;
            }
        }    

        return true;
    }
    // Subtracts another SquareMat from this one.
    SquareMat SquareMat::operator-(const SquareMat& other) const {
        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.mat[i][j] = mat[i][j] - other.mat[i][j];
            }
        }
        return result;
    }
    // Subtracts another SquareMat from this one and assigns the result to this one.
    SquareMat& SquareMat::operator*=(const SquareMat& other) {
        if (this->size != other.size) {
            throw std::invalid_argument("Matrices dimensions must match for multiplication");
        }
    
        SquareMat result(this->size);
    
        for (int i = 0; i < this->size; ++i) {
            for (int j = 0; j < this->size; ++j) {
                int sum = 0;
                for (int k = 0; k < this->size; ++k) {
                    sum += this->get(i, k) * other.get(k, j);
                }
                result.set(i, j, sum);
            }
        }
    
        for (int i = 0; i < this->size; ++i) {
            for (int j = 0; j < this->size; ++j) {
                this->set(i, j, result.get(i, j));
            }
        }
    
        return *this;
    }
    
    // Negates the SquareMat and returns the result.
    SquareMat SquareMat::operator-() const {
        SquareMat result(this->getSize());
        for (int i = 0; i < this->getSize(); ++i) {
            for (int j = 0; j < this->getSize(); ++j) {
                result.set(i, j, -this->get(i, j));
            }
        }
        return result;
    }
    // Multiplies a SquareMat by a scalar and returns the result.
    SquareMat operator*(int scalar, const SquareMat& mat) {
        SquareMat result(mat.getSize());
        for (int i = 0; i < mat.getSize(); ++i) {
            for (int j = 0; j < mat.getSize(); ++j) {
                result.set(i, j, scalar * mat.get(i, j));
            }
        }
        return result;
    }

    // Multiplies this SquareMat by a scalar and returns the result.
    SquareMat SquareMat::operator*(int scalar) const {
        SquareMat result(this->getSize());
        for (int i = 0; i < this->getSize(); ++i) {
            for (int j = 0; j < this->getSize(); ++j) {
                result.set(i, j, scalar * this->get(i, j));
            }
        }
        return result;
    }

    // Divides this SquareMat by a scalar and returns the result.
    SquareMat SquareMat::operator%(const SquareMat& other) const {
        if (this->size != other.size) {
            throw std::invalid_argument("Matrices dimensions must match for element-wise modulo.");
        }

        SquareMat result(this->size);

        for (int i = 0; i < this->size; ++i) {
            for (int j = 0; j < this->size; ++j) {
                double value = this->mat[i][j];
                int scalar = static_cast<int>(other.mat[i][j]);
                
                
                double mod = fmod(value, scalar);
                if (mod < 0) {
                    mod += scalar;
                }

                result.set(i, j, mod);
            }
        }

        return result;
    }
    // Divides this SquareMat by a scalar and returns the result.
    bool SquareMat::operator!=(const SquareMat& other) const {
        return !(*this == other);
    }
    // Divides this SquareMat by a scalar and returns the result.
    SquareMat SquareMat::operator^(int power) const {
        if (power < 0) {
            throw std::invalid_argument("Power must be non-negative.");
        }

        if (power == 0) {
            return SquareMat::identity(this->getSize()); 
        }
        SquareMat result = SquareMat::identity(this->getSize());
        
        
        SquareMat base = *this;
        for (int p = 0; p < power; ++p) {
            result = result * base;  
        }
        return result;
    }
    // Creates an identity matrix of size n x n.
    SquareMat SquareMat::operator~() const {
        int n = this->getSize(); 

        SquareMat result(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result.set(i, j, this->get(j, i));
            }
        }

        return result;
    }
    // Adds another SquareMat to this one and assigns the result to this one.
    SquareMat& SquareMat::operator++() {
        int n = this->getSize();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                this->set(i, j, this->get(i, j) + 1);  // הגדלה של כל איבר ב-1
            }
        }
        return *this;  // מחזירים את המטריצה המעודכנת
    }

    // Post-increment (++):
    SquareMat SquareMat::operator++(int) {
        SquareMat temp = *this; 
        int n = this->getSize();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                this->set(i, j, this->get(i, j) + 1); 
            }
        }
        return temp;
    }

    // Decrement operator (--) - decreases each element of the matrix by 1.
    SquareMat& SquareMat::operator--() {
        int n = this->getSize();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                this->set(i, j, this->get(i, j) - 1); 
            }
        }
        return *this; 
    }

    // Post-decrement (--) - decreases each element of the matrix by 1 and returns the original matrix.
    SquareMat SquareMat::operator--(int) {
        SquareMat temp = *this;  
        int n = this->getSize();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                this->set(i, j, this->get(i, j) - 1); 
            }
        }
        return temp; 
    }
    // Accessor method to get a pointer to the row of the matrix.
     helpobj SquareMat::operator[](int row) {
        if (row < 0 || row >= size) {
            throw std::out_of_range("Row index out of bounds");
        }
        return helpobj(size, mat[row]);
    }
    // Const accessor method to get a pointer to the row of the matrix.
    const double* SquareMat::operator[](int row) const {
        if (row < 0 || row >= size) {
            throw std::out_of_range("Row index out of bounds");
        }
        return mat[row];
    }
    // Calculates the total sum of all elements in the matrix.
    double SquareMat::totalSum() const {
        double sum = 0.0;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                sum += mat[i][j];
            }
        }
        return sum;
    }
    // Compares two SquareMat objects based on their total sum.
    bool SquareMat:: operator<(const SquareMat& other) const {
        return this->totalSum() < other.totalSum();
    }
    bool SquareMat:: operator>(const SquareMat& other) const {
        return this->totalSum() > other.totalSum();
    }

    bool  SquareMat:: operator<=(const SquareMat& other) const {
        return this->totalSum() <= other.totalSum();
    }

    bool SquareMat:: operator>=(const SquareMat& other) const {
        return this->totalSum() >= other.totalSum();
    }
    // Calculates the determinant of the matrix using Laplace expansion.
    double SquareMat::operator!() const {
        if (size == 1) {
            return mat[0][0];
        }
        if (size == 2) {
            return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
        }

        // Laplace expansion along the first row
        double det = 0;
        for (int col = 0; col < size; ++col) {
            // Create minor matrix
            SquareMat minor(size - 1);
            for (int i = 1; i < size; ++i) {
                int minor_col = 0;
                for (int j = 0; j < size; ++j) {
                    if (j == col) continue;
                    minor.set(i - 1, minor_col, mat[i][j]);
                    minor_col++;
                }
            }
            double sign = (col % 2 == 0) ? 1 : -1;
            det += sign * mat[0][col] * !minor; 
        }
        return det;
    }
    // Divides this SquareMat by another SquareMat and returns the result.
    SquareMat& SquareMat:: operator+=(const SquareMat& other) {
        if (this->size != other.size || this->size != other.size) {
            throw std::invalid_argument("Matrix sizes must match for addition.");
        }
        for (int i = 0; i < this->size; ++i) {
            for (int j = 0; j < this->size; ++j) {
                this->mat[i][j] += other.mat[i][j];
            }
        }
        return *this;
    }
    // Subtracts another SquareMat from this one and assigns the result to this one.
    SquareMat& SquareMat:: operator-=(const SquareMat& other) {
        if (this->size != other.size || this->size != other.size) {
            throw std::invalid_argument("Matrix sizes must match for subtraction.");
        }
        for (int i = 0; i < this->size; ++i) {
            for (int j = 0; j < this->size; ++j) {
                this->mat[i][j] -= other.mat[i][j];
            }
        }
        return *this;
    }

    // Divides this SquareMat by another SquareMat and assigns the result to this one.
    SquareMat& SquareMat:: operator/=(const SquareMat& other) {
        
        if (this->size != other.size) {
            throw std::invalid_argument("Matrix sizes must match for division.");
        }

        for (int i = 0; i < this->size; ++i) {
            for (int j = 0; j < this->size; ++j) {
                if (other.mat[i][j] == 0) {
                    throw std::invalid_argument("Division by zero encountered in matrix.");
                }
                this->mat[i][j] /= other.mat[i][j];  
            }
        }
        return *this;
    }
    // Divides this SquareMat by a scalar and assigns the result to this one.
    SquareMat& SquareMat::operator%=(const SquareMat& other) {
        if (size != other.size) {
            throw std::invalid_argument("Matrix sizes must be equal for %=");
        }

        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                mat[i][j] = std::fmod(mat[i][j], other.mat[i][j]);

        return *this;
    }
    // Divides this SquareMat by a scalar and assigns the result to this one.
    SquareMat& SquareMat::operator%=(int scalar) {
        if (scalar == 0) {
            throw std::invalid_argument("Division by zero in %=");
        }

        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                mat[i][j] = std::fmod(mat[i][j], scalar);

        return *this;
    }
    // Overloads the << operator to print the matrix.
    std::ostream& operator<<(std::ostream& os, const SquareMat& mat) {
        for (int i = 0; i < mat.size; ++i) {
            for (int j = 0; j < mat.size; ++j) {
                os << mat.mat[i][j];
                if (j != mat.size - 1)
                    os << " ";
            }
            os << std::endl;
        }
        return os;
    }


    }
