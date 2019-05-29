//
//  GreenBull.h
//  tp3
//
//  Created by Rania Abid on 2019-05-26.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#ifndef GreenBull_h
#define GreenBull_h
#include <iostream>
#include <string>
#include "ObjetMagique.h"
class GreenBull: public ObjetMagique
{
    
public:
    GreenBull();
    GreenBull(const std::string &nom, int bonus);
    
    friend std::ostream& operator<<(std::ostream& o, const GreenBull& greenBull);
    void utiliserSur(Creature& creature) const;

};

#endif /* GreenBull_h */
