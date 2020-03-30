from cs50 import *  
from math import *

# take the card number form user
n = get_int("Number: ")
first = second = count = sum_of_evens = sum_of_double_odds = 0

# the check sum on the card number
while (n > 0) :

        second = first
        first = round(n % 10)
        if (count % 2 == 0):
            sum_of_evens += first
        
        else:
            multiple = 2 * first
            sum_of_double_odds += (multiple // 10) + round(multiple % 10)
        n //= 10
        count += 1 
first_two = (first * 10) + second
xx = (sum_of_evens + sum_of_double_odds) % 10 

# check the type of the card visa or amex ...

if (xx == 0): 
    if (count == 15 and (first_two == 34 or first_two == 37)):
        print("AMEX");
        
    elif (count == 16 and (51 <= first_two <= 55)):
        print("MASTERCARD")

    elif ((count == 14 or count == 16) and first == 4):
        print("VISA")
        
    else:
        print("INVALID")
else:
    print("INVALID")

    

