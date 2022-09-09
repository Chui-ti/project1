#include<iostream>
using namespace std;

void user_menu()
{
	char number_seminar;
	int f = 0;

	while (f == 0)
	{
		cout << "-------------------------------------------" << endl;
		cout << "|1. Thirst seminar: one-demensional array.|" << endl;
		cout << "|2. Second seminar: two-demensional array.|" << endl;
		cout << "|3. Third  seminar: strings.              |" << endl;
		cout << "|4. The end of the program.               |" << endl;
		cout << "-------------------------------------------";
		cout << endl << "Select the number of seminar: ";
		cin >> number_seminar;

		switch (number_seminar)
		{
		case '1':
			//вызов первого кода
			f = 1;
			break;

		case '2':
			//вызов второго кода
			f = 1;
			break;

		case '3':
			//вызов третьего кода
			f = 1;
			break;
		case '4':
			f = 1;
			break;

		default :
			cout << "Please, chose 1, 2 or 3.";
			

		}


	}
	
}

