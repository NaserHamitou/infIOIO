//
//  CreatureMagique.h
//  tp4
//
//  Created by Rania Abid on 2019-06-04.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#ifndef CreatureMagique_h
#define CreatureMagique_h
#include <iostream>
#include <string>
#include <vector>
#include "Creature.h"
#include "AttaqueMagique.h"

class CreatureMagique:public Creature

{
public:
    CreatureMagique();
    CreatureMagique(int bonus, Creature creature);
protected:
    AttaqueMagique* attaque;
    int bonus_;
    
    
};

#endif /* CreatureMagique_h */
