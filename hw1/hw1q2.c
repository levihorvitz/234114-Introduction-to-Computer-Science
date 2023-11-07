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
int isempty (long long int x)
{
int num =0;
 num = x%100;
   if (num >= 'a' && num <= 'z')
   {
           return 1;
   }
        else
       {
        num = x%1000;
        if (num >= 'a' && num <= 'z')
                   return 1;

        }
    return 0;
}

int code (long long int x)                                 //get chars value
{
 int num = 0;
 while (x != 0)
 {
   num = x%100;

   if (num >= 'a' && num <= 'z')
     {
         if (num % 2 != 0)
         {
               printf("%c",num);

         }
      else
         {
                printf ("%c",(num- 'a')+'A');

         }
      x = x/100;
     }
    else
       {
        num = x%1000;
        if (num >= 'a' && num <= 'z')
        {
        if (num % 2 != 0)
         {
               printf("%c",num);
         }
      else
         {
                printf ("%c",(num- 'a')+'A');
         }
          x = x/1000;
        }
        else
        {
                    return 0;

        }
       }
      }
      return(1);
}

int main()
{
unsigned long int word =0;
long long int word2 = 0;
   printf("Enter an encoded word and I'll do my best:\n") ;                                         // flip number
   scanf(" %lu", &word);
   while (word != 0)
   {
    word2 = (word2*10+ word%10);
    word /=10;
   }

 if  (isempty(word2)== 0)
    {
    printf("\nThere is nothing there :(\n");


    }
 else
    {
            printf("The decoded word is: ");
            code(word2);
            printf("\nDone and even had time for coffee :)");
    }

  return 0;
    }
