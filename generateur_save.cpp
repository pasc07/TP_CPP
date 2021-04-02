#include "generateur_save.h"

GenerateurSave::GenerateurSave(){
}

void GenerateurSave::initialiser(){
	io=acces_memoire(&shmid);
	// associer..
	if(io==NULL) 
	{
		cout<<"Erreur pas de mem sh \n"<<endl;
	}
}

void GenerateurSave::genererPWM(pwm tension)
{
	initialiser();
	io->gene_pwm=tension;
}

int GenerateurSave::tension(){
	initialiser();
	return io-> gene_u;
}

/*!
* \fn
* \brief
* \param
* \return
*/
void GenerateurSave::ouvert(){
	initialiser();
	io->contacteur_AC=0;
}

/*!
* \fn
* \brief
* \param
* \return
*/
void GenerateurSave::fermer(){
	initialiser();
	io->contacteur_AC=1;
}

/*!
* \fn
* \brief
* \param
* \return
*/
void GenerateurSave::charger(){
	Etat etat =Etat1;
	initialiser();
	MEF(etat);
}


void GenerateurSave::MEF(Etat init)
{

	
	/*! \brief Implementation de la machine a etat fini correspondant au cycle charge*/

	Etat EP=init, ES=init;
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
		//prise.set_prise(OFF);
	
}


/*!
* \fn
* \brief
* \param
* \return
*/
void GenerateurSave::deconnecter(){
	int u;
	usleep(50000);
	/* Attente de reprise du vehicule*/
	BaseClient baseClient;
	baseClient.reprise();
	prise.deverouiller_trappe();
	genererPWM(DC);
	/* Pour gerer l'extinction du voyant prise a la deconnexion de la prise*/
	u=tension();
	
	while(u!=12){
		u=tension();
		usleep(500000);
	} 

	if(u==12){
		prise.set_prise(OFF);
		}
	usleep(50000);
	voyants.set_dispo(VERT);
	voyants.set_charge(OFF);
	genererPWM(STOP);
	usleep(50000);
	prise.verouiller_trappe();
	
}
