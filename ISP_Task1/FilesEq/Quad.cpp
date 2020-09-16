#include "Test.h"
#include "Quad.h"


namespace constants {
    double EPS = 0.000001;
    int precision = 6;
}


bool IsZero(double value) {
    assert(std::isfinite(value));
    return fabs(value) < constants::EPS;
}

void AbsZero(double &value) {
   value = fabs(value) < constants::EPS ? fabs(value) : value;
}


Params::Params() {
    std::cout << "Enter the coefficients a, b, c of the quadratic equation" << std::endl;
    std::cin >> this->a >> this->b >> this->c;
    if (std::cin.fail() || (a < INT_MIN || a > INT_MAX) ||
                           (b < INT_MIN || b > INT_MAX) || 
                           (c < INT_MIN || c > INT_MAX)) {
        std::cout << "Invalid input.\nExit.\n";
        exit(1);
    }
}


Params::Params(double a_, double b_, double c_) {
    a = a_;
    b = b_;
    c = c_;
}


int Params::Solve(double &root1, double &root2) {
    if (!IsZero(a)) {
        ///quadratic equation
        double d = b * b - 4 * a * c;
        if (IsZero(d)) {
            root1 = -b / (2 * a);
            AbsZero(root1);
            return 1;
        }
        if (d <= -constants::EPS) {
            return 0;
        }
        root1 = (-b - sqrt(d)) / (2 * a);
        root2 = (-b + sqrt(d)) / (2 * a);
        AbsZero(root1);
        AbsZero(root2);
        return 2;
    }
    if (!IsZero(b)) {
        ///linear equation
        root1 = -c / b;
        AbsZero(root1);
        return 1;
    }
    if (!IsZero(c)) {
        ///no roots
        return 0;
    }
    /// c = 0 ; x = any number
    return -1;
}


void SolverOfQuadEquation() {
    test();
    double root1 = NAN, root2 = NAN;
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

    }
}
