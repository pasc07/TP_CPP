
#include "lecteurcarte.h"
#include <iostream>

using namespace std;

void LecteurCarte::initialiser()
{
}

void LecteurCarte::lire_carte()
{
	int reussi=1;
	BaseClient baseclient;
	Voyants voyants;
	GenerateurSave generateurSave;
	int numero, etat;
	
	initialisations_ports();
	attente_insertion_carte();
	numero=lecture_numero_carte();
	etat=voyants.dispo();
	//cout<<"Etat= "<<etat<<endl;
	if(etat==1){
		
		reussi=baseclient.authentifier(numero);
		cout<<"Hello carte inserer et numero recuperer "<<numero<<endl;
	
	
		if(reussi==0)
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
	}
	usleep(1000000);
	attente_retrait_carte();
	liberation_ports();
}

