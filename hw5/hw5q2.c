#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define N 4
#define EMPTY_CELL -1


void PrintWelcomeMessage()
{
    printf("Please enter road matrix:\n");
}

void PrintSourceCityMessage()
{
    printf("Please enter source city:\n");
}

void PrintDestinationCityMessage()
{
    printf("Please enter destination city:\n");
}

void PrintShortestPathMessage()
{
    printf("The shortest path is:\n");
}

void PrintNumber(int num)
{
    printf("%d", num);
}

void PrintWhiteSpace()
{
    printf(" ");
}

//The function summarizes the way
int length (int matrix[N][N],int temp_array[N])
{
    int sum = 0;
    for (int i = 0; i < N -1; ++i) {
        if(temp_array[i+1] != EMPTY_CELL)
            sum += matrix[temp_array[i]][temp_array[i +1]];
    }
    return sum;
}

//The function checks the shortest way
void check_short_way(int matrix[N][N], int way[N], int temp_array[N], int* min){
    int sum = length(matrix,temp_array);
    if(sum<*min) {
        *min = sum;
        for (int i = 0; i < N; ++i) {
            way[i] = temp_array[i];
        }
    }
}

//The function checks to see if the space in the cell in temp_array is free
bool is_legal(int temp_array[N],int l){
        for (int k = 0; k <N ; ++k)
            if(temp_array[k]==l)
                return false;
        return true;
}

//Recursion function, works to find ways from source to destination
void find_short_way(int matrix[N][N],int way[N],int temp_array[N],int  destination, int* min, int move){
    //Stop conditions if we have reached our destination
    if(temp_array[move-1]==destination) {
        check_short_way(matrix,way,temp_array,min);
        return;
    }
    //Stop conditions if the way is longer than the ways ahead
    if(length(matrix,temp_array) > *min){
        return;
    }
    //Finding and returning the way
    for (int k = 0; k <N ; ++k) {
        if (is_legal(temp_array,k)){
            temp_array[move]=k;
            find_short_way(matrix,way,temp_array,destination,min,move + 1);
            temp_array[move] = EMPTY_CELL;
        }
    }
    temp_array[move]=EMPTY_CELL;
    return;
}

//Main function, responsible for printing and calling for secondary functions
int main() {
    int source,destination, matrix[N][N], way[N]={EMPTY_CELL,EMPTY_CELL,EMPTY_CELL,EMPTY_CELL},
        temp_array[N]={EMPTY_CELL,EMPTY_CELL,EMPTY_CELL,EMPTY_CELL};
    PrintWelcomeMessage();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    PrintSourceCityMessage();
    scanf("%d", &source);
    PrintDestinationCityMessage();
    scanf("%d", &destination);
    way[0]=source;
    temp_array[0] = source;
    int min = INT_MAX;
    find_short_way(matrix,way,temp_array,destination,&min,1);
    PrintShortestPathMessage();
    for (int k = 0; k <N ; ++k) {
        if (way[k]!=EMPTY_CELL) {
            PrintNumber(way[k]);
            PrintWhiteSpace();
        }
    }
    return 0;
}
