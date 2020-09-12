#include <iostream>
#include <cmath>
#include <assert.h>
#include <iomanip>

namespace constants {
    double EPS = 0.0001;
    int precision = 6;
}

///---------------------------------------------------------------------------------------------------------------------
/*!
is double number zero
 @param[in] a our double number
 @return true if number is zero
*/
bool IsZero(double value) {
    assert(std::isfinite(value));
    return fabs(value) < constants::EPS;
}
///---------------------------------------------------------------------------------------------------------------------

struct Params {

    Params() {
        std::cout << "Enter the coefficients a, b, c of the quadratic equation" << std::endl;
        std::cin >> this->a >> this->b >> this->c;
    }

    /*! Solves a quadratic equation ax^2 + bx + c = 0
     @param [in] a_ coefficient
     @param [in] b_ coefficient
     @param [in] c_ coefficient
    */
    Params(double a_, double b_, double c_) {
        a = a_;
        b = b_;
        c = c_;
    }

    /*! Solves a quadratic equation ax^2 + bx + c = 0
     @param [out] root1 Reference to first root
     @param [out] root2 Reference to second root
     @return Number of roots
     @note In case of infinite number of roots, returns -1
    */

    int Solve(double &root1, double &root2) {
        if (!IsZero(a)) {
            ///quadratic equation
            double d = b * b - 4 * a * c;
            if (IsZero(d)) {
                root1 = -b / (2 * a);
                return 1;
            }
            if (d < -constants::EPS) {
                return 0;
            }
            root1 = (-b - sqrt(d)) / (2 * a);
            root2 = (-b + sqrt(d)) / (2 * a);
            return 2;
        }
        if (!IsZero(b)) {
            ///linear equation
            root1 = -c / b;
            return 1;
        }
        if (!IsZero(c)) {
            ///no roots
            return 0;
        }
        /// c = 0 ; x = any number
        return -1;
    }

private:
    double a, b, c;
};

///---------------------------------------------------------------------------------------------------------------------
/*! Tests the function for solving a square equation */
void test() {

    double root1, root2;

    { /// -x^2 + 4x - 4 = 0 ; root = 2
        Params test_param(-1, 4, -4);
        assert(test_param.Solve(root1, root2) == 1);
        assert(root1 == 2);
    }

    { /// x^2 + x + 1 = 0 ; no roots
        Params test_param(1, 1, 1);
        assert(test_param.Solve(root1, root2) == 0);
    }

    { /// x^2 - 2 = 0 ; root1 = -sqrt(2), root2 = sqrt(2)
        Params test_param(1, 0, -2);
        assert(test_param.Solve(root1, root2) == 2);
        assert(IsZero(root1 + sqrt(2.0)));
        assert(IsZero(root2 - sqrt(2.0)));
    }

    { /// 3x + 4 = 0 ; root = -1.3333
        Params test_param(0, 3, 4);
        assert(test_param.Solve(root1, root2) == 1);
        assert(IsZero( root1 + 4.0 / 3 ));
    }

    { /// 7 = 0 ; no roots
        Params test_param(0, 0, 7);
        assert(test_param.Solve(root1, root2) == 0);
    }

    { /// 0 = 0 ; any number is root
        Params test_param(0, 0, 0);
        assert(test_param.Solve(root1, root2) == -1);
    }

}
///---------------------------------------------------------------------------------------------------------------------

int main() {
    test();
    double root1, root2;
    Params param;
    int nRoots = param.Solve(root1, root2);
    switch (nRoots) {

        case -1:    std::cout << "Any number" << std::endl;
                    break;

        case 0:     std::cout << "No roots" << std::endl;
                    break;

        case 1:     std::cout << std::fixed << std::setprecision(constants::precision)
                    << "x = " << root1 << std::endl;
                    break;

        case 2:     std::cout << std::fixed << std::setprecision(constants::precision)
                    << "x1 = " << root1 << ", x2 = " << root2 << std::endl;
                    break;

        default:    std::cout << "main(): ERROR: nRoots = " << nRoots << std::endl;
                    return 1;

    }

    return 0;
}
