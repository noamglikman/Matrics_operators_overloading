//noamglikman1@gmail.com
# Assigment 1- System Programming 2 -Algorithm implementation with CPP

* **Run Example:**
```
make clean
make valgrind
make
./main
```
* **Test run:**
```
make run_tests
```
## classes:
SquareMat.

## namespace:
matrix.

* **Project stracture:**
with run "tree" in terminal

```bash
.
.
├── README.md
├── SquareMat.cpp
├── SquareMat.hpp
├── doctest.hpp
├── main.cpp
├── makefile
└── tests.cpp
```
### General Explantation of the code ##
The code implements a SquareMat class representing a square matrix of a given size. The class includes the following basic functions:

## 1## 
Constructor - Creates a matrix of the specified size and initializes all values to 0. If the size is not positive, it throws an invalid_argument exception.
## 2##
Copy Constructor - Copies another matrix, creating a new matrix of the appropriate size and copying its values.
## 3##
Assignment Operator - Allows copying an existing matrix, ensuring that any previously allocated memory is cleaned up.
## 4##
Destructor - Frees the memory allocated for the matrix.
## 5##
set - Allows setting a value at a specific position in the matrix, with checks to ensure the indices are valid.
## 6##
get - Returns the value at a specific position in the matrix, with checks to ensure the indices are valid.
## 7##
getSize - Returns the size of the matrix.
## 8##
print - Prints the matrix in a formatted manner to the screen.

The code performs error checks and ensures that matrix access is done correctly, as well as proper memory management.
The SquareMat class represents a square matrix with double-precision floating-point elements. It allows for matrix creation, manipulation, and printing, as well as various matrix operations like addition, subtraction, multiplication, division, and exponentiation.

Private Members:
size: The dimension of the matrix (n x n).

mat: A pointer to a dynamically allocated 2D array that stores the matrix elements.

Constructor and Destructor:
The constructor initializes the matrix with the given size n and allocates memory for a 2D array.

The destructor ensures proper memory cleanup by freeing the dynamically allocated memory.

Matrix Element Access:
The class provides functions to set or get individual elements in the matrix by specifying the row and column indices.

Additionally, there are functions for accessing elements using references for modification or constant access.

Print Function:
The print method prints the matrix in a readable format, typically row by row.

Matrix Size:
A method is available to return the size of the matrix (the dimension n).

Operators:
The class overloads various operators to support matrix operations and comparisons:
# 1#
Copy Constructor: Creates a copy of another SquareMat object.
# 2#
Addition (+): Adds two matrices element-wise and returns the result.
# 3#
Multiplication (*): Multiplies the matrix with another matrix using standard matrix multiplication rules.
# 4#
Equality Comparison (==): Compares two matrices for equality.
# 5#
Subtraction (-): Subtracts one matrix from another element-wise.
# 6#
Scalar Multiplication (* with an integer): Multiplies each element of the matrix by a scalar value.
# 7#
Unary Negation (-): Negates all elements of the matrix.
# 8#
Division (/): Divides each element of the matrix by a scalar value.
# 9#
Exponentiation (^): Raises the matrix to a given power (matrix exponentiation).
# 10#
Identity Matrix: Creates and returns an identity matrix of a given size.
# 11#
Determinant (!): Computes the determinant of the matrix.
# 12#
Comparison Operators (<, <=, >, >=, !=): Compare two matrices element-wise.
# 13#
Assignment (=): Assigns one matrix to another.
# 14#
Increment and Decrement Operators (++, --): Support pre- and post-increment and pre- and post-decrement operations.
# 15#
Indexing ([]): Allows accessing a specific row of the matrix directly using the indexing operator.
# 16#
Matrix Sum: Computes the sum of all elements in the matrix.
# 17#
Stream Insertion Operator (<<): Provides functionality for printing the matrix to an output stream (such as the console).

The SquareMat class provides a comprehensive set of operations and features for working with square matrices, including the ability to perform matrix arithmetic, comparisons, and element-wise manipulations. It supports both scalar and matrix operations and provides convenient methods for managing memory and outputting the matrix.



## TESTS ##
1. Basic Arithmetic Test
Purpose: Verifies simple arithmetic functionality (1 + 1 == 2) using doctest's CHECK.

2. Matrix Initialization
Purpose: Verifies matrix initialization with default values and checks if the matrix is set up correctly with initial values being 0.

