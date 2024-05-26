#include <bits/stdc++.h>
using namespace std;

vector<char> board(9, ' ');
int player;

bool checkWin(char p)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i * 3] == p && board[i * 3 + 1] == p && board[i * 3 + 2] == p)
            return true;
        if (board[i] == p && board[i + 3] == p && board[i + 6] == p)
            return true;
    }
    if (board[0] == p && board[4] == p && board[8] == p)
        return true;
    if (board[2] == p && board[4] == p && board[6] == p)
        return true;
    return false;
}

bool isBoardFull()
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == ' ')
            return false;
    }
    return true;
}

int evaluateBoard()
{
    if (checkWin('X'))
        return 10;
    if (checkWin('O'))
        return -10;
    return 0;
}

int minimax(int maxi)
{
    int score = evaluateBoard();

    if (score == 10 || score == -10)
        return score;

    if (isBoardFull())
        return 0;

    if (maxi)
    {
        int bestScore = -1000;
        for (int i = 0; i < 9; i++)
        {
            if (board[i] == ' ')
            {
                board[i] = 'X';
                bestScore = max(bestScore, minimax(!maxi));
                board[i] = ' ';
            }
        }
        return bestScore;
    }
    else
    {
        int bestScore = 1000;
        for (int i = 0; i < 9; i++)
        {
            if (board[i] == ' ')
            {
                board[i] = 'O';
                bestScore = min(bestScore, minimax(!maxi));
                board[i] = ' ';
            }
        }
        return bestScore;
    }
}

int bestMove()
{
    int bestScore = -1000;
    int pos = -1;
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == ' ')
        {
            board[i] = 'X';
            int moveScore = minimax(false);
            board[i] = ' ';

            if (moveScore > bestScore)
            {
                bestScore = moveScore;
                pos = i;
            }
        }
    }
    return pos;
}

void printBoard()
{
    for (int i = 0; i < 3; i++)
    {
        cout << "----------" << endl;
        for (int j = i * 3; j < i * 3 + 3; j++)
            cout << "|" << board[j] << "|";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    player = 1;
    while (!checkWin('X') && !checkWin('O') && !isBoardFull())
    {
        if (player == 1)
        {
            int best = bestMove();
            board[best] = 'X';
            player = 2;
        }
        else
        {
            int pos;
            cout << "Enter position(0 - 8): ";
            cin >> pos;
            if (board[pos] == ' ')
            {
                board[pos] = 'O';
                player = 1;
            }
            else
                cout << "Enter valid position" << endl;
        }
        printBoard();
        if (checkWin('X'))
        {
            cout << "X is the winner!!" << endl;
            break;
        }
        if (checkWin('O'))
        {
            cout << "Y is the winner!!" << endl;
            break;
        }
        if (isBoardFull())
        {
            cout << "It's a draw!" << endl;
            break;
        }
    }

    return 0;
}
