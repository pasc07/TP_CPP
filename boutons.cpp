#include <iostream>
#include "boutons.h"

using namespace std;

Boutons::Boutons(){}

void Boutons::initialiser(){
	bouton=acces_memoire(&shmid);
	// associer..
	if(bouton==NULL) 
	{
		cout<<"Erreur pas de mem sh \n"<<endl;
	}
}

	int Boutons::charge(){
		initialiser();
		int status;
		status=bouton->bouton_charge;
		bouton->bouton_charge=0;
		return status;
	}
	int Boutons::stop()
	{
		int status;
		initialiser();
		status=bouton->bouton_stop;
		bouton->bouton_stop=0;
		return status;
	}


