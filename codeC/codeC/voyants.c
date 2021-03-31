#include <stdio.h>
#include <voyants.h>
#include <timer.h>
#include <time.h>
#include <unistd.h>

entrees *leds;

/*Acces a la memoire partagee*/
void voyants_initialiser()
{
	leds=acces_memoire(&shmid);
	// associer..
	if(leds==NULL) 
	{printf("Erreur pas de mem sh \n");}
	//led_charge=leds->timer_sec;
}

/*allumer le voyant charge*/
void voyants_set_charge(led led1)
{
	leds->led_charge=led1; 
}

/*allumer le voyant dispo*/
void voyants_set_dispo(led led1)
{
	leds->led_dispo=led1;
}

/*clignoter le voyant charge pendnat 8 secondes*/
void voyants_blink_charge()
{
int duree=8,n=0;
timer_raz();
	while(n <= duree)
	{
		usleep(250000);// 1/4 de secondes allumee
			leds->led_charge=VERT;
		usleep(250000); //1/4 de seconde eteint
			leds->led_charge=OFF;
		n++;
	}
}

/*clignoter le voyant defaut pendnat 8 secondes*/
void voyants_blink_defaut()
{

int duree=8,n=0;
timer_raz();
	while(n <= duree)
	{
		usleep(250000);
			leds->led_defaut=ROUGE;
		usleep(250000);
			leds->led_defaut=OFF;
		n++;
	}
}

int voyants_dispo(){
	return leds->led_dispo; // retrourne l'etat du voyant dispo
}

