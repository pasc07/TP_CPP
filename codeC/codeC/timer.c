#include <stdio.h>
#include <timer.h>
#include <donnees_borne.h>
#include <memoire_borne.h>
entrees *io;
int shmid;
int depart_timer;
int fin_timer;

void timer_pause(int s)
{
	int delay=0;
	timer_raz();
	while(delay<=s){
		delay=timer_valeur();
	}
}

void timer_init()
{
		io=acces_memoire(&shmid);
	// associer..
	if(io==NULL) printf("Erreur pas de mem sh \n");
}
void timer_raz(){
	depart_timer=io->timer_sec;
}

int timer_valeur()
{
	// associer..
	fin_timer=io->timer_sec;
	return fin_timer-depart_timer;
}
