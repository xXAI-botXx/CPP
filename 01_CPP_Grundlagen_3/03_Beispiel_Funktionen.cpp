#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int get_power(int base, int power)
{
	int ergebnis = 1;
	for (int i = 0; i < power; i++)
	{
		ergebnis *= base;
	}
	return ergebnis;
}

bool is_power_of_two(unsigned int number)
{
	bool is_power = false;
	int start_value = 0;
	
	for (int i = 0; get_power(2,i) <= number; i++)
	{
		if (get_power(2, i) == number)
		{
			return true;
		}
	}
	return false;
}

void check_power_of_two(unsigned int number)
{
	if (is_power_of_two(number))
	{
		cout << "Yes, " << number << " is a power of two!" << endl;
	}
	else
	{
		cout << "No, " << number << " is not a power of two!" << endl;
	}
	cout << endl << "-----" << endl << endl;
}

int main()
{
	/*check_power_of_two(8);
	check_power_of_two(2342);
	check_power_of_two(2);
	check_power_of_two(4582905812);
	check_power_of_two(64);*/

	bool is_running = true;
	int eingabe;
	while (is_running)
	{
		cout << "Which number do you want to proof? ";
		cin >> eingabe;
		cout << endl;

		check_power_of_two(eingabe);
	}

	return 0;
}