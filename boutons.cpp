#include <iostream>
#include "boutons.h"

using namespace std;

void Boutons::initialiser(){
	bouton=acces_memoire(&shmid);
	// associer..
	if(bouton==NULL) 
	{
		cout<<"Erreur pas de mem sh \n"<<endl;
	}
}

	int Boutons::boutons_charge(){
		int status;
		status=bouton->bouton_charge;
		bouton->bouton_charge=0;
		return status;
	}
	int Boutons::boutons_stop()
	{
		int status;
		status=bouton->bouton_stop;
		bouton->bouton_stop=0;
		return status;
	}


