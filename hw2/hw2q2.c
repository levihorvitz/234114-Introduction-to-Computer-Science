#include <stdio.h>
#define ARRAYSIZE 32

void PrintEnterMessage(){
    printf("Please enter a binary digit:\n");
}
void PrintScannedBinaryNumberIs(){
    printf("Scanned binary number is:\n");
}
void PrintOperationChoiceMessage(){
    printf("\nEnter S for shift-right or D of unsigned int representation:\n");
}
void PrintShiftedBinaryNumberIs(){
    printf("Shifted binary number is:\n");
}
void PrintUnsignedIntRepresentationIs(){
    printf("Unsigned int representation is:\n");
}

void PrintArry(char a[ARRAYSIZE]) {
    for (int i = 0; i <ARRAYSIZE ; ++i) {
        printf("%c", a[i]);
    }
}
void ShiftRight(char a[ARRAYSIZE]){
    printf("%d",0);
    for (int i = 0; i <ARRAYSIZE-1 ; ++i) {
        printf("%c", a[i]);
    }

}


void UnsignedIntValue(char *a) {
    int digit=1, sum=0;
    for (int i = ARRAYSIZE-1; i >-1; i--){
        if(a[i]=='1') {
            if (i ==(ARRAYSIZE-1))
                sum = 1;
            else {
                for (int j = 0; j <ARRAYSIZE-1- i; j++) {
                    digit = digit * 2;
                }
                sum += digit;
                digit=1;
            }
        }
    }
    printf("%d",sum);
}
int ProgramAction(char char_arry[ARRAYSIZE]){
    char operation;
    PrintScannedBinaryNumberIs();
    PrintArry(char_arry);
    PrintOperationChoiceMessage();
    scanf(" %c", &operation);
    if (operation == 'S') {
        PrintShiftedBinaryNumberIs();
        ShiftRight(char_arry);
    } else {
        PrintUnsignedIntRepresentationIs();
        UnsignedIntValue(char_arry);
    }
    return 1;
}

int main(){
    int j=0,sum=0;
    char num='0';
    char char_arry[ARRAYSIZE];
    PrintEnterMessage();
    for (int i = 0; i < ARRAYSIZE; i++) {
        char_arry[i] = '0';
    }
    while (num != '!'){
        scanf(" %c", &num);
        if(num != '!')
            char_arry[j++]=num;
        sum++;
    }
    sum--;
    for (int k = sum; k > 0 ; --k) {
        char_arry[ARRAYSIZE-1 - sum + k] = char_arry[k-1];
        char_arry[k-1] = '0';
    }
   ProgramAction(char_arry);
    return 0;
}


