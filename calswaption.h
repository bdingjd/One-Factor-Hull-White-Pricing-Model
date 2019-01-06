#ifndef CALSWAPTION_H
#define CALSWAPTION_H
#include "node.h"
#include "swaption.h"
#include "tree.h"

class CalSwaption
{
public: 

    ~CalSwaption(){};
    void input(int callFlag,int noSteps,int freq,int noTerms,double **swapInfo,
				int noZeroTerms,double *Term,double *Zero,int noVolRows,int noVolColumns,
				double **surface);
    void ReleaseM();
    CalSwaption(){};
	void Calibration(double aVar,double *sigVar,double *sigTerm,int &noSig);
    double BermPrice(double a,double *sig,double *sigTerm,int noSig,int callFlag); 
    void getEuropeanRTP(double *blackPriceRTP,double *treePriceRTP); 
    void getEuropeanRTR(double *blackPriceRTR,double *treePriceRTR); 

private:

    Tree TREE;
    Swaption SWPT;
    int noTerms,M,N,noCashTerms,*CashIndex,CallFlag,*NoNodes,freq,MaxNoStates,noZeroTerms;
    double TreeTime,**SwapInfo,*CashTerms,*tt,*term,*zero;
    double h;
    double *BlackPriceRTP,*TreePriceRTP,*BlackPriceRTR,*TreePriceRTR;
	int noVolRows,noVolColumns;
	double **Surface;
	int NoSig;
	double *SigTerm,*SigVar;
};
#endif
