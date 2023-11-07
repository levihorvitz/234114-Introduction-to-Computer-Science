#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define BASE_OF_TEN 10
#define TITHE 10
#define MIN_DIGITS 2

void PrintEnterNumber()
{
    printf("Please enter a number:\n");
}

void PrintIsPalindrome()
{
    printf("It's a palindrome!");
}

void PrintIsNotPalindrome()
{
    printf("It's not a palindrome!");
}

//Counts how many digits there are in number
int sum_digits(int num){
    int count=0;
    while (num) {
        count++;
        num= num / TITHE;
    }
    return count;
}

//Checks if the number is Palindrome
bool check_num(int num){
    double count=sum_digits(num);
    int division=pow(BASE_OF_TEN, count - 1);
    //Return condition if number is Palindrome
    if(count < MIN_DIGITS)
        return true;
    //Compares the beginning of the number with the end of the number
    if((num % TITHE) == (num / division))
        num= (num%division) / TITHE;
    else
            return false;
    //Callback to function
    check_num(num);
    return true;
}

//Main function. Scans the number and prints the conclusion
int main() {
    PrintEnterNumber();
    int num;
    scanf("%d", &num);
    if (check_num(num))
        PrintIsPalindrome();
    else
        PrintIsNotPalindrome();
    return 0;
}