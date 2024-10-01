import sys
import numpy as np

N = 3

def ShowMatrix(s, n):
    for i in range(n):
        print(s[i], end="")
        print()

def FillMatrix(f, n, s):
    for j in range(n):
        for i in range(n):
            f[i,j] = (i+1)*s
    return f

def TransposeMatrix(ht, h, n):
    for i in range(n):
        for j in range(n):
            ht[j, i] = h[i, j]
    return ht

def CracovianProduct(c, a, b, n):
    size = (n, n)
    bt = np.zeros(size)
    TransposeMatrix(bt, b, n)
    np.matmul(bt, a, out=c)
    return c

def main():
    if len(sys.argv) != 3:
        print("Error: Number of arguments incorrect")
    sa = int(sys.argv[1])
    sb = int(sys.argv[2])
    size = (N, N)
    a = np.zeros(size)
    b = np.zeros(size)
    FillMatrix(a, N, sa)
    FillMatrix(b, N, sb)
    ShowMatrix(a, N)
    ShowMatrix(b, N)
    c = np.zeros(size)
    CracovianProduct(c, a, b, N)
    ShowMatrix(c, N)

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    main()
