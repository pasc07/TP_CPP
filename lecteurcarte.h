#ifndef LECTEURCARTE_H
#define LECTEURCARTE_H

#include <lcarte.h>
#include <iostream>

#include "voyants.h"
#include "timer.h"
#include "baseclient.h"
#include "boutons.h"
#include "generateur_save.h"

using namespace std;
class LecteurCarte
{
private:
	
	int numero_courant;
	Boutons boutons;
	Prise prise;
	BaseClient baseclient;
	Voyants voyants;
	GenerateurSave generateurSave;
  public : 
	void initialiser();
	/*!
	* \fn void lire_carte()
	* \brief Lecteur de carte
	*
	* Cette fonction represente le point d'entree de rechargement d'un vehicule. Elle fait appel a d'autre fonction pour :
authentifier()
charger()
reprise()
deconnecter()
	*
	*/
	void lire_carte();
	
	/*!
	* \fn void reprise()
	* \brief Permet deverrouiller la trappe pour que l'utilisateur
	* reprenne son vehicule.
	* Pour etre sur que c'est l'utilisateur que le vehicule appartient
	* a ce dernier, on verifie egalement que la carte inserer
	* correspond a la derniere carte inserer.
	*/
	void reprise();
};

#endif // LECTEURCARTE_H
