#pragma once
#include <vector>

using namespace std;

class Neurone
{
public:
	Neurone(double);
    virtual ~Neurone();
    double getPotentiel() { return potentiel; }
    void setPotentiel(double val) { potentiel = val; }
    double getSigmoide() { return sigmoide; }
    void setSigmoide(double val) { sigmoide = val; }
    double getErreur() { return erreur; }
    void setErreur(double val) { erreur = val; }
    double getValeur() { return valeur; }
    void setValeur(double val) { valeur = val; }
    int getNbPoids() {return lstPoids.size(); }
    double getPoids(int);
    void setPoids(int, double);
    void addPoids(double);
    double calculEcart();
    double calculErreur();
	void afficheDonneesNeurone();

protected:

private:
    double potentiel;
    double sigmoide;
    double erreur;
    double valeur;
    vector<double> lstPoids;
};

