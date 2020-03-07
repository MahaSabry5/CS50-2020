#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void){
    float n  ;
    int count = 0 ;
// get the change from user
    do
        {
            n = get_float("Change owed: ");
        } 
    while (n < 0);
// convert to cents
int coins = round(n*100);
// count the less number of change
while (coins != 0){
    if (coins >= 25 ){
        count++;
        coins-=25;
    }
    else if (coins >= 10 ){
        count++;
        coins-=10;
    }
    else if (coins >= 5 ){
        count++;
        coins-=5;
    }
    else if (coins >= 1 ){
        count++;
        coins-=1;
    }
}
printf("%i\n",count);
}
