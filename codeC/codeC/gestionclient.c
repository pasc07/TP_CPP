#include <gestionclient.h>
#include <baseclient.h>
#include <string.h>
#include <stdio.h>
#include "lecteurcarte.h"
#include <unistd.h>

int i=0, num;

void initialiser(){
	for(i=0;i<20;i++){
		base_client[i].num_carte=0;
		strcpy(base_client[i].nom," ");
	}
} 


void gestionclient_ajouter(){
	printf("INSERER NOUVELLE CARTE\n");
	initialisations_ports();
	attente_insertion_carte();
	char nom_client[20];
	printf("ENTREE LE NOM DU CLIENT\n");
	//fgets(nom_client,20,stdin);
	if(scanf("%19s",nom_client)!=1){
	}
	
	/* Ajout a la base de donne*/
 		i=1;
 		while(base_client[i].num_carte!=0){
 			i++;
 			if(i==20)
				break;
 		}
 		if(i<20){
			strcpy(base_client[i].nom,nom_client);
			num=lecture_numero_carte();
			printf("numero lu: %d \n",num);
			base_client[i].num_carte=num;
			printf("REUSSI! CLIENT AJOUTE: NUM_CARTE:%d\n",num);
		}
		else
			printf("Vous ne pouvez pas enregistrer de client\n");
	
}


void gestionclient_supprimer(){

}
