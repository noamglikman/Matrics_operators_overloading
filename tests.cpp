//noamglikman1@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

//#include <doctest/doctest.h>
#include <iostream>
#include <cassert>
#include "SquareMat.hpp"
#include "doctest.hpp"
TEST_CASE("בדיקה לדוגמה") {
    CHECK(1 + 1 == 2);
}
TEST_CASE("Matrix Creation and Access") {
    using namespace matrix;
    
    SquareMat mat(3); // 3x3 matrix
    mat.set(0, 0, 1);
    mat.set(1, 1, 2);
    mat.set(2, 2, 3);

    std::cout << "Matrix created:" << std::endl;
    mat.print();

    // Test 1: Element Access
    SUBCASE("Access elements") {
        CHECK(mat.get(0, 0) == 1);
        CHECK(mat.get(1, 1) == 2);
        CHECK(mat.get(2, 2) == 3);
    }
    CHECK_THROWS_AS(mat.get(-1, 0), std::out_of_range);

    std::cout << "Access to elements checked successfully." << std::endl;
}

TEST_CASE("Value Change in Matrix") {
    using namespace matrix;

    SquareMat mat(3);
    mat.set(0, 0, 1);
    mat.set(1, 1, 2);
    mat.set(2, 2, 3);

    mat.set(1, 1, 10);  // Changing elements
    CHECK(mat.get(1, 1) == 10);
    CHECK_THROWS_AS(mat.get(-1, 0), std::out_of_range);
    std::cout << "Value at (1,1) changed to 10: " << std::endl;
    mat.print();
}

TEST_CASE("Set and Get elements") {
    using namespace matrix;

    SquareMat mat(3);  // מטריצה בגודל 3x3

    // בדיקות set ו-get
    mat.set(0, 0, 1.5);
    CHECK(mat.get(0, 0) == 1.5);  // הערך צריך להיות 1.5

    mat.set(1, 1, 2.5);
    CHECK(mat.get(1, 1) == 2.5);  // הערך צריך להיות 2.5

    mat.set(2, 2, 3.5);
    CHECK(mat.get(2, 2) == 3.5);  // הערך צריך להיות 3.5

    // שינוי ערכים ותיקול מחדש
    mat.set(0, 0, 5.0);
    CHECK(mat.get(0, 0) == 5.0);  // הערך צריך להיות 5.0 אחרי השינוי

    mat.set(1, 0, -3.2);
    CHECK(mat.get(1, 0) == -3.2);  // הערך צריך להיות -3.2
}

// טסט עבור חריגות בגישה עם get ו-set
TEST_CASE("Out of bounds access with get and set") {
    using namespace matrix;

    SquareMat mat(3);  // מטריצה בגודל 3x3

    // בדיקת חריגה ב-set
    CHECK_THROWS_AS(mat.set(3, 3, 4.5), std::out_of_range);  // מנסה להגדיר מחוץ לגבולות
    CHECK_THROWS_AS(mat.set(-1, -1, 5.5), std::out_of_range);  // מנסה להגדיר מחוץ לגבולות

    // בדיקת חריגה ב-get
    CHECK_THROWS_AS(mat.get(3, 3), std::out_of_range);  // מנסה לקרוא מחוץ לגבולות
    CHECK_THROWS_AS(mat.get(-1, -1), std::out_of_range);  // מנסה לקרוא מחוץ לגבולות
}

// טסט עבור מטריצה ריקה (ללא ערכים שהוגדרו מראש)
TEST_CASE("Empty Matrix Access") {
    using namespace matrix;

    SquareMat mat(3);  // מטריצה בגודל 3x3

    // בדיקת ערך ברירת מחדל כאשר לא הוגדרו ערכים מראש
    CHECK(mat.get(0, 0) == 0);  // הערך ברירת מחדל
    CHECK(mat.get(1, 1) == 0);  // הערך ברירת מחדל
    CHECK(mat.get(2, 2) == 0);  // הערך ברירת מחדל
}

// טסט עבור מטריצה בגודל 1 (edge case)
TEST_CASE("Single Element Matrix Access") {
    using namespace matrix;

    SquareMat mat(1);  // מטריצה בגודל 1x1

    mat.set(0, 0, 7.5);
    CHECK(mat.get(0, 0) == 7.5);  // הערך צריך להיות 7.5
}

