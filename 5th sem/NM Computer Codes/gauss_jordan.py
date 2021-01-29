# gauss_jordan.py

n =int(input('Enter the number of variables: '))
a = []

print('Enter the coefficients')
for i in range(n):
    a.append([float(x) for x in input().split()])
    


print('matrix:')
for i in range(n):
    for j in range(n+1):
        print(a[i][j], end = ' ')
    print('\n')


for j in range(n):
    if abs(a[j][j]) < 0.005:
        print('Diagonal element Zero')
        exit()
    for i in range(n):
        if i != j:
            ratio = a[i][j] / a[j][j]
            for k in range(n+1):
                a[i][k] -= ratio * a[j][k]
                

print('Augmented Diagonal matrix:')
for i in range(n):
    for j in range(n+1):
        print(a[i][j], end = ' ')
    print('\n')
    
print('The solution is:')
for i in range(n):
    print('x_{0} = {1}\n'.format(i, a[i][n] / a[i][i]))
    
