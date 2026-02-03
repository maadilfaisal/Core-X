#pragma once
#include<string>
#include<conio.h>
#include<iostream>
#include<cstring>
#include<sstream>
enum pieceValue
{
	pawn=100, king=10000, bishop=300, knight=300, rook=500, queen=900
};
class piece
{
	public:
	char pawn = 'p', queen = 'q', king = 'k', knight = 'n', rook = 'r', bishop = 'b';
	char King = 'K', Queen = 'Q', Pawn = 'P', Bishop = 'B', Knight = 'N', Rook = 'R';
};
using namespace std;
#define out(x) cout<<x<<endl;
void call();
void showboard(string);
void countPieces(string);
void passnplay();
char* to_1d(char[][8], char[]);
string generateFEN(char arr[][8], bool K_whiteCastle, bool Q_whiteCastle, bool k_blackCastle, bool q_blackCastle, bool moveColor,int moveCounter);
void writeFEN(char arr[][8],bool K_whiteCastle, bool Q_whiteCastle, bool k_blackCastle, bool q_blackCastle, bool moveColor,int moveCounter);
void to_2d(char(&arr)[8][9], char(&array)[65]);
bool validateMove(string, string);