import random
import sys
import string

MAX_STRING_LENGTH=30
MD5SUM_LENGTH=32
STRING_LETTERS=string.ascii_letters+string.digits+string.punctuation

def GenerateMD5Sum ():
    return "".join([random.choice(string.hexdigits) for i in range(MD5SUM_LENGTH)])

def GenerateString (flag):
    if (flag):
        strLen=MAX_STRING_LENGTH
    else:
        strLen=random.randint(1,MAX_STRING_LENGTH)
    return "".join([random.choice(STRING_LETTERS) for i in range(strLen)])


linesNumber = 100
testsNumber = 10
fullStrings = 0

if len(sys.argv) > 1:
    k = 1 
    while k <= len(sys.argv):
        currentFlag = sys.argv[k].split('=')
        if currentFlag[0] == "--lines" :
            linesNumber = int(currentFlag[1])
        elif currentFlag[0] == "--tests":
            testsNumber = int(currentFlag[1])
        elif (currentFlag[0] == "--full" or currentFlag[0] == "-f"):
            fullStrings = 1
        elif (currentFlag[0] == "--help" or currentFlag[0] == "-h"):
            print("Usage: testgen [OPTION]")
            print("Generates tests for 1st lab - DA, MAI2018")
            print("\t--lines=NUM\tset number of lines in one test to NUM")
            print("\t--tests=NUM\tset number of tests to NUM")
            print("\t-f, --f    \tmake strings always contain 2048 symbols")
            print("\t-h, --h    \ts\display this help and exit")
            

for test in range (testsNumber):
    outputFile=open("Tests/{}.t".format(test),'w')
    for line in range (linesNumber):
        print("{}\t{}".format(GenerateMD5Sum(), GenerateString(fullStrings)))
        outputFile.write("{}\t{}\n".format(GenerateMD5Sum(), GenerateString(fullStrings)))
        

outputFile.close()



