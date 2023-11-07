/*-------------------------------------------------------------------------
    Include files:
-------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdbool.h>
/*-------------------------------------------------------------------------
    Constants and definitions:
-------------------------------------------------------------------------*/
#define N 11
#define TWO_DIVADIBLE 2
#define X 'X'
#define O 'O'
#define BOTTOM_LINE '_'
/*-------------------------------------------------------------------------
    Function declaration
-------------------------------------------------------------------------*/
void print_welcome();
void print_enter_board_size();
void print_board(char board[N][N], int n);
void print_player_turn(int player_index);
void print_error();
void print_winner(int player_index);
void print_tie();

/*-------------------------------------------------------------------------
    Implementation
-------------------------------------------------------------------------*/
//chack sum_sign
//4 lines
bool chack_sum_sign(int sum_sign,int zise){
    if(sum_sign==zise)
        return true;
    else
        return false;
}
//Checking the queue of some player
//4 lines
int user_turn(int count_turn){
    if(count_turn%TWO_DIVADIBLE)
        return 1;
    else
        return TWO_DIVADIBLE;
}
//Checks if all characters in the row are the same
//9 lines
bool chack_row(char board[N][N],int zise, char sign){
    int sum_sign=0;
    for (int i = 0; i < zise ; ++i) {
        for (int j = 0; j < zise ; ++j) {
            if(board[i][j] == sign)
                sum_sign++;
        }
        if (chack_sum_sign(sum_sign,zise))
            return true;
        sum_sign=0;
    }
    return false;
}
//Checks if all characters in the col are the same
//9 lines
bool chack_coll(char board[N][N],int zise, char sign){
    int sum_sign=0;
    for (int i = 0; i < zise ; ++i) {
        for (int j = 0; j < zise ; ++j) {
            if(board[j][i] == sign)
                sum_sign++;
        }
        if (chack_sum_sign(sum_sign,zise))
            return true;
        sum_sign=0;
    }
    return false;
}
//Checks if all characters in the first slant are the same
//5 lines
bool chack_first_slant(char board[N][N],int zise, char sign){
    int sum_sign=0;
    for (int i = 0; i < zise ; ++i) {
        if( board[i][i]==sign)
            sum_sign++;
    }
    return chack_sum_sign(sum_sign,zise);
}
//Checks if all characters in the second sland are the same
//5 lines
int chack_second_sland(char board[N][N],int zise, char sign){
    int sum_sign=0;
    for (int i = zise - 1, j=0; i > -1 ; --i) {
        if(board[j++][i] == sign)
            sum_sign++;
    }
    return chack_sum_sign(sum_sign,zise);
}
//Checks all options to get a sequence of identical characters
//4 lines
bool chack_board(char board[N][N],int zise, char sign){
    if( chack_row(board,zise,sign) ||
        chack_coll(board,zise,sign) ||
        chack_first_slant(board,zise,sign)||
        chack_second_sland(board,zise,sign))
        return true;
    else
        return false;
}

//Checks the status of the game if there is a win or a draw or you can continue playing
//12 lines
bool chackStateOfTheGame(char board[N][N] , int zise, int row, int col, int player_index, int count_turn){
    if (chack_board(board, zise, board[row][col])) {
        if(player_index%TWO_DIVADIBLE == 0)
            player_index = TWO_DIVADIBLE;
        else
            player_index =1;
        print_winner(player_index);
        return false;
    }
    if (count_turn == (zise * zise )) {
        print_tie();
        return false;
    } else
        return true;
}

//completed board in the sign '_'
//3 lines
void completed_board(char board[N][N],int zise){
    for (int i = 0; i < zise; ++i) {
        for (int j = 0; j <zise ; ++j) {
            board[i][j]=BOTTOM_LINE;
        }
    }
}

//Checks whether the place requested is valid
//4 lines
bool legal_locition(char board[N][N],int row, int col, int zise){
    if(  row < zise && col > -1 && col < zise)
        if(board[row][col]== BOTTOM_LINE || row<0)
            return true;
    return false;
}

//save moves of oll the player
//2 lines
void save_moves(int memorys_arry[TWO_DIVADIBLE][N*N], int count_turn, int row, int col){
    memorys_arry[0][count_turn]=row;
    memorys_arry[1][count_turn]=col;
}

