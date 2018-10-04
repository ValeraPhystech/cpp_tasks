#include <iostream>
#include <math.h>
#include <cassert>

//-----------------------------
//! @brief Solves square equation in canonic form ax^2+bx+c=0
//! @param [in] a coefficient a
//! @param [in] b coefficient b
//! @param [in] c coefficient c
//! @param [out] x1 first root
//! @param [out] x2 second root
//! @return Number of roots
//! @note In case of infinite number of roots, returns -1
//-----------------------------
int SolveEquation(double a, double b, double c, double &x1, double &x2) {
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    if (a == 0) {
        if (b == 0) {
            return (c == 0) ? -1 : 0;
        } else /* if (b != 0) */
        {
            x1 = -1 * c / b;
            return 1;
        }
    } else /* if (a != 0) */
    {
        double d = b * b - 4 * a * c;
        if (d == 0) {
            x1 = x2 = -1 * b / (2 * a);
            return 1;
        } else {
            double sqrt_d = sqrt(d);
            x1 = (-1 * b - sqrt_d) / (2 * a);
            x2 = (-1 * b + sqrt_d) / (2 * a);
            return 2;
        }
    }
}

int main() {
    std::cout << "Solver of square equations" << std::endl;
    std::cout << "Canonic form: ax^2+bx+c=0" << std::endl;
    std::cout << "Enter a,b,c" << std::endl;
    double a = 0, b = 0, c = 0;
    std::cin >> a >> b >> c;

    double x1 = 0, x2 = 0;
    int RootsCount = SolveEquation(a, b, c, x1, x2);

    switch (RootsCount) {
        case 0:
            std::cout << "No roots found" << std::endl;
            break;
        case 1:
            std::cout << "x1 = x2 =" << x1 << std::endl;
            break;
        case 2:
            std::cout << "x1 = " << x1 << "x2 = " << x2 << std::endl;
            break;
        case -1:
            std::cout << "Any number" << std::endl;
            break;
    }
    return 0;
}