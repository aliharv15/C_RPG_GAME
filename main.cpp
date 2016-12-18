/*
 * Core.cpp
 *
 *  Created on: 16 Oct 2016
 *      Author: ali
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
//#include "allegro.h"
using namespace std;



class monster {
public:
	int ac;
	int hp; 
	int speed;
	int str;
	int dex;
	int con;
	int intel;
	int wis;
	int cha;
	int attack(int, int, int);
};

int monster::attack(int roll, int dmgMod, int armourClass) {
	cout << "Roll is: " << roll << "\n";
	cout << "dmgMod is: " << dmgMod << "\n";
	int strength = this->str;
	int damage;
	if (roll > armourClass) {
		damage = strength + dmgMod;
	}
	else {
		damage = 0;
	}
	return damage;
}

int diceRoll(int die){
	srand(time(NULL));
	int roll;
	switch (die){
		case '4':
			roll = rand() % 4 + 1; //creates a random number between 1 and 4
			break;
		case '6':
			roll = rand() % 6 + 1; //creates a random number between 1 and 6
			break;
		case '8':
			roll = rand() % 8 + 1; //creates a random number between 1 and 8
			break;
		case '10':
			roll = rand() % 10 + 1; //creates a random number between 1 and 10
			break;
		case '12':
			roll = rand() % 12 + 1; //creates a random number between 1 and 12
			break;
		case '20':
			roll = rand() % 20 + 1; //creates a random number between 1 and 20
			break;
		default:
			roll = 0;
			break;
	}
	return roll;
}


int main() {

	monster goblin;
	goblin.ac = 15;
	goblin.hp = 5;
	goblin.speed = 30;
	goblin.str = 11;
	goblin.dex = 13;
	goblin.con = 12;
	goblin.intel = 10;
	goblin.wis = 9;
	goblin.cha = 6;

	monster dragon;
	dragon.ac = 19;
	dragon.hp = 195;
	dragon.speed = 40;
	dragon.str = 23;
	dragon.dex = 14;
	dragon.con = 21;
	dragon.intel = 14;
	dragon.wis = 13;
	dragon.cha = 17;

	int damage = goblin.attack(diceRoll('20'), diceRoll('6'), dragon.ac);

	cout << damage << "\n";
	//cout << "Dragon Armour Class is " << dragon.ac << "\n";


return 0;
}
