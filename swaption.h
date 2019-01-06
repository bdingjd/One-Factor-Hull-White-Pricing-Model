#ifndef SWAPTION_H
#define SWAPTION_H
#include "node.h"
#include "norm.h"

class Swaption
{
public:

    Swaption(){};
    void Input(int noSteps,double treeTime,
		int NoTerms,double **SwapInfo,double *Zero,double *Term,
		int NoZeroTerms,int CaliFlag,int Freq,int maxDim,double a,
		double **surface,int noVolRows,int noVolColumns);

//  when CaliFlag = 0, all swaption prices are computed by true strike rates 
//  when CaliFlag = 1, all swaption prices are computed by taking forward rates as 
//  strike rates

//    void Input(int noSteps,double treeTime,
//                int NoTerms,double **SwapInfo,int CaliFlag,int Freq,int maxDim,double a);
    double EuroPrice(double Maturity,Node **Node1,double **Q,
		double *tt,int *CashIndex,int CallFlag,int *NoNodes); 
	double EuroClosedFormPrice(double Maturity,double Vol,int CallFlag);
	void Input(double sig);
    double BermPrice(Node **Node1,double **Q,double *tt,int *CashIndex,int CallFlag,int *NoNodes);
    double BlackPrice(double Maturity,int CallFlag,double &PV01,double &vol);
    double VolSurface(double OptMaturity,double SwapTerm);
    void ReleaseM();
    ~Swaption(){};


private:
    double LinearInt(double time);
    void SwapFunc(double Maturity,Node **Node1,double *S,
	double *tt,int *CashIndex,int CallFlag,int *NoNodes);
	void FuncAB(double t,double T,double aVar, double sigVar,double &AtT,double &BtT);
	void FuncAB1(double t,double T,double aVar,double sigVar,double &AtT,double &BtT); 
	double FuncA0t(double t);
    int Location(double t,double *tt);
    int *exflag,freq;
    double *srate,*strike,*r,*sterm,*term,*zero,r0; 
    double TreeTime,a,sig;
    int N,noTerms,noZeroTerms,MaxDim;
	int noVolRows,noVolColumns;
	double **Surface;
    norm Normal;

};
#endif
