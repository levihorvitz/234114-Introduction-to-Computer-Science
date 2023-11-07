/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>



/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/



/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/
int checkDigit(int id)                          //calculate check digit
{
    int id2 =0;
    int sum =0;

    for (int i = 0 ; i< 8; ++i)
    {
        id2 = id%10;

        if( i%2 ==0)                            //if the digit in even spot
        {
                id2 = id2*2;
                if (id2>9)
                id2 = id2%10 + id2/10 ;          //sum the digit of number bigger then 9
        }
            sum += id2;
            id = id/10;                          //prepare the next digit
    }
       sum = (10 - sum%10);                      //calculate final digit
          if (sum != 10)
           {
           return (sum);
           }

          else

           return (0);
    }



int main()
{
    char test;
    int id = 0;

    printf("Please enter the letter C for calculating CheckDigit and the letter V for validating an ID by its CheckDigit:\n");
    scanf("%c", &test);

    if (test == 'C')                                //first option
    {
        printf("\nCalculating CheckDigit, please enter 8 digits:\n\n");
       if (scanf("%d", &id) == 1)                //verified the value
       {

        printf("CheckDigit = %d" ,checkDigit(id));

       }
       else
       {
        printf("ERROR");

        return 0;
       }
    }
    else if (test == 'V')                            //second option
    {
        printf("\nValidating ID, please enter 9 digits ID:\n\n");
        if (scanf("%d" , &id)== 1)                   //verified the value
         {
            printf("You have entered CheckDigit = %d\n", id%10);

            printf("Calculated CheckDigit = %d\n\n", checkDigit(id/10));

            if (checkDigit(id/10) == id%10)
            {

              printf("Legal ID :)");
            }
            else
            {
              printf("Illegal ID :(");

            }
         }
        else
        {
                printf("ERROR\n");

        }

    }

   return 0;
}


