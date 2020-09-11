#include"MRootEval.hpp"
#include<limits>
#include<cmath>
inline auto MRootEval::IsZero(double x) -> bool
{
    return static_cast<int>(std::fabs(x) < std::numeric_limits<double>::epsilon());
}

auto MRootEval::SquareRootsEval(double a, double b, double c, double& x1, double& x2) -> int
{
    if (IsZero(a))
        if (IsZero(b))
            if (IsZero(c))
                return -1;
            else
            {
                x1 = x2 = std::numeric_limits<double>::quiet_NaN();
                return 0;
            }
        else
        {
            x1 = x2 = -c / b;
            return 1;
        }
    double d = b * b - 4 * a * c;

    if (d < 0)
    {
        x1 = x2 = std::numeric_limits<double>::quiet_NaN();
        return 0;
    }

    if (IsZero(d))
    {
        x1 = x2 = (-b) / (2 * a);
        return 1;
    }

    b = (-b) / (2 * a);
    d = std::sqrt(d) / (2 * a);
    x1 = b + d;
    x2 = b - d;
    return 2;
}