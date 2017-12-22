#ifndef PROBLEM_H
#define PROBLEM_H


  class Problem
  {
	public:
		Problem(int dimension, int numFunction);
		~Problem();

		/*friend ostream& operator<< (ostream& os, const Problem& pbm);
		friend istream& operator>> (istream& is, Problem& pbm);*/

		/*Problem& operator=  (const Problem& pbm);
		bool operator== (const Problem& pbm) const;
		bool operator!= (const Problem& pbm) const;*/


		int dimension() const;
		double LowerLimit, UpperLimit;
		int getNumFunction() const;

	private:

		int _dimension;
		int _num_func;
  };

#endif // PROBLEM_H
