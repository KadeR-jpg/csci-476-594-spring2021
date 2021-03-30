import numpy as np


def freq_analysis(file):
    msgArray = [str(i) for i in file]
    n = float(len(file))
    alphabet = {'a': 0.0, 'b': 0.0, 'c': 0.0, 'd': 0.0, 'e': 0.0, 'f': 0.0, 'g': 0.0,
                'h': 0.0, 'i': 0.0, 'j': 0.0, 'k': 0.0, 'l': 0.0, 'm': 0.0, 'n': 0.0,
                'o': 0.0, 'p': 0.0, 'q': 0.0, 'r': 0.0, 's': 0.0, 't': 0.0, 'u': 0.0,
                'v': 0.0, 'w': 0.0, 'x': 0.0, 'y': 0.0, 'z': 0.0}
    for x in msgArray:
        for k in alphabet.keys():
            if x == k:
                alphabet[k] += 1

    for k, v in alphabet.items():
        alphabet[k] = np.round(v/n, decimals=5)
    print(sorted(alphabet.items(), key=lambda x: x[1]))
    return alphabet


with open('csci-476-594-spring2021-private\crypto\cipher.txt', 'r') as inFile:
    fData = inFile.read()
    cpyData = [str(i) for i in fData]
    cipher = {'a': 'P',
              'b': 'H',
              'c': 'F',
              'd': 'J',
              'e': 'S',
              'f': 'R',
              'g': 'Q',
              'h': 'I',
              'i': 'L',
              'j': 'C',
              'k': 'K',
              'l': 'D',
              'm': 'W',
              'n': 'T',
              'o': 'G',
              'p': 'A',
              'q': 'V',
              'r': 'Y',
              's': 'B',
              't': 'N',
              'u': 'E',
              'v': 'M',
              'w': 'X',
              'x': 'O',
              'y': 'T',
              'z': 'U'}

    for i in range(len(cpyData)):
        for k, v in cipher.items():
            if cpyData[i] == k:
                cpyData[i] = v

    backToStr = ""
    for x in cpyData:
        backToStr += x
    print(fData)
    print(backToStr)
