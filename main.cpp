/// Includes

#include <iostream>


// Namespace
using namespace std;


/// Class declarations
// This "project" is just a simple implementation of the decorator pattern,
// so I'm not gonna bother with multiple files...


/// BASE WEAPON CLASS

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


/// A SWORD SUB-CLASS

// Creating an object sword that inherit of Weapon
class Sword : public Weapon
{

public:

	// Constructor : initialize your sword with a base damage value
	Sword(int damage = 10) { _damage = damage; }

	// Get the damage
	virtual int damage() { return _damage; }

};


/**
* Main function
*/
int main(int argc, char* argv[])
{
	// Instanciate your nice sword
	Weapon* ironSword = new Sword(12);

	// Hit something
	cout << "You hit for " << ironSword->damage() << " dmg!" << endl;

	// Free memory
	delete ironSword;

	return 0; // End
}