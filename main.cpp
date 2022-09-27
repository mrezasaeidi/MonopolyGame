#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <Windows.h>
#include <iomanip>
using namespace std;

struct he
{
	vector <int> ho;
};

int player[4][6], pri[4], house[40][4], step = 0, remaining = 4, prison[4] = { 0,0,0,0 };
char name[4][20];
he houses[4];
string ans;
bool status[4] = { true, true, true, true };

void deal(int h);
void lose(int m);
void sell(int n);
void jail(int k);
void pay(int n);
void print(int n);
void white_houses(int n);
void hotel(int n);

int main()
{
	int a[4], b[4], dice;
	srand(time(0));
	cout << "Welcome";
	Sleep(500);
	cout << " .";
	Sleep(500);
	cout << " .";
	Sleep(500);
	cout << " .";
	Sleep(500);
	system("cls");
	Sleep(500);
	cout << "to";
	Sleep(500);
	cout << " .";
	Sleep(500);
	cout << " .";
	Sleep(500);
	cout << " .";
	Sleep(500);
	system("cls");
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdout == INVALID_HANDLE_VALUE)
	{
		cout << "Error while getting input handle" << endl;
		return EXIT_FAILURE;
	}
	SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << endl;
	cout << "   @     @  @@@@  @    @  @@@@  @@@@@   @@@@  @     @     @\n";
	cout << "   @@   @@ @    @ @@   @ @    @ @    @ @    @ @      @   @\n";
	cout << "   @ @ @ @ @    @ @ @  @ @    @ @    @ @    @ @       @ @\n";
	cout << "   @  @  @ @    @ @  @ @ @    @ @@@@@  @    @ @        @\n";
	cout << "   @     @ @    @ @   @@ @    @ @      @    @ @        @\n";
	cout << "   @     @  @@@@  @    @  @@@@  @       @@@@  @@@@@@   @\n";
	SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << "\n\n\n";
	while (true)
	{
		HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hStdout == INVALID_HANDLE_VALUE)
		{
			cout << "Error while getting input handle" << endl;
			return EXIT_FAILURE;
		}
		SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\nPress \"S\" and then \"Enter\" to start the game:\n";
		SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cin >> ans;
		if (ans == "S" || ans == "s")
			break;
		else
			cout << "invalid, Please enter again:\n";
	}
	system("cls");
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 6; j++)
		{
			if (j == 1)
				player[i][1] = 2000;
			else
				player[i][j] = 0;
		}
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (j == 0)
				house[i][0] = i;
			else if (j == 2)
				house[i][2] = 5;
			else
				house[i][j] = 0;
		}
	}
	house[1][1] = house[3][1] = 60;
	house[6][1] = house[8][1] = 100;
	house[9][1] = house[13][1] = 120;
	house[11][1] = 140;
	house[14][1] = 160;
	house[16][1] = house[17][1] = 180;
	house[19][1] = 200;
	house[21][1] = house[23][1] = 220;
	house[24][1] = 240;
	house[26][1] = house[28][1] = 260;
	house[29][1] = 280;
	house[31][1] = house[32][1] = 300;
	house[34][1] = 320;
	house[37][1] = 350;
	house[39][1] = 400;
	house[5][1] = house[12][1] = house[15][1] = house[25][1] = house[27][1] = house[35][1] = house[38][1] = 200;
	for (int i = 0; i < 4; i++)
	{
		cout << "Player " << i + 1 << " Please Enter Your Name:\n";
		cin >> name[i];
	}
	do
	{
		for (int i = 0; i < 4; i++)
			a[i] = b[i] = rand() % 6 + 1;
	} while (b[0] == b[1] || b[0] == b[2] || b[0] == b[3] || b[1] == b[2] || b[1] == b[3] || b[2] == b[3]);
	cout << endl;
	for (int i = 0; i < 4; i++)
		cout << name[i] << "'s Dice is : " << b[i] << endl;
	cout << "\nPlaying priority is randomly set by dice number. \n\n";
	for (int i = 0; i < 3; i++)
		for (int j = 1; j < 4; j++)
			if (a[j]<a[j - 1])
				swap(a[j], a[j - 1]);
	for (int i = 0; i < 4; i++)
	{
		if (a[3] == b[i])
		{
			pri[0] = i;
			continue;
		}
		if (a[2] == b[i])
		{
			pri[1] = i;
			continue;
		}
		if (a[1] == b[i])
		{
			pri[2] = i;
			continue;
		}
		if (a[0] == b[i])
		{
			pri[3] = i;
			continue;
		}
	}
	cout << "So " << name[pri[0]] << " Plays first" << endl;
	for (int i = 1; i < 4; i++)
		cout << name[pri[i]] << " Plays after" << endl;
	while (true)
	{
		HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hStdout == INVALID_HANDLE_VALUE)
		{
			cout << "Error while getting input handle" << endl;
			return EXIT_FAILURE;
		}
		SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\nPress \"S\" and then \"Enter\" to start the game:\n";
		SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cin >> ans;
		if (ans == "S" || ans == "s")
			break;
		else
			cout << "invalid, Please enter again:\n";
	}
	while (remaining != 1)
	{
		if (status[pri[step]] == false)
		{
			step++;
			if (step>3)
				step = 0;
			continue;
		}
		if (player[pri[step]][5] == 1 && prison[pri[step]] < 2)
		{
			prison[pri[step]]++;
			step++;
			if (step > 3)
				step = 0;
			continue;
		}
		else if (player[pri[step]][5] == 1 && prison[pri[step]] == 2)
		{
			player[pri[step]][5] = 0;
			prison[pri[step]] = 0;
		}
		system("cls");
		print(pri[step]);
		HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hStdout == INVALID_HANDLE_VALUE)
		{
			cout << "Error while getting input handle" << endl;
			return EXIT_FAILURE;
		}
		SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\nPress \"D\" and then \"Enter\" to throw Dice\n";
		SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		for (;;)
		{
			string in_dice;
			cin >> in_dice;
			if (in_dice == "D" || in_dice == "d")
				break;
			else
				cout << "invalid, Please enter again: \n";
		}
		dice = (rand() % 6) + 1;
		cout << "Your Dice Number is " << dice << endl;
		_sleep(2000);
		player[pri[step]][0] += dice;
		if (player[pri[step]][0] >= 40)
		{
			player[pri[step]][0] -= 40;
			player[pri[step]][1] += 200;
			cout << (player[pri[step]][0] == 40 ? "You are on the beginning point" : "You passed the beginning point") << "so You are 200 coins awarded!\n";
			_sleep(1000);
		}
		system("cls");
		print(pri[step]);
		switch (player[pri[step]][0])
		{
		case 0:
			break;
		case 1:
			cout << "You are on a Pink House worthing 60 coins. \n";
			pay(pri[step]);
			break;
		case 2:
			white_houses(pri[step]);
			break;
		case 3:
			cout << "You are on a Pink House worthing 60 coins. \n";
			pay(pri[step]);
			break;
		case 4:
			white_houses(pri[step]);
			break;
		case 5:
			cout << "You are on a Black House worthing 200 coins. \n";
			pay(pri[step]);
			break;
		case 6:
			cout << "You are on a Green House worthing 100 coins. \n";
			pay(pri[step]);
			break;
		case 7:
			cout << "You are in the park, Have Fun !\n";
			break;
		case 8:
			cout << "You are on a Green House worthing 100 coins. \n";
			pay(pri[step]);
			break;
		case 9:
			cout << "You are on a Green House worthing 120 coins. \n";
			pay(pri[step]);
			break;
		case 10:
			cout << "You are in the park, Have Fun !\n";
			break;
		case 11:
			cout << "You are on a Red House worthing 140 coins. \n";
			pay(pri[step]);
			break;
		case 12:
			cout << "You are on a Black House worthing 200 coins. \n";
			pay(pri[step]);
			break;
		case 13:
			cout << "You are on a Red House worthing 140 coins. \n";
			pay(pri[step]);
			break;
		case 14:
			cout << "You are on a Red House worthing 160 coins. \n";
			pay(pri[step]);
			break;
		case 15:
			cout << "You are on a Black House worthing 200 coins. \n";
			pay(pri[step]);
			break;
		case 16:
			cout << "You are on an Orange House worthing 180 coins. \n";
			pay(pri[step]);
			break;
		case 17:
			cout << "You are on an Orange House worthing 180 coins. \n";
			pay(pri[step]);
			break;
		case 18:
			white_houses(pri[step]);
			break;
		case 19:
			cout << "You are on an Orange House worthing 200 coins. \n";
			pay(pri[step]);
			break;
		case 20:
			jail(pri[step]);
			break;
		case 21:
			cout << "You are on a Purple House worthing 220 coins. \n";
			pay(pri[step]);
			break;
		case 22:
			cout << "You are in the park, Have Fun !\n";
			break;
		case 23:
			cout << "You are on a Purple House worthing 220 coins. \n";
			pay(pri[step]);
			break;
		case 24:
			cout << "You are on a Purple House worthing 240 coins. \n";
			pay(pri[step]);
			break;
		case 25:
			cout << "You are on a Black House worthing 200 coins. \n";
			pay(pri[step]);
			break;
		case 26:
			cout << "You are on a Blue House worthing 260 coins. \n";
			pay(pri[step]);
			break;
		case 27:
			cout << "You are on a Black House worthing 200 coins. \n";
			pay(pri[step]);
			break;
		case 28:
			cout << "You are on a Blue House worthing 260 coins. \n";
			pay(pri[step]);
			break;
		case 29:
			cout << "You are on a Blue House worthing 280 coins. \n";
			pay(pri[step]);
			break;
		case 30:
			cout << "you should pay 100 coins as tax\n";
			player[pri[step]][1] -= 100;
			lose(pri[step]);
			break;
		case 31:
			cout << "You are on a Yellow House worthing 300 coins. \n";
			pay(pri[step]);
			break;
		case 32:
			cout << "You are on a Yellow House worthing 300 coins. \n";
			pay(pri[step]);
			break;
		case 33:
			white_houses(pri[step]);
			break;
		case 34:
			cout << "You are on a Yellow House worthing 320 coins. \n";
			pay(pri[step]);
			break;
		case 35:
			cout << "You are on a Black House worthing 200 coins. \n";
			pay(pri[step]);
			break;
		case 36:
			cout << "You are in the park, Have Fun !\n";
			break;
		case 37:
			cout << "You are on a Grey House worthing 350 coins. \n";
			pay(pri[step]);
			break;
		case 38:
			cout << "You are on a Black House worthing 200 coins. \n";
			pay(pri[step]);
			break;
		case 39:
			cout << "You are on a Grey House worthing 400 coins. \n";
			pay(pri[step]);
			break;
		}
		while (true)
		{
			HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
			if (hStdout == INVALID_HANDLE_VALUE)
			{
				cout << "Error while getting input handle" << endl;
				return EXIT_FAILURE;
			}
			SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "Enter \"C\" to continue: \n";
			SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cin >> ans;
			if (ans == "c" || ans == "C")
				break;
			else
				cout << "invalid, Please enter again: \n";
		}
		step++;
		if (step>3)
			step = 0;
	}
	for (int i = 0; i < 4; i++)
	{
		if (status[pri[i]] == true)
		{
			HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
			if (hStdout == INVALID_HANDLE_VALUE)
			{
				cout << "Error while getting input handle" << endl;
				return EXIT_FAILURE;
			}
			SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n\n**** " << name[pri[i]] << " congradulations! you win ****\n\n";
			SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			break;
		}
	}
	return 0;
}

