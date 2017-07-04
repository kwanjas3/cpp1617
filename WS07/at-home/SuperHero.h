#ifndef SICT_SUPERHERO_H__
#define SICT_SUPERHERO_H__

#include "Hero.h"

class SuperHero: public Hero {
    int m_superPowerAttackBonus; // superpower:  attack bonus
    int m_superPowerDefendBonus;      // superpower:  defense

public:
    // constructors  
    SuperHero();
    SuperHero(const char* name, 
            int maximumHealth, 
            int attack,
            
            int superPowerAttack, 
            int superPowerDefend);
    int getAttack() const; 
    int getDefend() const; 
 };

void applyDamage (SuperHero& A,  SuperHero& B);
const SuperHero & operator*(const SuperHero &, const SuperHero &);

#endif
