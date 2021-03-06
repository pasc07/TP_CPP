#include "voyants.h"
#include <memoire_borne.h>

using namespace std;

Voyants::Voyants(){
}

void Voyants::initialiser(){
	leds=acces_memoire(&shmid);
	// associer..
	if(leds==NULL) 
	{
		cout<<"Erreur pas de mem sh"<<endl;
	}
}

void Voyants::set_charge(led ledCoul){
	initialiser();
	leds->led_charge=ledCoul; 	
}

void Voyants::set_dispo(led ledCoul){
	initialiser();
	leds->led_dispo=ledCoul;
}
void Voyants::blink_charge(){
    	int duree=8,n=0;
		//Timer timer = Timer();
		//timer.raz();
	while(n <= duree)
	{
		usleep(250000);// 1/4 de secondes allumee
			initialiser();
			leds->led_charge=VERT;
		usleep(250000); //1/4 de seconde eteint
			initialiser();
			leds->led_charge=OFF;
		n++;
		status_bouton=boutons.charge();
		if(status_bouton==1)
			break;
	}
}

void Voyants::set_defaut(){

}

int Voyants::dispo(){
	initialiser();
	if((leds->led_dispo)==VERT) // retrourne l'etat du voyant dispo
		return 1;
	else
		return 0;
}

void Voyants::blink_defaut(){
	//Timer timer = Timer();
	//timer.raz();
	int duree=8,n=0;
	
	while(n <= duree)
	{
		usleep(250000);
			initialiser();
			leds->led_defaut=ROUGE;
		usleep(250000);
			initialiser();
			leds->led_defaut=OFF;
		n++;
	}

}

int Voyants::getStatus_bouton(){
			return status_bouton;
		}
