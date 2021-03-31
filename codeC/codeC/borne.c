#include <stdio.h>
#include <memoire_borne.h>
#include <donnees_borne.h>
#include <baseclient.h>
#include <boutons.h>
#include <voyants.h>
#include <timer.h>
#include <generateur_save.h>
#include <gestionclient.h>

#include "lecteurcarte.h"


/* Appelee pour ajouter des clients*/
void ajout(){
	printf("AJOUTER CLIENTS\n");
	gestionclient_ajouter();
}


int main()
{
	initialiser();
    //lecteurcarte_initialiser();
   
    timer_init();
    voyants_initialiser();
    boutons_initialiser();
	timer_raz();
	
	// Appeler la focntion d'ajout de client si necessaire
	//ajout();
	
	printf("\n DEBUT PROCESSUS [0 pour le test]\n");
    while (1)
    {
    	
        lecteurcarte_lire_carte();

    }

}
