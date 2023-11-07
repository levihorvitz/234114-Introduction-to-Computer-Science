/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/
#define FIRST_LETTER 'a'
#define TWO 2

/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/
void AskBobForAliceMessage(){
    printf("Hey Bob, Please enter Alice's message:\n");
}
void PrintPizzaAndBear(){
    printf("Alice wants to eat Pizza and drink Beer this evening.");
}
void PrintPastaAndBear(){
    printf("Alice wants to eat Pasta and drink Beer this evening.");
}
void PrintRisottoAndBear(){
    printf("Alice wants to eat Risotto and drink Beer this evening.");
}
void PrintPizzaAndWine(){
    printf("Alice wants to eat Pizza and drink Wine this evening.");
}
void PrintPastaAndWine(){
    printf("Alice wants to eat Pasta and drink Wine this evening.");
}
void PrintRisottoAndWine(){
    printf("Alice wants to eat Risotto and drink Wine this evening.");
}

int ChackInformtion(int letter_sum, int monotonit_sum, int odd, int sum){
    if(odd<letter_sum/TWO){
        if(sum%TWO)
            PrintPizzaAndWine();
        else
            PrintPizzaAndBear();
        return 1;
    }
    if(letter_sum==monotonit_sum) {
        if (sum % TWO)
            PrintRisottoAndWine();
        else
            PrintRisottoAndBear();
    } else{
        if(sum%TWO)
            PrintPastaAndWine();
        else
            PrintPastaAndBear();
    }
    return 1;
}

int CheckMessage() {
    int sum = 0, monotonit_sum = 0, letter_sum = 0, odd = 0, last_num = 0;
    char char_scanf = '0';
    while (char_scanf != '@') {
        letter_sum++;
        scanf(" %c", &char_scanf);
        /*int letter_index = char_scanf - FIRST_LETTER + 1;*/
        int letter_index = char_scanf;
        if (letter_index % TWO)
            odd++;
        if (letter_index >= last_num) {
            last_num = letter_index;
            monotonit_sum++;
        }
        sum += letter_index;
    }
    letter_sum--;
    ChackInformtion(letter_sum,monotonit_sum,odd,sum);
    return 1;
}



int main() {

    AskBobForAliceMessage();
    CheckMessage();
    return 0;
}
