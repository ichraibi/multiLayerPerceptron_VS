#pragma once
#include "Neurone.h"
#include <vector>
 
using namespace std;
 
class Couche
{
    public:
        Couche();
        virtual ~Couche();
 
        void addNeurone(Neurone* n);
        Neurone* getNeurone(int i) {return lstNeurones.at(i);}
        int getNbNeurones() {return lstNeurones.size();}
 
        double calculErreur();
    protected:
    private:
        vector<Neurone*> lstNeurones;
};
