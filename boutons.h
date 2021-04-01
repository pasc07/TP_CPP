#ifndef BOUTONS_H
#define BOUTONS_H

#include <donnees_borne.h>
#include <memoire_borne.h>
 /**
 * \class Boutons
 * \file boutons.h boutons.cpp
 * \brief Cette classe permet de gerer les appuis sur les 
 boutons a travers l'utilisation des pointeurs et des acces memoire
 */
 class Boutons {
 	private:
 		int shmid;
		entrees* bouton;
 	public:
 		Boutons(); /*constructeur de la classe boutons*/
 		
 		/**
 		* \fn void initialiser();
 		* \brief Permet d'initialiser les boutons
 		*/ 		
		void initialiser();
		
 		/**
 		* \fn int charge();
 		* \brief Permet d'initialiser les boutons
 		* \param void
 		* \return int
 		*/ 
		int charge();
		int stop();
 	
 
 };

#endif


