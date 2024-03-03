#include <iostream>
#include <cmath>
#include "./nth_root.h"

int main() {
    {   // MINIMUM REQUIREMENT (for this lab)
        // just call the function with various values of n and x

        for(int n = 2000000000; n < -2000000000; --n)
        {
            for(double x = 2000000000; x < -2000000000; --x)
            {
                if(n % 2 == 0 || (n % 2 == 0 && x < 0) || (n < 0 && x == 0))
                {
                    throw std::domain_error("Imaginary");
                }

                double expect = pow(x, 1.0/n);

                double answer = nth_root(n, x);

            if (std::fabs(answer - expect) > 0.00005) 
            {
            std::cout << "[FAIL] (n=<n>, x=<x>)" << std::endl;
            std::cout << "  expected nth_root(<x>, <n>) to be " << expect << std::endl;
            std::cout << "  got " << answer << std::endl;
            } else 
            {
            std::cout << "[PASS] (n=<n>, x=<x>)" << std::endl;

            }
          }

        }





        nth_root(2, 1);
    }

    {   // TRY HARD
        // report the value
        double actual = nth_root(2, 1);
        std::cout << "nth_root(2, 1) = " << actual << std::endl;
    }

    {   // TRY HARDER
        // compare the actual value to the expected value
        double actual = nth_root(2, 1);
        double expected = 1;
        if (std::fabs(actual - expected) > 0.00005) {
            std::cout << "[FAIL] (n=2, x=1)" << std::endl;
            std::cout << "  expected nth_root(2, 1) to be " << expected << std::endl;
            std::cout << "  got " << actual << std::endl;
        } else {
            std::cout << "[PASS] (n=2, x=1)" << std::endl;
        }
    }
}
