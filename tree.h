#ifndef TREE_H
#define TREE_H
#include "node.h"
class Tree
{
public:
    Tree(){};
    void input(int noSteps,double mu,double *sigma,double *sigmaTerm,int noSigma,double Time,
				int noZeroTerms,double *Term,double *Zero);
    void Generator(Node **Node1,double **Q,double *CashTerms,
	int NoCashTerms,int *CashIndex,double *tt,int *NoNodes);
    int MaxNoStates(double *CashTerms,int NoCashTerms,int *CashIndex,double *tt,int *NoNodes);
//  tt[i]: the time length from time step 0 to time step i

private:
    double LinearInt(double time);
    double VolFunc(double time);
    double *r,a,*sig,*sigTerm,TreeTime,*term,*zero;
    int N,M,noZeroTerms,noSig; 
};
#endif
