//
//  EtatEndormi.h
//  tp3
//
//  Created by Rania Abid on 2019-05-25.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#ifndef EtatEndormi_h
#define EtatEndormi_h
#include <iostream>
#include <string>
#include "EtatCreature.h"
class EtatEndormi: public EtatCreature
{
public:
    EtatEndormi(const std::string& nom);
    EtatEndormi(const std::string& nom, unsigned int duree);
    friend std::ostream& operator<<(std::ostream& o, const EtatEndormi& etatEndormi);
    void appliquerEtat(Creature& creature); 
    bool peutAttaquer() const;
    bool estFini() const;

    
    
};

#endif /* EtatEndormi_h */
