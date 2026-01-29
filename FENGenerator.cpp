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
string generateFEN(char arr[][8])
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
	
	return fen;
}

void writeFEN(char arr[][8])
{
	out(generateFEN(arr));
}
