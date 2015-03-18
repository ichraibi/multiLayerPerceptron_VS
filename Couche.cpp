#include "Couche.h"
#include <vector>
 
#include <math.h>
 
Couche::Couche()
{
    //ctor
}
 
Couche::~Couche()
{
    //dtor
}
 
void Couche::addNeurone(Neurone* n){
 
    lstNeurones.push_back(n);
}
 
double Couche::calculErreur() {
 
    double err = 0;
 
    for(int i=0;i<lstNeurones.size();i++) {
 
        err += pow(lstNeurones.at(i)->getValeur() - lstNeurones.at(i)->getSigmoide(), 2);
    }
 
    return 0.5*err;
}