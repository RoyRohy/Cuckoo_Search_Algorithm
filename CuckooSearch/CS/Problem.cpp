#include "Problem.h"

Problem::Problem(int dimension, int numFunction) : _dimension{dimension}, _num_func{numFunction}
{
    switch(_num_func)
    {
        case 1: //Rosenbrock
            LowerLimit=-5;
            UpperLimit=10;
            break;
        case 2: //Rastigin
            LowerLimit=-5.12;
            UpperLimit=5.12;
            break;
        case 3: //Ackley
            LowerLimit=-32.768;
            UpperLimit=32.768;
            break;
        case 4: //Schwefel
            LowerLimit=-500;
            UpperLimit=500;
            break;
        case 5: //Schaffer
            LowerLimit=-100;
            UpperLimit=100;
            break;
        case 6: //Weierstrass
            LowerLimit=-0.5;
            UpperLimit=0.5;
            break;
    }
}

Problem::~Problem()
{
    //dtor
}

int Problem::dimension() const
{
    return 30;
}

int Problem::getNumFunction() const
{
    return _num_func;
}