void deal(int h)
{
	int max = 0, winer, t[4];
	for (int j = 0; j < 4; j++)
	{
		if (status[pri[j]])
		{
			while (true)
			{
				cout << name[pri[j]] << " Please enter Your Offered Price\n";
				cin >> t[pri[j]];
				if (t[pri[j]] <= 0)
					cout << "invalid, ";
				else
					break;
			}
			if (t[pri[j]] > max)
			{
				max = t[pri[j]];
				winer = pri[j];
			}
		}
		else
			continue;
	}
	player[winer][1] -= max;
	houses[winer].ho.push_back(h);
	house[h][2] = winer;
	player[winer][2]++;
	if (h == 5 || h == 12 || h == 15 || h == 25 || h == 27 || h == 35 || h == 38)
		player[winer][4]++;
	cout << endl << name[winer] << " You won the deal, and bought this house by " << max << " Coins.\n";
	lose(winer);
	hotel(winer);
}

void lose(int m)
{
	if (player[m][1] < 0 && player[m][2] == 0 && status[m] == true)
	{
		HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		/*if (hStdout == INVALID_HANDLE_VALUE)
		{
		cout << "Error while getting input handle" << endl;
		return EXIT_FAILURE;
		}*/
		SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << name[m] << " you ran out of coins and dont have any house left! Sorry you lost.\n";
		SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		remaining--;
		status[m] = false;
	}
	else if (player[m][1] < 0 && player[m][2] != 0)
		sell(m);
}

