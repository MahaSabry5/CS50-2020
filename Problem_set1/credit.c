#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool check_sum(long n);
int count, first_two, first ;
int main(void)
{
    //take the card number form user
    long n = get_long("Number: ");
    bool check = check_sum(n);
    //check the type of the card visa or amex ...
    if (check)
    {
        if (count == 15 && (first_two == 34 || first_two == 37))
        {
            printf("AMEX\n");
        }
        else if (count == 16 && first_two >= 51 && first_two <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if ((count == 14 || count == 16) && first == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    return 0 ;   
}
//function to do the check sum on the card number
bool check_sum(long n)
{
    count = 0, first_two = 0, first = 0 ;
    int sum_of_double_odds = 0, sum_of_evens = 0 ;
    int second = 0 ;
    while (n)
    {
        second = first;
        first = n % 10;
        if (count % 2 == 0)
        {
            sum_of_evens += first;
        }
        else
        {
            int multiple = 2 * first;
            sum_of_double_odds += (multiple / 10) + (multiple % 10);
        }

        n /= 10;
        count++;  
    }
    
    int sum = (sum_of_evens + sum_of_double_odds) ;
    first_two = (first * 10) + second;

    if (sum % 10 == 0)
    {
        return true ;
    }
    else 
    {
        return false;
    }
}
