#include "timer.h"

using namespace std;

Timer::Timer(){}
void Timer::initialiser(){
	io=acces_memoire(&shmid);
	// associer..
	if(io==NULL) 
	{
		cout<<"Erreur pas de mem sh \n"<<endl;
	}
}

void Timer::pause(int s){
	int delay=0;
	raz();
	while(delay<=s){
		delay=Timer::valeur();
	}
}

void Timer::raz(){
	initialiser();
	depart_timer=io->timer_sec;
	cout<<"Fin pause"<<endl;
}

int Timer::valeur(){
	initialiser();
	fin_timer=io->timer_sec;
	return fin_timer-depart_timer;
}
