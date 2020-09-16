#pragma once

#include <iostream>
#include <cmath>
#include <iomanip>
#include <assert.h>
#include <limits.h>


/*! Is double number zero
 @param[in] a our double number
 @return true if number is zero
*/
bool IsZero(double value);


/*! Taking module
 @param[in] a our double number
 @return the module of value if his absolute value smalle then EPS
*/
void AbsZero(double &value);


struct Params {

    Params();


    /*! Enter coefficients of quadratic equation ax^2 + bx + c = 0
     @param [in] a_ coefficient
     @param [in] b_ coefficient
     @param [in] c_ coefficient
    */
    Params(double a_, double b_, double c_);


    /*! Solves a quadratic equation ax^2 + bx + c = 0
     @param [out] root1 Reference to first root
     @param [out] root2 Reference to second root
     @return Number of roots
     @note In case of infinite number of roots, returns -1
    */
    int Solve(double &root1, double &root2);


private:

    double a, b, c;
};


/*! Testing and solving our Equaition */
void SolverOfQuadEquation();
