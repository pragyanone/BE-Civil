n = int(input('Enter the number of unknowns: '))
print('Enter the augmented coefficients: ')
a=[]
for i in range(n):
    a.append([float(x) for x in input().split()])

# print the system
print('\nThe system of equations is:')
for i in range(n):
    for j in range(n-1):
        print('{}x{} + '.format(a[i][j], chr(0x2080 + j+1)), end='')
    print('{}x{} = {}'.format(a[i][n-1], chr(0x2080 + n), a[i][n]))

tol = 0.01
x = [float(x) for x in input('\nEnter the initial guesses: ').split()]
itr = 1
while True:
    temp = x[:]
    itr += 1
    for i in range(n):
        sum = a[i][n]
        for k in range(n):
            if k != i:
                sum -= a[i][k] * x[k]
        sum /= a[i][i]
        x[i] = sum    
    print(x)
    if max(abs(x-y) for x,y in zip(x,temp)) < tol:
        break
    if itr > 100:
        print('No Solution')
        break
