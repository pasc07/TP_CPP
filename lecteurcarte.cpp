
#include "lecteurcarte.h"
#include <iostream>

using namespace std;

void LecteurCarte::initialiser()
{
}

void LecteurCarte::lire_carte()
{
	initialisations_ports();
	attente_insertion_carte();
	numero=lecture_numero_carte();
	if(numero){
	cout<<" Hello je bosse bien "<<numero<<endl;
	}
}

