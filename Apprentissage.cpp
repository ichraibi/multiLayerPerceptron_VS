#include "Apprentissage.h"
 
Apprentissage::Apprentissage()
{
    erreur = 2; //Arbitraire
}
 
Apprentissage::~Apprentissage()
{
    //dtor
}
 
void Apprentissage::addEntree(double val)
{
    lesEntrees.push_back(val);
}
void Apprentissage::addSortie(double val)
{
    lesSorties.push_back(val);
}
 
double Apprentissage::getEntree(int i)
{
    return lesEntrees.at(i);
}
double Apprentissage::getSortie(int i)
{
    return lesSorties.at(i);
}
 
void Apprentissage::setErreur(double val)
{
    erreur = val;
}
double Apprentissage::getErreur()
{
    return erreur;
}