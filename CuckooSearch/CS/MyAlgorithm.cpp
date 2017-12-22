#include "MyAlgorithm.h"

MyAlgorithm::MyAlgorithm(/*const*/ Problem& pbm,/*const*/ SetUpParams& setup) : _pbm{pbm}, _setup{setup}
{
    //ctor
}

MyAlgorithm::~MyAlgorithm()
{
    /*for(int i=0;i<_solutions.size();i+=1)
    {
        delete _solutions[i];
    }*/
}

SetUpParams& MyAlgorithm::setup() const
{
    return _setup;
}

void MyAlgorithm::initialize()
{

    for(int i=0;i<_setup.solution_size();i+=1)
    {
        Solution s{_pbm};
        std::cout<<"test taille : "<<_setup.solution_size()<<std::endl;
        _solutions.push_back(s);
    }
}

void MyAlgorithm::evaluate()
{
    for(int i=0;i<_solutions.size();i+=1)
    {
        _fitness_values[i]=_solutions[i].get_fitness();
    }
}

/*const*/ std::vector<Solution>& MyAlgorithm::solutions() /*const*/
{
    return _solutions;
}

unsigned int MyAlgorithm::upper_cost() const
{
    return _upper_cost;
}

unsigned int MyAlgorithm::lower_cost() const
{
    return _lower_cost;
}

Solution& MyAlgorithm::solution(const unsigned int index) /*const*/
{
    return _solutions[index];
}

double MyAlgorithm::fitness(const unsigned int index)/* const*/
{
    return _solutions[index].get_fitness();
}

double MyAlgorithm::best_cost() /*const*/
{
    double best = _solutions[0].get_fitness();
    for(int i=1;i<_solutions.size();i+=1)
    {
        if(best<_solutions[i].get_fitness())
            best=_solutions[i].get_fitness();
    }
    return best;
}

double MyAlgorithm::worst_cost() /*const*/
{
    double worst = _solutions[0].get_fitness();
    for(int i=1;i<_solutions.size();i+=1)
    {
        if(worst>_solutions[i].get_fitness())
            worst=_solutions[i].get_fitness();
    }
    return worst;
}

Solution& MyAlgorithm::best_solution() /*const*/
{
    Solution& best_sol = _solutions[0];
    for(int i=1;i<_solutions.size();i+=1)
    {
        if(best_sol.get_fitness()<_solutions[i].get_fitness())
            best_sol=_solutions[i];
    }

    return best_sol;
}

Solution& MyAlgorithm::worst_solution() /*const*/
{
    Solution& worst_sol = _solutions[0];
    for(int i=1;i<_solutions.size();i+=1)
    {
        if(worst_sol.get_fitness()>_solutions[i].get_fitness())
            worst_sol=_solutions[i];
    }

    return worst_sol;
}

void MyAlgorithm::evolution(unsigned int& iter, unsigned int& nbAppelFitness)  // à modifier pour que ça corresponde à un seul changement de population(donc pas de while mais un if plutôt et pas d'initialisation ici)
{
    //initialize();
    if(iter<=_setup.independent_runs() && nbAppelFitness<=_setup.nb_evolution_steps())
    {
        // Lévi flights
        Levy l;
        Solution tempSol{_pbm};

        for(int j=0; j<_setup.solution_size();j+=1) {

            tempSol.position(j, l.rnd());
        }



        //double levi_fit=levi_choice.get_fitness();
        srand(time(NULL));
        int position = rand()%30;
        Solution replaced = _solutions[position];

        if(tempSol.get_fitness()>replaced.get_fitness())
            _solutions[position]=tempSol;

        for(int i=0;i<9;i+=1)
        {
            double pos = 0/*_solutions[0].get_fitness()*/;
            for(int i=1;i<_solutions.size();i+=1)
            {
            if(_solutions[pos].get_fitness()<_solutions[i].get_fitness())
                pos=i;
                nbAppelFitness+=2;
            }
            const Solution& nSol{_pbm};
            _solutions[pos]=nSol;
        }
    }
    iter+=1;
}




