from sys import argv , exit
import csv
from cs50 import SQL

# check if correct number of command-line arguments
if len(argv) > 2:
    print("Usage: python roster.py house")
    exit(1)
    
# open our database
db = SQL("sqlite:///students.db")

# make query to select name and birth from database according to house name
rows = db.execute("SELECT first ,middle ,last ,birth FROM students WHERE house = ? ORDER BY last , first", argv[1])

# printing the name followed by birth year
for k in rows:
    print (k["first"],end=" ")
    if (k['middle'] == None):
        print (k['last'],end="")
        print(", born" , k['birth'])

    else:
        print(k['middle'],k['last'],end="")
        print(", born" , k['birth'])





