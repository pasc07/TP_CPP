#ifndef GENERATEUR_SAVE_H
#define GENERATEUR_SAV_H

class GenerateurSave
{
    void genererPWM(int pwmtension);
    void MEF(int etat_initial);
    void initialiser();
    void charger();
    void deconnecter();
    void test_tension();
    void fermerAC();
    void ouvrireAC();
    void sansnom1();

};

#endif
