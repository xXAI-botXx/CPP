/*
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	bool gewonnen = false;
	int anz_spiele;
	int runden = 0;
	cout << "Willkommen bei meinem Gluecksspiel" << endl;
	cout << "Wie viele Durchlaeufe soll das Spiel haben?: ";
	cin >> anz_spiele;

	//While-Schleife, wenn ich nicht weiﬂ, wie oft ich iterieren will (siehe nicht dieses Beispiel)
	//Solange wie die Bedingung True ergibt und nicht abgebrochen wird
	while(!gewonnen && runden < anz_spiele)
	{
		int zahl;
		cout << "Bitte gebe eine Zahl aus dem Intervall [1,10] ein: ";
		cin >> zahl;

		//Gleichheit (==), Kleiner Gleich (<=), Groesser Gleich (>=)
		//Unggleichheit (!=), Kleiner (<), Groesser (>)
		//UND (&&), oder (||)

		if (zahl == 4) {
			gewonnen = true;
			cout << "Super! Du hast gewonnen!" << endl;
		}
		else if (zahl % 2 == 0 && zahl <= 10 && zahl >= 0) {
			cout << "Du hast einen Nebenpreis gewonnen." << endl;
		}
		else {
			cout << "Du hast verloren." << endl;
		}
		runden++;
	}

	return 0;
}*/