#include <iostream>
using namespace std;

class victory
{
public:
	int FirstPlayerWins = 0;
	void FirstPlayer()
	{
		cout << " *** First ( O ) Player is WINNER *** " << endl << "-------------------------------" << endl << endl;
	}
	int SecondPlayerWins = 0;
	void SecondPlayer()
	{
		cout << " *** Second ( X ) Player is WINNER *** " << endl << "------------------------------" << endl << endl;
	}
};

void board(char space[3][3]);
void guide();
void Fchoice(char space[3][3], int& row, int& column, int& FirstPlayerChoice, victory VictoryCheck);
void Schoice(char space[3][3], int& row, int& column, int& SecondPlayerChoice, victory VictoryCheck);
void PVS(victory VictoryCheck);
void GamePlay(char space[3][3], int& row, int& column, int& FirstPlayerChoice, int& SecondPlayerChoice, victory VictoryCheck);


int main()
{
	char space[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };
	int row;
	int column;
	int FirstPlayerChoice;
	int SecondPlayerChoice;
	victory VictoryCheck;
	guide();
	GamePlay(space, row, column, FirstPlayerChoice, SecondPlayerChoice, VictoryCheck);
	system("pause");
	return 0;
}

void guide()
{
	cout << " Hi , this is your board game : " << endl;
	cout << " First Player Sign is : O and Second Player Sign is : X " << endl;
	cout << " (1) | (2) | (3)" << endl <<
		" ---------------" << endl <<
		" (4) | (5) | (6)" << endl <<
		" ---------------" << endl <<
		" (7) | (8) | (9)" << endl << endl;
}

void board(char space[3][3])
{
	cout << "     |     |   \n";
	cout << "   " << space[0][0] << " |  " << space[0][1] << "  |  " << space[0][2] << "  \n";
	cout << "_____|_____|______\n";
	cout << "     |     |   \n";
	cout << "   " << space[1][0] << " |  " << space[1][1] << "  |  " << space[1][2] << "  \n";
	cout << "_____|_____|______\n";
	cout << "     |     |   \n";
	cout << "   " << space[2][0] << " |  " << space[2][1] << "  |  " << space[2][2] << "  \n";
	cout << "     |     |   \n";
}

void Fchoice(char space[3][3], int& row, int& column, int& FirstPlayerChoice, victory VictoryCheck)
{
	cout << "First ( O ) Player turn :  ";
	do
	{
		cin >> FirstPlayerChoice;
		while (FirstPlayerChoice < 1 || FirstPlayerChoice > 9)
		{
			cout << "Invalid Choice , Please Choose a Field From 1 to 9 : " << endl;
			cin >> FirstPlayerChoice;
		}
		switch (FirstPlayerChoice)
		{
		case 1:
			row = 0;
			column = 0;
			break;
		case 2:
			row = 0;
			column = 1;
			break;
		case 3:
			row = 0;
			column = 2;
			break;
		case 4:
			row = 1;
			column = 0;
			break;
		case 5:
			row = 1;
			column = 1;
			break;
		case 6:
			row = 1;
			column = 2;
			break;
		case 7:
			row = 2;
			column = 0;
			break;
		case 8:
			row = 2;
			column = 1;
			break;
		case 9:
			row = 2;
			column = 2;
			break;
		}
		if (space[row][column] == 'O' || space[row][column] == 'X')
		{
			cout << " this field is already has been used , please choose another field :  ";
		}

	} while (space[row][column] == 'O' || space[row][column] == 'X');

	space[row][column] = 'O';
	board(space);

}

void Schoice(char space[3][3], int& row, int& column, int& SecondPlayerChoice, victory VictoryCheck)
{
	cout << "Second ( X ) Player turn :  ";
	do
	{
		cin >> SecondPlayerChoice;
		while (SecondPlayerChoice < 1 || SecondPlayerChoice > 9)
		{
			cout << "Invalid Choice , Please Choose a Field From 1 to 9 : " << endl;
			cin >> SecondPlayerChoice;
		}
		switch (SecondPlayerChoice)
		{
		case 1:
			row = 0;
			column = 0;
			break;
		case 2:
			row = 0;
			column = 1;
			break;
		case 3:
			row = 0;
			column = 2;
			break;
		case 4:
			row = 1;
			column = 0;
			break;
		case 5:
			row = 1;
			column = 1;
			break;
		case 6:
			row = 1;
			column = 2;
			break;
		case 7:
			row = 2;
			column = 0;
			break;
		case 8:
			row = 2;
			column = 1;
			break;
		case 9:
			row = 2;
			column = 2;
			break;
		}
		if (space[row][column] == 'O' || space[row][column] == 'X')
		{
			cout << " this field is already has been used , please choose another field :  ";
		}
	} while (space[row][column] == 'O' || space[row][column] == 'X');

	space[row][column] = 'X';
	board(space);
}

void PVS(victory VictoryCheck)
{
	cout << "Player Number 1 ( O ) Have : " << VictoryCheck.FirstPlayerWins << " Wins" << endl;
	cout << "Player Number 2 ( X ) Have : " << VictoryCheck.SecondPlayerWins << " Wins" << endl;
}

