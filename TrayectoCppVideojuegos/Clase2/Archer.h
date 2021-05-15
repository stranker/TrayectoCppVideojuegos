#pragma once // Solo se invoca y se incluye una vez
#include "Player.h" // Incluyo mi clase Player

class Archer : // Declaro mi clase Archer
    public Player { // Deriva de la clase Player
public:
    Archer(int _health); // Constructor de Archer con parametro entero
    Archer(); // Constructor de Archer sin parametros
    ~Archer(); // Destructor de Archer - Se suelen finalizar procesos, eliminar variables creadas, etc
    virtual void Damage(int amount) override; // Override de la funcion Damage de la clase Player
    virtual void Debug(); // Declarar el metodo Debug para definirlo en el .cpp - En la clase Player es virtual puro
};
