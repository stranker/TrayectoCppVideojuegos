#pragma once // Solo se invoca y se incluye una vez
#include <iostream> // Incluyo la libreria input/output stream

using namespace std; // Uso el namespace std

class Player { // Declaro mi clase Player
private:
	int health = 0; // Declaro y defino la variable entera health
	const int MAX_HEALTH = 100; // Declaro y defino la constante MAX_HEALTH
protected:
	int damage = 0; // Declaro y defino la variable damage
public:
	Player(int _health); // Constructor de Player pasandole un parametro entero
	Player(); // Constructor sin parametros
	void TakeDamage(int damage); // Metodo que devuelve un void
	int GetHealth(); // Metodo que devuelve la variable entera health
	bool IsAlive(); // Metodo que devuelve si el player esta vivo
	void Heal(int _health); // Metodo para curar al player
	virtual void Damage(int amount); // Metodo para aplicar danio
	virtual void Debug() = 0; // Metodo debug para imprimir mi Player
};