//Performs a repetition operation during moves
//6 lines
void undo(char board[N][N],int memorys_arry[TWO_DIVADIBLE][N*N],int zise, int count_turn, int move_back){
    for (int i = 0; i <move_back ; ++i) {
        int x=memorys_arry[0][count_turn-1];
        int y=memorys_arry[1][count_turn-1];
        board[x][y]=BOTTOM_LINE;
        count_turn--;
    }
    print_board(board,zise);
}
//insert sign x or o
//5 lines
void insert_sign(char board[N][N], int zise,int row, int col, int player_index){
    if (player_index == 1)
        board[row][col] = X;
    else
        board[row][col] = O;
    print_board(board, zise);
}

//Checks if the repeat action is an odd number or illegal
//6 lines
bool negativ_num(char board[N][N],int memorys_arry[TWO_DIVADIBLE][N*N],int zise, int count_turn, int row){
    if (count_turn>=-row && (-row)%TWO_DIVADIBLE) {
        undo(board, memorys_arry, zise, count_turn, -row);
        return true;
    }
    else
        print_error();
    return false;
}

//Checking the legality of moves
//12 lines
bool Checking_the_legality_of_moves(char board[N][N], int zise, int row, int col, int* player_index,
        int* count_turn, bool* should_print, int memorys_arry[TWO_DIVADIBLE][N * N],bool* endgame){
    if (legal_locition(board, row, col, zise)) {
        insert_sign(board, zise, row, col, *player_index);
        save_moves(memorys_arry, *count_turn, row, col);
        (*player_index)++;
        (*count_turn)++;
        if (!chackStateOfTheGame(board, zise, row, col, *player_index, *count_turn))
            *endgame = true;
        return true;
    } else {
        print_error();
        *should_print = false;
        return false;
    }
}

//Check the line input
//5 lines
void chek_the_line(char board[N][N], int zise, int row, int* player_index,
        int* count_turn, bool* should_print, int memorys_arry[TWO_DIVADIBLE][N * N]){
    if(negativ_num(board,memorys_arry, zise,*count_turn,row)){
        *count_turn += row;
       (*player_index)++;
    } else
        *should_print = false;
}

//Column absorption. Line and column synchronization
//3 lines
void Column_absorption(int* row, int* col){
    scanf("%d", col);
    (*row)--;
    (*col)--;
}

//Calculate and print the player turn
//4 lines
void Calculate_turn(int *player_index, bool *should_print){
    *player_index = user_turn(*player_index);
    if(*should_print)
        print_player_turn(*player_index);
    *should_print =true;
}

//Get the characters from the player
//13 lines
int program_action(char board[N][N], int zise){
    int row=0, col=0, count_turn = 0, player_index=1, memorys_arry[TWO_DIVADIBLE][N * N];
    bool should_print = true,endgame = false;
    while(1) {
        Calculate_turn(&player_index, &should_print);
        scanf("%d", &row);
        if (row < 0) {
            chek_the_line(board, zise, row, &player_index, &count_turn, &should_print, memorys_arry);
            continue;
        }
        Column_absorption(&row,&col);
       if(!Checking_the_legality_of_moves(board, zise, row, col, &player_index, &count_turn, &should_print,
                                         memorys_arry,&endgame))
           continue;
       if(endgame)
           return 0;
    }
}



//start the game
// 8 lines
int main() {
    int zise;
    char board[N][N] = {{0}};
    print_welcome();
    print_enter_board_size();
    scanf("%d", &zise);
    completed_board(board, zise);
    print_board(board, zise);
    return program_action(board,zise);
}
//print welcome message
//1 lines
void print_welcome()
{
    printf("*** Welcome to AVOIDANCE TIC-TAC-TOE game ***\n\n");
}

//print message to enter board size
//1 lines
void print_enter_board_size()
{
    printf("Please enter board size (1 to %d):\n", N);
}

//print the board
//7 lines
void print_board(char board[N][N], int n)
{
    printf("\nCurrent board:\n");
    for (int i = 0; i < n; i++)
    {
        printf("|");
        for (int j = 0; j < n; j++)
        {
            printf("%c|", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//print a request for player with index "player_index" to move
//1 lines
void print_player_turn(int player_index)
{
    printf("\nPlayer ** %d **, enter next move:\n", player_index);
}

//print error message
//1 lines
void print_error()
{
    printf("Illegal move!!!, please try again:\n");
}

//print the winner
//1 lines
void print_winner(int player_index)
{
    printf("Player %d Wins! Hooray!\n", player_index);
}

//print message to announce there is a tie (no one wins)
//1 lines
void print_tie()
{
    printf("It's a tie!\n");
}

