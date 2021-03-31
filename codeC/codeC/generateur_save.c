#include <stdio.h>
#include <generateur_save.h>
#include <voyants.h>
#include <time.h>
#include <unistd.h>
#include <prise.h>
#include <boutons.h> 
#include <baseclient.h>

entrees *io;

void generateur_save_generer_PWM(pwm tension)
{
	io->gene_pwm=tension;
}
int generateur_save_tension()
{
	return io-> gene_u;
}


void generateur_save_charger()
{
/* Programmation de la machine a etat fini correspondant au cycle charge*/

	 /*declarations et initialisations */
typedef enum {Etat1, Etat2, Etat3,Etat4,Etat5} etat;
etat EP=Etat1, ES=Etat1;
/* Entrees: u pour recuperer la tension du fil pilote
et stop pour recuprer l'appui sur le bouton stop*/
int u,stop; 

	voyants_set_dispo(OFF);
	voyants_set_charge(ROUGE);
	prise_deverouiller_trappe();
	generateur_save_generer_PWM(DC);
while (1) /* boucle infinie */
{
	/* lecture des entrees */
	u=generateur_save_tension();
	stop=boutons_stop();
	/* Evolution du graphe */
	switch (EP )
	{
		case Etat1 : if (u==9) ES=Etat2;
		break;
		case Etat2 : if (u==6) ES = Etat3;
					else if(stop==1) ES=Etat5;
		break;
		case Etat3 : if(u==6) ES=Etat4;
					else if((u==9) || (stop==1)) ES=Etat5;
		break;
		/* Etat4: Etat de charge */
		case Etat4 : if(u==9) ES=Etat5;
					if(stop==1) ES=Etat5;
		break;
		default : ES = Etat1;
	} /* fin switch */
	/* bloc M*/
	EP=ES;
	printf("%d \n",EP);
	/* bloc G  et 	ecriture des sortie*/
	if(EP==Etat1){
		//voyants_set_dispo(OFF);
		//voyants_set_charge(ROUGE);
		printf("%d \n",EP);
		prise_deverouiller_trappe();
		generateur_save_generer_PWM(DC);
	
	}
	if(EP==Etat2){
		prise_set_prise(VERT);
		prise_verouiller_trappe();
		generateur_save_generer_PWM(AC_1K);
	
	}
	
	if(EP==Etat3){
		generateur_save_fermer();
		generateur_save_generer_PWM(AC_CL);
		prise_verouiller_trappe();
		usleep(30000);
	}
	if(EP==Etat4){
		generateur_save_generer_PWM(AC_CL);

	}
	if(EP==Etat5){
		generateur_save_ouvert();
		voyants_set_charge(VERT);
		generateur_save_generer_PWM(DC);
		generateur_save_deconnecter();
		break; //Sortie de boucle de charge a la fin de Etat5
	}
	/* Temps d'attente pour que la tension du fil pilote change*/
	usleep(1500000);
	
	} /* fin du while */
	prise_set_prise(OFF);
}


/* Ouverture de la trappe*/
void generateur_save_ouvert()
{
	io->contacteur_AC=0;
}

/*Fermeture de la trappe*/
void generateur_save_fermer()
{
	io->contacteur_AC=1;
}

/* Deconnexion et remise a l'etat initiale*/
void generateur_save_deconnecter()
{
	int u;
	usleep(50000);
	/* Attente de reprise du vehicule*/
	//prise_deverouiller_trappe();
	reprise();
	generateur_save_generer_PWM(DC);
	
	/* Pour gerer l'extinction du voyant prise a la deconnexion de la prise*/
	u=generateur_save_tension();
	while(u!=12){
		u=generateur_save_tension();
		usleep(500000);
	}
	usleep(50000);
	if(u==12)
		prise_set_prise(OFF);
/*fin*/

	voyants_set_dispo(VERT);
	voyants_set_charge(OFF);
	generateur_save_generer_PWM(STOP);
	prise_verouiller_trappe();
	
}
