#include "generateur_save.h"

void GenerateurSave::genererPWM(pwm tension)
{
	io->gene_pwm=tension;
}

int GenerateurSave::tension(){
	return io-> gene_u;
}

void GenerateurSave::MEF(etat init)
{

	
	/*! brief Implementation de la machine a etat fini correspondant au cycle charge*/

	etat EP=init, ES=init;
	/* Entrees: u pour recuperer la tension du fil pilote
	et stop pour recuprer l'appui sur le bouton stop*/
	int u,stop; 
	
	
	voyants.set_dispo(OFF);
	voyants.set_charge(ROUGE);
	prise.deverouiller_trappe();
	genererPWM(DC);
	
	while (1) /* boucle infinie */
	{
		/* lecture des entrees */
		u=tension();
		stop=boutons.stop();
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
		cout<<EP<<endl; //affichage de test
		
		/* bloc G  et 	ecriture des sortie*/
		if(EP==Etat1){
			//voyants_set_dispo(OFF);
			//voyants_set_charge(ROUGE);
			cout<<EP<<endl;
			prise.deverouiller_trappe();
			genererPWM(DC);
		
		}
		if(EP==Etat2){
			prise.set_prise(VERT);
			prise.verouiller_trappe();
			genererPWM(AC_1K);
		
		}
		
		if(EP==Etat3){
			fermer();
			genererPWM(AC_CL);
			prise.verouiller_trappe();
			usleep(30000);
		}
		if(EP==Etat4){
			genererPWM(AC_CL);
	
		}
		if(EP==Etat5){
			ouvert();
			voyants.set_charge(VERT);
			genererPWM(DC);
			deconnecter();
			break; //Sortie de boucle de charge a la fin de Etat5
		}
		/* Temps d'attente pour que la tension du fil pilote change*/
		usleep(1500000);
		
		} /* fin du while */
		prise.set_prise(OFF);
	
}
void GenerateurSave::charger(){

}
void GenerateurSave::ouvert(){

}
void GenerateurSave::fermer(){

}
void GenerateurSave::deconnecter(){

}