// טסט עבור מטריצה בגודל 5 (יותר גדולה)
TEST_CASE("Larger Matrix Access") {
    using namespace matrix;

    SquareMat mat(5);  // מטריצה בגודל 5x5

    mat.set(4, 4, 10.0);
    CHECK(mat.get(4, 4) == 10.0);  // הערך צריך להיות 10.0
}

TEST_CASE("Access with `at()` method") {
    using namespace matrix;

    SquareMat mat(3);
    mat.set(0, 0, 1);
    mat.set(1, 1, 2);
    mat.set(2, 2, 3);

    mat.at(0, 1) = 5; // Change through `at()`
    CHECK(mat.get(0, 1) == 5);
    CHECK_THROWS_AS(mat.get(-1, 0), std::out_of_range);
    std::cout << "Element at (0, 1) set to 5: " << std::endl;
    mat.print();
}
TEST_CASE("Identity Matrix") {
    using namespace matrix;

    SquareMat identityMat = SquareMat::identity(3);

    CHECK(identityMat.get(0, 0) == 1);  // האיבר בדיאגונל הראשי צריך להיות 1
    CHECK(identityMat.get(1, 1) == 1);  // האיבר בדיאגונל הראשי צריך להיות 1
    CHECK(identityMat.get(2, 2) == 1);  // האיבר בדיאגונל הראשי צריך להיות 1

    CHECK(identityMat.get(0, 1) == 0);
    CHECK(identityMat.get(1, 0) == 0);
    CHECK(identityMat.get(0, 2) == 0);
    CHECK(identityMat.get(2, 0) == 0);
    CHECK(identityMat.get(1, 2) == 0);
    CHECK(identityMat.get(2, 1) == 0);

    identityMat = SquareMat::identity(4);

    CHECK(identityMat.get(0, 0) == 1);
    CHECK(identityMat.get(1, 1) == 1);
    CHECK(identityMat.get(2, 2) == 1);
    CHECK(identityMat.get(3, 3) == 1);

    CHECK(identityMat.get(0, 1) == 0);
    CHECK(identityMat.get(1, 0) == 0);
    CHECK(identityMat.get(0, 2) == 0);
    CHECK(identityMat.get(0, 3) == 0);
    CHECK(identityMat.get(1, 2) == 0);
    CHECK(identityMat.get(1, 3) == 0);
    CHECK(identityMat.get(2, 0) == 0);
    CHECK(identityMat.get(2, 1) == 0);
    CHECK(identityMat.get(2, 3) == 0);
    CHECK(identityMat.get(3, 0) == 0);
    CHECK(identityMat.get(3, 1) == 0);
    CHECK(identityMat.get(3, 2) == 0);
}
TEST_CASE("Operator + Test") {
    using namespace matrix;

    SquareMat A(2), B(2);
    A.set(0, 0, 1); A.set(0, 1, 2);
    A.set(1, 0, 3); A.set(1, 1, 4);

    B.set(0, 0, 5); B.set(0, 1, 6);
    B.set(1, 0, 7); B.set(1, 1, 8);

    SquareMat C = A + B;

    SUBCASE("Check sum") {
        CHECK(C.get(0, 0) == 6);
        CHECK(C.get(0, 1) == 8);
        CHECK(C.get(1, 0) == 10);
        CHECK(C.get(1, 1) == 12);
        
    }
    SquareMat D(3); // מטריצה בגודל שונה
    CHECK_THROWS_AS(A + D, std::invalid_argument); 

    std::cout << "Test operator+ passed!" << std::endl;
}

