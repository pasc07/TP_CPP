/*
	int tension;
	
	voyants_set_dispo(OFF);
	voyants_set_charge(ROUGE);
	//generateur_save_generer_PWM(DC);
	prise_deverouiller_trappe();
	tension=generateur_save_tension();
	
	usleep(2000000);
	prise_verouiller_trappe();
	usleep(2000);
	prise_set_prise(VERT);
	
	tension=generateur_save_tension();
	//while(tension!=6){
	generateur_save_generer_PWM(AC_1K);
		tension=generateur_save_tension();
	//}
	//generateur_save_generer_PWM(DC);
	generateur_save_fermer();
	usleep(2000000);
	
	
	tension=generateur_save_tension();
	//while(tension!=9){
		generateur_save_generer_PWM(AC_CL);
		tension=generateur_save_tension();
//	}
	//if(tension==9){
	generateur_save_ouvert();
	usleep(2000);	
	//}
	voyants_set_charge(VERT); */
