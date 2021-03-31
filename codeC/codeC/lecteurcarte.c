#include <stdio.h>
#include <unistd.h>
#include "lecteurcarte.h"
#include <baseclient.h>
#include <boutons.h>
#include <voyants.h>
#include <timer.h>
#include <generateur_save.h>

//attribut privee
int numero;
int reussi;

void lecteurcarte_initialiser()
{
}

void lecteurcarte_lire_carte()
{
	initialisations_ports();
	attente_insertion_carte();
	//if (carte_inseree() ) //Pour eviter la repetion du message
		numero=lecture_numero_carte();
	printf("Numero lu: %d \n",numero);
	if(voyants_dispo()){
		reussi=baseclient_authentifier(numero);
	}
	
	timer_raz();
	if(reussi==0)
	{
		voyants_blink_defaut();
	}
	else
	{
		printf("Authentification reussi!\n");
		voyants_blink_charge();
		int status_bouton=boutons_charge();
		if(status_bouton==1){
			generateur_save_charger();
		}
	}
	

	usleep(2000000);
	attente_retrait_carte();
	liberation_ports();
	
}

