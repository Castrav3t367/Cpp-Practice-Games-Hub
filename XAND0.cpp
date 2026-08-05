#include <iostream>

using namespace std;

// 1. THE GAME STATE
// A 3x3 grid to hold 'X', 'O', or empty spaces ' '
char board[3][3] = { {' ', ' ', ' '}, 
                     {' ', ' ', ' '}, 
                     {' ', ' ', ' '} };

// 2. THE RENDER PHASE
// Function to print the board to the console
void drawBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
    cout << "\n";
}

// Function to check if someone has won
char checkWinner() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        // Check rows
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) 
            return board[i][0];
        // Check columns
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) 
            return board[0][i];
    }
    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) 
        return board[0][0];
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) 
        return board[0][2];
    
    return ' '; // Return an empty space if there is no winner yet
}

int main() {
    char currentPlayer = 'X';
    int turnCount = 0;
    bool gameWon = false;

    cout << "Welcome to Tic-Tac-Toe!\n";

    // 3. THE GAME LOOP
    // Keep playing until 9 turns have passed or someone wins
    while (turnCount < 9 && !gameWon) {
        
        // DRAW
        drawBoard();
        
        // INPUT
        int row, col;
        cout << "Player " << currentPlayer << ", enter row (1-3) and column (1-3) separated by a space: ";
        cin >> row >> col;

        // Convert human numbers (1-3) to computer indexes (0-2)
        row--; 
        col--;

        // UPDATE (Check if move is valid)
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            
            board[row][col] = currentPlayer; // Place the marker
            turnCount++;                     // Increase the turn counter

            // Check for a winner
            char winner = checkWinner();
            if (winner != ' ') {
                drawBoard();
                cout << "Player " << winner << " wins!!\n";
                gameWon = true;
            } else {
                // Swap player for the next turn
                if (currentPlayer == 'X') {
                    currentPlayer = 'O';
                } else {
                    currentPlayer = 'X';
                }
            }
        } else {
            // The user typed a bad number or picked an occupied spot
            cout << "Invalid move! That spot is taken or out of bounds. Try again.\n";
        }
    } // End of Game Loop

    // If 9 turns passed and no one won
    if (!gameWon) {
        drawBoard();
        cout << "It's a draw!\n";
    }

    return 0;
}