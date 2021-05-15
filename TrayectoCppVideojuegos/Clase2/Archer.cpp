#include "Archer.h"

Archer::Archer(int _health) : Player(_health) { // Llamo al constructor de Player
}

Archer::Archer() {
}

Archer::~Archer() {
}

void Archer::Damage(int amount) {
	cout << "20" << endl;
}

void Archer::Debug() {
	cout << "Soy un arquero y mi vida es:" << GetHealth() << endl;
}
