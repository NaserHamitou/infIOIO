//
//  Elixir.h
//  tp3
//
//  Created by Rania Abid on 2019-05-26.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#ifndef Elixir_h
#define Elixir_h
#include <iostream>
#include <string>
#include "PotionMagique.h"
class Elixir: public PotionMagique
{
public:
    Elixir();
    Elixir(const std::string &nom, int bonus);
    
    friend std::ostream& operator<<(std::ostream& o, const Elixir& elixir);
    void utiliserSur(Creature& creature) const;
};
#endif /* Elixir_h */
