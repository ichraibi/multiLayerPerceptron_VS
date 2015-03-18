#include "mlp.h"

#include <vector>
#include <iostream>

using namespace std;

mlp::mlp()
{
	coucheDepart = new Couche();
    coucheInter = new Couche();
    coucheFin = new Couche();
	nbCoucheInter=1;
	vector<Apprentissage*> lesAppr;
}

mlp::~mlp(void)
{

}

void mlp::initPoidsRandom()
{
	cout << "Initialisation aléatoire des poids... ";
 
    for(int i = 0 ; i < coucheDepart->getNbNeurones() ; i++)
    {
        for(int j = 0 ; j < coucheInter->getNbNeurones() ; j ++)
        {
            coucheDepart->getNeurone(i)->addPoids(getRand());
        }
    }
 
    for(int i = 0 ; i < coucheInter->getNbNeurones() ; i++)
    {
        for(int j = 0 ; j < coucheFin->getNbNeurones() ; j ++)
        {
            coucheInter->getNeurone(i)->addPoids(getRand());
        }
    }
 
    cout << "done!" << endl;
}

void mlp::initCouchePerceptron ()
{

	cout << "Creation des neurones ... " << endl;
	
    int nbNeuronesCoucheEntree = 2;
	int nbNeuronesCoucheCachee = 1;
	int nbNeuronesCoucheSortie = 1;
 
	cout << "Nombre de neurones de :  " << endl;
	cout << "-- Couche d'entree      : " << nbNeuronesCoucheEntree << endl;
	cout << "-- Couche Intermediaire : " << nbNeuronesCoucheCachee << endl;
	cout << "-- Couche Sortie        : " << nbNeuronesCoucheSortie << endl;

	int ModifValeurDefaut = 0 ;
	char rep; 
	cout << "Modifier les valeurs par défaut ? (o: oui, autre : non)"<< endl ;
    cin >> rep ;
    cout << endl ;

	if(rep!='o')
		ModifValeurDefaut =0;
	else
		ModifValeurDefaut=1;

	if (ModifValeurDefaut==1)
	{
		cout << "Combien de neurones d'entree ? " ;
		cin >> nbNeuronesCoucheEntree;
		cout << endl;

		cout << "Combien de neurones dans la couche cachee ? " ;
		cin >> nbNeuronesCoucheCachee;
		cout << endl;

		cout << "Combien de neurones de sortie ? ";
		cin >> nbNeuronesCoucheSortie;
		cout << endl;
	}

	for (int i = 0; i <nbNeuronesCoucheEntree; i++)
    {
        Neurone* n = new Neurone(0.0);
        coucheDepart->addNeurone(n);
    }

    for (int i = 0; i < nbNeuronesCoucheCachee; i++)
    {
        Neurone* n = new Neurone(0.0);
        coucheInter->addNeurone(n);
    }
 
    for (int i = 0; i < nbNeuronesCoucheSortie; i++)
    {
        Neurone* n = new Neurone(0.0);
        coucheFin->addNeurone(n);
    }
	
	cout << "done!" << endl;

}

vector<Apprentissage* > mlp::creationBaseApprentissage()
{
	cout << "Création de la base d'apprentissage : " << endl;
 
    bool continuer = true;
 
    while(continuer)
    {
        Apprentissage* a = new Apprentissage();
 
        lesAppr.push_back(a);
        cout << "-- Debut apprentissage " << lesAppr.size() << endl;
 
		for(int i = 0 ; i < coucheDepart->getNbNeurones() ; i++)
        {
            double val;
            cout << "--- Valeur neurone entree " << i << " : ";
            cin >> val;
            cout << endl;
 
            a->addEntree(val);
        }
 
		for(int i = 0 ; i < coucheFin->getNbNeurones() ; i++)
        {
            double val;
            cout << "--- Valeur neurone sortie " << i << " : ";
            cin >> val;
            cout << endl;
 
            a->addSortie(val);
        }
 
        cout << "-- Fin apprentissage " << lesAppr.size() << endl;
 
        char rep;
        cout << "Autre jeu de donnee (o: oui, autre : non)? ";
        cin >> rep;
        cout << endl;
 
        if(rep!='o')
            continuer = false;
    }
 
    cout << "done!" << endl;
	return lesAppr;
}

