#include "prise.h"

void  Prise::verouiller_trappe()
{
	io->led_trappe=OFF;
}

void Prise::deverouiller_trappe()
{
	io->led_trappe=VERT;
}

void  Prise::set_prise(led etat)
{
	io->led_prise=etat;
}
