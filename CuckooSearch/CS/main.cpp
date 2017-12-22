#include <stdio.h>
#include <stdlib.h>

#include "MyAlgorithm.h"
#include "SetUpParams.h"
#include "Solution.h"
#include "Problem.h"

using namespace std;


int main()
{

    SetUpParams setup{};

    cout<<"Choix de la fonction :\n";
    cout<<"Rosenbrock (1)\n";
    cout<<"Rastrigin (2)\n";
    cout<<"Ackley (3)\n";
    cout<<"Schwefel (4)\n";
    cout<<"Schaffer (5)\n";
    cout<<"Weierstrass (6)\n";

    int choix;
    cin>>choix;

    cout<<"COUCOU\n";

    if(choix<1 || choix>6) {

        cout<<"Mauvais numéro de fonction, fin du programme\n";
        return 0;
    }

    Problem pb{30,choix};



    MyAlgorithm myAlgo{pb,setup};



    myAlgo.initialize();

    cout<<"COUCOU2\n";

    unsigned int iter = 1;
    unsigned int nbRuns = 1;
    unsigned int nbAppelFitness = 0;

    Solution bestSol{pb};
    //double bestFitness; // pas utile ?

    vector<Solution> resultatsSol;
    vector<double> resultatsFit;



    while(nbRuns<=setup.independent_runs())
    {

        while(iter<=setup.nb_evolution_steps()) {
            cout<<"salut\n";

            myAlgo.evolution(iter,nbAppelFitness);

        }
        bestSol=myAlgo.best_solution();
        resultatsSol.push_back(bestSol);
        resultatsFit.push_back(bestSol.get_fitness());
        nbRuns+=1;
    }



    /*cout<<"La meilleure solution est : \n";
    for(unsigned int i=0;i<myAlgo.solutions().size();i++) {

        cout<<bestSol.solution()[i]<<" ";
    }
    cout<<endl;
    cout<<"Avec la fitness suivante : \n";
    cout<<bestSol.get_fitness();*/

    double som = 0;
    for(unsigned int i=0;i<resultatsFit.size();i+=1)
    {

        som+=resultatsFit[i];
    }

    cout<<"La moyenne des fitness des meilleures solutions est : "<<som/resultatsFit.size()<<endl;

    double maxi = resultatsFit[0];
    double mini = resultatsFit[0];

    for(unsigned int j=1;j<resultatsFit.size();j+=1)
    {
        if(maxi<resultatsFit[j])
            maxi=resultatsFit[j];
        if(mini>resultatsFit[j])
            mini=resultatsFit[j];
    }

    cout<<"L'écart type des solutions trouvées est : "<<maxi-mini<<endl;


    return 0;
}
