import numpy

def solve():
    array = [[0, 0.88, 0.38, 0.27, 0.27, 0.38], 
    	     [0.41, 0, 0.08, 0.89, 0.5, 0.29],
    	     [0.92, 0.01, 0, 0.47, 0.76, 0.21],
    	     [0.04, 0.49, 0.18, 0, 0.85, 0.19],
    	     [0.46, 0.32, 0.49, 0.09, 0, 0.16],
    	     [0.24, 0.18, 0.14, 0.68, 0.63, 0]]
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
