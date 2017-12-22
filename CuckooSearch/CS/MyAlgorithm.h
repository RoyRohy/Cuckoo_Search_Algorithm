#ifndef MYALGORITHM_H
#define MYALGORITHM_H

#include <stdlib.h>
#include <time.h>

#include "Problem.h"
#include "SetUpParams.h"
#include "Solution.h"
#include "Levy.h"



  class MyAlgorithm
  {
	private:
		std::vector<Solution> _solutions;     // individuals in population
		std::vector<double> _fitness_values;
		/*const*/ SetUpParams& _setup;
		unsigned int _upper_cost,_lower_cost; // lower and upper fitness of individuals in population
		/*const*/ Problem& _pbm;
		/*int iter;
		int nb_appel_fitness;*/

	public:
		MyAlgorithm(/*const*/ Problem& pbm,/*const*/ SetUpParams& setup);
		~MyAlgorithm();

		/*friend ostream& operator<< (ostream& os, const MyAlgorithm& myAlgo);
		friend istream& operator>> (istream& is, MyAlgorithm& myAlgo);
		MyAlgorithm& operator= (const MyAlgorithm& myAlgo);*/
		SetUpParams& setup() const; // getteur
	  	void initialize();

		// creates an array with fitness of all solutions in MyAlgorithm and its position in the MyAlgorithm
        void evaluate();

	 	/*const*/ std::vector<Solution>& solutions() /*const*/; // getteur
		unsigned int upper_cost() const; // getteur
		unsigned int lower_cost() const; // getteur
		Solution& solution(const unsigned int index) /*const*/; // retourne la solution à l'index index
        //vector<struct particle>&  fitness_values();
		double fitness(const unsigned int index) /*const*/; // retourne la fitness de la solution à l'index index


		double best_cost() /*const*/; // getteur meilleure des meilleures fitness
		double worst_cost() /*const*/; // getteur pire des pires fitness
		Solution& best_solution() /*const*/; // getteur de la Solution de la meilleure des meilleures fitness
		Solution& worst_solution() /*const*/;// getteur de la pire solution obtenue durant tout le programme

		void evolution(unsigned int& iter, unsigned int& nbAppelFitness); /*makes an evolution step*/

  };

#endif // MYALGORITHM_H
