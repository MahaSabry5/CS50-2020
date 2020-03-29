from cs50 import *

# check the range if the number from 1:8
while True:
    n = get_int("Enter positive number: ")
    if (n >= 1) and (n <= 8):
        break

# iterates the height and print spaces and hashes 
for i in range(n):
    print(' ' * (n - i - 1), end="")
    print("#" * (i + 1), end="  ")
    print("#" * (i + 1), end="")
    print("")
    