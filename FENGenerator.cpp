#include"core.h"
char* to_1d(char arr[][8],char array[])
{
	int counter = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			array[counter] = arr[i][j];
			counter++;
		}
	}
	return array;
}
void to_2d(char (& arr)[8][9], char (&array)[65])
{
	int counter = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			arr[i][j] = array[counter];
			counter++;
		}
		arr[i][8] = '\0';
	}
}
string generateFEN(char arr[][8], bool K_whiteCastle, bool Q_whiteCastle, bool k_blackCastle, bool q_blackCastle,bool moveColor,int moveCounter)
{
	char a = '/';
	char array[64];
	string fen = "";
	to_1d(arr, array);
	int counter = 0;
	for (int i = 0; i < 64; i++)
	{

		if (array[i] != '.')
		{
			if (counter == 0)
			{
				fen += array[i];
			}
			else if (counter > 0)
			{
				fen += to_string(counter);
				fen += array[i];
				counter = 0;
			}

		}
		if (array[i] == '.')
		{
			counter++;
		}
		if (i % 8 == 7 && counter > 0)
		{
			fen += to_string(counter);
			counter = 0;
		}
		if (i % 8 == 7&&i!=63)
		{
			fen += a;

		}

	}
	fen += " ";
	if (moveColor == true)
	{
		fen += "w";
	}
	else if (moveColor == false)
	{
		fen += "b";
	}
	fen += " ";
	if (K_whiteCastle == true)
	{
		fen += "K";
	}
	if (Q_whiteCastle == true)
	{
		fen += "Q";
	}
	if (k_blackCastle == true)
	{
		fen += "k";
	}
	if (q_blackCastle == true)
	{
		fen += "q";
	}
	fen += " ";
	fen += "-";
	fen += " ";
	fen += to_string(moveCounter);
	return fen;
}

void writeFEN(char arr[][8],bool K_whiteCastle,bool Q_whiteCastle,bool k_blackCastle,bool q_blackCastle,bool moveColor,int moveCounter)
{
	cout<<generateFEN(arr, K_whiteCastle, Q_whiteCastle, k_blackCastle, q_blackCastle, moveColor,moveCounter)<<endl;
}
