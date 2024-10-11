#include <stdio.h>
#include <stdlib.h>

#define ROWS 3 
#define COLS 3   

// Function to print the current state of the game board
void print_board(char board[ROWS][COLS]) {
    printf("Tic Tac Toe\n");
    printf("-------------\n");
    printf("Player 1 (X) - Player 2 (O)\n");

    // Print the board with separators
    for (int i = 0; i < ROWS; i++) {
        printf("     |     |     |\n");
        printf("  %c  |  %c  |  %c  |\n", board[i][0], board[i][1], board[i][2]);
        if (i < ROWS - 1) {
            printf("_____|_____|_____|\n");
        }
    }
    printf("     |     |     |\n");
}

// Function to check if there's a winner
int check_winner(char board[ROWS][COLS]) {
    // Check rows and columns for a win
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0] == 'X' ? 1 : 2; // Player 1 or Player 2 wins
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i] == 'X' ? 1 : 2; // Player 1 or Player 2 wins
    }

    // Check diagonals for a win
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0] == 'X' ? 1 : 2; // Player 1 or Player 2 wins
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2] == 'X' ? 1 : 2; // Player 1 or Player 2 wins

    return 0; // No winner yet
}

int main() {
    // Initialize the game board
    char board[ROWS][COLS] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int player = 1; // Start with Player 1
    int moves = 0;  // Count of moves made
    int row, col;   // Player's move coordinates
    int winner = 0; // Variable to store the winner

    // Main game loop
    while (moves < ROWS * COLS && winner == 0) {
        print_board(board);
        printf("Player %d, enter row and column (0, 1, or 2) separated by a space: ", player);

        // Read player input
        if (scanf("%d %d", &row, &col) != 2) {
            printf("Invalid input. Please enter two integers.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        // Validate input and check if the cell is free
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Place the player's mark on the board
        board[row][col] = (player == 1) ? 'X' : 'O';
        moves++; // Increment move count

        // Check for a winner after the move
        winner = check_winner(board);

        // Switch to the other player
        player = (player == 1) ? 2 : 1;
    }

    // Final board display
    print_board(board);

    // Display the result of the game
    if (winner) {
        printf("Player %d wins!\n", winner);
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}
