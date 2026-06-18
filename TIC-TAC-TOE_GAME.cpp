#include <iostream>
using namespace std;

char board[3][3];

// Initialize board
void initializeBoard() {
    char ch = '1';
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ch++;
        }
    }
}

// Display board
void displayBoard() {
    cout << "\n";
    for(int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
        if(i < 2)
            cout << "---|---|---" << endl;
    }
    cout << "\n";
}

// Check win
bool checkWin() {
    // Rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] &&
           board[i][1] == board[i][2])
            return true;
    }

    // Columns
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == board[1][i] &&
           board[1][i] == board[2][i])
            return true;
    }

    // Diagonals
    if(board[0][0] == board[1][1] &&
       board[1][1] == board[2][2])
        return true;

    if(board[0][2] == board[1][1] &&
       board[1][1] == board[2][0])
        return true;

    return false;
}

// Check draw
bool checkDraw() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] >= '1' && board[i][j] <= '9')
                return false;
        }
    }
    return true;
}

int main() {
    char playAgain;

    do {
        initializeBoard();
        char currentPlayer = 'X';
        int choice;

        while(true) {
            displayBoard();

            cout << "Player " << currentPlayer
                 << ", enter a position (1-9): ";
            cin >> choice;

            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;

            if(choice < 1 || choice > 9 ||
               board[row][col] == 'X' ||
               board[row][col] == 'O') {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            board[row][col] = currentPlayer;

            if(checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer
                     << " wins!\n";
                break;
            }

            if(checkDraw()) {
                displayBoard();
                cout << "The game is a draw!\n";
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;

    } while(playAgain == 'Y' || playAgain == 'y');

    cout << "Thank you for playing Tic-Tac-Toe!\n";
    return 0;
}