void sell(int n)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	/*if (hStdout == INVALID_HANDLE_VALUE)
	{
	cout << "Error while getting input handle" << endl;
	return EXIT_FAILURE;
	}*/
	SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << name[n] << " you ran out of coins, you have to sell one of your houses.\n";
	SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	while (true)
	{
		int z;
		cout << "\nYour have houses number:\n";
		for (int i = 0; i < houses[n].ho.size(); i++)
			cout << houses[n].ho[i] << "\t";
		cout << "\nPlease enter the Number of House that You want to sell:\n";
		cin >> z;
		if (house[z][2] == n)
		{
			if (z == 5 || z == 12 || z == 15 || z == 25 || z == 27 || z == 35 || z == 38)
				player[n][4]--;
			player[n][1] += house[z][1];
			cout << "You earned " << house[z][1] << " Coins by selling this house.\n";
			house[z][2] = 5;
			player[n][2]--;
			for (int j = 0; j < houses[n].ho.size(); j++)
				if (houses[n].ho[j] == z)
				{
					houses[n].ho[j] = houses[n].ho[houses[n].ho.size() - 1];
					houses[n].ho.pop_back();
					break;
				}
			break;
		}
		else
			cout << name[n] << " Entered Number is not Your House. Please enter another Number: \n";
	}
	lose(n);
	hotel(n);
}