void GamePlay(char space[3][3], int& row, int& column, int& FirstPlayerChoice, int& SecondPlayerChoice, victory VictoryCheck)
{
	string Restart = "yes";

	while (Restart == "yes" || Restart == "Yes" || Restart == "+" || Restart == "y" || Restart == "Y")
	{
		bool flag = false;
		char space[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };
		for (int first_player = 0; first_player < 5; first_player++)
		{
			if (flag == true)
			{
				break;
			}
			int second_player = first_player;

			Fchoice(space, row, column, FirstPlayerChoice, VictoryCheck);

			if (space[0][0] == space[0][1] &&
				space[0][1] == space[0][2] &&
				space[0][2] == 'O' ||
				space[0][0] == space[1][0] &&
				space[1][0] == space[2][0] &&
				space[2][0] == 'O' ||
				space[0][0] == space[1][1] &&
				space[1][1] == space[2][2] &&
				space[2][2] == 'O' ||
				space[0][1] == space[1][1] &&
				space[1][1] == space[2][1] &&
				space[2][1] == 'O' ||
				space[0][2] == space[1][2] &&
				space[1][2] == space[2][2] &&
				space[2][2] == 'O' ||
				space[1][0] == space[1][1] &&
				space[1][1] == space[1][2] &&
				space[1][2] == 'O' ||
				space[2][0] == space[2][1] &&
				space[2][1] == space[2][2] &&
				space[2][2] == 'O' ||
				space[0][2] == space[1][1] &&
				space[1][1] == space[2][0] &&
				space[2][0] == 'O')
			{
				VictoryCheck.FirstPlayer();
				VictoryCheck.FirstPlayerWins++;
				PVS(VictoryCheck);
				break;
			}
			else if (space[0][0] == space[0][1] &&
				space[0][1] == space[0][2] &&
				space[0][2] == 'X' ||
				space[0][0] == space[1][0] &&
				space[1][0] == space[2][0] &&
				space[2][0] == 'X' ||
				space[0][0] == space[1][1] &&
				space[1][1] == space[2][2] &&
				space[2][2] == 'X' ||
				space[0][1] == space[1][1] &&
				space[1][1] == space[2][1] &&
				space[2][1] == 'X' ||
				space[0][2] == space[1][2] &&
				space[1][2] == space[2][2] &&
				space[2][2] == 'X' ||
				space[1][0] == space[1][1] &&
				space[1][1] == space[1][2] &&
				space[1][2] == 'X' ||
				space[2][0] == space[2][1] &&
				space[2][1] == space[2][2] &&
				space[2][2] == 'X' ||
				space[0][2] == space[1][1] &&
				space[1][1] == space[2][0] &&
				space[2][0] == 'X')
			{
				VictoryCheck.SecondPlayer();
				VictoryCheck.SecondPlayerWins++;
				PVS(VictoryCheck);
				break;
			}
			else if (flag == false && first_player == 4)
			{
				cout << " *** YOUR MATCH IS TIE *** " << endl << "------------------------" << endl << endl;
				board(space);
				PVS(VictoryCheck);
			}

			while (second_player < 4)
			{
				Schoice(space, row, column, SecondPlayerChoice, VictoryCheck);

				if (space[0][0] == space[0][1] &&
					space[0][1] == space[0][2] &&
					space[0][2] == 'O' ||
					space[0][0] == space[1][0] &&
					space[1][0] == space[2][0] &&
					space[2][0] == 'O' ||
					space[0][0] == space[1][1] &&
					space[1][1] == space[2][2] &&
					space[2][2] == 'O' ||
					space[0][1] == space[1][1] &&
					space[1][1] == space[2][1] &&
					space[2][1] == 'O' ||
					space[0][2] == space[1][2] &&
					space[1][2] == space[2][2] &&
					space[2][2] == 'O' ||
					space[1][0] == space[1][1] &&
					space[1][1] == space[1][2] &&
					space[1][2] == 'O' ||
					space[2][0] == space[2][1] &&
					space[2][1] == space[2][2] &&
					space[2][2] == 'O' ||
					space[0][2] == space[1][1] &&
					space[1][1] == space[2][0] &&
					space[2][0] == 'O')
				{
					VictoryCheck.FirstPlayer();
					VictoryCheck.FirstPlayerWins++;
					PVS(VictoryCheck);
					flag = true;
					break;
				}
				else if (space[0][0] == space[0][1] &&
					space[0][1] == space[0][2] &&
					space[0][2] == 'X' ||
					space[0][0] == space[1][0] &&
					space[1][0] == space[2][0] &&
					space[2][0] == 'X' ||
					space[0][0] == space[1][1] &&
					space[1][1] == space[2][2] &&
					space[2][2] == 'X' ||
					space[0][1] == space[1][1] &&
					space[1][1] == space[2][1] &&
					space[2][1] == 'X' ||
					space[0][2] == space[1][2] &&
					space[1][2] == space[2][2] &&
					space[2][2] == 'X' ||
					space[1][0] == space[1][1] &&
					space[1][1] == space[1][2] &&
					space[1][2] == 'X' ||
					space[2][0] == space[2][1] &&
					space[2][1] == space[2][2] &&
					space[2][2] == 'X' ||
					space[0][2] == space[1][1] &&
					space[1][1] == space[2][0] &&
					space[2][0] == 'X')
				{
					VictoryCheck.SecondPlayer();
					VictoryCheck.SecondPlayerWins++;
					PVS(VictoryCheck);
					flag = true;
					break;
				}
				break;
			}
		}
		cout << "Do you want to Restart The Game (Yes or No): ";
		cin >> Restart;
	}
	
}


