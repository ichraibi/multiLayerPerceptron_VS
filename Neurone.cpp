#include "Neurone.h"

using namespace std;
#include <iostream>

Neurone::Neurone(double val)
{
    valeur = val;
    potentiel = 0;
    sigmoide = val;
    erreur = 0;
}
 
Neurone::~Neurone()
{
    //dtor

}
 
void Neurone::addPoids(double d){
 
    lstPoids.push_back(d);
}
 
 double Neurone::getPoids(int i) {
 
    return lstPoids.at(i);
 }
 
double Neurone::calculEcart(){
 
    return valeur - sigmoide;
}
 
double Neurone::calculErreur(){
 
    double phy = sigmoide * (1 - sigmoide);
    erreur = phy * calculEcart();
 
    return erreur;
}
 
void Neurone::setPoids(int i, double p){
 
    lstPoids[i] = p;
}


void Neurone::afficheDonneesNeurone()
{
	cout << "potentiel " <<potentiel <<" | ";
	cout << "sigmoide " <<sigmoide <<" | ";
	cout << "erreur " <<erreur <<" | ";
	cout << "valeur " <<valeur <<endl;
	cout << "LstPoids : " ;
	for (int i=0; i< lstPoids.size(); i++)
	{
		cout << "i _ " <<i ;
		cout << " lstPoids[i] _ " <<lstPoids[i] ;
	}
	cout <<""<<endl ;
    
}
