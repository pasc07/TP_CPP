#ifndef BOUTONS_H
#define BOUTONS_H

#include <donnees_borne.h>
#include <memoire_borne.h>
 /**
 * \class bouton 
 * \file boutons.h boutons.cpp
 * \brief Cette classe permet de gerer les appuis sur les 
 boutons a travers l'utilisation des pointeurs et des acces memoire
 */
 class Boutons{
 	private:
 		int shmid;
		entrees* bouton;
 	public:
 		Boutons(); /*constructeur de la classe boutons*/
 		
 		/**
 		* \fn void boutons_initialiser();
 		* \brief Permet d'initialiser les boutons
 		*/ 		
		void initialiser();
		
 		/**
 		* \fn int boutons_charge();
 		* \brief Permet d'initialiser les boutons
 		* \param void
 		* \return int
 		*/ 
		int boutons_charge();
		int boutons_stop();
 	
 
 };

#endif


