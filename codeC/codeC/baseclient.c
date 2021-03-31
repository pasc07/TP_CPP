#include <baseclient.h>
#include <string.h>
#include "lecteurcarte.h"
#include <stdio.h>
#include <voyants.h>
#include <unistd.h>
#include <prise.h>

int recherche(int num){
	int i=0;
	while(base_client[i].num_carte!=num){
		i++;
		if(i==20)
			break;
	}
	if(i<20)
	return 1;
	else
	return 0;
}

int baseclient_authentifier(int num_carte){
	if(recherche(num_carte)==1)
			return 1;
		else
			return 0;
	}
void reprise(){
	printf("REPRISE \n");
	int reussi, numero;
	while(1){
	initialisations_ports();
	attente_insertion_carte();
	//if (carte_inseree() ) //Pour eviter la repetion du message
	
	numero=lecture_numero_carte();
	printf("Numero lu: %d \n",numero);

	reussi=baseclient_authentifier(numero);

	if(reussi==0)
	{
		voyants_blink_defaut();
	}
	else
	{
		printf("Authentification reussi!\n");
		prise_deverouiller_trappe();
	}
	if(reussi==1)
		break;
	}
}