void jail(int k)
{
	cout << name[k] << "You're in Jail ! \n";
	if (player[k][3] > 0)
	{
		player[k][3]--;
		cout << "You have " << player[k][3] + 1 << " vouchers, we decrease one, and you will be free. \n";
	}
	else
	{
		while (true)
		{
			cout << "Do you want to pay 200 coins to get free? (Yes/No) \n";
			cin >> ans;
			if (ans == "Yes" || ans == "yes" || ans == "YES" || ans == "yES" || ans == "yEs" || ans == "yeS" || ans == "YeS" || ans == "YEs" || ans == "Y" || ans == "y")
			{
				player[k][1] -= 200;
				cout << "You are free! \n";
				lose(k);
				break;
			}
			else if (ans == "No" || ans == "no" || ans == "NO" || ans == "nO" || ans == "n" || ans == "N")
			{
				player[k][5] = 1;
				cout << "So You won't play for two rounds. \n";
				break;
			}
			else
				cout << "invalid\n";
		}
	}
}

void pay(int n)
{
	int l = player[n][0];
	if (house[l][2] == 5)
	{
		while (true)
		{
			cout << name[n] << ", this House does not owe to anyone" << " do you want to buy it?(yes/no)\n";
			cin >> ans;
			if (ans == "Yes" || ans == "yes" || ans == "YES" || ans == "yES" || ans == "yEs" || ans == "yeS" || ans == "YeS" || ans == "YEs" || ans == "Y" || ans == "y")
			{
				player[n][1] -= house[l][1];
				houses[n].ho.push_back(house[l][0]);
				house[l][2] = n;
				player[n][2]++;
				if (l == 5 || l == 12 || l == 15 || l == 25 || l == 27 || l == 35 || l == 38)
					player[n][4]++;
				lose(n);
				hotel(n);
				break;
			}
			else if (ans == "No" || ans == "no" || ans == "NO" || ans == "nO" || ans == "n" || ans == "N")
			{
				cout << "So this house will be sold to the top offered price.\n";
				deal(house[l][0]);
				break;
			}
			else
				cout << "invalid, Please enter again:\n";
		}
	}
	else if (house[l][2] != n && house[l][2] != 5)
	{
		if (l == 5 || l == 12 || l == 15 || l == 25 || l == 27 || l == 35 || l == 38)
		{
			player[n][1] -= player[house[l][2]][4] * 50;
			player[house[l][2]][1] += player[house[l][2]][4] * 50;
			cout << name[n] << " This house already has an owner, so you paid " << player[house[l][2]][4] * 50 << " Coins as rent to " << name[house[l][2]] << ".\n";
			lose(n);
		}
		else if (house[l][3] == 1)
		{
			switch (l)
			{
			case 6:
			case 8:
			case 9:
				player[n][1] -= 160;
				player[house[6][2]][1] += 160;
				cout << name[n] << " This house already has an owner, so you paid 160 coins as rent to " << name[house[l][2]] << ".\n";
				lose(n);
				break;
			case 11:
			case 13:
			case 14:
				player[n][1] -= 220;
				player[house[11][2]][1] += 220;
				cout << name[n] << " This house already has an owner, so you paid 220 coins as rent to " << name[house[l][2]] << ".\n";
				lose(n);
				break;
			case 16:
			case 17:
			case 19:
				player[n][1] -= 280;
				player[house[16][2]][1] += 280;
				cout << name[n] << " This house already has an owner, so you paid 280 coins as rent to " << name[house[l][2]] << ".\n";
				lose(n);
				break;
			case 21:
			case 23:
			case 24:
				player[n][1] -= 340;
				player[house[21][2]][1] += 340;
				cout << name[n] << " This house already has an owner, so you paid 340 coins as rent to " << name[house[l][2]] << ".\n";
				lose(n);
				break;
			case 26:
			case 28:
			case 29:
				player[n][1] -= 400;
				player[house[26][2]][1] += 400;
				cout << name[n] << " This house already has an owner, so you paid 400 coins as rent to " << name[house[l][2]] << ".\n";
				lose(n);
				break;
			case 31:
			case 32:
			case 34:
				player[n][1] -= 460;
				player[house[31][2]][1] += 460;
				cout << name[n] << " This house already has an owner, so you paid 460 coins as rent to " << name[house[l][2]] << ".\n";
				lose(n);
				break;
			}
		}
		else
		{
			player[n][1] -= (house[l][1] / 2);
			player[house[l][2]][1] += (house[l][1] / 2);
			cout << name[n] << " This house already has an owner, so you paid " << house[l][1] / 2 << " coins as rent to " << name[house[l][2]] << ".\n";
			lose(n);
		}
	}
}

