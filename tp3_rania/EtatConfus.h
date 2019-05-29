//
//  EtatConfus.h
//  tp3
//
//  Created by Rania Abid on 2019-05-22.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#ifndef EtatConfus_h
#define EtatConfus_h
#include <iostream>
#include <string>
#include "EtatCreature.h"
class EtatConfus: public EtatCreature
{
public:
    
    EtatConfus(const std::string& nom);
    EtatConfus(const std::string& nom, unsigned int duree);
     friend std::ostream& operator<<(std::ostream& o, const EtatConfus& etatConfus);
    void appliquerEtat(Creature& creature); //‡ appliquer sur la crÈature qui possËde ce pouvoir
    bool peutAttaquer() const; //dÈtermine si l'Ètat de la crÈature lui permet d'attaquer
    bool estFini() const; //si vrai, informe la crÈature qu'elle peut retourner ‡ l'Ètat normal

};

#endif /* EtatConfus_h */