TEST_CASE("Operator * Test") {
    using namespace matrix;

    SquareMat A(2), B(2);
    A.set(0, 0, 1); A.set(0, 1, 2);
    A.set(1, 0, 3); A.set(1, 1, 4);

    B.set(0, 0, 5); B.set(0, 1, 6);
    B.set(1, 0, 7); B.set(1, 1, 8);

    SquareMat C = A * B;

    SUBCASE("Check multiplication") {
        CHECK(C.get(0, 0) == 19); // 1*5 + 2*7
        CHECK(C.get(0, 1) == 22); // 1*6 + 2*8
        CHECK(C.get(1, 0) == 43); // 3*5 + 4*7
        CHECK(C.get(1, 1) == 50); // 3*6 + 4*8
    }
    SquareMat D(3); // מטריצה בגודל שונה
    CHECK_THROWS_AS(A * D, std::invalid_argument); 
    std::cout << "Test operator* passed!" << std::endl;
}
TEST_CASE("Operator % Test") {
    using namespace matrix;

    SquareMat A(2), B(2);
    A.set(0, 0, 5); A.set(0, 1, 10);
    A.set(1, 0, 15); A.set(1, 1, 20);

    B.set(0, 0, 3); B.set(0, 1, 4);
    B.set(1, 0, 7); B.set(1, 1, 6);

    SquareMat C = A % B;

    SUBCASE("Check element-wise modulo") {
        
        CHECK(C.get(0, 0) == fmod(5, 3));
        CHECK(C.get(0, 1) == fmod(10, 4));
        CHECK(C.get(1, 0) == fmod(15, 7));
        CHECK(C.get(1, 1) == fmod(20, 6));
    }

    SquareMat D(3); 
    CHECK_THROWS_AS(A % D, std::invalid_argument);  // בדיקה שתחזור שגיאה אם המטריצות לא באותו גודל

    std::cout << "Test operator% passed!" << std::endl;
}

TEST_CASE("Equality Operator Test") {
    using namespace matrix;

    SquareMat A(2), B(2), C(2);
    A.set(0, 0, 1); A.set(0, 1, 2);
    A.set(1, 0, 3); A.set(1, 1, 4);

    B.set(0, 0, 1); B.set(0, 1, 2);
    B.set(1, 0, 3); B.set(1, 1, 4);

    C.set(0, 0, 0); C.set(0, 1, 0);
    C.set(1, 0, 0); C.set(1, 1, 0);

    SUBCASE("Check equality") {
        CHECK(A == B);
        CHECK(!(A == C));
    }

    std::cout << "Test operator== passed!" << std::endl;
}

TEST_CASE("Operator - Test") {
    using namespace matrix;

    SquareMat A(2), B(2);
    A.set(0, 0, 5); A.set(0, 1, 7);
    A.set(1, 0, 9); A.set(1, 1, 4);

    B.set(0, 0, 2); B.set(0, 1, 3);
    B.set(1, 0, 1); B.set(1, 1, 4);

    SquareMat C = A - B;

    SUBCASE("Check subtraction") {
        CHECK(C.get(0, 0) == 3);
        CHECK(C.get(0, 1) == 4);
        CHECK(C.get(1, 0) == 8);
        CHECK(C.get(1, 1) == 0);
    }

    std::cout << "Test operator- passed!" << std::endl;
}

TEST_CASE("Operator *= Test") {
    using namespace matrix;

    SquareMat A(2), B(2);
    A.set(0, 0, 1); A.set(0, 1, 2);
    A.set(1, 0, 3); A.set(1, 1, 4);

    B.set(0, 0, 5); B.set(0, 1, 6);
    B.set(1, 0, 7); B.set(1, 1, 8);

    A *= B;

    SUBCASE("Check multiplication assignment") {
        CHECK(A.get(0, 0) == 19); // 1*5 + 2*7
        CHECK(A.get(0, 1) == 22); // 1*6 + 2*8
        CHECK(A.get(1, 0) == 43); // 3*5 + 4*7
        CHECK(A.get(1, 1) == 50); // 3*6 + 4*8
    }

    std::cout << "Test passed for valid multiplication!" << std::endl;
}

