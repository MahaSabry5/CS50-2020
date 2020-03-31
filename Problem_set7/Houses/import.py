from sys import argv , exit
import csv
from cs50 import SQL

# check if correct number of command-line arguments
if len(argv) > 2:
    print("Usage: python import.py data.csv")
    exit(1)

# open our database
db = SQL("sqlite:///students.db")

# open the csv file
csv_file = csv.reader(open(argv[1]))
next(csv_file)

# fill the database with each row of the csv file
for row in csv_file:
    #print(row)
    name = row[0].split()
    #print(name)
    if (len(name) > 2):
        db.execute("INSERT INTO students (first, middle, last ,house, birth) VALUES(?,?,?,?,?)",name[0],name[1],name[2],row[1], row[2])
    elif (len(name) == 2 ):
        db.execute("INSERT INTO students (first, middle, last ,house, birth) VALUES(?,?,?,?,?)",name[0],None,name[1],row[1], row[2])


    
        
