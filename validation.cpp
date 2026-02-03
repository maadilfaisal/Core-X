#include"core.h"
bool validateMove(string FEN,string move)
{
	int counter = 0;
	char currentPosition[65];
	char currentPosition2D[8][9];
	for (char i : FEN)
	{
        //cout << i;
		if (i == '/')
		{
		}
		else if (i == ' ')
		{
			break;
		}
        else if (i >= '0' && i <= '8')
        {
            for (char k = '0'; k < i; k++)
            {
                currentPosition[counter] = '.';
                counter++;
                //cout << "yes";
            }
        }
		else
		{
			currentPosition[counter] = i;
			counter++;
		}
	}
    currentPosition[64] = '\0';
    //cout << "yes";
    //cout << currentPosition;
	to_2d(currentPosition2D, currentPosition);
    stringstream ss(move);
    string targetSqr, currentSqr;
    bool validMove = false;
    ss >> currentSqr;
    ss >> targetSqr;
    int currentRow, CurrentColomn;
    int targetRow, targetColomn;
    currentRow = (currentSqr[1]);
    targetRow = (targetSqr[1]);
    currentRow -= 49;
    targetRow -= 49;
    switch (currentRow)
    {
    case 0:
        currentRow = 7;
        break;
    case 1:
        currentRow = 6;
        break;
    case 2:
        currentRow = 5;
        break;
    case 3:
        currentRow = 4;
        break;
    case 4:
        currentRow = 3;
        break;
    case 5:
        currentRow = 2;
        break;
    case 6:
        currentRow = 1;
        break;
    case 7:
        currentRow = 0;
        break;
    }
    switch (targetRow)
    {
    case 0:
        targetRow = 7;
        break;
    case 1:
        targetRow = 6;
        break;
    case 2:
        targetRow = 5;
        break;
    case 3:
        targetRow = 4;
        break;
    case 4:
        targetRow = 3;
        break;
    case 5:
        targetRow = 2;
        break;
    case 6:
        targetRow = 1;
        break;
    case 7:
        targetRow = 0;
        break;
    }
   // cout << currentRow;

    switch (currentSqr[0])
    {
    case 'a':
        CurrentColomn = 0;
        break;
    case 'b':
        CurrentColomn = 1;
        break;
    case 'c':
        CurrentColomn = 2;
        break;
    case 'd':
        CurrentColomn = 3;
        break;
    case 'e':
        CurrentColomn = 4;
        break;
    case 'f':
        CurrentColomn = 5;
        break;
    case 'g':
        CurrentColomn = 6;
        break;
    case 'h':
        CurrentColomn = 7;
        break;

    }

    switch (targetSqr[0])
    {
    case 'a':
        targetColomn = 0;
        break;
    case 'b':
        targetColomn = 1;
        break;
    case 'c':
        targetColomn = 2;
        break;
    case 'd':
        targetColomn = 3;
        break;
    case 'e':
        targetColomn = 4;
        break;
    case 'f':
        targetColomn = 5;
        break;
    case 'g':
        targetColomn = 6;
        break;
    case 'h':
        targetColomn = 7;
        break;
    }
    
       
  
    if (currentPosition2D[currentRow][CurrentColomn] == 'b')
    {
        if (targetColomn > CurrentColomn && targetRow > currentRow)
        {
            for (int i = currentRow+1, j = CurrentColomn+1; i <=targetRow  && j< targetColomn; i++, j++)
            {
                switch (currentPosition2D[i][j])
                {
                case 'p':
                case 'b':
                case 'n':
                case 'q':
                case 'k':
                case 'r':
                case 'R':
                case 'N':
                case 'B':
                case 'Q':
                case 'K':
                case 'P':
                    return false;
                    break;
                }
            }
            for (int i = currentRow, j = CurrentColomn; i <= targetRow && j <= targetColomn; i++, j++)
            {
                if (j == targetColomn && i == targetRow)
                {
                    validMove = true;
                }
               
            }
            if (!validMove)
            {
                return false;
            }
        }
        else if (targetRow > currentRow && targetColomn < CurrentColomn)
        {
            for (int i = currentRow+1, j = CurrentColomn-1; i<=targetRow && j>=targetColomn; i++, j--)
            {
                switch (currentPosition2D[i][j])
                {
                    
                    case 'p':
                    case 'b':
                    case 'n':
                    case 'q':
                    case 'k':
                    case 'r':
                    case 'R':
                    case 'N':
                    case 'B':
                    case 'Q':
                    case 'K':
                    case 'P':
                       // cout << currentRow << CurrentColomn;
                        return false;
                        break;
                    
                }
            }
            for (int i = currentRow, j = CurrentColomn; i<=targetRow && j>=targetColomn; i++, j--)
            {
        //cout << "yes";
                if (j == targetColomn && i == targetRow)
                {
                    validMove = true;
                }
            }
            if (!validMove)
            {
                return false;
            }
        }
        else if (targetRow < currentRow && targetColomn < CurrentColomn)
        {
            for (int i = currentRow-1, j = CurrentColomn-1; i >= targetRow&& j >= targetColomn; i--, j--)
            {
                switch (currentPosition2D[i][j])
                {
                case 'p':
                case 'b':
                case 'n':
                case 'q':
                case 'k':
                case 'r':
                case 'R':
                case 'N':
                case 'B':
                case 'Q':
                case 'K':
                case 'P':
                    return false;
                }
            }
            for (int i = currentRow, j = CurrentColomn; i >= targetRow && j >= targetColomn; i--, j--)
            {
                if (j == targetColomn && i == targetRow)
                {
                    validMove = true;
                }
            }
            if (!validMove)
            {
                return false;
            }
        }
        else if (targetRow < currentRow&& targetColomn > CurrentColomn)
        {
            for (int i = currentRow-1, j = CurrentColomn+1; i >= targetRow && j <= targetColomn; i--, j++)
            {
                switch (currentPosition2D[i][j])
                {
                case 'p':
                case 'b':
                case 'n':
                case 'q':
                case 'k':
                case 'r':
                case 'R':
                case 'N':
                case 'B':
                case 'Q':
                case 'K':
                case 'P':
                    return false;
                }
            }
            for (int i = currentRow, j = CurrentColomn; i >= targetRow && j <= targetColomn; i--, j++)
            {
                if (i == targetRow && j == targetColomn)
                {
                    validMove = true;
                }
            }
            if (!validMove)
            {
                return false;
            }
        }
    }
}