3. Matrix Set and Get Test
Purpose: Verifies that elements can be set and retrieved from the matrix correctly.

4. Matrix Set and Get Out of Bounds
Purpose: Ensures that accessing or setting elements out of bounds results in a std::out_of_range exception.

5. Empty Matrix Initialization
Purpose: Tests the creation of an empty matrix and checks that all values are initialized to 0 by default.

6. Accessing Single Element in Matrix
Purpose: Tests matrix behavior when accessing a single element, checking for correct value retrieval and out-of-bounds exceptions.

7. Multiple Element Matrix
Purpose: Tests the behavior of a matrix with more than one element, ensuring correct set/get operations.

8. Identity Matrix Test
Purpose: Verifies the creation of an identity matrix, checking that diagonal values are 1 and off-diagonal values are 0.

9. Addition Operator Test
Purpose: Tests the addition operator (+) for matrices, ensuring the result is correct when adding matrices of the same dimensions and handling error cases when matrices have different sizes.

10. Subtraction Operator Test
Purpose: Verifies that matrix subtraction works correctly, ensuring the correct difference when subtracting two matrices of the same size.

11. Multiplication Operator Test
Purpose: Tests matrix multiplication (*), ensuring that multiplication between matrices of compatible sizes produces the correct result and throws exceptions for incompatible sizes.

12. Modulo Operator Test
Purpose: Tests element-wise modulo operation (%) between two matrices, checking that each corresponding element undergoes modulo correctly.

13. Equality Operator Test
Purpose: Tests the equality operator (==) to check if matrices with identical elements are recognized as equal, and matrices with different elements are recognized as unequal.

14. Multiplication Assignment Operator Test
Purpose: Verifies that matrix multiplication with the *= operator works correctly, updating the matrix in place.

15. Matrix Transpose Test
Purpose: Verifies that transposing a matrix results in the correct transposed matrix by switching rows and columns.

16. Matrix Assignment Test
Purpose: Tests the assignment of one matrix to another, ensuring that the assignment operator copies the correct values.

17. Accessing Uninitialized Matrix Element
Purpose: Checks the behavior when accessing an uninitialized element in the matrix and verifies that it returns a default value of 0.

18. Diagonal Matrix Test
Purpose: Verifies the behavior of a diagonal matrix, ensuring that all non-diagonal elements are 0 and diagonal elements are correctly set.

19. Matrix Resize Test
Purpose: Tests resizing the matrix, ensuring that the matrix expands or contracts correctly while maintaining correct values.

20. Matrix Copy Constructor Test
Purpose: Verifies the behavior of the copy constructor, ensuring that a new matrix is correctly initialized as a copy of an existing matrix.

21. Matrix Move Constructor Test
Purpose: Tests the move constructor to ensure efficient transfer of resources when moving a matrix.

22. Matrix Resize After Addition
Purpose: Tests resizing of matrices after performing addition, ensuring that the resized matrix still holds the correct values.

23. Handling Large Matrix Operations
Purpose: Tests the performance and correctness of matrix operations (such as multiplication) on large matrices, ensuring they work efficiently and correctly.

24. Error Handling with Invalid Matrix Dimensions
Purpose: Tests error handling when performing operations (like multiplication or addition) on matrices with invalid dimensions (e.g., mismatched row/column sizes).

25. Matrix Fill with Value Test
Purpose: Verifies the ability to fill the matrix with a specific value and check that all elements are updated accordingly.

26. Out-of-Bounds Test for Set/Get
Purpose: Tests both set() and get() functions with out-of-bounds indices, ensuring proper exception handling for invalid access.

27. Matrix Scalar Multiplication
Purpose: Verifies that multiplying a matrix by a scalar works correctly and all matrix elements are scaled by the scalar.

28. Matrix Determinant Test
Purpose: Verifies correct calculation of the determinant of the matrix.

29. Matrix Inverse Test
Purpose: Verifies that matrix inversion works correctly, checking for proper handling of invertible matrices and non-invertible cases.

30. Matrix Singular Test
Purpose: Tests the behavior when attempting to invert a singular matrix (determinant = 0), ensuring that an exception or error is raised.

31. Matrix Comparison Test
Purpose: Verifies that matrices of different dimensions cannot be compared for equality or inequality, testing for correct handling of these cases.

32. Matrix Type Handling
Purpose: Verifies that matrices with mixed types (e.g., integers and floats) handle arithmetic correctly without data loss or errors.



