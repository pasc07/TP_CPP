#include "timer.h"

using namespace std;

Timer::Timer(){
	//implemtation of raz
}

void Timer::pause(int s){
	int delay=0;
	raz();
	while(delay<=s){
		delay=Timer::valeur();
	}
}

void Timer::raz(){
	depart_timer=io->timer_sec;
}

int Timer::valeur(){
	// associer..
	fin_timer=io->timer_sec;
	return fin_timer-depart_timer;
}
