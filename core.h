#pragma once
#include<string>
#include<conio.h>
#include<iostream>
#include<cstring>
#include<sstream>
using namespace std;
#define out(x) cout<<x<<endl;
void call();
void showboard(string);
void countPieces(string);
void passnplay();
char* to_1d(char[][8], char[]);
string generateFEN(char arr[][8]);
void writeFEN(char arr[][8]);
