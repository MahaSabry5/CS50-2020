from cs50 import *
from math import *

# make sure that the change not negative just positive number
while True:
    n = get_float("Change owed: ")
    if (n >= 0):
        break
    
count = 0 
coins = round(n * 100)

# calculate cash that will be paid
while (coins != 0):
    if (coins >= 25 ):
        count += 1
        coins -= 25
        
    elif (coins >= 10 ):
        count += 1
        coins -= 10
    
    elif (coins >= 5 ):
        count += 1
        coins -= 5

    elif (coins >= 1 ):
        count += 1
        coins -= 1 
    
print(count)
