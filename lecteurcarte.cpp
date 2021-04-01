
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
	cout<<"Hello carte inserer et numero recuperer "<<numero<<endl;
	}
		if(false)
	{
		voyants.blink_defaut();
	}
	else
	{
		cout<<"Authentification reussi!"<<endl;
		voyants.blink_charge();
		int status_bouton=boutons.charge();
		if(status_bouton==1){
			generateurSave.charger();
		}
	}
	usleep(2000000);
	attente_retrait_carte();
	liberation_ports();
}

