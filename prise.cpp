#include "prise.h"

Prise::Prise(){}
void Prise::initialiser(){
	io=acces_memoire(&shmid);
	// associer..
	if(io==NULL) 
	{
		cout<<"Erreur pas de mem sh \n"<<endl;
	}
}

void  Prise::verouiller_trappe()
{
	initialiser();
	io->led_trappe=OFF;
}

void Prise::deverouiller_trappe()
{
	initialiser();
	io->led_trappe=VERT;
}

void  Prise::set_prise(led etat)
{
	initialiser();
	io->led_prise=etat;
}
