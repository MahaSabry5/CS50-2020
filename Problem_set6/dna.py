from sys import argv , exit
import csv

# check if correct number of command-line arguments
if len(argv) < 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

# open csv file and read it
csv_file = csv.reader(open(argv[1]))
name = next(csv_file)
name.pop(0)

# open text file and read it
text_file = open(argv[2],"r")
seq = text_file.read()

# make dictionary for the STRs 
sequences = {}
for item in name:
    sequences[item] = 0

# count the longest run of consecutive repeats of the STR in the DNA sequence   
for key in sequences:
    l = len(key)
    counter = 0
    for i in range(len(seq) - l):
        counter = 0
        if seq[i:i + l] == key :
            counter += 1
            while True:
                i += l 
                if seq[i:i + l] != key:
                    break
                elif seq[i:i + l] == key:
                    counter += 1
            if counter > sequences[key]:
                sequences[key] = counter

# print the name if found match or print no match
STR = list(sequences.values())
for row in csv_file:
    test_list = list(map(int, row[1:len(row)]))
    flag = False
    if (test_list == STR):
        flag = True
        break
if flag == True:
    print(row[0])
else:
    print("No match")
        
    