from cs50 import *
from math import *

text = get_string("Text: ")
letter = 0 
word = 1 
sentence = 0 

# counting number of letters , words , sentences 
for i in text:
    if (i.isalpha()):
        letter += 1
            
    if (i.isspace()):
        word += 1
            
    if (i == '!' or i == '.' or i == '?'):
        sentence += 1
        
# calculate The Coleman-Liau index 
L = (letter / word) * 100 
S = (sentence / word) * 100 
index = round((0.0588 * L) - (0.296 * S) - 15.8)
if (index >= 16):
    print("Grade 16+")
    
elif (index < 1):
    print("Before Grade 1")
    
else:
    print("Grade", index)

         
    