#include "Player.h"

Player::Player(int _health) {
	health = _health;
	damage = 0;
}

Player::Player() {
	health = 0;
	damage = 0;
}

void Player::TakeDamage(int damage) {
	health -= damage;
}

int Player::GetHealth() {
	return health;
}

bool Player::IsAlive() {
	return health > 0;
}

void Player::Heal(int _health) {
	health += _health;
	health = health > MAX_HEALTH ? MAX_HEALTH : health;
	if (health > MAX_HEALTH){
		health = MAX_HEALTH;
	}
	//health = Mathf.Clamp(health, min, max); -> Unity
	//health = clamp(health, min, max) -> Godot
}

void Player::Damage(int amount) {
	cout << amount << endl;
}
