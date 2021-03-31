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
#include <donnees_bornes.h>
#include <

class Timer
{
	private:
	
	public:
	/**
  	* \fn void Timer () : represente le constructeur de la classe Timer
  	* \brief Permet d'initialiser la timer
  	* \param void 
  	* \return void
  	*/
		Timer();
		/**
  	* \fn void raz() 
  	* \brief Permet d'initialiser le compteur de temps
  	Communique a travers un pointeur
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
    	void valeur();
    	/**
  	* \fn void pause( int s);
  	* \brief Permet de faire une pause de s temps dans l'execution
  	des taches par le systemes
  	* \param int s 
  	* \return void
  	*/
    	void pause( int s);
	
};

#endif //TIMER_H
