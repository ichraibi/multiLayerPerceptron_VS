#pragma once
#include <vector>
using namespace std;
 
class Apprentissage
{
    public:
        Apprentissage();
        virtual ~Apprentissage();
 
        void addEntree(double val);
        void addSortie(double val);
        double getEntree(int i);
        double getSortie(int i);
        void setErreur(double val);
        double getErreur();

    protected:

    private:
        vector<double> lesEntrees;
        vector<double> lesSorties;
 
        double erreur;
};
