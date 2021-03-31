#ifndef VOYANTS_H
#define VOYANTS_H

/*!
* \class Voyants
* \file voyants.h
* \brief Gere les voyants de la borne
* \author Sewoda Pascal and Achari Kahina
* \version 1.0
*/
#include <donnees_borne.h>
#include <iostream>
#include <lcarte.h>
#include "timer.h"
#include "time.h"
#include "unistd.h"


class Voyants
{
	private:
		entrees *leds;
		int shmid; /*Share memory id */
	public:
		Voyants();
		
		/**
		* \fn void initialier();
		* \brief Permet de configurer l'acces a la memoire partagee a l'aide  la variable shmid (share memory id) pour permettre de communiquer avec la carte. Un message d'erreur s'affiche en cas de probleme d'acces.
		* \param void
		* \return void
		*/
    	void initialier();
    	
  		/**
		* \fn void set_charge(int ledCoul);
		* \brief Allume le voyant charge quand le vehicule charge
		* \param int ledCoul: qui represente la couleur a afficher
		* \return void
		*/
    	void set_charge(led ledCoul);
    	void set_dispo(led ledCoul);
    	void blink_charge();

    	void set_defaut();
    	void etat_dispo();
    	//methode ajouter
    	
    	/**
    	* \brief Les fonctions suivantes ont ete ajoutee
    	pour plus de commoditer d'ecriture du programme de gestion
    	*/
		void initialiser();
		void blink_defaut();
    	
    	

};

#endif
