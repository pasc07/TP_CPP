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
#include "boutons.h"
#include "unistd.h"


class Voyants
{
	private:
		entrees *leds;
		int shmid; /*Share memory id */
		int status_bouton;
		Boutons boutons;
		
	public:
		Voyants();
		
		/**
		* \fn void initialiser();
		* \brief Permet de configurer l'acces a la memoire partagee a l'aide  la variable shmid (share memory id) pour permettre de communiquer avec la carte. Un message d'erreur s'affiche en cas de probleme d'acces.
		* \param void
		* \return void
		*/
    	void initialiser();
    	
  		/**
		* \fn void set_charge(int ledCoul)
		* \brief Allume le voyant charge quand le vehicule charge
		* \param int ledCoul: qui represente la couleur a afficher
		* \return void
		*/
    	void set_charge(led ledCoul);
    	
    	/**
		* \fn void set_dispo(int ledCoul)
		* \brief Allume le voyant disponible a la fin de la charge
		* \param int ledCoul: qui represente la couleur a afficher
		* \return void
		*/
    	void set_dispo(led ledCoul);
    	
    	/**
		* \fn void blink_charge()
		* \brief Clignoter la led charge pendant 8 seconde
		* \param int ledCoul: qui represente la couleur a afficher
		* \return void
		*/
    	void blink_charge();
		
		/**
		* \fn void set_defaut()
		* \brief Allume la LED defaut de la borne
		* \param int ledCoul: qui represente la couleur a afficher
		* \return void
		*/
    	void set_defaut();
    	int dispo();
  	
    	/**
    	* \fn void blink_defaut();
    	* \brief clignoter la LED defaut pendant 8 secondes
    	*/
		void blink_defaut();
		
		int getStatus_bouton();
    	
    	

};

#endif
