#include <iostream>
#include <stdlib.h>

//#define LEN_X 10;	//Keine Variable, sondern eine Textersetzung;
//#define LEFT 'a';
//#define RIGHT 'd';

using std::cout;
using std::cin;
using std::endl;

int main() 
{
	bool repeat = true;

	while (true)
	{
		int LEN_X = 10;
		char LEFT = 'a';
		char RIGHT = 'd';
		// Wir haben 10 Spielfelder
		unsigned int player_pos = 0;
		unsigned int start = 0;
		unsigned int goal = LEN_X - 1;

		char move;
		bool finished = false;

		while (!finished)
		{

			//for (int i = 0; i < LEN_X; i++)
			for (int i = 0; i < LEN_X; i++)
			{
				if (i != player_pos && i != goal && i != start)
					cout << ".";
				else if (i == player_pos)
					cout << "P";
				else if (i == goal || i == start)
					cout << "|";
			}

			cin >> move;

			system("CLS");

			if (move == LEFT && player_pos > 0)
			{
				player_pos--;
				cout << "You moved left!" << endl;
			}
			else if (move == RIGHT && player_pos < LEN_X - 1)
			{
				player_pos++;
				cout << "You moved right!" << endl;
			}
			else
			{
				cout << "Unrecognized move!" << endl;
			}

			//Überprüfe Position
			if (player_pos == goal)
			{
				cout << "You won the game!" << endl;
				finished = true;
				//break;
			}
		}

		cout << "Play again? (0=N, 1=Y)" << endl;
		cin >> repeat;

		if (repeat == 0)
		{
			break;
		}

		//leert die Konsole
		system("CLS");
	}

	getchar();
	getchar();
	return 0;
}