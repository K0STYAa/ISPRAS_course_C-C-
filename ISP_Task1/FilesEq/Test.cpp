#include "Quad.h"
#include "Test.h"

void test() {

    double root1 = NAN, root2 = NAN;

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
        assert(IsZero(root1 + 4.0 / 3));
    }

    { /// 7 = 0 ; no roots
        Params test_param(0, 0, 7);
        assert(test_param.Solve(root1, root2) == 0);
    }

    { /// 0 = 0 ; any number is root
        Params test_param(0, 0, 0);
        assert(test_param.Solve(root1, root2) == -1);
    }

    std::cerr << "Solution of the quadratic equation was tested\n"; 

}
