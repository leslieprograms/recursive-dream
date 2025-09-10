#include <iostream>
#include <string>
using namespace std;

class Character 
{
protected:
    string name;

private:
    int health;
    int level;

public:
    Character(const std::string& n, int l) : name(n),
                            level(l), health(100)
    {
        /*
        name = n;
        level = l;
        health = 100;
        */
    }

    void displayCharacterInfo() const 
    {
        cout << "Health: " << health << endl;
        cout << "Level: " << level << endl;
    }

    void takeDamage(int damage) 
    {
        if (health > damage)
            health = health - damage;
        else
            health = 0;

    	//health = (health > damage) ? health - damage : 0;
    }
};

class Warrior : Character 
{
private:
    int strength;

public:
    Warrior(const std::string& n, int l, int s)
        : Character(n, l)
        {
            strength = s;
        }

    void specialAbility() const
    {
        cout << name << " uses Berserker Rage! Strength increased by " 
        	<< strength << " points!" << endl;
    }

    void attack(Warrior& enemy) 
    {
        int damage = strength * 2;
        enemy.takeDamage(damage);
        cout << name << " attacks and deals " 
        	<< damage << " damage!" << endl;
    }

    void takeDamage(int damage)
    {
    	Character::takeDamage(damage);
    }

    void displayCharacterInfo() const
    {
    	cout << "Name: " << name << endl;
    	Character::displayCharacterInfo();
    }
};

int main()
{
	Warrior w1("Conan", 50, 35);
	Warrior w2("Kira", 75, 60);

	w1.attack(w2);
	w2.attack(w1);

    cout << endl;

	w1.displayCharacterInfo();

	cout << endl;

	w2.displayCharacterInfo();

	return 0;
}