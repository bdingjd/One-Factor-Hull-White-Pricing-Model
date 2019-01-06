#ifndef ZEROCURVE_H
#define ZEROCURVE_H 
 
class ZeroCurve
{
public:
	// default constructor
	ZeroCurve(){};
	void input(double *Term,double *Rate,int NoZeroTerms);
	// get rate for given term
	double getRate(double time); 
	void releaseM();
	

	~ZeroCurve(){};

private: 
	int size;
	double *term,*rate;
};
#endif