TEST_CASE("Unary Minus Operator Test") {
    using namespace matrix;
    
    SquareMat mat(3);
    mat.set(0, 0, 1);
    mat.set(0, 1, -2);
    mat.set(0, 2, 3);
    mat.set(1, 0, -4);
    mat.set(1, 1, 5);
    mat.set(1, 2, -6);
    mat.set(2, 0, 7);
    mat.set(2, 1, -8);
    mat.set(2, 2, 9);

    SquareMat result = -mat;

    SUBCASE("Check unary minus") {
        CHECK(result.get(0, 0) == -1);
        CHECK(result.get(0, 1) == 2);
        CHECK(result.get(0, 2) == -3);
        CHECK(result.get(1, 0) == 4);
        CHECK(result.get(1, 1) == -5);
        CHECK(result.get(1, 2) == 6);
        CHECK(result.get(2, 0) == -7);
        CHECK(result.get(2, 1) == 8);
        CHECK(result.get(2, 2) == -9);
    }

    std::cout << "Unary minus operator test passed!" << std::endl;

}
TEST_CASE("Unary Minus Operator Test") {
    using namespace matrix;
    SquareMat m(2);
    m.set(0, 0, 1); m.set(0, 1, -2);
    m.set(1, 0, 3); m.set(1, 1, 0);

    SquareMat neg = -m;

    CHECK(neg.get(0, 0) == -1);
    CHECK(neg.get(0, 1) == 2);
    CHECK(neg.get(1, 0) == -3);
    CHECK(neg.get(1, 1) == 0);

    CHECK(m.get(0, 0) == 1);  // original not changed
    std::cout << "Unary minus operator test passed!" << std::endl;
}
TEST_CASE("Matrix * Scalar Operator") {
    using namespace matrix;
    SquareMat m(2);
    m.set(0, 0, 1); m.set(0, 1, 2);
    m.set(1, 0, -3); m.set(1, 1, 4);

    SquareMat res = m * 2;

    CHECK(res.get(0, 0) == 2);
    CHECK(res.get(0, 1) == 4);
    CHECK(res.get(1, 0) == -6);
    CHECK(res.get(1, 1) == 8);
}
TEST_CASE("Scalar * Matrix Operator") {
    using namespace matrix;
    SquareMat m(2);
    m.set(0, 0, 1); m.set(0, 1, 2);
    m.set(1, 0, -3); m.set(1, 1, 4);

    SquareMat res = 3 * m;

    CHECK(res.get(0, 0) == 3);
    CHECK(res.get(0, 1) == 6);
    CHECK(res.get(1, 0) == -9);
    CHECK(res.get(1, 1) == 12);
}
TEST_CASE("Inequality Operator") {
    using namespace matrix;
    SquareMat a(2), b(2), c(2);
    a.set(0, 0, 1); a.set(0, 1, 2); a.set(1, 0, 3); a.set(1, 1, 4);
    b.set(0, 0, 1); b.set(0, 1, 2); b.set(1, 0, 3); b.set(1, 1, 4);
    c.set(0, 0, 1); c.set(0, 1, 2); c.set(1, 0, 3); c.set(1, 1, 5);

    CHECK((a != b) == false);  // should be equal
    CHECK((a != c) == true);   // different in one value
}
TEST_CASE("Operator ^ Test (Matrix Power)") {
    using namespace matrix;

    SquareMat A(2);
    A.set(0, 0, 1); A.set(0, 1, 2);
    A.set(1, 0, 3); A.set(1, 1, 4);

    SquareMat result = A ^ 2;

    SUBCASE("Check power") {
        CHECK(result.get(0, 0) == 7);  // (1*1 + 2*3)
        CHECK(result.get(0, 1) == 10); // (1*2 + 2*4)
        CHECK(result.get(1, 0) == 15); // (3*1 + 4*3)
        CHECK(result.get(1, 1) == 22); // (3*2 + 4*4)
    }
    CHECK_THROWS_AS(A ^ -1, std::invalid_argument); // בדיקה שתחזור שגיאה אם החזקה שלילית
}
TEST_CASE("Transpose Operator Test with Error Handling") {
    using namespace matrix;
    // מטריצה 2x2 תקינה
    SquareMat mat(2);
    mat.set(0, 0, 1);
    mat.set(0, 1, 2);
    mat.set(1, 0, 3);
    mat.set(1, 1, 4);

    // ביצוע טרנספוזה
    SquareMat transposed = ~mat;

    // בדיקות עבור מטריצה תקינה
    CHECK(transposed.get(0, 0) == 1);
    CHECK(transposed.get(0, 1) == 3);
    CHECK(transposed.get(1, 0) == 2);
    CHECK(transposed.get(1, 1) == 4); 

    SquareMat singleElementMat(1);
    singleElementMat.set(0, 0, 5);

    // ביצוע טרנספוזה על מטריצה 1x1 (אמור להחזיר את אותה המטריצה)
    SquareMat transposedSingle = ~singleElementMat;
    CHECK(transposedSingle.get(0, 0) == 5);
    
    SquareMat invalidMat(2);
    invalidMat.set(0, 0, -1);  // לדוגמה הערך שלילי
    invalidMat.set(0, 1, -2);
    invalidMat.set(1, 0, -3);
    invalidMat.set(1, 1, -4);

    // כאן המטריצה תקינה עדיין, אז אין צורך בשגיאה כאן
    SquareMat transposedInvalid = ~invalidMat;
    CHECK(transposedInvalid.get(0, 0) == -1);
    CHECK(transposedInvalid.get(0, 1) == -3);
    CHECK(transposedInvalid.get(1, 0) == -2);
    CHECK(transposedInvalid.get(1, 1) == -4);
}
TEST_CASE("Increment and Decrement Operators") {
    using namespace matrix;
    SquareMat mat(2);
    mat.set(0, 0, 1);
    mat.set(0, 1, 2);
    mat.set(1, 0, 3);
    mat.set(1, 1, 4);

    // Pre-increment
    ++mat;
    CHECK(mat.get(0, 0) == 2);
    CHECK(mat.get(0, 1) == 3);
    CHECK(mat.get(1, 0) == 4);
    CHECK(mat.get(1, 1) == 5);

    // Post-increment
    mat++;
    CHECK(mat.get(0, 0) == 3);
    CHECK(mat.get(0, 1) == 4);
    CHECK(mat.get(1, 0) == 5);
    CHECK(mat.get(1, 1) == 6);

    // Pre-decrement
    --mat;
    CHECK(mat.get(0, 0) == 2);
    CHECK(mat.get(0, 1) == 3);
    CHECK(mat.get(1, 0) == 4);
    CHECK(mat.get(1, 1) == 5);

    // Post-decrement
    mat--;
    CHECK(mat.get(0, 0) == 1);
    CHECK(mat.get(0, 1) == 2);
    CHECK(mat.get(1, 0) == 3);
    CHECK(mat.get(1, 1) == 4);
}
TEST_CASE("Operator [] Access and Modify Elements") {
    using namespace matrix;
    SquareMat mat(3);

    mat[0][0] = 1.1;
    mat[0][1] = 2.2;
    mat[0][2] = 3.3;
    mat[1][0] = 4.4;
    mat[1][1] = 5.5;
    mat[1][2] = 6.6;
    mat[2][0] = 7.7;
    mat[2][1] = 8.8;
    mat[2][2] = 9.9;

    CHECK(mat[0][0] == doctest::Approx(1.1));
    CHECK(mat[0][1] == doctest::Approx(2.2));
    CHECK(mat[0][2] == doctest::Approx(3.3));
    CHECK(mat[1][0] == doctest::Approx(4.4));
    CHECK(mat[1][1] == doctest::Approx(5.5));
    CHECK(mat[1][2] == doctest::Approx(6.6));
    CHECK(mat[2][0] == doctest::Approx(7.7));
    CHECK(mat[2][1] == doctest::Approx(8.8));
    CHECK(mat[2][2] == doctest::Approx(9.9));
    CHECK_THROWS_AS(mat[-1][0], std::out_of_range);
    CHECK_THROWS_AS(mat[3][6], std::out_of_range);
    CHECK_THROWS_AS(mat[2][6], std::out_of_range);
    
}
TEST_CASE("Comparison Operators (<, >, <=, >=) Test") {
    using namespace matrix;

    SquareMat A(2);
    A.set(0, 0, 1);
    A.set(0, 1, 2);
    A.set(1, 0, 3);
    A.set(1, 1, 4); // sum = 10

    SquareMat B(2);
    B.set(0, 0, 5);
    B.set(0, 1, 5);
    B.set(1, 0, 5);
    B.set(1, 1, 5); // sum = 20

    SquareMat C(2);
    C.set(0, 0, 1);
    C.set(0, 1, 2);
    C.set(1, 0, 3);
    C.set(1, 1, 4); // sum = 10 (כמו A)

    CHECK(A < B);       // 10 < 20
    CHECK(B > A);       // 20 > 10
    CHECK(A <= C);      // 10 <= 10
    CHECK(C >= A);      // 10 >= 10
    CHECK_FALSE(B <= A);
    CHECK_FALSE(A > B);
}
TEST_CASE("Determinant Operator (!) Test") {
    using namespace matrix;

    SquareMat mat1(1);
    mat1.set(0, 0, 5);
    CHECK((!mat1) == 5);

    SquareMat mat2(2);
    mat2.set(0, 0, 1);
    mat2.set(0, 1, 2);
    mat2.set(1, 0, 3);
    mat2.set(1, 1, 4);
    // det = 1*4 - 2*3 = 4 - 6 = -2
    CHECK((!mat2) == -2);

    SquareMat mat3(3);
    mat3.set(0, 0, 6); mat3.set(0, 1, 1); mat3.set(0, 2, 1);
    mat3.set(1, 0, 4); mat3.set(1, 1, -2); mat3.set(1, 2, 5);
    mat3.set(2, 0, 2); mat3.set(2, 1, 8); mat3.set(2, 2, 7);
    // det = 6(-2*7 - 5*8) - 1(4*7 - 5*2) + 1(4*8 - (-2)*2)
    //     = 6(-14 - 40) - 1(28 - 10) + 1(32 + 4)
    //     = 6(-54) - 18 + 36 = -324 -18 + 36 = -306
    CHECK((!mat3) == -306);
}


