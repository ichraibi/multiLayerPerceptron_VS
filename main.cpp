#include <iostream>
#include <stdlib.h>
 
#include "Couche.h"
#include "Neurone.h"
#include "Apprentissage.h"
#include "mlp.h"

#include <math.h>
 
using namespace std;
 
double getRand();
 
int main()
{
    cout << "Creation des couches ... ";
 
	mlp perceptron;
 
    cout << "done!" << endl;
 
	perceptron.initCouchePerceptron();

    perceptron.creationBaseApprentissage();
	 
	perceptron.initPoidsRandom();

	perceptron.cycleApprentissage();

	perceptron.testApprentissage();
    
	return 0;
}
 