double mlp::getRand()
{
    return (double)rand()/(RAND_MAX)-0.5;
}


void mlp::cycleApprentissage()
{
	double erreur = 1.0;
    int currentDonnee = 0;
	int nbCycleApprentissage =0;
    cout << "Debut du cycle d'apprentissage" << endl;
 
    while (erreur > 0.095) {
 
        cout << "Installation des données d'apprentissage... "<<endl;
 
        Apprentissage* a = lesAppr.at(currentDonnee);
		
		cout << "des neurones d'entrées..... "<<endl;
        for(int i = 0; i < coucheDepart->getNbNeurones() ; i ++)
        {
            coucheDepart->getNeurone(i)->setValeur(a->getEntree(i));
            coucheDepart->getNeurone(i)->setSigmoide(a->getEntree(i));
			coucheDepart->getNeurone(i)->afficheDonneesNeurone();
        }
		
		cout << "des neurones de sorties..... "<<endl;
        for(int i = 0; i < coucheFin->getNbNeurones() ; i ++)
        {
            coucheFin->getNeurone(i)->setValeur(a->getSortie(i));
			coucheFin->getNeurone(i)->afficheDonneesNeurone();
        }
 
        cout << "done!" << endl;
 
        cout << "Propagation de la couche de départ à la couche intermédiaire ..."<< endl;
 
        for(int i=0;i<coucheInter->getNbNeurones();i++){
 
            double npot =0.0;
 
            for(int j=0;j<coucheDepart->getNbNeurones();j++) {
 
                npot += coucheDepart->getNeurone(j)->getSigmoide() * coucheDepart->getNeurone(j)->getPoids(i);
            }
 
            coucheInter->getNeurone(i)->setPotentiel(npot);
 
            coucheInter->getNeurone(i)->setSigmoide(1/(1+exp((-1)*npot)));
        }
 
        cout << "Propagation de la couche intermédiaire à la couche de sortie ..."<<endl;
 
        for(int i=0;i<coucheFin->getNbNeurones();i++){
 
            double npot =0.0;
 
            for(int j=0;j<coucheInter->getNbNeurones();j++) {
 
                npot += coucheInter->getNeurone(j)->getSigmoide() * coucheInter->getNeurone(j)->getPoids(i);
            }
 
            coucheFin->getNeurone(i)->setPotentiel(npot);
 
            coucheFin->getNeurone(i)->setSigmoide(1/(1+exp((-1)*npot)));
        }
 
        cout << "done!" << endl;
 
        cout << "Calcul de l'erreur ... ";
 
        a->setErreur(coucheFin->calculErreur());
 
        cout << "done!" << endl;
 
        cout << "Signal d'erreur couche sortie ... ";
 
        for(int i=0;i<coucheFin->getNbNeurones();i++){
 
            coucheFin->getNeurone(i)->calculErreur();
        }
 
        cout << "done!" << endl;
 
        cout << "Signal d'erreur couche cachee ... ";
 
        for(int i=0;i< coucheInter->getNbNeurones();i++) {
 
            Neurone* n = coucheInter->getNeurone(i);
 
            double phy = n->getSigmoide() * (1 - n->getSigmoide());
            double del = 0.0;
 
            for(int j=0;j < n->getNbPoids();j++) {
 
                del += coucheFin->getNeurone(j)->getErreur() * n->getPoids(j);
            }
 
            n->setErreur(phy * del);
        }
 
        cout << "done!" << endl;
 
        cout << "Correction poids sortie... ";
 
        for(int i=0;i<coucheInter->getNbNeurones();i++){
 
            for(int j=0;j<coucheInter->getNeurone(i)->getNbPoids();j++) {
 
                coucheInter->getNeurone(i)->setPoids(j,coucheInter->getNeurone(i)->getPoids(j) + coucheInter->getNeurone(i)->getSigmoide() * coucheFin->getNeurone(j)->getErreur());
            }
        }
 
        cout << "done!" << endl;
 
        cout << "Correction poids cachee... ";
 
        for(int i=0;i<coucheDepart->getNbNeurones();i++){
 
            for(int j=0;j<coucheDepart->getNeurone(i)->getNbPoids();j++) {
 
                coucheDepart->getNeurone(i)->setPoids(j,coucheDepart->getNeurone(i)->getPoids(j) + coucheDepart->getNeurone(i)->getSigmoide() * coucheInter->getNeurone(j)->getErreur());
            }
        }
 
        cout << "done!" << endl;
 
        currentDonnee = ( currentDonnee + 1 ) % lesAppr.size();
 
        double totErr = 0;
 
        for(unsigned int i = 0 ; i < lesAppr.size(); i++)
        {
            totErr += lesAppr.at(i)->getErreur();
        }
 
        erreur = totErr / lesAppr.size();
 
        cout << "Moyenne erreur : " << erreur << endl;
		nbCycleApprentissage++;
    }
 
    cout << "Fin de l'apprentissage en " << nbCycleApprentissage <<" cycles "<< endl;
 
    //Affichage de la sortie
    cout << "Valeur de sortie finale : " << endl;
 
    for (int i = 0; i < coucheFin->getNbNeurones(); i++)
    {
        cout << coucheFin->getNeurone(i)->getSigmoide() << endl;
    }
 
    cout << "OK" << endl;
 
}

