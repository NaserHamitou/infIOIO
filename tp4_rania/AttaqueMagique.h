//
//  AttaqueMagique.h
//  tp4
//
//  Created by Rania Abid on 2019-05-30.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#ifndef AttaqueMagique_h
#define AttaqueMagique_h
#include <string>
#include <vector>
#include "Creature.h"

class AttaqueMagique
{
public:
    AttaqueMagique();
    AttaqueMagique(int duree);
    virtual ~AttaqueMagique()=default;
    int obtenirDuree()const;
    void modifierDuree(int duree);
    virtual std::string obtenirTypeAttaque() const;
    virtual void appliquerAttaque(Creature & creature)=0;
    virtual bool estFini() ;
    friend std::ostream& operator<<(std::ostream& os, const Creature& creature);
    
protected:
    int duree_;
};
#endif /* AttaqueMagique_h */
