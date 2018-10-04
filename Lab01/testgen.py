import random
import sys
import string

MAX_STRING_LENGTH=30
MD5SUM_LENGTH=32
STRING_LETTERS=string.ascii_letters+string.digits+string.punctuation
MD5SUM_LETTERS="0123456789abcdef"

def GenerateMD5Sum ():
    #return "".join([random.choice(string.hexdigits) for i in range(MD5SUM_LENGTH)])
    return "".join([random.choice(MD5SUM_LETTERS) for i in range(MD5SUM_LENGTH)])

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
    for argument in (sys.argv[1:]):
        currentFlag = argument.split('=')
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
            sys.exit()
            

for test in range (testsNumber):
    values=list()
    outputFile=open("Tests/{}.t".format(test),'w')
    for line in range (linesNumber):
        key = GenerateMD5Sum()
        value = GenerateString(fullStrings)
        #print("{}\t{}".format(key, value))
        outputFile.write("{}\t{}\n".format(key, value))
        values.append((key,value))
    values = sorted (values,key=lambda val:val[0])
    outputFile.close()
    outputFile=open("Tests/{}.a".format(test),'w')
    for val in values:
        #print("{}\t{}".format(val[0], val[1]))
        outputFile.write("{}\t{}\n".format(val[0],val[1]))
    outputFile.close()
        





