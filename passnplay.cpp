#include"core.h"
void passnplay()
{
    system("cls");
    string move;
    char board[8][8] = { {'r','n','b','q','k','b','n','r'},
                         {'p','p','p','p','p','p','p','p'},
                         {'.','.','.','.','.','.','.','.'},
                         {'.','.','.','.','.','.','.','.'},
                         {'.','.','.','.','.','.','.','.'},
                         {'.','.','.','.','.','.','.','.'},
                         {'P','P','P','P','P','P','P','P'},
                         {'R','N','B','Q','K','B','N','R'}, };
    cout <<R"(
+---------------+
|r|n|b|q|k|b|n|r|
|p|p|p|p|p|p|p|p|
|.|.|.|.|.|.|.|.|
|.|.|.START.|.|.|
|.|.|.GAME..|.|.|
|.|.|.|.|.|.|.|.|
|P|P|P|P|P|P|P|P|
|R|N|B|K|Q|B|N|R|
+---------------+)";
	cout<<endl << "Press Enter to start....";
    getchar();
    bool q_blackCastle = true;
    bool k_blackCastle = true;
    bool Q_whiteCastle = true;
    bool K_whiteCastle = true;
    int moveColor = true;
    int moveCounter = 1;
    int BlackdrawCounter = 1;
    int WhitedrawCounter = 1;
    system("cls");
    while (true)
    {
        start:
        if (moveColor)
        {
            cout << "White to move!"<<endl;
        }
        else if (!moveColor)
        {
            cout << "Black to move!" << endl;
        }
        cout << "+---------------+"<<endl;
        for (int i = 0; i < 8; i++)
        {
            cout << "|";
            for (int j = 0; j < 8; j++)
            {
                cout << board[i][j]<<"|";
            }
            if (i == 3)
            {
                cout<<"    | Move:" << moveCounter;
            }
            cout << endl;
        }
        cout << "+---------------+" << endl;
        cout << "Enter move: ";
        getline(cin, move);
        if (move == "resign"&&moveColor==true)
        {
            cout << "Black won by resignation."<<endl;
            return;
        }

        else if (move == "abort")
        {
            cout << "Game aborted."<<endl;
            return;
        }
        else if (move == "resign" && moveColor == false)
        {
            cout << "White won by resignation." << endl;
            return;
        }
        else if (move == "draw" && moveColor == true)
        {
            if (moveCounter < 15)
            {
                cout << "Draw can be offered after 15 moves:" << endl;
                goto start;
            }
            
            else if(WhitedrawCounter>15)
            {
                cout << "Black do you want to accept draw(accept/nope):" << endl;
                getline(cin,move);
                    cin.ignore();
                if (move == "accept")
                {
                    cout << "Game drawn by agreement" << endl;
                    return;
                }
                else
                {
                    cout << "Offer rejected,try again after 15 moves"<<endl;
                    BlackdrawCounter = 0;
                    goto start;
                }
            }
            else
            {
                cout << "Draw counter is less than 15!"<<endl;
                goto start;
            }
        }
        else if (move == "draw" && moveColor == false)
        {
            if (moveCounter < 15)
            {
                cout << "Draw can be offered after 15 moves:" << endl;
                goto start;
            }
            else if(WhitedrawCounter>15)
            {
                cout << "White do you want to accept draw(accept/nope):" << endl;
                getline(cin, move);
                cin.ignore();
                if (move == "accept")
                {
                    cout << "Game drawn by agreement" << endl;
                    return;
                }
                else
                {
                    cout << "Offer rejected,try again after 15 moves"<<endl;
                    WhitedrawCounter = 0;
                    goto start;
                }
            }
            else
             {
                cout << "Draw counter is less than 15!" << endl;
                goto start;
             }
        }
        else if (move == "fen")
        {
            writeFEN(board,K_whiteCastle,Q_whiteCastle,k_blackCastle,q_blackCastle,moveColor,moveCounter);
            goto start;
        }
        
        stringstream ss(move);
        string targetSqr,currentSqr;
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
       
        if(board[currentRow][CurrentColomn]=='.')
        {
            cout << "Invalid move, no piece on current square to move."<<endl;
        }
        else if (board[currentRow][CurrentColomn] > 'A' && board[currentRow][CurrentColomn] < 'Z' && moveColor == true)
        {
            if (board[targetRow][targetColomn] > 'A' && board[targetRow][targetColomn] < 'Z')
            {
                cout << "Illegal move, friendly piece on target square" << endl;
            }
            else
            {
                board[targetRow][targetColomn] = board[currentRow][CurrentColomn];
                moveColor = false;
                if (board[currentRow][CurrentColomn] == 'k')
                {
                    k_blackCastle = false;
                    q_blackCastle = false;
                }
                if (currentRow == 0 && CurrentColomn == 0)
                {
                    q_blackCastle = false;
                }
                if (currentRow == 7 && CurrentColomn == 7)
                {
                    K_whiteCastle = false;
                }
                if (currentRow == 7 && CurrentColomn == 0)
                {
                    Q_whiteCastle = false;
                }
                if (currentRow == 0 && CurrentColomn == 7)
                {
                    k_blackCastle = false;
                }
                if (board[currentRow][CurrentColomn] == 'K')
                {
                    K_whiteCastle = false;
                    Q_whiteCastle = false;
                }
                board[currentRow][CurrentColomn] = '.';
            }
        }
        else if (board[currentRow][CurrentColomn] > 'a' && board[currentRow][CurrentColomn] < 'z' && moveColor == false)
        {
            if (board[targetRow][targetColomn] > 'a' && board[targetRow][targetColomn] < 'z')
            {
                cout << "Illegal move, friendly piece on target square"<<endl;
            }
            else
            {
                board[targetRow][targetColomn] = board[currentRow][CurrentColomn];
                BlackdrawCounter++;
                WhitedrawCounter++;
                moveCounter++;
                moveColor = true; 
                if (board[currentRow][CurrentColomn] == 'k')
                {
                    k_blackCastle = false;
                    q_blackCastle = false;
                }
                if (currentRow == 0 && CurrentColomn == 0)
                {
                    q_blackCastle = false;
                }
                if (currentRow == 7 && CurrentColomn == 7)
                {
                    K_whiteCastle = false;
                }
                if (currentRow == 7 && CurrentColomn == 0)
                {
                    Q_whiteCastle = false;
                }
                if (currentRow == 0 && CurrentColomn == 7)
                {
                    k_blackCastle = false;
                }
                if (board[currentRow][CurrentColomn] == 'K')
                {
                    K_whiteCastle = false;
                    Q_whiteCastle = false;
                }
                board[currentRow][CurrentColomn] = '.';
            }
        }
        else
        {
            cout << "Invalid move, wrong turn!"<<endl;
        }
    }
}