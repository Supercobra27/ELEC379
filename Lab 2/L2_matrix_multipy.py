import numpy as np
import time

problem_size = 960

N = problem_size

size = (N,N)

A = np.random.randint(1, 10, size)
B = np.random.randint(1, 10, size)
C = np.zeros(size)

def matrix_multiply(a,b,c,n):
    for i in range(n):
        for j in range(n):
            for k in range(n):
                c[i, j] += a[i, k] * b[k, j]
    return c
                
if __name__ == "__main__":
    print(A)
    print(B)
    t1 = time.time()
    print(matrix_multiply(A,B,C,N))
    t2 = time.time()
    print(t2-t1)
