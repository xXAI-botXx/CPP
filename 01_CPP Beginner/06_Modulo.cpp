/*
#include <iostream>

int main() {
	int eingabe;

	std::cout << "Ich prüfe für dich, ob ein Jahr ein Schaltjahr ist/war oder nicht." << std::endl;
	std::cout << "Gib eine Zahl ein: ";
	std::cin >> eingabe;

	//ist Schaltjahr?
	if (eingabe%4 == 0) {
		//Sonderfall sind jahrhindertwenden
		if (eingabe % 100 == 0) {
			if (eingabe % 400 == 0) {
				std::cout << "Alles klar, das Jahr " << eingabe << " ist ein Schaltjahr." << std::endl;
			}
			else if (eingabe % 400 != 0) {
				std::cout << "Tut mir Leid, das Jahr " << eingabe << " ist kein Schaltjahr." << std::endl;
			}
		}
		else {
			std::cout << "Alles klar, das Jahr " << eingabe << " ist ein Schaltjahr." << std::endl;
		}
	}
	else {
		if (eingabe <= 2020) {
			std::cout << "Das Jahr " << eingabe << " war kein Schaltjahr." << std::endl;
		}
		else {
			std::cout << "Das Jahr " << eingabe << " wird kein Schaltjahr." << std::endl;
		}
	}

	return 0;
}*/