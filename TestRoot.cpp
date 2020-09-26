#include"TestRoot.hpp"
#include<cassert>
#include<iostream>
#include<limits>
#include<cmath>
TestSquare::TestRoot::TestRoot()
{
    x1 = x2 = std::numeric_limits<double>::quiet_NaN();
    n = 0;
}

TestSquare::TestRoot::TestRoot(double y1, double y2, int k) : x1(y1), x2(y2), n(k) {}

TestSquare::TestRoot::TestRoot(double a, double b, double c)
{
    x1 = x2 = std::numeric_limits<double>::quiet_NaN();
    n = SquareRootsEval(a, b, c, x1, x2);
}

auto TestSquare::TestRoot::operator==(const TestRoot& arg) -> bool
{
    if (arg.n != n)
        return 0;
    if (arg.n == 0)
        return 1;
    if (arg.x1 == x1 && arg.x2 == x2)
        return 1;
    return 0;
}

auto TestSquare::testRootEval() -> void
{
#define TESTM(a1, a2, a3, b1, b2, b3)\
    assert(TestRoot(a1, a2, a3) == TestRoot(b1, b2, b3));\
    std::cerr << "Assertion " #b1 " x^2 + " #b2 " x + " #b3 " = 0"\
              << "x1 = " #a1 " x2 = " #a2 " amount is " #a3 " [PASSED]"\
              << std::endl;

    assert(-1 == TestRoot(0., 0., 0.).n);
    std::cerr << "Assertion 0x^2 + 0x + 0 = 0 x = infinity [PASSED]" << std::endl;
    
    TESTM(    1.,  1.,      1,           0.,            1.,     -1.);
    TESTM(   0.5, 0.5,      1,           0.,            1.,    -0.5);
    TESTM(0.2222, 0.2222,   1,           0.,            1., -0.2222);
    TESTM(   0.5,    0.5,   1,           0.,            1.,    -0.5);
    TESTM(  -0.1,   -0.1,   1,           0.,            1.,     0.1);
    TESTM(   -1.,    -1.,   1,           1.,            2.,      1.);
    TESTM(   -2.,    -2.,   1,           1.,            4.,      4.);
    TESTM(    1.,     0., -2., std::sqrt(2), -std::sqrt(2),       2);
    TESTM(    0.,     0.,   0,           1.,            0.,      2.);
}
