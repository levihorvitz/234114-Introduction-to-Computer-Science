#include<stdio.h>
#define MAX_SIZE 25

void matrix_multiply(int array1[MAX_SIZE][MAX_SIZE],int array2[MAX_SIZE][MAX_SIZE],int dim);

void PrintEnterMatrixDimension(){
    printf("Please enter matrix dimension: ");
    return;
}

void PrintEnterMatrix(){
    printf("Please enter your matrix:\n");
    return;
}

void PrintEnterNilpotencyIndex(){
    printf("Please enter Nilpotency index: ");
    return;
}

void PrintItIsKNilpotenetMatrix(int k){
    printf("It is %d-nilpotent matrix!\n", k);
    return;
}

void PrintItIsNotKNilpotentMatrix(int k){
    printf("It is not %d-nilpotent matrix.\n", k);
    return;
}
void PrintScannedMatrixIs(){
    printf("Scanned matrix is:\n");
    return;
}

void PrintMetrix(int a[MAX_SIZE][MAX_SIZE], int dim) {
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j <dim ; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int CheckZeroMetrix(int metrix[MAX_SIZE][MAX_SIZE],int dim){
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j <dim ; j++)
        {
            if( metrix[i][j] != 0)
                return 0;
        }
    }
    return 1;
}

void CopyMetrix(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE]){
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            b[i][j] = a[i][j];
        }
    }
}

int CheckNilpotenet(int metrix[MAX_SIZE][MAX_SIZE],int dim,int index){

    int temp_metrix[MAX_SIZE][MAX_SIZE];
    CopyMetrix(metrix,temp_metrix);
    for (int i = 1; i < index; ++i) {
        if(CheckZeroMetrix(metrix,dim)){
            return 0;
        }
        matrix_multiply(metrix,temp_metrix,dim);
    }
    return CheckZeroMetrix(metrix,dim);
}

void matrix_multiply(int metrix1[MAX_SIZE][MAX_SIZE],int metrix2[MAX_SIZE][MAX_SIZE],int dim){
    int temp_metrix[MAX_SIZE][MAX_SIZE];
    CopyMetrix(metrix1,temp_metrix);
    int sum =0;
    for (int i = 0; i < dim; i++) {
        for (int k = 0; k < dim; k++) {
            for (int j = 0; j < dim; j++) {
                sum += temp_metrix[i][j]*metrix2[j][k];
            }
            metrix1[i][k]=sum;
            sum=0;
        }
    }
}

int ProgramAction(int metrix[MAX_SIZE][MAX_SIZE],int dim){
    int index;
    PrintEnterNilpotencyIndex();
    scanf("%d", &index);
    if(CheckNilpotenet(metrix,dim, index)) {
        PrintItIsKNilpotenetMatrix(index);
    }
    else {
        PrintItIsNotKNilpotentMatrix(index);
    }
    return 1;
}

int main(){
    int dim;
    int metrix[MAX_SIZE][MAX_SIZE] = {{0}};
    PrintEnterMatrixDimension();
    scanf("%d", &dim);
    PrintEnterMatrix();
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j <dim ; j++)
        {
            scanf("%d",&metrix[i][j]);
        }
    }
    PrintScannedMatrixIs();
    PrintMetrix(metrix,dim);
    ProgramAction(metrix,dim);
    return 0;
}