void mlp::testApprentissage()
{
	  //Demarrage de test
    cout << "*********************************" << endl << endl;
    cout << "Test de l'apprentissage : " << endl;
 
    bool continuer = true;
	
    while(continuer)
    {
        for (int i = 0 ; i < coucheDepart->getNbNeurones() ; i++)
        {
            double val;
            cout << "--- Valeur neurone entree " << i << " : ";
            cin >> val;
            cout << endl;
 
            coucheDepart->getNeurone(i)->setValeur(val);
            coucheDepart->getNeurone(i)->setSigmoide(val);
        }
 
        cout << "Passage dans le reseau de neurone... ";
 
        for(int i=0;i<coucheInter->getNbNeurones();i++){
 
            double npot =0.0;
 
            for(int j=0;j<coucheDepart->getNbNeurones();j++) {
 
                npot += coucheDepart->getNeurone(j)->getSigmoide() * coucheDepart->getNeurone(j)->getPoids(i);
            }
 
            coucheInter->getNeurone(i)->setPotentiel(npot);
 
            coucheInter->getNeurone(i)->setSigmoide(1/(1+exp((-1)*npot)));
        }
 
        for(int i=0;i<coucheFin->getNbNeurones();i++){
 
            double npot =0.0;
 
            for(int j=0;j<coucheInter->getNbNeurones();j++) {
 
                npot += coucheInter->getNeurone(j)->getSigmoide() * coucheInter->getNeurone(j)->getPoids(i);
            }
 
            coucheFin->getNeurone(i)->setPotentiel(npot);
 
            coucheFin->getNeurone(i)->setSigmoide(1/(1+exp((-1)*npot)));
        }
 
        cout << "done!" << endl;
 
        cout << "Affichage des resultats : " << endl;
 
        for (int i = 0; i < coucheFin->getNbNeurones(); i++)
        {
            cout << "Valeur de sortie neurone " << i << " : " << coucheFin->getNeurone(i)->getSigmoide() << endl;
        }
 
        char rep;
        cout << "Autre test (o: oui, autre : non)? ";
        cin >> rep;
        cout << endl;
 
        if(rep!='o')
            continuer = false;
    }
 
}