# Determination of critical depth
# Q ** 2 / g = A ** 3 / T

# Receiving input
print('\n \n------- Determination of critical depth -------')
print('    ------ Enter data in SI unit -------')
Q = float(input('Enter discharge: Q \n'))
b = float(input('Enter bottom width: b \n'))
z = float(input('Enter side slope: z \n'))
y = float(input('Enter initial depth: y \n'))

# Defining quantifies
A = b * y + y ** 2 * z		# Area
T = b + 2 * y * z		# Top width
g = 9.81			# Acceleration due to gravity
LHS = Q **2 / g
print('Q ** 2 / g = ', LHS)
RHS = A ** 3 / T
print('A ** 3 / T = ', RHS , '(for initial depth)')
itr = 0
# Iteration for trial and error
while abs(LHS - RHS) > 0.01:
	itr += 1
	if RHS > LHS:
		y -= 0.00001
	else:
		y += 0.0001
	A = b * y + y ** 2 * z
	T = b + 2 * y * z
	RHS = A ** 3 / T
	print(y)
	if itr > 100: break

# Output
if not itr > 100:
	print('The critical depth is %.3f' % (y))
else:
	print('Solution not found for given data')
