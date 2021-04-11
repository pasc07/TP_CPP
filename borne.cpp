#include <iostream>
#include <memoire_borne.h>
#include <donnees_borne.h>
/*!
* \file borne.cpp
* \brief Fonction principale de la borne
* Cette fonction principale fait appel a la fonction lecteur carte qui 
* demarre un cycle de rechargement.
* Le circuit de recharge dédié et imposé dans le « Mode 3 » est défini dans la proposition de norme IEC 61851-1 « ELECTRIC VEHICLE CONDUCTIVE CHARGING SYSTEM ». Cela permet de garantir une sécurité maximale des utilisateurs lors de la recharge de leur véhicule électrique. La Figure 3 représente la connectique entre une borne et un véhicule.
*
*Code admin =1234 
* \author Sewoda et Achari
* \version 1.0
* \date 11/04/2021
*
*/

#include "lecteurcarte.h"
#include "baseclient.h"
#define ADMIN 1234

using namespace std;
int main()
{
    LecteurCarte lecteurcarte;
    BaseClient baseclient;
    while (1){
    	int choix;
    	cout<<"\n\n INTERFACE DE GESTION DE LA BORNE DE RECHARGE\n"<<endl;
    	cout<<"Entree votre choix"<<endl;
    	cout<<"1. Client"<<endl;
    	cout<<"2. Administrateur"<<endl;
    	cin>>choix;
    	cin.ignore();
    
    	switch(choix)
    	{
    	case 2 : cout<<"Entrez le code admin [defaut:1234]"<<endl;
    			int code;
    			cin>>code;
    			cin.ignore();
    			if(code==ADMIN){
    				cout<<"-------------INTERFACE DE GESTION----------\n"<<endl;
    				baseclient.ajout();
					break;
				}else{
					cout<<"Code invalide"<<endl;
					break;
				}
		case 1 :cout<<" DEBUT PROCESSUS [Par defaut: 18]"<<endl;
        		lecteurcarte.lire_carte();
        		cout<<" FIN DU PROCESSUS DE CHARGE"<<endl;
				break;
		default:
			cout<<"Veuillez entrer un numero valide"<<endl;
			break;
			return 0;
    	}
    }
}
