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
	leds->led_charge=ledCoul; 	
}

void Voyants::set_dispo(led ledCoul){
	leds->led_dispo=ledCoul;
}
void Voyants::blink_charge(){
    	int duree=8,n=0;
		Timer timer = Timer();
		timer.raz();
	while(n <= duree)
	{
		usleep(250000);// 1/4 de secondes allumee
			leds->led_charge=VERT;
		usleep(250000); //1/4 de seconde eteint
			leds->led_charge=OFF;
		n++;
	}
}

void Voyants::set_defaut(){

}

void Voyants::etat_dispo(){

}

void Voyants::blink_defaut(){
	Timer timer = Timer();
	timer.raz();
	int duree=8,n=0;
	
	while(n <= duree)
	{
		usleep(250000);
			leds->led_defaut=ROUGE;
		usleep(250000);
			leds->led_defaut=OFF;
		n++;
	}

}
