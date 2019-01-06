#ifndef NODE_H
#define NODE_H
class Node
{
public:
    Node(){};
    void input(double pu,double pm,double pd,double rate,int iu,int im,int id); 
    void inputRate(double rate);
    double Pu,Pm,Pd,r;
    int Iu,Im,Id;
private:

};
#endif



