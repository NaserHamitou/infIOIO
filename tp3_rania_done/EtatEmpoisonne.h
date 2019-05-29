//
//  EtatEmpoisonne.h
//  tp3
//
//  Created by Rania Abid on 2019-05-25.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#ifndef EtatEmpoisonne_h
#define EtatEmpoisonne_h
#include <iostream>
#include <string>
#include "EtatCreature.h"
class EtatEmpoisonne: public EtatCreature
{
public:
    EtatEmpoisonne(const std::string& nom);
    EtatEmpoisonne(const std::string& nom, unsigned int duree);
    
    friend std::ostream& operator<<(std::ostream& o, const EtatEmpoisonne& etatEmpoisonne);
    void appliquerEtat(Creature& creature);
    bool estFini() const;
    
    
    
};

#endif /* EtatEmpoisonne_h */
