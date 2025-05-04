#include "SquareMat.hpp"
#include <iostream>

using namespace matrix;

int main() {
    try {
        // Create a 3x3 square matrix
        SquareMat mat(3);

        // Set values in the matrix using set(i, j, value)
        mat.set(0, 0, 1.1);
        mat.set(0, 1, 2.2);
        mat.set(0, 2, 3.3);
        mat.set(1, 0, 4.4);
        mat.set(1, 1, 5.5);
        mat.set(1, 2, 6.6);
        mat.set(2, 0, 7.7);
        mat.set(2, 1, 8.8);
        mat.set(2, 2, 9.9);

        // Print the original matrix
        std::cout << "Original Matrix:" << std::endl;
        mat.print();

        // Test copy constructor: create a new matrix as a copy of the original
        SquareMat copy(mat);
        std::cout << "\nCopied Matrix (via copy constructor):" << std::endl;
        copy.print();

        // Test assignment operator
        SquareMat assigned(3); // create an empty matrix
        assigned = mat;        // assign the original to it
        std::cout << "\nAssigned Matrix (via operator=):" << std::endl;
        assigned.print();

        // Create and print an identity matrix of size 4x4
        SquareMat identityMat = SquareMat::identity(4);
        std::cout << "\nIdentity Matrix (4x4):" << std::endl;
        identityMat.print();

        // Access and modify an element using the at() method
        std::cout << "\nValue at (1,1) in original matrix: " << mat.at(1, 1) << std::endl;
        mat.at(1, 1) = 99.99;  // modify the value at (1,1)
        std::cout << "\nModified Matrix after setting at(1,1) = 99.99:" << std::endl;
        mat.print();

    } catch (const std::exception& e) {
        // Catch and print any exceptions thrown (e.g. out-of-bounds access)
        std::cerr << "Exception occurred: " << e.what() << std::endl;
    }
    // 2matrix
    SquareMat A(2);
    SquareMat B(2);

    
    A.set(0, 0, 1); A.set(0, 1, 2);
    A.set(1, 0, 3); A.set(1, 1, 4);

    B.set(0, 0, 5); B.set(0, 1, 6);
    B.set(1, 0, 7); B.set(1, 1, 8);

    //print the matrices
    std::cout << "Matrix A:\n" << A << "\n";
    std::cout << "Matrix B:\n" << B << "\n";

    //plus
    SquareMat C = A + B;
    std::cout << "A + B:\n" << C << "\n";

    //minus
    SquareMat D = A - B;
    std::cout << "A - B:\n" << D << "\n";

    // multiply
    SquareMat E = A * B;
    std::cout << "A * B:\n" << E << "\n";

    // multiply by scalar
    SquareMat F = 2 * A;
    std::cout << "2 * A:\n" << F << "\n";

    // multiply by scalar
    SquareMat G = A ^ 2;
    std::cout << "A ^ 2:\n" << G << "\n";

    
    SquareMat H = ~A;
    std::cout << "~A (transpose):\n" << H << "\n";

    //negative
    SquareMat I = -A;
    std::cout << "-A:\n" << I << "\n";

    
    std::cout << "A++:\n" << A++ << "\n";
    std::cout << "++A:\n" << ++A << "\n";
    std::cout << "A--:\n" << A-- << "\n";
    std::cout << "--A:\n" << --A << "\n";

    // Accessing elements
    std::cout << "A == B? " << (A == B ? "Yes" : "No") << "\n";
    std::cout << "A != B? " << (A != B ? "Yes" : "No") << "\n";

    // % 
    SquareMat M = B % F;
    std::cout << "B % (2*A):\n" << M << "\n";

    // compare
    std::cout << "A < B? " << (A < B ? "Yes" : "No") << "\n";

    // determinant
    std::cout << "!A (determinant): " << !A << "\n";

    return 0;
}
