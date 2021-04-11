#ifndef LECTEURCARTE_H
#define LECTEURCARTE_H

/*!
* \author SEWODA & ACHARI
* \date 01 April 2021
* \version 1.3
* \class LecteurCarte
* \file lecteurcarte.h
* \brief Cette classe permet d'interagir avec la borne avec la carte client la borne de recharge.
*/

#include <lcarte.h>
#include <iostream>

#include "voyants.h"
#include "timer.h"
#include "boutons.h"
#include "baseclient.h"
#include "generateur_save.h"

using namespace std;
class LecteurCarte
{
private:
	
	int numero_courant;
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
	*
	* authentifier()
	* charger()
	* reprise()
	* deconnecter()
	*
	*/
	void lire_carte();
	
	/*!
	* \fn void reprise()
	* \brief Permet deverrouiller la trappe pour que l'utilisateur
	* reprenne son vehicule.
	* Pour etre sur que le vehicule appartient
	* a ce dernier, on verifie egalement que la carte inserer
	* correspond a la derniere carte inserer.
	*/
	void reprise();
};

#endif // LECTEURCARTE_H