TEST_CASE("Operator += Test") {
    using namespace matrix;

    SquareMat m1(2);
    m1.set(0, 0, 1); m1.set(0, 1, 2);
    m1.set(1, 0, 3); m1.set(1, 1, 4);

    SquareMat m2(2);
    m2.set(0, 0, 5); m2.set(0, 1, 6);
    m2.set(1, 0, 7); m2.set(1, 1, 8);

    m1 += m2;
    // Result should be:
    // [6 8]
    // [10 12]
    CHECK(m1[0][0] == 6);
    CHECK(m1[0][1] == 8);
    CHECK(m1[1][0] == 10);
    CHECK(m1[1][1] == 12);

    // Error case - size mismatch
    SquareMat m3(3);
    CHECK_THROWS_AS(m1 += m3, std::invalid_argument);
}
TEST_CASE("Operator -= Test") {
    using namespace matrix;

    SquareMat m1(2);
    m1.set(0, 0, 9); m1.set(0, 1, 8);
    m1.set(1, 0, 7); m1.set(1, 1, 6);

    SquareMat m2(2);
    m2.set(0, 0, 1); m2.set(0, 1, 2);
    m2.set(1, 0, 3); m2.set(1, 1, 4);

    m1 -= m2;
    // Result:
    // [8 6]
    // [4 2]
    CHECK(m1[0][0] == 8);
    CHECK(m1[0][1] == 6);
    CHECK(m1[1][0] == 4);
    CHECK(m1[1][1] == 2);

    // Error case - size mismatch
    SquareMat m3(3);
    CHECK_THROWS_AS(m1 -= m3, std::invalid_argument);
}
TEST_CASE("Operator /= Test") {
    using namespace matrix;

    SquareMat m1(2);
    m1.set(0, 0, 10); m1.set(0, 1, 20);
    m1.set(1, 0, 30); m1.set(1, 1, 40);

    SquareMat m2(2);
    m2.set(0, 0, 2); m2.set(0, 1, 4);
    m2.set(1, 0, 5); m2.set(1, 1, 8);

    m1 /= m2;
    // Result:
    // [5 5]
    // [6 5]
    CHECK(m1[0][0] == doctest::Approx(5));
    CHECK(m1[0][1] == doctest::Approx(5));
    CHECK(m1[1][0] == doctest::Approx(6));
    CHECK(m1[1][1] == doctest::Approx(5));

    // Division by zero
    m2.set(1, 1, 0);
    CHECK_THROWS_AS(m1 /= m2, std::invalid_argument);

    // Size mismatch
    SquareMat m3(3);
    CHECK_THROWS_AS(m1 /= m3, std::invalid_argument);
}
TEST_CASE("Operator %= Matrix Test") {
    using namespace matrix;

    SquareMat m1(2);
    m1.set(0, 0, 10); m1.set(0, 1, 9);
    m1.set(1, 0, 8); m1.set(1, 1, 7);

    SquareMat m2(2);
    m2.set(0, 0, 4); m2.set(0, 1, 3);
    m2.set(1, 0, 5); m2.set(1, 1, 2);

    m1 %= m2;
    // [2 0]
    // [3 1]
    CHECK(m1[0][0] == doctest::Approx(2));
    CHECK(m1[0][1] == doctest::Approx(0));
    CHECK(m1[1][0] == doctest::Approx(3));
    CHECK(m1[1][1] == doctest::Approx(1));

    // Size mismatch
    SquareMat m3(3);
    CHECK_THROWS_AS(m1 %= m3, std::invalid_argument);
}


