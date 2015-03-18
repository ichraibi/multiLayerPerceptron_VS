#pragma once
#include "Couche.h"
#include "Apprentissage.h"

class mlp
{
	public:
		mlp();
		~mlp(void);
	
		Couche* getCoucheDepart() { return coucheDepart; }
		Couche* getCoucheInter() { return coucheInter; }
		Couche* getCoucheFin() { return coucheFin; }
		
		int getNbCoucheInter(){return nbCoucheInter;}
		void setNbCoucheInter(int nbCoucheCache){ nbCoucheInter= nbCoucheCache;}

		vector<Apprentissage*> getlesAppr(){return lesAppr;}

		void initPoidsRandom();
		void initCouchePerceptron ();
		vector<Apprentissage* > creationBaseApprentissage();
		double getRand(); 

		void cycleApprentissage();
		void testApprentissage();

	private:
		Couche* coucheDepart ;
		Couche* coucheInter ;
		Couche* coucheFin ;
		int nbCoucheInter;
		vector<Apprentissage*> lesAppr;
};

