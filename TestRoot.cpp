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
    assert(-1 == TestRoot(0., 0., 0.).n);
    std::cerr << "Assertion 0x^2 + 0x + 0 = 0 x = infinity [PASSED]" << std::endl;

    assert(TestRoot(1., 1., 1) == TestRoot(0., 1., -1.));
    std::cerr << "Assertion 0x^2 + x - 1 = 0 x = 1 [PASSED]" << std::endl;

    assert(TestRoot(0.5, 0.5, 1) == TestRoot(0., 1., -0.5));
    std::cerr << "Assertion 0x^2 + x - 0.5 = 0 x = 0.5 [PASSED]" << std::endl;

    assert(TestRoot(0.2222, 0.2222, 1) == TestRoot(0., 1., -0.2222));
    std::cerr << "Assertion 0x^2 + x - 0.2222 = 0 x = 0.2222 [PASSED]" << std::endl;

    assert(TestRoot(0.5, 0.5, 1) == TestRoot(0., 1., -0.5));
    std::cerr << "Assertion 0x^2 + x - 0.5 = 0 x = 0.5 [PASSED]" << std::endl;

    assert(TestRoot(-0.1, -0.1, 1) == TestRoot(0., 1., 0.1));
    std::cerr << "Assertion 0x^2 + x + 0.1 = 0 x = -0.1 [PASSED]" << std::endl;



    assert(TestRoot(-1., -1., 1) == TestRoot(1., 2., 1.));
    std::cerr << "Assertion x^2 + 2x + 1 = 0 x = -1 [PASSED]" << std::endl;

    assert(TestRoot(-2., -2., 1) == TestRoot(1., 4., 4.));
    std::cerr << "Assertion x^2 + 4x + 4 = 0 x = -2 [PASSED]" << std::endl;

    assert(TestRoot(1., 0., -2.) == TestRoot(std::sqrt(2), -std::sqrt(2), 2));
    std::cerr << "Assertion x^2 + x - 2 = 0; x1 = 2 x2 = -2 [PASSED]" << std::endl;

    assert(TestRoot(0., 0., 0) == TestRoot(1., 0., 2.));
    std::cerr << "Assertion x^2 + x - 1 = 0 x are not real [PASSED]" << std::endl;

}