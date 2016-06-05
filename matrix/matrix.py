# -*- coding: utf-8 -*-
import time

def matrix(size):
    tstart = time.time()
    a = [[1 for i in range(size)] for j in range(size)]
    c = [[0 for i in range(size)] for j in range(size)]
    for i in range(size):
        for j in range(size):
            for k in range(size):
                c[i][j] += a[i][k] * a[k][j]
    tend = time.time()
    print (tend - tstart)


if __name__ == "__main__":
    size = 1
    for i in range(10):
        size *= 2
        matrix(size)
