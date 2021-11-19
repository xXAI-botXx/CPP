/*
#include <iostream>
//using namespace std;	//dadurch: angabe von std:: nicht mehr notwendig -> siehe andere Methode
//oder: using std::cout; using std::cin; using std::endl;

//C++ Dateiendung: .cpp oder .cc

void greeting() {
	std::cout << "Hello World" << std::endl;

	//getchar()
}

void try_out() {

	//Variable wurde definiert (angelegt)
	int speed;
	//Variable wurde initialisiert (zugeweisen) -> Objekt erzeugt
	speed = 8;

	int speed2 = 34;
	int ergebnis;

	//Rechenoperationen
	ergebnis = speed2 + speed;
	std::cout << "Ergebnis: " << ergebnis << std::endl;

	ergebnis *= 2;	//special schreibweise, gibts bei jeder Rechenoperation
	std::cout << "Ergebnis*2: " << ergebnis << std::endl;

	ergebnis = speed - speed2;
	std::cout << "Ergbnis: " << ergebnis << std::endl;

	ergebnis = speed2 / speed;	//Rundet
	std::cout << "Ergebnis: " << ergebnis << std::endl;

	//special addieren
	int c = 0;
	std::cout << "C: " << c << std::endl;
	c++;
	std::cout << "Level Up: " << c << std::endl << std::endl;

	//Variablen entweder signed oder unsigned -> automatisch signed!
	//			signed = mit negativen Bereich (dafür positiv nicht so groß)
	//			unsigned = nur einen positiven Bereich, dafür doppelt so groß

	//Weitere Datentypen:
	bool ich_bin_reich = false;
	std::cout << "Bin ich reich? (in Computersprache): " << ich_bin_reich << std::endl;
	bool ich_bin_gluecklich = true;
	std::cout << "Bin ich trotzdem gluecklich? (in Computersprache): " << ich_bin_gluecklich << std::endl << std::endl;

	//8 bit
	char lieblings_alpha = 't';
	std::cout << "Mein lieblings Buchstabe lautet: " << lieblings_alpha << std::endl;

	char lieblings_gross_alpha = 84;	//nach ASKII Art
	std::cout << "Mein lieblings Grossbuchstabe lautet: " << lieblings_gross_alpha << std::endl;

	//16 bit 
	short meine_kleine_zahl = 4567;
	std::cout << "Meine kleine Zahl lautet: " << meine_kleine_zahl << std::endl;

	short meine_kleine_zu_grosse_zahl = 32767 + 1;
	std::cout << "Upps diese Zahl war für 'short' zu gross! Jetzt wird wieder von hinten gezaehlt: " << meine_kleine_zu_grosse_zahl << std::endl;

	unsigned short meine_kleine_grosse_zahl = 65.535;
	std::cout << "Unsigned Char geht bis zu: " << meine_kleine_grosse_zahl << std::endl << std::endl;

	//32 bit
	int meine_ganzzahl = 32767 + 1;
	std::cout << "Meine Ganzzahl lautet: " << meine_ganzzahl << std::endl;

	int meine_max_ganzzahl = 2147483647;
	std::cout << "Meine max Integer lautet: " << meine_max_ganzzahl << std::endl;

	unsigned int meine_max_un_ganzzahl = 4294967295;
	std::cout << "Meine max unsigned Integer lautet: " << meine_max_un_ganzzahl << std::endl << std::endl;

	//64 bit
	long long meine_grosse_zahl = 9223372036854775807;
	std::cout << "Meine grosse Zahl: " << meine_grosse_zahl << std::endl;

	unsigned long long meine_wirklich_grosse_zahl = 18446744073709551615;
	std::cout << "Meine wirklich grosse Zahl: " << meine_wirklich_grosse_zahl << std::endl << std::endl;

	//32 bit (Rationale Zahlen sind Teilmenge der natürlichen Zahlen => float kann auch Ganzzahl sein)
	float f_zahl = 0.123456789;
	std::cout << "Meine Kommazahl: " << f_zahl << std::endl;

	//64 bit
	double d_zahl = 0.123456789;
	std::cout << "Meine grosse Kommazahl: " << d_zahl << std::endl;

	//80 bit
	long double ld_zahl = 0.123456789;
	std::cout << "Meine sehr grosse Kommazahl: " << ld_zahl << std::endl << std::endl;

	getchar();
}

void zahlen_prunch() {
	//Definiere/Deklariere 3 Variablen (lege 3 Variablen an)
	float zahl1, zahl2, zahl3;

	std::cout << "Gebe eine Zahl ein: ";
	std::cin >> zahl1;

	std::cout << "Gebe eine weitere Zahl ein: ";
	std::cin >> zahl2;

	//Addition
	zahl3 = zahl1 + zahl2;
	std::cout << std::endl << "Addition ergibt: " << zahl3 << std::endl;

	//Subtraktion
	zahl3 = zahl1 - zahl2;
	std::cout << "Subtraktion ergibt: " << zahl3 << std::endl;

	//Multipilkation
	zahl3 = zahl1 * zahl2;
	std::cout << "Multipikation ergibt: " << zahl3 << std::endl;

	//Division
	zahl3 = zahl1 / zahl2;
	std::cout << "Division ergibt: " << zahl3 << std::endl << std::endl;
}

int main() {
		//Deklaration: (extern int speed;)
		//	Ein Programmausdruck der einen Namen in einen Scope ein - bzw.wiedereinführt.

		//Definition: (int speed;)
		//	Eine Deklaration die die Details einer Entität bekannt macht oder, im Fall von Variablen, die dazu führt, dass Speicher für die Entität reserviert wird.

		//	Eine Deklaration einer Klasse(struct, class, enum, union) Funktion oder Methode wird zu einer Definition, wenn auf die Deklaration ein in geschweiften Klammern eingeschlossener Block folgt.
		//	Variablendeklarationen sind immer auch Definitionen es sei denn, der Deklaration ist ein extern vorangestellt.

		//Initialisierung: (speed = 1) 
		//	Eine Definition mit expliziter Anfangswertzuweisung.

	//greeting();
	//try_out();
	zahlen_prunch();

 	return 0;
}*/