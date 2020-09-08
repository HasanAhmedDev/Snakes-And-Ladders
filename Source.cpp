#include<iostream>
#include<fstream>
#include"mygraphics.h"
#include"myconsole.h"
#include <conio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
void save(int pos1, int pos2, int p1score, int p1gold, int p1silver, int p1diamond, int p1sword, int p1shield, int p2score, int p2gold, int p2silver, int p2diamond, int p2sword, int p2shield, int boardprison[], int boardgold[], int boardsilver[], int boarddiamond[], int boardsword[], int boardshield[], int boardsnake[][4], int boardladder[][4])
{
	ofstream fout;
	fout.open("Save.txt");
	fout << pos1 << ' ' << pos2 << endl;
	fout << p1score << ' ' << p1gold << ' ' << p1silver << ' ' << p1diamond << ' ' << p1sword << ' ' << p1shield << endl;
	fout << p2score << ' ' << p2gold << ' ' << p2silver << ' ' << p2diamond << ' ' << p2sword << ' ' << p2shield << endl;
	for (int i = 0; i < 4; i++)
		fout << boardprison[i] << ' ';
	fout << endl;
	for (int i = 0; i < 4; i++)
		fout << boardgold[i] << ' ';
	fout << endl;
	for (int i = 0; i < 4; i++)
		fout << boardsilver[i] << ' ';
	fout << endl;
	for (int i = 0; i < 4; i++)
		fout << boarddiamond[i] << ' ';
	fout << endl;
	for (int i = 0; i < 4; i++)
		fout << boardsword[i] << ' ';
	fout << endl;
	for (int i = 0; i < 4; i++)
		fout << boardshield[i] << ' ';
	fout << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
			fout << boardsnake[i][j] << ' ';
		fout << endl;
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
			fout << boardladder[i][j] << ' ';
		fout << endl;
	}
	fout << endl;
	fout.close();
	myDrawTextWithFont(200, 200, 100, "Game Saved", RGB(255, 255, 255), RGB(0, 0, 0));
}
void load(int &pos1, int&pos2, int &p1score, int &p1gold, int &p1silver, int &p1diamond, int &p1sword, int &p1shield, int &p2score, int &p2gold, int &p2silver, int &p2diamond, int &p2sword, int &p2shield, int boardprison[], int boardgold[], int boardsilver[], int boarddiamond[], int boardsword[], int boardshield[], int boardsnake[][4], int boardladder[][4])
{
	ifstream fin;
	fin.open("Save.txt");
	fin >> pos1;
	fin >> pos2;
	fin >> p1score;
	fin >> p1gold;
	fin >> p1silver;
	fin >> p1diamond;
	fin >> p1sword;
	fin >> p1shield;
	fin >> p2score;
	fin >> p2gold;
	fin >> p2silver;
	fin >> p2diamond;
	fin >> p2sword;
	fin >> p2shield;
	for (int i = 0; i < 4; i++)
		fin >> boardprison[i];
	for (int i = 0; i < 4; i++)
		fin >> boardgold[i];
	for (int i = 0; i < 4; i++)
		fin >> boardsilver[i];
	for (int i = 0; i < 4; i++)
		fin >> boarddiamond[i];
	for (int i = 0; i < 4; i++)
		fin >> boardsword[i];
	for (int i = 0; i < 4; i++)
		fin >> boardshield[i];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
			fin >> boardsnake[i][j];
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
			fin >> boardladder[i][j];
	}
	fin.close();
}

bool randFound(int no, int objects[])
{
	//return false;
	for (int i = 0; i < 40; ++i)
	{
		if (objects[i] == -1)
			i = 40;
		else if (no == objects[i])
			return true;
	}
	return false;
}

