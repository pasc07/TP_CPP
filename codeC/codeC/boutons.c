#include <stdio.h>
#include <boutons.h> 

int shmid;
entrees* bouton;
void boutons_initialiser()
{
	bouton=acces_memoire(&shmid);
	// associer..
	if(bouton==NULL) 
	{printf("Erreur pas de mem sh \n");}
}

int boutons_charge()
{
	int status;
	status=bouton->bouton_charge;
	bouton->bouton_charge=0;
	return status;
	
}
int boutons_stop()
{
	int status;
	status=bouton->bouton_stop;
	bouton->bouton_stop=0;
	return status;
}
