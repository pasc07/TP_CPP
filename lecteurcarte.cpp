
#include "lecteurcarte.h"
#include <iostream>

using namespace std;

void LecteurCarte::initialiser()
{
}

void LecteurCarte::lire_carte()
{
	int reussi=1;
	baseclient.lire();
	initialisations_ports();
	attente_insertion_carte();
	numero_courant=lecture_numero_carte();
	if(voyants.dispo()==1){
		
		reussi=baseclient.authentifier(numero_courant);
		cout<<"Numero de carte: "<<numero_courant<<endl;
	
	
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
				reprise();
				generateurSave.deconnecter();
			}
		}
	}
	usleep(1000000);
	attente_retrait_carte();
	liberation_ports();
}


void LecteurCarte::reprise(){
	cout<<"REPRISE "<<endl;
	int reussi, numero;
	while(1){
		initialisations_ports();
		attente_insertion_carte();
		//if (carte_inseree() ) 
		
		numero=lecture_numero_carte();
		//cout<<"Numero lu: "<<numero<<endl;
	
		reussi=baseclient.authentifier(numero);
		
		if((reussi==0)||(numero!=numero_courant))
		{
			voyants.blink_defaut();
		}
		else
		{
			cout<<"Authentification reussi!"<<endl;
			prise.deverouiller_trappe();
			break;
		}
	}
}