void randomgold(int objects[])
{
	int num = 2;
	for (int i = 0; i < 4; i++)
	{
		srand(time(NULL));
		int rnum = (rand() % 23) + num;
		objects[i] = rnum;
		num += 25;
	}
}
void randomsilver(int objects[])
{
	int num = 2;
	int rnum = 0;
	for (int i = 4; i < 8; i++)
	{
		srand(time(NULL) + i);
		rnum = (rand() % 23) + num;
		while (randFound(rnum, objects))
		{
			srand(time(NULL) + i + 1);
			rnum = (rand() % 23) + num;
		}
		objects[i] = rnum;
		num += 25;
	}
}
void randomdiamond(int objects[])
{

	int num = 2;
	int rnum = 0;
	for (int i = 8; i < 12; i++)
	{
		srand(time(NULL) + i);
		rnum = (rand() % 23) + num;
		while (randFound(rnum, objects))
		{
			srand(time(NULL) + i + 1);
			rnum = (rand() % 23) + num;
		}
		objects[i] = rnum;
		num += 25;
	}
}
void randomsword(int objects[])
{
	int num = 2;
	int rnum = 0;
	for (int i = 12; i < 16; i++)
	{
		srand(time(NULL) + i);
		rnum = (rand() % 23) + num;
		while (randFound(rnum, objects))
		{
			srand(time(NULL) + i + 1);
			rnum = (rand() % 23) + num;
		}
		objects[i] = rnum;
		num += 25;
	}
}
void randomshield(int objects[])
{
	int num = 2;
	int rnum = 0;
	for (int i = 16; i < 20; i++)
	{
		srand(time(NULL) + i);
		rnum = (rand() % 23) + num;
		while (randFound(rnum, objects))
		{
			srand(time(NULL) + i + 1);
			rnum = (rand() % 23) + num;
		}
		objects[i] = rnum;
		num += 25;
	}
}
void randomprison(int objects[])
{
	int num = 2;
	int rnum = 0;
	for (int i = 20; i < 24; i++)
	{
		srand(time(NULL) + i);
		rnum = (rand() % 23) + num;
		while (randFound(rnum, objects))
		{
			srand(time(NULL) + i + 1);
			rnum = (rand() % 23) + num;
		}
		objects[i] = rnum;
		num += 25;
	}
}
void snakesheads(int objects[])
{
	int num = 90;
	int rnum = 0;
	for (int i = 24; i < 28; i++)
	{
		srand(time(NULL) + i);
		rnum = (rand() % 9) + num;
		while (randFound(rnum, objects))
		{
			srand(time(NULL) + i + 1);
			rnum = (rand() % 9) + num;
		}
		objects[i] = rnum;
		num -= 20;
	}
}
void snakestails(int objects[])
{
	int num = 50;
	int rnum = 0;
	int count1 = 1;
	for (int i = 28; i < 31; i++)
	{
		srand(time(NULL) + i);
		rnum = (rand() % 9) + num;
		while (randFound(rnum, objects))
		{
			srand(time(NULL) + i + 1);
			rnum = (rand() % 9) + num;
		}
		objects[i] = rnum;
		num -= 10;
	}
	srand(time(NULL) + 50);
	rnum = (rand() % 8) + 2;
	while (randFound(rnum, objects))
	{
		srand(time(NULL) + 51);
		rnum = (rand() % 8) + 2;
	}
	objects[31] = rnum;
}
void laddersheads(int objects[])
{
	int num = 90;
	int rnum = 0;
	for (int i = 32; i < 36; i++)
	{
		srand(time(NULL) + i);
		rnum = (rand() % 9) + num;
		while (randFound(rnum, objects))
		{
			srand(time(NULL) + i + 1);
			rnum = (rand() % 9) + num;
		}
		objects[i] = rnum;
		num -= 20;
	}
}
void ladderstails(int objects[])
{
	int num = 50;
	int rnum = 0;
	int count1 = 1;
	for (int i = 36; i < 39; i++)
	{
		srand(time(NULL) + i);
		rnum = (rand() % 9) + num;
		while (randFound(rnum, objects))
		{
			srand(time(NULL) + i + 1);
			rnum = (rand() % 9) + num;
		}
		objects[i] = rnum;
		num -= 10;
	}
	srand(time(NULL) + 52);
	rnum = (rand() % 8) + 2;
	while (randFound(rnum, objects))
	{
		srand(time(NULL) + 53);
		rnum = (rand() % 8) + 2;
	}
	objects[39] = rnum;
}
void drawboard(int xaxis[], int yaxis[], int boardgold[], int boardsilver[], int boarddiamond[], int boardprison[], int boardsword[], int boardshield[], int boardsnake[][4], int boardladder[][4])
{
	for (int i = 0; i < 4; i++)
	{
		int pos = boardgold[i];
		int x = xaxis[pos - 1];
		int y = yaxis[pos - 1];
		if ((pos) % 2 == 0)
			myDrawTextWithFont(x + 7, y - 27, 17, "Gold", RGB(255, 255, 255), RGB(25, 25, 112));
		else
			myDrawTextWithFont(x + 7, y - 27, 17, "Gold", RGB(255, 255, 255), RGB(255, 165, 0));
	}
	for (int i = 0; i < 4; i++)
	{
		int pos = boardsilver[i];
		int x = xaxis[pos - 1];
		int y = yaxis[pos - 1];
		if ((pos) % 2 == 0)
			myDrawTextWithFont(x + 7, y - 27, 17, "Silver", RGB(255, 255, 255), RGB(25, 25, 112));
		else
			myDrawTextWithFont(x + 7, y - 27, 17, "Silver", RGB(255, 255, 255), RGB(255, 165, 0));

	}
	for (int i = 0; i < 4; i++)
	{
		int pos = boarddiamond[i];
		int x = xaxis[pos - 1];
		int y = yaxis[pos - 1];
		if ((pos) % 2 == 0)
			myDrawTextWithFont(x + 7, y - 27, 17, "Diamond", RGB(255, 255, 255), RGB(25, 25, 112));
		else
			myDrawTextWithFont(x + 7, y - 27, 17, "Diamond", RGB(255, 255, 255), RGB(255, 165, 0));
	}
	for (int i = 0; i < 4; i++)
	{
		int pos = boardprison[i];
		int x = xaxis[pos - 1];
		int y = yaxis[pos - 1];
		if ((pos) % 2 == 0)
			myDrawTextWithFont(x + 7, y - 27, 17, "Prison", RGB(255, 255, 255), RGB(25, 25, 112));
		else
			myDrawTextWithFont(x + 7, y - 27, 17, "Prison", RGB(255, 255, 255), RGB(255, 165, 0));
	}
	for (int i = 0; i < 4; i++)
	{
		int pos = boardsword[i];
		int x = xaxis[pos - 1];
		int y = yaxis[pos - 1];
		if ((pos) % 2 == 0)
			myDrawTextWithFont(x + 7, y - 27, 17, "Sword", RGB(255, 255, 255), RGB(25, 25, 112));
		else
			myDrawTextWithFont(x + 7, y - 27, 17, "Sword", RGB(255, 255, 255), RGB(255, 165, 0));

	}
	for (int i = 0; i < 4; i++)
	{
		int pos = boardshield[i];
		int x = xaxis[pos - 1];
		int y = yaxis[pos - 1];
		if ((pos) % 2 == 0)
			myDrawTextWithFont(x + 7, y - 27, 17, "Shield", RGB(255, 255, 255), RGB(25, 25, 112));
		else
			myDrawTextWithFont(x + 7, y - 27, 17, "Shield", RGB(255, 255, 255), RGB(255, 165, 0));
	}
	for (int i = 0; i < 4; i++)
	{
		int pos = boardsnake[1][i];
		int x = xaxis[pos - 1];
		int y = yaxis[pos - 1];
		if (i == 0) {
			if ((pos) % 2 == 0)
				myDrawTextWithFont(x + 7, y - 27, 17, "Snake4H", RGB(255, 255, 255), RGB(25, 25, 112));
			else
				myDrawTextWithFont(x + 7, y - 27, 17, "Snake4H", RGB(255, 255, 255), RGB(255, 165, 0));
		}
		else if (i == 1)
		{
			if ((pos) % 2 == 0)
				myDrawTextWithFont(x + 7, y - 27, 17, "Snake3H", RGB(255, 255, 255), RGB(25, 25, 112));
			else
				myDrawTextWithFont(x + 7, y - 27, 17, "Snake3H", RGB(255, 255, 255), RGB(255, 165, 0));
		}
		else if (i == 2)
		{
			if ((pos) % 2 == 0)
				myDrawTextWithFont(x + 7, y - 27, 17, "Snake2H", RGB(255, 255, 255), RGB(25, 25, 112));
			else
				myDrawTextWithFont(x + 7, y - 27, 17, "Snake2H", RGB(255, 255, 255), RGB(255, 165, 0));
		}
		else if (i == 3)
		{
			if ((pos) % 2 == 0)
				myDrawTextWithFont(x + 7, y - 27, 17, "Snake1H", RGB(255, 255, 255), RGB(25, 25, 112));
			else
				myDrawTextWithFont(x + 7, y - 27, 17, "Snake1H", RGB(255, 255, 255), RGB(255, 165, 0));
		}
	}
	for (int i = 0; i < 4; i++)
	{
		int pos = boardsnake[0][i];
		int x = xaxis[pos - 1];
		int y = yaxis[pos - 1];
		if (i == 0)
		{
			if ((pos) % 2 == 0)
				myDrawTextWithFont(x + 7, y - 27, 17, "Snake4T", RGB(255, 255, 255), RGB(25, 25, 112));
			else
				myDrawTextWithFont(x + 7, y - 27, 17, "Snake4T", RGB(255, 255, 255), RGB(255, 165, 0));
		}
		else if (i == 1)
		{
			if ((pos) % 2 == 0)
				myDrawTextWithFont(x + 7, y - 27, 17, "Snake3T", RGB(255, 255, 255), RGB(25, 25, 112));
			else
				myDrawTextWithFont(x + 7, y - 27, 17, "Snake3T", RGB(255, 255, 255), RGB(255, 165, 0));
		}
		else if (i == 2)
		{
			if ((pos) % 2 == 0)
				myDrawTextWithFont(x + 7, y - 27, 17, "Snake2T", RGB(255, 255, 255), RGB(25, 25, 112));
			else
				myDrawTextWithFont(x + 7, y - 27, 17, "Snake2T", RGB(255, 255, 255), RGB(255, 165, 0));
		}
		else if (i == 3)
		{
			if ((pos) % 2 == 0)
				myDrawTextWithFont(x + 7, y - 27, 17, "Snake1T", RGB(255, 255, 255), RGB(25, 25, 112));
			else
				myDrawTextWithFont(x + 7, y - 27, 17, "Snake1T", RGB(255, 255, 255), RGB(255, 165, 0));
		}
	}
	for (int i = 0; i < 4; i++)
	{
		int pos = boardladder[1][i];
		int x = xaxis[pos - 1];
		int y = yaxis[pos - 1];
		if (i == 0)
		{
			if ((pos) % 2 == 0)
				myDrawTextWithFont(x + 7, y - 27, 17, "Ladder4E", RGB(255, 255, 255), RGB(25, 25, 112));
			else
				myDrawTextWithFont(x + 7, y - 27, 17, "Ladder4E", RGB(255, 255, 255), RGB(255, 165, 0));
		}
		if (i == 1)
		{
			if ((pos) % 2 == 0)
				myDrawTextWithFont(x + 7, y - 27, 17, "Ladder3E", RGB(255, 255, 255), RGB(25, 25, 112));
			else
				myDrawTextWithFont(x + 7, y - 27, 17, "Ladder3E", RGB(255, 255, 255), RGB(255, 165, 0));
		}
		if (i == 2)
		{
			if ((pos) % 2 == 0)
				myDrawTextWithFont(x + 7, y - 27, 17, "Ladder2E", RGB(255, 255, 255), RGB(25, 25, 112));
			else
				myDrawTextWithFont(x + 7, y - 27, 17, "Ladder2E", RGB(255, 255, 255), RGB(255, 165, 0));
		}
		if (i == 3)
		{
			if ((pos) % 2 == 0)
				myDrawTextWithFont(x + 7, y - 27, 17, "Ladder1E", RGB(255, 255, 255), RGB(25, 25, 112));
			else
				myDrawTextWithFont(x + 7, y - 27, 17, "Ladder1E", RGB(255, 255, 255), RGB(255, 165, 0));
		}
	}
	for (int i = 0; i < 4; i++)
	{
		int pos = boardladder[0][i];
		int x = xaxis[pos - 1];
		int y = yaxis[pos - 1];
		if (i == 0)
		{
			if ((pos) % 2 == 0)
				myDrawTextWithFont(x + 7, y - 27, 17, "Ladder4S", RGB(255, 255, 255), RGB(25, 25, 112));
			else
				myDrawTextWithFont(x + 7, y - 27, 17, "Ladder4S", RGB(255, 255, 255), RGB(255, 165, 0));
		}
		if (i == 1)
		{
			if ((pos) % 2 == 0)
				myDrawTextWithFont(x + 7, y - 27, 17, "Ladder3S", RGB(255, 255, 255), RGB(25, 25, 112));
			else
				myDrawTextWithFont(x + 7, y - 27, 17, "Ladder3S", RGB(255, 255, 255), RGB(255, 165, 0));
		}
		if (i == 2)
		{
			if ((pos) % 2 == 0)
				myDrawTextWithFont(x + 7, y - 27, 17, "Ladder2S", RGB(255, 255, 255), RGB(25, 25, 112));
			else
				myDrawTextWithFont(x + 7, y - 27, 17, "Ladder2S", RGB(255, 255, 255), RGB(255, 165, 0));
		}
		if (i == 3)
		{
			if ((pos) % 2 == 0)
				myDrawTextWithFont(x + 7, y - 27, 17, "Ladder1S", RGB(255, 255, 255), RGB(25, 25, 112));
			else
				myDrawTextWithFont(x + 7, y - 27, 17, "Ladder1S", RGB(255, 255, 255), RGB(255, 165, 0));
		}
	}
}
void placegot(int xaxis[], int yaxis[], int &pos, bool player)
{
	if (player)
	{
		int x = xaxis[pos - 1];
		int y = yaxis[pos - 1];
		myEllipse(x + 30, y - 2, x + 30 + 15, y + 13, RGB(151, 2, 36), RGB(151, 2, 36));
	}
	else if (!player)
	{
		int x = xaxis[pos - 1];
		int y = yaxis[pos - 1];
		myEllipse(x + 46, y - 2, x + 46 + 15, y + 13, RGB(0, 0, 0), RGB(0, 0, 0));
	}
}
void putgot1(int xaxis[], int yaxis[], int &pos, int number)
{
	int x = xaxis[pos + number - 1];
	int y = yaxis[pos + number - 1];
	myEllipse(x + 30, y - 2, x + 30 + 15, y + 13, RGB(151, 2, 36), RGB(151, 2, 36));
	int xx = xaxis[pos - 1];
	int yy = yaxis[pos - 1];
	if ((pos) % 2 == 0)
		myEllipse(xx + 30, yy - 2, xx + 30 + 15, yy + 13, RGB(25, 25, 112), RGB(25, 25, 112));
	else
		myEllipse(xx + 30, yy - 2, xx + 30 + 15, yy + 13, RGB(255, 165, 0), RGB(255, 165, 0));
	pos = pos + number;
}
void putgot2(int xaxis[], int yaxis[], int &pos, int number)
{

	int x = xaxis[pos + number - 1];
	int y = yaxis[pos + number - 1];
	myEllipse(x + 46, y - 2, x + 46 + 15, y + 13, RGB(0, 0, 0), RGB(0, 0, 0));
	int xx = xaxis[pos - 1];
	int yy = yaxis[pos - 1];
	if ((pos) % 2 == 0)
		myEllipse(xx + 46, yy - 2, xx + 46 + 15, yy + 13, RGB(25, 25, 112), RGB(25, 25, 112));
	else
		myEllipse(xx + 46, yy - 2, xx + 46 + 15, yy + 13, RGB(255, 165, 0), RGB(255, 165, 0));
	pos = pos + number;
}
int checkkey()
{
	if (_kbhit())
	{
		int a = _getch();
		return a;
	}
}
int main()
{
	int pos1 = 0, pos2 = 0;
	int p1count = 0, p2count = 0;
	int p1score = 0, p1gold = 0, p1silver = 0, p1diamond = 0, p1sword = 0, p1shield = 0;
	int p2score = 0, p2gold = 0, p2silver = 0, p2diamond = 0, p2sword = 0, p2shield = 0;
	int boardprison[4];
	int boardsnake[2][4];
	int boardladder[2][4];
	int boardgold[4];
	int boardsilver[4];
	int boarddiamond[4];
	int boardsword[4];
	int boardshield[4];
	int choice;
	PlaceCursor(119, 0);
	int objects[40] = { -1 };
	randomgold(objects);
	randomsilver(objects);
	randomdiamond(objects);
	randomsword(objects);
	randomshield(objects);
	randomprison(objects);
	snakesheads(objects);
	snakestails(objects);
	laddersheads(objects);
	ladderstails(objects);
	for (int i = 350; i > 0; i -= 1) {
		myDrawTextWithFont(170, i, 100, "Snakes And Ladders", RGB(23, 123, 225), RGB(0, 0, 0));
		int j = 0;
		while (j < 3332222)
		{
			j++;
		}
	}
	for (int i = 0; i < 310; i++)
	{
		myDrawTextWithFont(i, 170, 50, "New Game(Press 1)", RGB(225, 155, 55), RGB(0, 0, 0));
		int j = 0;
		while (j < 3332222)
		{
			j++;
		}
	}
	for (int i = 0; i < 310; i++)
	{
		myDrawTextWithFont(i, 250, 50, "Load Game(Press 0)", RGB(55, 255, 125), RGB(0, 0, 0));
		int j = 0;
		while (j < 3332222)
		{
			j++;
		}

	}
	int checkk = 0;
	while (checkk == 0)
	{
		if (checkkey() == 49) {
			choice = 1;
			checkk = 1;
			myDrawTextWithFont(170, 1, 100, "Snakes And Ladders", RGB(0, 0, 0), RGB(0, 0, 0));
			myDrawTextWithFont(309, 170, 50, "New Game(Press 1)", RGB(0, 0, 0), RGB(0, 0, 0));
			myDrawTextWithFont(309, 250, 50, "Load Game(Press 0)", RGB(0, 0, 0), RGB(0, 0, 0));
		}
		else if (checkkey() == 48) {
			choice = 0;
			checkk = 1;
			myDrawTextWithFont(170, 1, 100, "Snakes And Ladders", RGB(0, 0, 0), RGB(0, 0, 0));
			myDrawTextWithFont(309, 170, 50, "New Game(Press 1)", RGB(0, 0, 0), RGB(0, 0, 0));
			myDrawTextWithFont(309, 250, 50, "Load Game(Press 0)", RGB(0, 0, 0), RGB(0, 0, 0));
		}
	}
	if (choice == 1) {
		for (int i = 0; i < 4; i++)
			boardgold[i] = objects[i];
		for (int i = 4, j = 0; j < 4, i < 8; j++, i++)
			boardsilver[j] = objects[i];
		for (int i = 8, j = 0; j < 4, i < 12; j++, i++)
			boarddiamond[j] = objects[i];
		for (int i = 12, j = 0; j < 4, i < 16; j++, i++)
			boardsword[j] = objects[i];
		for (int i = 16, j = 0; j < 4, i < 20; j++, i++)
			boardshield[j] = objects[i];
		for (int i = 20, j = 0; j < 4, i < 24; j++, i++)
			boardprison[j] = objects[i];
		for (int i = 28, j = 0; j < 4, i < 32; j++, i++)
			boardsnake[0][j] = objects[i];
		for (int i = 24, j = 0; j < 4, i < 28; j++, i++)
			boardsnake[1][j] = objects[i];
		for (int i = 36, j = 0; j < 4, i < 40; j++, i++)
			boardladder[0][j] = objects[i];
		for (int i = 32, j = 0; j < 4, i < 36; j++, i++)
			boardladder[1][j] = objects[i];
	}
	else
	{
		load(pos1, pos2, p1score, p1gold, p1silver, p1diamond, p1sword, p1shield, p2score, p2gold, p2silver, p2diamond, p2sword, p2shield, boardprison, boardgold, boardsilver, boarddiamond, boardsword, boardshield, boardsnake, boardladder);
	}
	int xaxis[100] = { 3,83,163,243,323,403,483,563,643,723,723,643,563,483,403,323,243,163,83,3,3,83,163,243,323,403,483,563,643,723,723,643,563,483,403,323,243,163,83,3,3,83,163,243,323,403,483,563,643,723,723,643,563,483,403,323,243,163,83,3,3,83,163,243,323,403,483,563,643,723,723,643,563,483,403,323,243,163,83,3,3,83,163,243,323,403,483,563,643,723,723,643,563,483,403,323,243,163,83,3 };
	int yaxis[100] = { 460,460, 460, 460, 460, 460, 460, 460, 460, 460,415,415,415,415,415,415,415,415,415,415,367,367,367,367,367,367,367,367,367,367,319,319,319,319,319,319,319,319,319,319,271,271,271,271,271,271,271,271,271,271,223,223,223,223,223,223,223,223,223,223,175,175,175,175,175,175,175,175,175,175,127,127,127,127,127,127,127,127,127,127,79,79,79,79,79,79,79,79,79,79,31,31,31,31,31,31,31,31,31,31 };
	PlaceCursor(119, 0);
	COLORREF A = RGB(139, 139, 131);
	COLORREF blue = RGB(25, 25, 112);
	COLORREF yellow = RGB(255, 165, 0);
	for (int i = 0, j = 81; i < 721, j < 801; i += 160, j += 160)
	{
		myRect(i, 0, i + 80, 47, blue, blue);
		myRect(j, 0, j + 80, 47, yellow, yellow);
	}
	for (int i = 0, j = 81; i < 721, j < 801; i += 160, j += 160)
	{
		myRect(i, 48, i + 80, 95, yellow, yellow);
		myRect(j, 48, j + 80, 95, blue, blue);
	}
	for (int i = 0, j = 81; i < 721, j < 801; i += 160, j += 160)
	{
		myRect(i, 96, i + 80, 143, blue, blue);
		myRect(j, 96, j + 80, 143, yellow, yellow);
	}
	for (int i = 0, j = 81; i < 721, j < 801; i += 160, j += 160)
	{
		myRect(i, 144, i + 80, 191, yellow, yellow);
		myRect(j, 144, j + 80, 191, blue, blue);
	}
	for (int i = 0, j = 81; i < 721, j < 801; i += 160, j += 160)
	{
		myRect(i, 192, i + 80, 239, blue, blue);
		myRect(j, 192, j + 80, 239, yellow, yellow);
	}
	for (int i = 0, j = 81; i < 721, j < 801; i += 160, j += 160)
	{
		myRect(i, 240, i + 80, 287, yellow, yellow);
		myRect(j, 240, j + 80, 287, blue, blue);
	}
	for (int i = 0, j = 81; i < 721, j < 801; i += 160, j += 160)
	{
		myRect(i, 288, i + 80, 335, blue, blue);
		myRect(j, 288, j + 80, 335, yellow, yellow);
	}
	for (int i = 0, j = 81; i < 721, j < 801; i += 160, j += 160)
	{
		myRect(i, 336, i + 80, 383, yellow, yellow);
		myRect(j, 336, j + 80, 383, blue, blue);
	}
	for (int i = 0, j = 81; i < 721, j < 801; i += 160, j += 160)
	{
		myRect(i, 384, i + 80, 431, blue, blue);
		myRect(j, 384, j + 80, 431, yellow, yellow);
	}
	for (int i = 0, j = 81; i < 721, j < 801; i += 160, j += 160)
	{
		myRect(i, 432, i + 80, 480, yellow, yellow);
		myRect(j, 432, j + 80, 480, blue, blue);
	}
	myDrawText(3, 460, 30, "1", RGB(255, 255, 255), yellow);
	myDrawText(83, 460, 30, "2", RGB(255, 255, 255), blue);
	myDrawText(163, 460, 30, "3", RGB(255, 255, 255), yellow);
	myDrawText(243, 460, 30, "4", RGB(255, 255, 255), blue);
	myDrawText(323, 460, 30, "5", RGB(255, 255, 255), yellow);
	myDrawText(403, 460, 30, "6", RGB(255, 255, 255), blue);
	myDrawText(483, 460, 30, "7", RGB(255, 255, 255), yellow);
	myDrawText(563, 460, 30, "8", RGB(255, 255, 255), blue);
	myDrawText(643, 460, 30, "9", RGB(255, 255, 255), yellow);
	myDrawText(723, 460, 30, "10", RGB(255, 255, 255), blue);
	myDrawText(723, 415, 30, "11", RGB(255, 255, 255), yellow);
	myDrawText(643, 415, 30, "12", RGB(255, 255, 255), blue);
	myDrawText(563, 415, 30, "13", RGB(255, 255, 255), yellow);
	myDrawText(483, 415, 30, "14", RGB(255, 255, 255), blue);
	myDrawText(403, 415, 30, "15", RGB(255, 255, 255), yellow);
	myDrawText(323, 415, 30, "16", RGB(255, 255, 255), blue);
	myDrawText(243, 415, 30, "17", RGB(255, 255, 255), yellow);
	myDrawText(163, 415, 30, "18", RGB(255, 255, 255), blue);
	myDrawText(83, 415, 30, "19", RGB(255, 255, 255), yellow);
	myDrawText(3, 415, 30, "20", RGB(255, 255, 255), blue);
	myDrawText(3, 367, 30, "21", RGB(255, 255, 255), yellow);
	myDrawText(83, 367, 30, "22", RGB(255, 255, 255), blue);
	myDrawText(163, 367, 30, "23", RGB(255, 255, 255), yellow);
	myDrawText(243, 367, 30, "24", RGB(255, 255, 255), blue);
	myDrawText(323, 367, 30, "25", RGB(255, 255, 255), yellow);
	myDrawText(403, 367, 30, "26", RGB(255, 255, 255), blue);
	myDrawText(483, 367, 30, "27", RGB(255, 255, 255), yellow);
	myDrawText(563, 367, 30, "28", RGB(255, 255, 255), blue);
	myDrawText(643, 367, 30, "29", RGB(255, 255, 255), yellow);
	myDrawText(723, 367, 30, "30", RGB(255, 255, 255), blue);
	myDrawText(723, 319, 30, "31", RGB(255, 255, 255), yellow);
	myDrawText(643, 319, 30, "32", RGB(255, 255, 255), blue);
	myDrawText(563, 319, 30, "33", RGB(255, 255, 255), yellow);
	myDrawText(483, 319, 30, "34", RGB(255, 255, 255), blue);
	myDrawText(403, 319, 30, "35", RGB(255, 255, 255), yellow);
	myDrawText(323, 319, 30, "36", RGB(255, 255, 255), blue);
	myDrawText(243, 319, 30, "37", RGB(255, 255, 255), yellow);
	myDrawText(163, 319, 30, "38", RGB(255, 255, 255), blue);
	myDrawText(83, 319, 30, "39", RGB(255, 255, 255), yellow);
	myDrawText(3, 319, 30, "40", RGB(255, 255, 255), blue);
	myDrawText(3, 271, 30, "41", RGB(255, 255, 255), yellow);
	myDrawText(83, 271, 30, "42", RGB(255, 255, 255), blue);
	myDrawText(163, 271, 30, "43", RGB(255, 255, 255), yellow);
	myDrawText(243, 271, 30, "44", RGB(255, 255, 255), blue);
	myDrawText(323, 271, 30, "45", RGB(255, 255, 255), yellow);
	myDrawText(403, 271, 30, "46", RGB(255, 255, 255), blue);
	myDrawText(483, 271, 30, "47", RGB(255, 255, 255), yellow);
	myDrawText(563, 271, 30, "48", RGB(255, 255, 255), blue);
	myDrawText(643, 271, 30, "49", RGB(255, 255, 255), yellow);
	myDrawText(723, 271, 30, "50", RGB(255, 255, 255), blue);
	myDrawText(723, 223, 30, "51", RGB(255, 255, 255), yellow);
	myDrawText(643, 223, 30, "52", RGB(255, 255, 255), blue);
	myDrawText(563, 223, 30, "53", RGB(255, 255, 255), yellow);
	myDrawText(483, 223, 30, "54", RGB(255, 255, 255), blue);
	myDrawText(403, 223, 30, "55", RGB(255, 255, 255), yellow);
	myDrawText(323, 223, 30, "56", RGB(255, 255, 255), blue);
	myDrawText(243, 223, 30, "57", RGB(255, 255, 255), yellow);
	myDrawText(163, 223, 30, "58", RGB(255, 255, 255), blue);
	myDrawText(83, 223, 30, "59", RGB(255, 255, 255), yellow);
	myDrawText(3, 223, 30, "60", RGB(255, 255, 255), blue);
	myDrawText(3, 175, 30, "61", RGB(255, 255, 255), yellow);
	myDrawText(83, 175, 30, "62", RGB(255, 255, 255), blue);
	myDrawText(163, 175, 30, "63", RGB(255, 255, 255), yellow);
	myDrawText(243, 175, 30, "64", RGB(255, 255, 255), blue);
	myDrawText(323, 175, 30, "65", RGB(255, 255, 255), yellow);
	myDrawText(403, 175, 30, "66", RGB(255, 255, 255), blue);
	myDrawText(483, 175, 30, "67", RGB(255, 255, 255), yellow);
	myDrawText(563, 175, 30, "68", RGB(255, 255, 255), blue);
	myDrawText(643, 175, 30, "69", RGB(255, 255, 255), yellow);
	myDrawText(723, 175, 30, "70", RGB(255, 255, 255), blue);
	myDrawText(723, 127, 30, "71", RGB(255, 255, 255), yellow);
	myDrawText(643, 127, 30, "72", RGB(255, 255, 255), blue);
	myDrawText(563, 127, 30, "73", RGB(255, 255, 255), yellow);
	myDrawText(483, 127, 30, "74", RGB(255, 255, 255), blue);
	myDrawText(403, 127, 30, "75", RGB(255, 255, 255), yellow);
	myDrawText(323, 127, 30, "76", RGB(255, 255, 255), blue);
	myDrawText(243, 127, 30, "77", RGB(255, 255, 255), yellow);
	myDrawText(163, 127, 30, "78", RGB(255, 255, 255), blue);
	myDrawText(83, 127, 30, "79", RGB(255, 255, 255), yellow);
	myDrawText(3, 127, 30, "80", RGB(255, 255, 255), blue);
	myDrawText(3, 79, 30, "81", RGB(255, 255, 255), yellow);
	myDrawText(83, 79, 30, "82", RGB(255, 255, 255), blue);
	myDrawText(163, 79, 30, "83", RGB(255, 255, 255), yellow);
	myDrawText(243, 79, 30, "84", RGB(255, 255, 255), blue);
	myDrawText(323, 79, 30, "85", RGB(255, 255, 255), yellow);
	myDrawText(403, 79, 30, "86", RGB(255, 255, 255), blue);
	myDrawText(483, 79, 30, "87", RGB(255, 255, 255), yellow);
	myDrawText(563, 79, 30, "88", RGB(255, 255, 255), blue);
	myDrawText(643, 79, 30, "89", RGB(255, 255, 255), yellow);
	myDrawText(723, 79, 30, "90", RGB(255, 255, 255), blue);
	myDrawText(723, 31, 30, "91", RGB(255, 255, 255), yellow);
	myDrawText(643, 31, 30, "92", RGB(255, 255, 255), blue);
	myDrawText(563, 31, 30, "93", RGB(255, 255, 255), yellow);
	myDrawText(483, 31, 30, "94", RGB(255, 255, 255), blue);
	myDrawText(403, 31, 30, "95", RGB(255, 255, 255), yellow);
	myDrawText(323, 31, 30, "96", RGB(255, 255, 255), blue);
	myDrawText(243, 31, 30, "97", RGB(255, 255, 255), yellow);
	myDrawText(163, 31, 30, "98", RGB(255, 255, 255), blue);
	myDrawText(83, 31, 30, "99", RGB(255, 255, 255), yellow);
	myDrawText(3, 31, 30, "100", RGB(255, 255, 255), blue);
	drawboard(xaxis, yaxis, boardgold, boardsilver, boarddiamond, boardprison, boardsword, boardshield, boardsnake, boardladder);
	myLine(801, 159, 978, 159, A);
	myLine(801, 159 + 159, 978, 159 + 159, A);
	if (choice == 1) {
		myDrawTextWithFont(837, 1, 20, "Player 1 Stats :", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(806, 30, 17, "P1 Gold :", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(806, 50, 17, "P1 Silver :", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(806, 70, 17, "P1 Diamond :", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(806, 90, 17, "P1 Sword :", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(806, 110, 17, "P1 Shield :", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(806, 130, 17, "P1 Score :", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawText(920, 32, 1, "0", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawText(920, 52, 1, "0", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawText(920, 72, 1, "0", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawText(920, 92, 1, "0", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawText(920, 112, 1, "0", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawText(920, 132, 1, "0", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(837, 160, 20, "Player 2 Stats :", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(806, 190, 17, "P2 Gold :", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(806, 210, 17, "P2 Silver :", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(806, 230, 17, "P2 Diamond :", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(806, 250, 17, "P2 Sword :", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(806, 270, 17, "P2 Shield :", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(806, 290, 17, "P2 Score :", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawText(920, 192, 1, "0", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawText(920, 212, 1, "0", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawText(920, 232, 1, "0", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawText(920, 252, 1, "0", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawText(920, 272, 1, "0", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawText(920, 292, 1, "0", RGB(255, 255, 255), RGB(0, 0, 0));
	}
	else
	{
		myDrawTextWithFont(837, 1, 20, "Player 1 Stats :", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(806, 30, 17, "P1 Gold :", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(806, 50, 17, "P1 Silver :", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(806, 70, 17, "P1 Diamond :", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(806, 90, 17, "P1 Sword :", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(806, 110, 17, "P1 Shield :", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(806, 130, 17, "P1 Score :", RGB(255, 255, 255), RGB(0, 0, 0));
		char ch[20];
		sprintf_s(ch, "%d", p1gold);
		myDrawText(920, 32, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
		sprintf_s(ch, "%d", p1silver);
		myDrawText(920, 52, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
		sprintf_s(ch, "%d", p1diamond);
		myDrawText(920, 72, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
		sprintf_s(ch, "%d", p1sword);
		myDrawText(920, 92, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
		sprintf_s(ch, "%d", p1shield);
		myDrawText(920, 112, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
		sprintf_s(ch, "%d", p1score);
		myDrawText(920, 132, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(837, 160, 20, "Player 2 Stats :", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(806, 190, 17, "P2 Gold :", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(806, 210, 17, "P2 Silver :", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(806, 230, 17, "P2 Diamond :", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(806, 250, 17, "P2 Sword :", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(806, 270, 17, "P2 Shield :", RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(806, 290, 17, "P2 Score :", RGB(255, 255, 255), RGB(0, 0, 0));
		sprintf_s(ch, "%d", p2gold);
		myDrawText(920, 192, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
		sprintf_s(ch, "%d", p2silver);
		myDrawText(920, 212, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
		sprintf_s(ch, "%d", p2diamond);
		myDrawText(920, 232, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
		sprintf_s(ch, "%d", p2sword);
		myDrawText(920, 252, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
		sprintf_s(ch, "%d", p2shield);
		myDrawText(920, 272, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
		sprintf_s(ch, "%d", p2score);
		myDrawText(920, 292, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
	}
	myDrawTextWithFont(828, 320, 20, "Message Center", RGB(255, 255, 255), RGB(0, 0, 0));
	if (choice == 1) {
		pos1 = 1;
		pos2 = 1;
	}
	int i = 1;
	bool p1 = true;
	while (i == 1)
	{
		myDrawText(837, 350, 1, "Roll Dice(Enter)", RGB(255, 255, 255), RGB(0, 0, 0));
		placegot(xaxis, yaxis, pos1, true);
		placegot(xaxis, yaxis, pos2, false);
		if (checkkey() == 13)
		{
			srand(time(NULL));
			int rnum = rand() % 7;
			rnum = rnum == 0 ? 1 : rnum;
			char ch1[20];
			sprintf_s(ch1, "%d", rnum);
			myDrawTextWithFont(860, 390, 70, "           ", RGB(0, 0, 0), RGB(0, 0, 0));
			myDrawTextWithFont(860, 390, 70, ch1, RGB(255, 255, 255), RGB(255, 0, 0));
			if (rnum + pos1 <= 100 && p1 == true && p1count == 0)
			{
				int j = 0;
				while (j == 0) {
					if (checkkey() == 49) {
						putgot1(xaxis, yaxis, pos1, rnum);
						j += 1;
					}
				}
				for (int i = 0; i < 4; i++)
				{
					if (pos1 == boardprison[i])
					{
						if (p1diamond == 0) {
							p1score = p1score - 20;
							myDrawText(920, 132, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
							char ch[20];
							sprintf_s(ch, "%d", p1score);
							myDrawText(920, 132, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
							p1count = 2;
							p1 = !p1;
						}
						else
						{
							int k = 0;
							while (k == 0)
							{
								if (checkkey() == 100) {
									p1diamond = p1diamond - 1;
									p1score = p1score - 50;
									myDrawText(920, 72, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
									myDrawText(920, 132, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
									char ch1[20];
									sprintf_s(ch1, "%d", p1diamond);
									myDrawText(920, 72, 1, ch1, RGB(255, 255, 255), RGB(0, 0, 0));
									char ch[20];
									sprintf_s(ch, "%d", p1score);
									myDrawText(920, 132, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
									k = 1;
								}
								else if (checkkey() == 27)
								{
									save(pos1, pos2, p1score, p1gold, p1silver, p1diamond, p1sword, p1shield, p2score, p2gold, p2silver, p2diamond, p2sword, p2shield, boardprison, boardgold, boardsilver, boarddiamond, boardsword, boardshield, boardsnake, boardladder);
									i = 2;
								}
								else if (checkkey() == 108)
								{
									p1score = p1score - 20;
									myDrawText(920, 132, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
									char ch[20];
									sprintf_s(ch, "%d", p1score);
									myDrawText(920, 132, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
									p1count = 2;
									p1 = !p1;
									k = 1;
								}
							}
						}
					}
					if (pos1 == boardsnake[1][i])
					{
						if (p1sword == 0 && p1shield == 0 && p1gold < 3 && p1silver < 6)
						{
							int pos = boardsnake[0][i];
							int number = pos - pos1;
							putgot1(xaxis, yaxis, pos1, number);
						}
						else
						{
							int k = 0;
							while (k == 0)
							{
								if (checkkey() == 115 && p1sword != 0)
								{
									p1sword = p1sword - 1;
									myDrawText(920, 92, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
									char ch1[20];
									sprintf_s(ch1, "%d", p1sword);
									myDrawText(920, 92, 1, ch1, RGB(255, 255, 255), RGB(0, 0, 0));
									k = 1;
								}
								else if (checkkey() == 104 && p1shield != 0)
								{
									p1shield = p1shield - 1;
									myDrawText(920, 112, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
									char ch1[20];
									sprintf_s(ch1, "%d", p1shield);
									myDrawText(920, 112, 1, ch1, RGB(255, 255, 255), RGB(0, 0, 0));
									k = 1;
								}
								else if (checkkey() == 103 && p1gold>2)
								{
									int number;
									int rem;
									rem = pos1 % 10;
									if (rem == 0)
										putgot1(xaxis, yaxis, pos1, 1);
									else
									{
										number = (20 - ((2 * rem) - 1));
										putgot1(xaxis, yaxis, pos1, number);
									}
									p1gold = p1gold - 3;
									p1score = p1score - 30;
									myDrawText(920, 32, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
									myDrawText(920, 132, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
									char ch1[20];
									sprintf_s(ch1, "%d", p1gold);
									myDrawText(920, 32, 1, ch1, RGB(255, 255, 255), RGB(0, 0, 0));
									char ch[20];
									sprintf_s(ch, "%d", p1diamond);
									myDrawText(920, 132, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
									k = 1;
								}
								else if (checkkey() == 105 && p1silver > 5)
								{
									int number;
									number = pos1 % 10;
									if (number == 0)
										putgot1(xaxis, yaxis, pos1, 1);
									else
									{
										number = (20 - ((2 * number) - 1));
										putgot1(xaxis, yaxis, pos1, number);
									}
									p1silver = p1silver - 6;
									p1score = p1score - 30;
									myDrawText(920, 52, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
									myDrawText(920, 132, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
									char ch1[20];
									sprintf_s(ch1, "%d", p1silver);
									myDrawText(920, 52, 1, ch1, RGB(255, 255, 255), RGB(0, 0, 0));
									char ch[20];
									sprintf_s(ch, "%d", p1score);;
									myDrawText(920, 132, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
									k = 1;
								}
								else if (checkkey() == 27)
								{
									save(pos1, pos2, p1score, p1gold, p1silver, p1diamond, p1sword, p1shield, p2score, p2gold, p2silver, p2diamond, p2sword, p2shield, boardprison, boardgold, boardsilver, boarddiamond, boardsword, boardshield, boardsnake, boardladder);
									i = 2;
								}
								else if (checkkey() == 108)
								{
									int pos = boardsnake[0][i];
									int number = pos - pos1;
									putgot1(xaxis, yaxis, pos1, number);
									k = 1;
								}
							}
						}
					}

					if (pos1 == boardladder[0][i])
					{
						int pos = boardladder[1][i];
						int number = pos - pos1;
						putgot1(xaxis, yaxis, pos1, number);
					}
					if (pos1 == boardsilver[i])
					{
						int k = 0;
						while (k == 0)
						{
							if (checkkey() == 112) {
								p1silver += 1;
								p1score += 5;
								if ((pos1) % 2 == 0)
									myDrawTextWithFont(xaxis[pos1 - 1] + 7, yaxis[pos1 - 1] - 27, 17, "Silver", RGB(25, 25, 112), RGB(25, 25, 112));
								else
									myDrawTextWithFont(xaxis[pos1 - 1] + 7, yaxis[pos1 - 1] - 27, 17, "Silver", RGB(255, 165, 0), RGB(255, 165, 0));
								boardsilver[i] = -1;
								myDrawText(920, 52, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
								myDrawText(920, 132, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
								char ch1[20];
								sprintf_s(ch1, "%d", p1silver);
								myDrawText(920, 52, 1, ch1, RGB(255, 255, 255), RGB(0, 0, 0));
								char ch[20];
								sprintf_s(ch, "%d", p1score);
								myDrawText(920, 132, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
								k = 1;
							}
							else if (checkkey() == 108) {
								k = 1;
							}
							else if (checkkey() == 27)
							{
								save(pos1, pos2, p1score, p1gold, p1silver, p1diamond, p1sword, p1shield, p2score, p2gold, p2silver, p2diamond, p2sword, p2shield, boardprison, boardgold, boardsilver, boarddiamond, boardsword, boardshield, boardsnake, boardladder);
								i = 2;
							}
						}
					}
					if (pos1 == boardgold[i])
					{
						int k = 0;
						while (k == 0) {
							if (checkkey() == 112) {
								p1gold += 1;
								p1score += 10;
								if ((pos1) % 2 == 0)
									myDrawTextWithFont(xaxis[pos1 - 1] + 7, yaxis[pos1 - 1] - 27, 17, "Gold", RGB(25, 25, 112), RGB(25, 25, 112));
								else
									myDrawTextWithFont(xaxis[pos1 - 1] + 7, yaxis[pos1 - 1] - 27, 17, "Gold", RGB(255, 165, 0), RGB(255, 165, 0));
								boardgold[i] = -1;
								myDrawText(920, 32, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
								myDrawText(920, 132, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
								char ch1[20];
								sprintf_s(ch1, "%d", p1gold);
								myDrawText(920, 32, 1, ch1, RGB(255, 255, 255), RGB(0, 0, 0));
								char ch[20];
								sprintf_s(ch, "%d", p1score);
								myDrawText(920, 132, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
								k = 1;
							}
							else if (checkkey() == 108)
								k = 1;
							else if (checkkey() == 27)
							{
								save(pos1, pos2, p1score, p1gold, p1silver, p1diamond, p1sword, p1shield, p2score, p2gold, p2silver, p2diamond, p2sword, p2shield, boardprison, boardgold, boardsilver, boarddiamond, boardsword, boardshield, boardsnake, boardladder);
								i = 2;
							}
						}
					}
					if (pos1 == boarddiamond[i])
					{
						int k = 0;
						while (k == 0) {
							if (checkkey() == 112) {
								p1diamond += 1;
								p1score += 50;
								if ((pos1) % 2 == 0)
									myDrawTextWithFont(xaxis[pos1 - 1] + 7, yaxis[pos1 - 1] - 27, 17, "Diamond", RGB(25, 25, 112), RGB(25, 25, 112));
								else
									myDrawTextWithFont(xaxis[pos1 - 1] + 7, yaxis[pos1 - 1] - 27, 17, "Diamond", RGB(255, 165, 0), RGB(255, 165, 0));
								boarddiamond[i] = -1;
								myDrawText(920, 72, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
								myDrawText(920, 132, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
								char ch1[20];
								sprintf_s(ch1, "%d", p1diamond);
								myDrawText(920, 72, 1, ch1, RGB(255, 255, 255), RGB(0, 0, 0));
								char ch[20];
								sprintf_s(ch, "%d", p1score);
								myDrawText(920, 132, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
								k = 1;
							}
							else if (checkkey() == 108)
								k = 1;
							else if (checkkey() == 27)
							{
								save(pos1, pos2, p1score, p1gold, p1silver, p1diamond, p1sword, p1shield, p2score, p2gold, p2silver, p2diamond, p2sword, p2shield, boardprison, boardgold, boardsilver, boarddiamond, boardsword, boardshield, boardsnake, boardladder);
								i = 2;
							}
						}
					}
					if (pos1 == boardsword[i])
					{
						int k = 0;
						while (k == 0) {
							if (checkkey() == 112) {
								p1sword += 1;
								p1score += 10;
								if ((pos1) % 2 == 0)
									myDrawTextWithFont(xaxis[pos1 - 1] + 7, yaxis[pos1 - 1] - 27, 17, "Sword", RGB(25, 25, 112), RGB(25, 25, 112));
								else
									myDrawTextWithFont(xaxis[pos1 - 1] + 7, yaxis[pos1 - 1] - 27, 17, "Sword", RGB(255, 165, 0), RGB(255, 165, 0));
								boardsword[i] = -1;
								myDrawText(920, 92, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
								myDrawText(920, 132, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
								char ch1[20];
								sprintf_s(ch1, "%d", p1sword);
								myDrawText(920, 92, 1, ch1, RGB(255, 255, 255), RGB(0, 0, 0));
								char ch[20];
								sprintf_s(ch, "%d", p1score);
								myDrawText(920, 132, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
								k = 1;
							}
							else if (checkkey() == 108)
								k = 1;
							else if (checkkey() == 27)
							{
								save(pos1, pos2, p1score, p1gold, p1silver, p1diamond, p1sword, p1shield, p2score, p2gold, p2silver, p2diamond, p2sword, p2shield, boardprison, boardgold, boardsilver, boarddiamond, boardsword, boardshield, boardsnake, boardladder);
								i = 2;
							}
						}
					}
					if (pos1 == boardshield[i])
					{
						int k = 0;
						while (k == 0) {
							if (checkkey() == 112) {
								p1shield += 1;
								p1score += 20;
								if ((pos1) % 2 == 0)
									myDrawTextWithFont(xaxis[pos1 - 1] + 7, yaxis[pos1 - 1] - 27, 17, "Shield", RGB(25, 25, 112), RGB(25, 25, 112));
								else
									myDrawTextWithFont(xaxis[pos1 - 1] + 7, yaxis[pos1 - 1] - 27, 17, "Shield", RGB(255, 165, 0), RGB(255, 165, 0));
								boardshield[i] = -1;
								myDrawText(920, 112, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
								myDrawText(920, 132, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
								char ch1[20];
								sprintf_s(ch1, "%d", p1shield);
								myDrawText(920, 112, 1, ch1, RGB(255, 255, 255), RGB(0, 0, 0));
								char ch[20];
								sprintf_s(ch, "%d", p1score);
								myDrawText(920, 132, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
								k = 1;
							}
							else if (checkkey() == 108)
								k = 1;
							else if (checkkey() == 27)
							{
								save(pos1, pos2, p1score, p1gold, p1silver, p1diamond, p1sword, p1shield, p2score, p2gold, p2silver, p2diamond, p2sword, p2shield, boardprison, boardgold, boardsilver, boarddiamond, boardsword, boardshield, boardsnake, boardladder);
								i = 2;
							}
						}
					}
				}
			}
			else if (p1count>0)
				p1count--;
			if (rnum + pos2 <= 100 && p1 == false && p2count == 0)
			{

				int j = 0;
				while (j == 0) {
					if (checkkey() == 50) {
						putgot2(xaxis, yaxis, pos2, rnum);
						j += 1;
					}
				}
				for (int i = 0; i < 4; i++)
				{
					if (pos2 == boardprison[i])
					{
						if (p2diamond == 0)
						{
							p2score = p2score - 20;
							p2count = 3;
							myDrawText(920, 292, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
							char ch[20];
							sprintf_s(ch, "%d", p2score);
							myDrawText(920, 292, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
							p1 = !p1;
						}
						else
						{
							int k = 0;
							while (k == 0)
							{
								if (checkkey() == 100) {
									p2diamond = p2diamond - 1;
									p2score = p2score - 50;
									myDrawText(920, 232, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
									myDrawText(920, 292, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
									char ch1[20];
									sprintf_s(ch1, "%d", p2diamond);
									myDrawText(920, 232, 1, ch1, RGB(255, 255, 255), RGB(0, 0, 0));
									char ch[20];
									sprintf_s(ch, "%d", p2score);
									myDrawText(920, 292, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
									k = 1;
								}
								else if (checkkey() == 27)
								{
									save(pos1, pos2, p1score, p1gold, p1silver, p1diamond, p1sword, p1shield, p2score, p2gold, p2silver, p2diamond, p2sword, p2shield, boardprison, boardgold, boardsilver, boarddiamond, boardsword, boardshield, boardsnake, boardladder);
									i = 2;
								}
								else if (checkkey() == 108)
								{
									p2score = p2score - 20;
									p2count = 3;
									myDrawText(920, 292, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
									char ch[20];
									sprintf_s(ch, "%d", p2score);
									myDrawText(920, 292, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
									p1 = !p1;
									k = 1;
								}
							}
						}
					}
					if (pos2 == boardsnake[1][i])
					{
						if (p2sword == 0 && p2shield == 0 && p2gold < 3 && p2silver < 6)
						{
							int pos = boardsnake[0][i];
							int number = pos - pos2;
							putgot2(xaxis, yaxis, pos2, number);
						}
						else
						{
							int k = 0;
							while (k == 0)
							{
								if (checkkey() == 115 && p2sword != 0)
								{
									p2sword = p2sword - 1;
									myDrawText(920, 252, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
									char ch1[20];
									sprintf_s(ch1, "%d", p2sword);
									myDrawText(920, 252, 1, ch1, RGB(255, 255, 255), RGB(0, 0, 0));
									k = 1;
								}
								else if (checkkey() == 104 && p2shield != 0)
								{
									p2shield = p2shield - 1;
									myDrawText(920, 272, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
									char ch1[20];
									sprintf_s(ch1, "%d", p2shield);
									myDrawText(920, 272, 1, ch1, RGB(255, 255, 255), RGB(0, 0, 0));
									k = 1;
								}
								else if (checkkey() == 103 && p1gold>2)
								{
									int number;
									int rem;
									rem = pos2 % 10;
									if (rem == 0)
										putgot2(xaxis, yaxis, pos2, 1);
									else
									{
										number = (20 - ((2 * rem) - 1));
										putgot2(xaxis, yaxis, pos2, number);
									}
									p2gold = p2gold - 3;
									p2score = p2score - 30;
									myDrawText(920, 192, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
									myDrawText(920, 292, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
									char ch1[20];
									sprintf_s(ch1, "%d", p2gold);
									myDrawText(920, 192, 1, ch1, RGB(255, 255, 255), RGB(0, 0, 0));
									char ch[20];
									sprintf_s(ch, "%d", p2score);
									myDrawText(920, 292, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
									k = 1;
								}
								else if (checkkey() == 105 && p1silver > 5)
								{
									int number;
									number = pos2 % 10;
									if (number == 0)
										putgot2(xaxis, yaxis, pos2, 1);
									else
									{
										number = (20 - ((2 * number) - 1));
										putgot2(xaxis, yaxis, pos2, number);
									}
									p2silver = p2silver - 6;
									p2score = p2score - 30;
									myDrawText(920, 212, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
									myDrawText(920, 292, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
									char ch1[20];
									sprintf_s(ch1, "%d", p2silver);
									myDrawText(920, 212, 1, ch1, RGB(255, 255, 255), RGB(0, 0, 0));
									char ch[20];
									sprintf_s(ch, "%d", p2score);
									myDrawText(920, 292, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
									k = 1;
								}
								else if (checkkey() == 27)
								{
									save(pos1, pos2, p1score, p1gold, p1silver, p1diamond, p1sword, p1shield, p2score, p2gold, p2silver, p2diamond, p2sword, p2shield, boardprison, boardgold, boardsilver, boarddiamond, boardsword, boardshield, boardsnake, boardladder);
									i = 2;
								}
								else if (checkkey() == 108)
								{
									int pos = boardsnake[0][i];
									int number = pos - pos2;
									putgot2(xaxis, yaxis, pos2, number);
									k = 1;
								}
							}
						}
					}
					if (pos2 == boardladder[0][i])
					{
						int pos = boardladder[1][i];
						int number = pos - pos2;
						putgot2(xaxis, yaxis, pos2, number);
					}
					if (pos2 == boardsilver[i])
					{
						int k = 0;
						while (k == 0) {
							if (checkkey() == 112) {
								//myDrawText(837, 350, 1, "Pick Silver", RGB(255, 255, 255), RGB(0, 0, 0));
								p2silver += 1;
								p2score += 5;
								if ((pos2) % 2 == 0)
									myDrawTextWithFont(xaxis[pos2 - 1] + 7, yaxis[pos2 - 1] - 27, 17, "Silver", RGB(25, 25, 112), RGB(25, 25, 112));
								else
									myDrawTextWithFont(xaxis[pos2 - 1] + 7, yaxis[pos2 - 1] - 27, 17, "Silver", RGB(255, 165, 0), RGB(255, 165, 0));
								boardsilver[i] = -1;
								myDrawText(920, 212, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
								myDrawText(920, 292, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
								char ch1[20];
								sprintf_s(ch1, "%d", p2silver);
								myDrawText(920, 212, 1, ch1, RGB(255, 255, 255), RGB(0, 0, 0));
								char ch[20];
								sprintf_s(ch, "%d", p2score);
								myDrawText(920, 292, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
								k = 1;
							}
							else if (checkkey() == 108)
								k = 1;
							else if (checkkey() == 27)
							{
								save(pos1, pos2, p1score, p1gold, p1silver, p1diamond, p1sword, p1shield, p2score, p2gold, p2silver, p2diamond, p2sword, p2shield, boardprison, boardgold, boardsilver, boarddiamond, boardsword, boardshield, boardsnake, boardladder);
								i = 2;
							}
						}
					}
					if (pos2 == boardgold[i])
					{
						int k = 0;
						while (k == 0) {
							if (checkkey() == 112) {
								p2gold += 1;
								p2score += 10;
								if ((pos2) % 2 == 0)
									myDrawTextWithFont(xaxis[pos2 - 1] + 7, yaxis[pos2 - 1] - 27, 17, "Gold", RGB(25, 25, 112), RGB(25, 25, 112));
								else
									myDrawTextWithFont(xaxis[pos2 - 1] + 7, yaxis[pos2 - 1] - 27, 17, "Gold", RGB(255, 165, 0), RGB(255, 165, 0));
								boardgold[i] = -1;
								myDrawText(920, 192, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
								myDrawText(920, 292, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
								char ch1[20];
								sprintf_s(ch1, "%d", p2gold);
								myDrawText(920, 192, 1, ch1, RGB(255, 255, 255), RGB(0, 0, 0));
								char ch[50];
								sprintf_s(ch, "%d", p2score);
								myDrawText(920, 292, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
								k = 1;
							}
							else if (checkkey() == 108)
								k = 1;
							else if (checkkey() == 27)
							{
								save(pos1, pos2, p1score, p1gold, p1silver, p1diamond, p1sword, p1shield, p2score, p2gold, p2silver, p2diamond, p2sword, p2shield, boardprison, boardgold, boardsilver, boarddiamond, boardsword, boardshield, boardsnake, boardladder);
								i = 2;
							}
						}
					}
					if (pos2 == boarddiamond[i])
					{
						int k = 0;
						while (k == 0) {
							if (checkkey() == 112) {
								p2diamond += 1;
								p2score += 50;
								if ((pos2) % 2 == 0)
									myDrawTextWithFont(xaxis[pos2 - 1] + 7, yaxis[pos2 - 1] - 27, 17, "Diamond", RGB(25, 25, 112), RGB(25, 25, 112));
								else
									myDrawTextWithFont(xaxis[pos2 - 1] + 7, yaxis[pos2 - 1] - 27, 17, "Diamond", RGB(255, 165, 0), RGB(255, 165, 0));
								boarddiamond[i] = -1;
								myDrawText(920, 232, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
								myDrawText(920, 292, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
								char ch1[20];
								sprintf_s(ch1, "%d", p2diamond);
								myDrawText(920, 232, 1, ch1, RGB(255, 255, 255), RGB(0, 0, 0));
								char ch[20];
								sprintf_s(ch, "%d", p2score);
								myDrawText(920, 292, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
								k = 1;
							}
							else if (checkkey() == 108)
								k = 1;
							else if (checkkey() == 27)
							{
								save(pos1, pos2, p1score, p1gold, p1silver, p1diamond, p1sword, p1shield, p2score, p2gold, p2silver, p2diamond, p2sword, p2shield, boardprison, boardgold, boardsilver, boarddiamond, boardsword, boardshield, boardsnake, boardladder);
								i = 2;
							}
						}
					}
					if (pos2 == boardsword[i])
					{
						int k = 0;
						while (k == 0) {
							if (checkkey() == 112) {
								p2sword += 1;
								p2score += 10;
								if ((pos2) % 2 == 0)
									myDrawTextWithFont(xaxis[pos2 - 1] + 7, yaxis[pos2 - 1] - 27, 17, "Sword", RGB(25, 25, 112), RGB(25, 25, 112));
								else
									myDrawTextWithFont(xaxis[pos2 - 1] + 7, yaxis[pos2 - 1] - 27, 17, "Sword", RGB(255, 165, 0), RGB(255, 165, 0));
								boardsword[i] = -1;
								myDrawText(920, 252, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
								myDrawText(920, 292, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
								char ch1[20];
								sprintf_s(ch1, "%d", p2sword);
								myDrawText(920, 252, 1, ch1, RGB(255, 255, 255), RGB(0, 0, 0));
								char ch[20];
								sprintf_s(ch, "%d", p2score);
								myDrawText(920, 292, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
								k = 1;
							}
							else if (checkkey() == 108)
								k = 1;
							else if (checkkey() == 27)
							{
								save(pos1, pos2, p1score, p1gold, p1silver, p1diamond, p1sword, p1shield, p2score, p2gold, p2silver, p2diamond, p2sword, p2shield, boardprison, boardgold, boardsilver, boarddiamond, boardsword, boardshield, boardsnake, boardladder);
								i = 2;
							}
						}
					}
					if (pos2 == boardshield[i])
					{
						int k = 0;
						while (k == 0) {
							if (checkkey() == 112) {
								p2shield += 1;
								p2score += 20;
								if ((pos2) % 2 == 0)
									myDrawTextWithFont(xaxis[pos2 - 1] + 7, yaxis[pos2 - 1] - 27, 17, "Shield", RGB(25, 25, 112), RGB(25, 25, 112));
								else
									myDrawTextWithFont(xaxis[pos2 - 1] + 7, yaxis[pos2 - 1] - 27, 17, "Shield", RGB(255, 165, 0), RGB(255, 165, 0));
								boardshield[i] = -1;
								myDrawText(920, 272, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
								myDrawText(920, 292, 1, "     ", RGB(0, 0, 0), RGB(0, 0, 0));
								char ch1[20];
								sprintf_s(ch1, "%d", p2shield);
								myDrawText(920, 272, 1, ch1, RGB(255, 255, 255), RGB(0, 0, 0));
								char ch[20];
								sprintf_s(ch, "%d", p2score);
								myDrawText(920, 292, 1, ch, RGB(255, 255, 255), RGB(0, 0, 0));
								k = 1;
							}
							else if (checkkey() == 108)
								k = 1;
						}
					}
					else if (checkkey() == 27)
					{
						save(pos1, pos2, p1score, p1gold, p1silver, p1diamond, p1sword, p1shield, p2score, p2gold, p2silver, p2diamond, p2sword, p2shield, boardprison, boardgold, boardsilver, boarddiamond, boardsword, boardshield, boardsnake, boardladder);
						i = 2;
					}
				}
			}
			else if (p2count>0)
				p2count--;
			if (pos1 == 100 || pos2 == 100)
				i = 2;
			if (p1count == 0 && p2count == 0)
				p1 = !p1;
		}
		else if (checkkey() == 27)
		{
			save(pos1, pos2, p1score, p1gold, p1silver, p1diamond, p1sword, p1shield, p2score, p2gold, p2silver, p2diamond, p2sword, p2shield, boardprison, boardgold, boardsilver, boarddiamond, boardsword, boardshield, boardsnake, boardladder);
			i = 2;
		}
	}
	if (p1score > p2score && pos1 == 100)
		myDrawTextWithFont(200, 200, 60, "Player 1 Wins", RGB(255, 255, 255), RGB(0, 0, 0));
	else if (p1score > p2score && pos2 == 100)
		myDrawTextWithFont(200, 200, 60, "Game Drawn", RGB(255, 255, 255), RGB(0, 0, 0));
	else if (p2score > p1score && pos2 == 100)
		myDrawTextWithFont(200, 200, 60, "Player 2 wins", RGB(255, 255, 255), RGB(0, 0, 0));
	else if (p2score > p1score && pos1 == 100)
		myDrawTextWithFont(200, 200, 60, "Game Drawn", RGB(255, 255, 255), RGB(0, 0, 0));
	cin.get();
}
