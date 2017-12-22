#include "Solution.h"

#ifndef M_PI
   #define M_PI 3.14159265358979323846
#endif

#include <iostream>
#include <cfloat>


Solution::Solution (/*const*/ Problem& pbm): _pbm{pbm}{

    std::cout<<"test constructeur solution !!!\n";
    initialize();
}

Solution::Solution (const Solution& sol) : _pbm{sol._pbm}, _current_fitness{sol._current_fitness}, _solution{sol._solution} {}

const Problem& Solution::pbm() const{

    return _pbm;
}

Solution::~Solution(){
    _solution.pop_back();
}

void Solution :: fitness()
{
    int num = _pbm.getNumFunction();
    switch(num)
    {
    case 1: //Rosenbrock
        {
           double somme=0;
        for (int i=0; i<_pbm.dimension();i++){
            somme+= pow(_solution[i+1]- pow(_solution[i],2),2)+pow(_solution[i]-1,2);
        }
        _current_fitness=100*somme;
        break;
        }

    case 2: //Rastrigin
    {
        double somme=0;
        for (int i=0; i<_pbm.dimension();i++){
            somme+= pow(_solution[i],2)-10 * cos(2*M_PI*_solution[i]);
        }
        _current_fitness=10*_pbm.dimension();
        break;
    }

    case 3: // Ackley
    {
            double a=20,b=0.2,c=2*M_PI,som1=0,som2=0;
        for (int i=0; i<_pbm.dimension();i++){
            som1+=pow(_solution[i],2);
            som2+=cos(c*_solution[i]);
        }
         _current_fitness= -a* exp((-b*sqrt((1/_pbm.dimension())*som1))- exp((1/_pbm.dimension())*som2))+a+ exp(1);
         break;
    }

    case 4: //Schwefel
    {
        double somme=0;
        for(int i=0; i< _pbm.dimension();i++){
            somme+= _solution[i]*sin(sqrt(abs(_solution[i])));
        }
        _current_fitness= 418.9829*_pbm.dimension()-somme;
        break;
    }

    case 5: //Schaffer // a voir
    {
        double numerateur= pow(sin(pow(_solution[0],2)-pow(_solution[1],2)),2) -0.5;
        double denominateur= pow(1+0.001*(pow(_solution[0],2)+pow(_solution[1],2)),2);
        _current_fitness= 0.5+(numerateur/denominateur);
        break;
    }

    case 6: //Weierstrass
    {
        double som1=0,som2=0,kmax=20,b=3,a=0.5,f_bias=90;
        for (int i=0;i<_pbm.dimension();i++){
            for (int k=0; k<kmax;k++){
                som1+= pow(a,k)*cos(2*M_PI*pow(b,k)*(_solution[i]+0.5));
            }
        }
        for(int k=0;k<=kmax;k++){
             som2+= pow(a,k)*cos(2*M_PI*pow(b,k)*0.5);
        }
        _current_fitness= som1-_pbm.dimension()*som2+f_bias;
        break;
    }

    }
}
double Solution::get_fitness(){
    fitness();
    return _current_fitness;
}

unsigned int Solution:: size() const{
    return _solution.size();
}

std::vector<double>& Solution::solution(){
    return _solution;
}

double& Solution::position(const int index){
    return _solution[index];
}

void  Solution::position(const int index, const double value){
    _solution[index]= value;
}

void Solution::initialize(){
    for(int i=0;i<30;i++){
        std::cout<<"salut du init solution\n";
        srand(time(NULL));
        std::cout<<"salut du init solution2\n";
        _solution[i]=static_cast<double>(rand());
        std::cout<<"salut du init solution3\n";
    }
}

Solution& Solution::operator=(const Solution& sol){
    _pbm=sol._pbm;
   _current_fitness=sol._current_fitness;
   _solution=sol._solution;
}

