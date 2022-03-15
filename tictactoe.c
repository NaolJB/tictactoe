#include<stdio.h>
#include<stdlib.h>
#include<time.h> // for the time function
void printBoard(char board[3][3]);
int placeMarker(char board[3][3], int row, int col, int player);
int computerMove(char board[3][3]);
int check(char board[3][3]);
int checkTie(char board[3][3]);
int main()
{
    char board[3][3];
    //fill board with empty spaces
    for(int i = 0; i <3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
    int isOver = 0; // 0 means game is not over
    int player = 1; // indicates who's making a move, -1 or 1
    int row, col;
    while(isOver == 0)
    {
        int count = 0;
        if(player == 1){
            printBoard(board);
            printf("\n\nPlease choose a row and column (1-3): ");
            scanf("%d %d", &row, &col);
            placeMarker(board, row, col, player);
        }

        // indicate player -1

        else
        {
            computerMove(board);
        }
        // call function to check if game is over
        isOver = check(board);
        if(checkTie(board) == 1){ printf("The game is tie\n");}
        player = player * -1;
        //end the game and check who won the game
    }
    printBoard(board);
    return 0;
}
// function to check the winner
int check(char board[3][3]){
    int count =0;
    for(int r = 0; r < 3; r++)
    {
        for(int c = 0; c < 3; c++)
        {
            if(board[r][c] == 'X' && board[r][c + 1] =='X' && board[r][c + 2] =='X')
            {
                printf("Player 1 is the winner\n"); return 1;
            }
            else if(board[r][c] == 'X' && board[r+1][c] =='X' && board[r+2][c] =='X')
            {
                printf("Player 1 is the winner\n"); return 1;
            }
            else if(board[r][c] == 'X' && board[r+1][c+1] =='X' && board[r+2][c+2] =='X')
            {
                printf("Player 1 is the winner\n"); return 1;
            }
            else if(board[r][c+2] == 'X' && board[r+1][c+1] =='X' && board[r+2][c] =='X')
            {
                printf("Player 1 is the winner\n"); return 1;
            }
            else if(board[r][c] == 'O' && board[r][c +1] == 'O' && board[r][c +2] == 'O'){
                printf("You lost the game\n"); return 1;
            }
            else if(board[r][c] == 'O' && board[r + 1][c] == 'O' && board[r + 2][c] == 'O'){
                printf("You lost the game\n"); return 1;
            }
            else if(board[r][c] == 'O' && board[r + 1][c + 1] == 'O' && board[r + 2][c + 2] == 'O'){
                printf("You lost the game\n"); return 1;
            }
            else if(board[r][c+2] == 'O' && board[r + 1][c + 1] == 'O' && board[r + 2][c] == 'O'){
                printf("You lost the game\n"); return 1;
            }
        }
    }
    return 0;
}
// function definitions
void printBoard(char board[3][3])
{
    for(int r = 0; r < 3; r++)
    {
        for(int c = 0; c < 3; c++)
        {
            printf("%c", board[r][c]);
            if(c <= 1){ printf("|"); }
        }
        if( r<=1){ printf("\n-----\n"); }
    }
}
//zero means couldn't place marker, try again, 1 means good move
int placeMarker(char board[3][3], int row, int col, int player){
    // Check if move is valid
    while(board[row - 1][col - 1] != ' ')
    {
        printf("There is a piece already there. Try again.\n\n");
        printf("Please enter row and column: ");
        scanf("%d %d", &row, &col);
    }

    board[row-1][col-1] = 'X';
    return 1;
}
int computerMove(char board[3][3])
{

    srand(time(NULL));
    int row, col;
    while(1){
        // Between 0 and 2
        row = rand()%3;
        col = rand()%3;

        //check if available
        if(board[row][col] == ' ')
        {
            board[row][col] = 'O';
            return 1;
        }
    }
}
int checkTie(char board[3][3]){

    int counter = 0;
    for(int r = 0; r < 3; r++)
    {
        for(int c = 0; c < 3; c++)
        {
            if(board[r][c] != ' '){
                counter = counter + 1;
            }
        }
    }
    if (counter == 9){return 1;}
    else{ counter = 0;}
    return 0;
}
