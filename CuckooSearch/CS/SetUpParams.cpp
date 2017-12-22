#include "SetUpParams.h"
#include <stdlib.h>
#include <stdio.h>
#include <cmath>

SetUpParams::SetUpParams() : _independent_runs{30}, _nb_evolution_steps{static_cast<unsigned int>(2*pow(10.0,6.0))}, _population_size{30}, _solution_size{30}
{
    //ctor
}

/*SetUpParams::SetUpParams(unsigned int runs, unsigned int steps, unsigned int popsize, unsigned int solsize) : _independent_runs{runs}, _nb_evolution_steps{steps}, _population_size{popsize}, _solution_size{solsize}
{

}*/

SetUpParams::~SetUpParams()
{
    //dtor
}

void SetUpParams::independent_runs(const unsigned int val)
{
    _independent_runs=val;
}

void SetUpParams::nb_evolution_steps(const unsigned int val)
{
    _nb_evolution_steps=val;
}

void SetUpParams::population_size(const unsigned int val)
{
    _population_size=val;
}

void SetUpParams::solution_size(const unsigned int val)
{
    _solution_size=val;
}

unsigned int SetUpParams::independent_runs() const
{
    return _independent_runs;
}

unsigned int SetUpParams::nb_evolution_steps() const
{
    return _nb_evolution_steps;
}

unsigned int SetUpParams::population_size() const
{
    return _population_size;
}

unsigned int SetUpParams::solution_size() const
{
    return _solution_size;
}
