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
#include <memoire_borne.h>
#include <stdio.h>
#include <timer.h>
#include <time.h>
#include <unistd.h>

class Voyants
{
	private:
		entrees *leds;
	public:
		Voyants();
		
		/*
		* \fn void initialier();
		* \brief Permet de configurer l'acces a la memoire partagee
		* \param void
		* \return void
		*/
    	void initialier();
    	
  		/*
		* \fn void set_charge(int ledCoul);
		* \brief Allume le voyant charge quand le vehicule charge
		* \param int ledCoul: qui represente la couleur a afficher
		* \return void
		*/
    	void set_charge(int ledCoul);
    	void blink_charge(int ledCoul);
    	void set_dispo(int ledCout);
    	void set_defaut(int ledCout);
    	void blink_defaut(int ledCout);
    	void etat_dispo();
    	//methode ajouter
    	
    	/*
    	* \brief Les fonctions suivantes ont ete ajoutee
    	pour plus de commoditer d'ecriture du programme de gestion
    	*/
		void voyants_initialiser();
		void voyants_blink_defaut();
    	
    	

};

#endif
