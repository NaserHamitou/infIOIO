//
//  CreatureMagique.h
//  tp3
//
//  Created by Rania Abid on 2019-05-28.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#ifndef CreatureMagique_h
#define CreatureMagique_h
#include "Creature.h"

class CreatureMagique:public Creature
{
public:
    CreatureMagique(const std::string& nom, unsigned int attaque,unsigned int defense, unsigned int pointDeVie, unsigned int energie);
    //constructeur pae copie
    CreatureMagique(const CreatureMagique& creatureMagique);
    
    CreatureMagique& operator=(const CreatureMagique& creatureMagique);
    friend std::ostream& operator<<(std::ostream& os, const CreatureMagique& creatureMagique);
    void attaquer(const Pouvoir& pouvoir, Creature& creature);
    
private:
    int bonus_;
};

#endif /* CreatureMagique_h */
