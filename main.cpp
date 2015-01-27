/// Includes

#include <iostream>


// Namespace
using namespace std;


/// Class declarations
// This "project" is just a simple implementation of the decorator pattern,
// so I'm not gonna bother with multiple files...



// This is our base abstract class that will define what a weapon should looks like
// Here we just put a method to get the damage the weapon will deal
class Weapon
{

public:

	// We need a function to get the damage our weapon deal
	virtual int damage() = 0;

	// Destructor
	virtual ~Weapon() {}

protected:

	// An int to store the damage
	int _damage;

};



// Creating an object sword that inherit of Weapon
class Sword : public Weapon
{

public:

	// Constructor : initialize your sword with a base damage value
	Sword(int damage = 10)
	{
		_damage = damage;
	}

	// Get the damage
	virtual int damage() { return _damage; }

};

/////////////////////////////////////////////////
/// Decorator implementation : Enchant weapon ///
/////////////////////////////////////////////////

// Enchant base class
class Enchant : public Weapon
{

public:

	// Constructor : take a Weapon in parameter, since our Enchant inherit from Weapon, that can also be an already Enchanted weapon
	Enchant(Weapon* weapon) :
		_weapon(weapon)
	{}

	// Free the weapon
	virtual ~Enchant() { delete _weapon; }

	// Just return the damage of the weapon
	virtual int damage() { return _weapon->damage(); }

protected:

	// Pointer to our weapon
	Weapon* _weapon;

};

/// Some op magic

// A fire enchant
class Fire : public Enchant
{

public:

	Fire(Weapon* weapon) :
		Enchant(weapon)
	{}

	// Return the damage of the weapon plus the bonus damage of the fire enchant
	int damage() { return _weapon->damage() + 8; }

};

// An ice enchant
class Ice : public Enchant
{

public:

	Ice(Weapon* weapon) :
		Enchant(weapon)
	{}

	// Return the damage of the weapon plus the bonus damage of the ice enchant
	int damage() { return _weapon->damage() + 5; }

};

// A lightning op enchant
class Lightning : public Enchant
{

public:

	Lightning(Weapon* weapon) :
		Enchant(weapon)
	{}

	// Return the damage of the weapon with some bonus
	int damage() { return _weapon->damage() * 2; }

};

/**
* Main function
*/
int main(int argc, char* argv[])
{
	// Instanciate your nice sword
	Weapon* ironSword = new Sword(12);
	Weapon* fireSword = new Fire(new Sword(12));
	Weapon* excalibur = new Lightning(new Fire(new Ice(new Lightning(new Lightning(new Ice(new Fire(new Sword(12)))))))); // cheat detected o/

	// Hit something
	cout << "You hit for " << ironSword->damage() << " dmg!" << endl;
	cout << "You hit for " << fireSword->damage() << " dmg!" << endl;
	cout << "You hit for " << excalibur->damage() << " dmg!" << endl;

	// Free memory
	delete ironSword;
	delete fireSword;
	delete excalibur; // How dare you ! :x

	return 0; // End
}
