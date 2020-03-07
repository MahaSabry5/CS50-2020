#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n ;
    //get the height from the user between 1 and 8
    do
    {
        n = get_int("Enter positive number: ");
    }
    while (n < 1 || n > 8);
    // iterates the height and print spaces and hashes 
    for (int i = 0 ; i < n ; i++)
    {
        for (int k = 1 ; k < n - i ; k++)
        {
            printf("%c", ' ');
        }
        for (int j = 0 ; j < i + 1 ; j++)
        {
            printf("#");
        }

        printf("\n");
    
    }
}
