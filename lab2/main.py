import numpy

def solve():
    array = [[0, 1], [2, 0]]
    n = len(array)

    coef = numpy.zeros((n, n))
    sum = numpy.zeros(n)
    
    for i in range(n):
        for j in range(n):
            sum[i] += array[i][j]
            coef[i][j] = array[j][i]
        coef[i][i] = -sum[i]

    print(coef)

    m = numpy.zeros(n)
    m[-1] = 1

    for i in range(n):
        coef[-1][i] = 1
    out = numpy.linalg.solve(coef, m)

    print(coef)
    print(m)
    print(out)

    time = numpy.zeros(n)
    for i in range(n):
        time[i] = (1 - out[i]) / out[i] / sum[i]
    
    print(time)

if __name__ == '__main__':
    solve()