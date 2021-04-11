#include <iostream>
#include <memoire_borne.h>
#include <donnees_borne.h>
/*!
* \file borne.cpp
* \brief Fonction principale de la borne
* \author Sewoda et Achari
* \version 1.0
* \date 11/04/2021
* Cette fonction principale fait appel a la fonction lecteur carte qui 
* demarre un cycle de rechargement
*/

#include "lecteurcarte.h"
#include "baseclient.h"


using namespace std;
int main()
{
    LecteurCarte lecteurcarte;

    BaseClient baseclient;
    int choix;
    cout<<"INTERFACE DE GESTION DE LA BORNE DE RECHARGE"<<endl;
    cout<<"Entree votre choix"<<endl;
    cout<<"1. Client"<<endl;
    cout<<"2. Administrateur"<<endl;
    cin>>choix;
    cin.ignore();
    
    while (1){
    
    	switch(choix)
    	{
    	case 2 : cout<<"INTERFACE DE GESTION"<<endl;
    			baseclient.ajout();
				break;
		case 1 :cout<<" DEBUT PROCESSUS [18 pour le test]"<<endl;
                	
        		cout<<"Debut de while"<<endl;
        		lecteurcarte.lire_carte();
                cout<<"Fin while"<<endl;
    		
				break;
		default:
			cout<<"Veuillez entrer un numero valide"<<endl;
			break;
			return 0;
    	}
    }
}
