#include"core.h"
void call()
{
	string request;
	while (true)

	{
		cout<<"welcome >>";
		getline(cin, request);
		if (request == "showboard")
		{
			cout<<"Paste FEN>>";
			getline(cin, request);
			showboard(request);
			out("");
		}
		else if(request=="cls")
		{
			system("cls");
		}
		else if (request == "countpiece")
		{
			cout << "Paste FEN>>";
			getline(cin, request);
			countPieces(request);
		}
		else
		{
			cout<<"Command '" <<request <<"' does not exist or is currently unavailable."<<endl;
		}
	}
}

void showboard(string fen)
{
	int length = fen.length();
	cout << "+---------------+\n";
	cout << "|";
	for (int i = 0; i < length; i++)
	{
		if (fen[i] > '0' && fen[i] < '9')
		{
			for (int j = 48; j < (fen[i]); j++)
			{
				cout << ".|";
			}
		}
		else if (fen[i] == '/')
		{
			cout << "\n|";
		}
		else if(fen[i]==' ')
		{
			break;
		}
		else
		{
			cout << fen[i]<<"|";
		}
	}
	cout << "\n+---------------+\n";
}
void countPieces(string fen)
{
	int black = 0, white = 0;
	for (char i : fen)
	{
		switch (i)
		{
		case 'p':
			black++;
			break;
		case 'q':
			black += 9;
			break;
		case 'r':
			black += 5;
			break;
		case 'n':
		case 'b':
			black += 3;
			break;
		case 'P':
			white++;
			break;
		case 'Q':
			white += 9;
			break;
		case 'R':
			white += 5;
			break;
		case 'N':
		case 'B':
			white += 3;
			break;
		case ' ':
			goto printresult;
		}


	}
printresult:
	cout << "White: " << white << endl;
	cout << "Black: " << black << endl;
}