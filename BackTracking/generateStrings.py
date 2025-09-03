

def Binary(n):
    if ( n < 1 ):
        print(string)
    else:
        string[n - 1] = 0
        Binary(n-1)
        string[n-1] = 1
        Binary(n-1)


string = [0] * 5
Binary(len(string))