void print(int n)
{
	cout << "  ____________________________________________________________________________" << endl;
	cout << " |        Name        |Location| Money |Houses count|Vouchers count|  status  |" << endl;
	cout << " |____________________|________|_______|____________|______________|__________|" << endl;
	cout << " |" << setw(20) << setfill(' ') << name[pri[0]] << "|" << setw(8) << setfill(' ') << player[pri[0]][0] << "|" << setw(7) << setfill(' ') << player[pri[0]][1] << "|" << setw(12) << setfill(' ') << player[pri[0]][2] << "|" << setw(14) << setfill(' ') << player[pri[0]][3] << "|" << setw(10) << setfill(' ') << (status[pri[0]] ? "playing" : "failed") << "|" << endl;
	cout << " |____________________|________|_______|____________|______________|__________|" << endl;
	cout << " |" << setw(20) << setfill(' ') << name[pri[1]] << "|" << setw(8) << setfill(' ') << player[pri[1]][0] << "|" << setw(7) << setfill(' ') << player[pri[1]][1] << "|" << setw(12) << setfill(' ') << player[pri[1]][2] << "|" << setw(14) << setfill(' ') << player[pri[1]][3] << "|" << setw(10) << setfill(' ') << (status[pri[1]] ? "playing" : "failed") << "|" << endl;
	cout << " |____________________|________|_______|____________|______________|__________|" << endl;
	cout << " |" << setw(20) << setfill(' ') << name[pri[2]] << "|" << setw(8) << setfill(' ') << player[pri[2]][0] << "|" << setw(7) << setfill(' ') << player[pri[2]][1] << "|" << setw(12) << setfill(' ') << player[pri[2]][2] << "|" << setw(14) << setfill(' ') << player[pri[2]][3] << "|" << setw(10) << setfill(' ') << (status[pri[2]] ? "playing" : "failed") << "|" << endl;
	cout << " |____________________|________|_______|____________|______________|__________|" << endl;
	cout << " |" << setw(20) << setfill(' ') << name[pri[3]] << "|" << setw(8) << setfill(' ') << player[pri[3]][0] << "|" << setw(7) << setfill(' ') << player[pri[3]][1] << "|" << setw(12) << setfill(' ') << player[pri[3]][2] << "|" << setw(14) << setfill(' ') << player[pri[3]][3] << "|" << setw(10) << setfill(' ') << (status[pri[3]] ? "playing" : "failed") << "|" << endl;
	cout << " |____________________|________|_______|____________|______________|__________|" << endl;
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	/*if (hStdout == INVALID_HANDLE_VALUE)
	{
	cout << "Error while getting input handle" << endl;
	return EXIT_FAILURE;
	}*/
	SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\nIt's " << name[n] << "'s Turn !\n";
	SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void white_houses(int n)
{
	int which, rand_player;
	which = rand() % 6 + 1;
	cout << "\nYou're on a White House!\n";
	_sleep(1000);
	switch (which)
	{
	case 1:
		cout << "You lost 100 Coins!\n";
		_sleep(1000);
		player[n][1] -= 100;
		lose(n);
		break;
	case 2:
		do {
			rand_player = rand() % 4;
		} while (rand_player == n || status[rand_player] == false);
		cout << "You should pay 50 Coins to " << name[rand_player] << ".\n";
		player[rand_player][1] += 50;
		player[n][1] -= 50;
		lose(n);
		break;
	case 3:
		cout << "You earned 100 Coins!\n";
		player[n][1] += 100;
		break;
	case 4:
		do {
			rand_player = rand() % 4;
		} while (rand_player == n || status[rand_player] == false);
		cout << "You got 100 Coins from " << name[rand_player] << ".\n";
		player[n][1] += 100;
		player[rand_player][1] -= 100;
		lose(rand_player);
		break;
	case 5:
		player[n][0] = 20;
		jail(n);
		break;
	case 6:
		cout << "You got 1 Voucher!\n";
		player[n][3]++;
		break;
	}
}

void hotel(int n)
{
	if (house[6][2] == n && house[9][2] == n && house[8][2] == n)
	{
		if (house[6][3] != 1)
		{
			while (true)
			{
				cout << name[n] << " you can build a green hotel by paying 320 coins, would you want to? (yes/no)\n";
				cin >> ans;
				if (ans == "Yes" || ans == "yes" || ans == "YES" || ans == "yES" || ans == "yEs" || ans == "yeS" || ans == "YeS" || ans == "YEs" || ans == "Y" || ans == "y")
				{
					player[n][1] -= (house[6][1] + house[8][1] + house[9][1]);
					house[6][3] = house[8][3] = house[9][3] = 1;
					lose(n);
					break;
				}
				else if (ans == "No" || ans == "no" || ans == "NO" || ans == "nO" || ans == "n" || ans == "N")
					break;
				else
					cout << "Invalid, please enter again: \n";
			}
		}
	}
	else
		house[6][3] = house[8][3] = house[9][3] = 0;
	if (house[11][2] == n && house[14][2] == n && house[13][2] == n)
	{
		if (house[11][3] != 1)
		{
			while (true)
			{
				cout << name[n] << " you can build a red hotel by paying 440 coins, would you want to? (yes/no)\n";
				cin >> ans;
				if (ans == "Yes" || ans == "yes" || ans == "YES" || ans == "yES" || ans == "yEs" || ans == "yeS" || ans == "YeS" || ans == "YEs" || ans == "Y" || ans == "y")
				{
					player[n][1] -= (house[11][1] + house[13][1] + house[14][1]);
					house[11][3] = house[13][3] = house[14][3] = 1;
					lose(n);
					break;
				}
				else if (ans == "No" || ans == "no" || ans == "NO" || ans == "nO" || ans == "n" || ans == "N")
					break;
				else
					cout << "Invalid, please enter again: \n";
			}
		}
	}
	else
		house[11][3] = house[13][3] = house[14][3] = 0;
	if (house[16][2] == n && house[19][2] == n && house[17][2] == n)
	{
		if (house[16][3] != 1)
		{
			while (true)
			{
				cout << name[n] << " you can build an orange hotel by paying 560 coins, would you want to? (yes/no)\n";
				cin >> ans;
				if (ans == "Yes" || ans == "yes" || ans == "YES" || ans == "yES" || ans == "yEs" || ans == "yeS" || ans == "YeS" || ans == "YEs" || ans == "Y" || ans == "y")
				{
					player[n][1] -= (house[16][1] + house[17][1] + house[19][1]);
					house[16][3] = house[17][3] = house[19][3] = 1;
					lose(n);
					break;
				}
				else if (ans == "No" || ans == "no" || ans == "NO" || ans == "nO" || ans == "n" || ans == "N")
					break;
				else
					cout << "Invalid, please enter again: \n";
			}
		}
	}
	else
		house[16][3] = house[17][3] = house[19][3] = 0;
	if (house[21][2] == n && house[24][2] == n && house[23][2] == n)
	{
		if (house[21][3] != 1)
		{
			while (true)
			{
				cout << name[n] << " you can build a purple hotel by paying 680 coins, would you want to? (yes/no)\n";
				cin >> ans;
				if (ans == "Yes" || ans == "yes" || ans == "YES" || ans == "yES" || ans == "yEs" || ans == "yeS" || ans == "YeS" || ans == "YEs" || ans == "Y" || ans == "y")
				{
					player[n][1] -= (house[21][1] + house[23][1] + house[24][1]);
					house[21][3] = house[23][3] = house[24][3] = 1;
					lose(n);
					break;
				}
				else if (ans == "No" || ans == "no" || ans == "NO" || ans == "nO" || ans == "n" || ans == "N")
					break;
				else
					cout << "Invalid, please enter again: \n";
			}
		}
	}
	else
		house[21][3] = house[23][3] = house[24][3] = 0;
	if (house[26][2] == n && house[29][2] == n && house[28][2] == n)
	{
		if (house[26][3] != 1)
		{
			while (true)
			{
				cout << name[n] << " you can build a blue hotel by paying 800 coins, would you want to? (yes/no)\n";
				cin >> ans;
				if (ans == "Yes" || ans == "yes" || ans == "YES" || ans == "yES" || ans == "yEs" || ans == "yeS" || ans == "YeS" || ans == "YEs" || ans == "Y" || ans == "y")
				{
					player[n][1] -= (house[26][1] + house[28][1] + house[29][1]);
					house[26][3] = house[28][3] = house[29][3] = 1;
					lose(n);
					break;
				}
				else if (ans == "No" || ans == "no" || ans == "NO" || ans == "nO" || ans == "n" || ans == "N")
					break;
				else
					cout << "Invalid, please enter again: \n";
			}
		}
	}
	else
		house[26][3] = house[28][3] = house[29][3] = 0;
	if (house[31][2] == n && house[34][2] == n && house[32][2] == n)
	{
		if (house[31][3] != 1)
		{
			while (true)
			{
				cout << name[n] << " you can build a yellow hotel by paying 920 coins, would you want to? (yes/no)\n";
				cin >> ans;
				if (ans == "Yes" || ans == "yes" || ans == "YES" || ans == "yES" || ans == "yEs" || ans == "yeS" || ans == "YeS" || ans == "YEs" || ans == "Y" || ans == "y")
				{
					player[n][1] -= (house[31][1] + house[32][1] + house[34][1]);
					house[31][3] = house[32][3] = house[34][3] = 1;
					lose(n);
					break;
				}
				else if (ans == "No" || ans == "no" || ans == "NO" || ans == "nO" || ans == "n" || ans == "N")
					break;
				else
					cout << "Invalid, please enter again: \n";
			}
		}
	}
	else
		house[31][3] = house[32][3] = house[34][3] = 0;
}
