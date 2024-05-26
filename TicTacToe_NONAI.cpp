#include<bits/stdc++.h>
using namespace std;

vector<int> board(9, 2);
int blank = 2, x = 3, o = 5;
int player = 1;
int turn = 1;

void printBoard(){
    for(int i = 0; i < 3; i++){
        cout << "---------" << endl;
        for(int j = i * 3; j < i * 3 + 3; j++){
            if(board[j] == 3)
                cout << "|X|";
            else if(board[j] == 5)
                cout << "|O|";
            else
                cout << "| |";
        }
        cout << endl;
    }
    cout << "---------" << endl;
}

bool checkWin(int p){
    for(int i = 0; i < 3; i++){

        if(board[i * 3] * board[i * 3 + 1] * board[i * 3 + 2] == p * p * p)
            return true;
        if(board[i] * board[i + 3] * board[i + 6] == p * p * p)
            return true;
    }
        if(board[0] * board[4] * board[8] == p * p * p)
            return true;
        if(board[2] * board[4] * board[6] == p * p * p)
            return true;

    return false;
}

void go(int position){
    if(turn % 2 == 1)
        board[position - 1] = x;
    else
        board[position - 1] = o;

    turn++;
}

int make2(){

    if(board[4] == blank)
        return 5;

    for(int i = 1; i < 9; i += 2){
        if(board[i] == blank)
            return i + 1;
    }
    return -1;
}

int possWin(int p){
    for(int i = 0; i < 3; i++){

        if(board[i * 3] * board[i * 3 + 1] * board[i * 3 + 2] == p * p * blank){
            for(int j = i * 3; j < i * 3 + 3; j++){
                if(board[j] == blank)
                    return j + 1;
            }
        }
        if(board[i] * board[i + 3] * board[i + 6] == p * p * blank){
            for(int j = i * 3; j < i * 3 + 3; j++){
                if(board[j] == blank)
                    return j + 1;
            }
        }
    }
        if(board[0] * board[4] * board[8] == p * p * blank){
            if(board[0] == blank)
                return 1;
            if(board[4] == blank)
                return 5;
            if(board[8] == blank)
                return 9;

        }
        if(board[2] * board[4] * board[6] == p * p * p){
            if(board[2] == blank)
                return 3;
            if(board[4] == blank)
                return 5;
            if(board[6] == blank)
                return 7;
        }

    return -1;

}

int anywhere(){
    for(int i = 0; i < 9; i++){
        if(board[i] == blank)
            return i + 1;
    }
    return -1;
}

int main(){
    cout << "Enter 1 for Computer and 2 for Human : " << endl;
    cin >> player;

    while(turn <= 9){
        if(player == 1){
            switch(turn){

                case 1:
                    go(1);
                    break;

                case 2:
                    if(board[4] == blank)
                        go(5);
                    else
                        go(1);
                    break;

                case 3:
                    if(board[8] == blank)
                        go(9);
                    else
                        go(3);
                    break;

                case 4:
                    if(possWin(x) != -1)
                        go(possWin(x));
                    else{
                        int pos = make2();
                        if(pos != -1)
                            go(pos);
                    }
                    break;

                case 5:
                    if(possWin(x) != -1)
                        go(possWin(x));
                    else if(possWin(o) != -1)
                        go(possWin(o));
                    else{
                        if(board[6] == blank)
                            go(7);
                        else
                            go(3);
                    }
                    break;

                case 6:
                    if(possWin(o) != -1)
                        go(possWin(o));
                    else if(possWin(x) != -1)
                        go(possWin(x));
                    else
                        go(make2());
                    break;

                case 7:
                    if(possWin(x) != -1)
                        go(possWin(x));
                    else if(possWin(o) != -1)
                        go(possWin(o));
                    else
                        go(anywhere());
                    break;

                case 8:
                    if(possWin(o) != -1)
                        go(possWin(o));
                    else if(possWin(x) != -1)
                        go(possWin(x));
                    else
                        go(anywhere());
                    break;

                case 9:
                    if(possWin(x) != -1)
                        go(possWin(x));
                    else if(possWin(o) != -1)
                        go(possWin(o));
                    else
                        go(anywhere());
                    break;

                default:
                    break;
            }
            player = 2;
        }
        else{
            int pos;
            cout << "Enter the position : " << endl;
            cin >> pos;

            if(board[pos - 1] == blank){
                go(pos);
                player = 1;
            }

            else
                cout << "Enter valid position" << endl;
        }
        printBoard();

        if(checkWin(o)){
            cout << "O is the winner" << endl;
            break;
        }
        if(checkWin(x)){
            cout << "X is the winner" << endl;
            break;
        }

        if(turn == 10)
            cout << "It is a draw" << endl;
    }
    return 0;
}
