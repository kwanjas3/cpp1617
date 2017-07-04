#ifndef HERO_H
#define HERO_H

#include <iostream>

class Hero {
    char m_name[41];    
    int  m_attack;
    int  m_maximumHealth;
    int  m_health; 
	/////////////////////////////////////////////////
	   // Hero::isEmpty ()
	   // return true if the Hero object is uninitialized
	   //
	bool isEmpty() const
	{
		bool check = false;
		if (m_name[0] == 0 &&
			m_attack == 0 &&
			m_maximumHealth == 0 &&
			m_health == 0
			) {
			check = true;
		}
		return check;
	}

public:
    // constructors
    Hero ();
	void setEmpty();
    Hero (const char name[], int maximumHealth, int attack);

    // member functions
    void respawn();
	bool isAlive() const; 
	int  getAttack() const;
    void deductHealth(int);
	void display(std::ostream& os);
    // friend helper function to insert name into ostream
	friend std::ostream& operator<<(std::ostream&, const Hero&);
};

void applyDamage (Hero& A, Hero& B);
const Hero & operator*(const Hero &, const Hero &);

#endif
