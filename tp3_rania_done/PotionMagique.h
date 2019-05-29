//
//  PotionMagique.h
//  tp3
//
//  Created by Rania Abid on 2019-05-25.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#ifndef PotionMagique_h
#define PotionMagique_h
#include <iostream>
#include <string>
#include "ObjetMagique.h"
class PotionMagique: public ObjetMagique
{
    public:
    
    PotionMagique();
    PotionMagique(const std::string &nom, int bonus);
    friend std::ostream& operator<<(std::ostream& o, const PotionMagique& potionMagique);
    void utiliserSur(Creature& creature) const;
    

    
};

#endif /* PotionMagique_h */
