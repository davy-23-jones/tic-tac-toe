#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

const char PLAYER = 'X';
const char COMPUTER = 'O';
char board[3][3];

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char winner);

int main(){
    char winner = ' ';
    resetBoard();
    while(winner==' '){
        printBoard();
        playerMove();
        computerMove();
        winner = checkWinner();
        if(winner!=' '){
            printWinner(winner);
        }
    }
    return 0;
}

void resetBoard(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            board[i][j] = ' ';
        }
    }
}

void printBoard(){
    printf("\n %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
}

int checkFreeSpaces(){
    int freeSpaces = 9;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] != ' '){
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}

void playerMove(){
    int x;
    int y;
    while(board[x][y] != ' '){
        printf("\nEnter the row:");
        scanf("%d", &x);
        printf("\nEnter the column:");
        scanf("%d", &y);
        if(board[x][y] != ' '){
            printf("Invalid");
        }
        else{
            if(x==2 && y == 2){
                printf("dfj;lkajf");
            }
            board[x][y] = PLAYER;
            break;
        }
    }
   
}

void computerMove(){
    srand(time(0));
    while(1){
        int x = rand() % 3;
        int y = rand() % 3;
        if(board[x][y] == ' '){
            board[x][y] = COMPUTER;
            break;
        }
    }
}

char checkWinner(){
    // for rows
    char winner = ' ';
    for(int i=0; i<3; i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
            winner = board[i][0];
        }
    }
    // for columns
    for(int i=0; i<3; i++){
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            winner = board[0][i];
        }
    }
    // for diagonal
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
        winner = board[0][0];
    }
    else if(board[0][2] == board[1][1] && board[0][2] == board[2][0]){
        winner = board[0][2];
    }
    return winner;
}

void printWinner(char winner){
    printBoard();
    if(winner == PLAYER){
        printf("\n\nYou won!");
    }
    else if(winner == COMPUTER){
        printf("\n\nYou lost..");
    }
}