#include <iostream>
#include <vector>
using namespace std;

// Function to print the board
void printBoard(vector<vector<char>>& board){
    int N = board.size();
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if placing a queen at (row, col) is safe
bool isSafe(vector<vector<char>>& board, int row, int col){
    int N = board.size();

    // Check left row
    for(int i=0; i<col; i++){
        if(board[row][i] == 'Q'){
            return false;
        }
    }

    // Check upper left diagonal
    for(int i=row, j=col; i>=0 && j>=0; i--, j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    // Check lower left diagonal
    for(int i=row, j=col; i<N && j>=0; i++, j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    return true;
}

// Function to solve the N-Queens problem
bool solveNQueens(vector<vector<char>>& board, int col){
    int N = board.size();
    if(col >= N){ // All queens are placed
        return true;
    }

    for(int i=0; i<N; i++){
        if(isSafe(board, i, col)){
            board[i][col] = 'Q';

            if(solveNQueens(board, col+1)){
                return true;
            }

            board[i][col] = '.'; // Backtrack
        }
    }
    return false;
}

int main(){
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    // Initialize board
    vector<vector<char>> board(N, vector<char>(N, '.'));

    if(solveNQueens(board, 0)){
        cout << "Solution exists:" << endl;
        printBoard(board);
    } else {
        cout << "Solution doesn't exist." << endl;
    }
    return 0;
}
