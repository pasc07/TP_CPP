#ifndef TIMER_H
#define TIMER_H

/*!
* \class Timer
* \file timer.h
* \brief Cette classe permet de creer des methodes pour la gestion
* du temps dans le systeme de recharge de vehicule
* \author Sewoda et Achari
* \version 1.0
*/

#include <iostream>
#include <donnees_borne.h>
#include <memoire_borne.h>
#include <lcarte.h>


class Timer
{
	private:
		entrees *io;
		int shmid;
		int depart_timer;
		int fin_timer;
	
	public:
	/**
  	* \fn void Timer () 
  	* \brief represente le constructeur de la classe Timer.
  	* 
  	* Permet d'initialiser le timer.
  	* \param void 
  	* \return void
  	*/
		Timer();
		
		 		/**
 		* \fn void initialiser();
 		* \brief Permet d'initialiser les acces memoires
 		*
 		* Autorise l'acces a la memoire partagee. Appeler a chaque 
 		* interaction avec la borne. Sinon affiche erreur d'acces
 		* \param void
 		* \return void
 		*/ 	
		void initialiser();
		
	/**
  	* \fn void raz() 
  	* \brief Permet d'initialiser le compteur de temps.
  	*
  	* Communique a travers un pointeur
  	* \param void 
  	* \return void
  	*/
    	void raz();
    	/**
  	* \fn void valeur() 
  	* \brief Renvoi la valeur actuel du compteur temps systeme
  	* \param void 
  	* \return void
  	*/
    	int valeur();
    	/**
  	* \fn void pause( int s);
  	* \brief Permet de faire une pause de s secondes dans l'execution
  	des taches par le systemes
  	* \param int s 
  	* \return void
  	*/
    	void pause( int s);
	
};

#endif //TIMER_H
