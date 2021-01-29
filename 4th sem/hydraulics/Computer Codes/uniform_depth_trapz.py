# Determination of normal depth
# Qn/S**(.5) = AR**(2/3)


# Receiving input
print('\n \n------- Determination of normal depth -------')
print('   ------- Enter data in SI unit -------')
b = float(input('Enter the bed width \n'))
n = float(input("Enter manning's coefficient: n \n"))
Q = float(input('Enter the discharge \n'))
S = float(input('Enter the bed slope \n'))
z = float(input('Enter the side slope: z \n'))
y = float(input('Enter initial depth of flow \n'))

# Defining Quantities
A = b * y + z * y ** 2							# Area
P = b + 2 * y * (1 + z ** 2) ** .5				# Wetted Perimeter
R = A / P 										# Hydraulic Radius
LHS = A*R ** (2/3)
print('AR**(2/3) = ',LHS, '(for initial depth)')
RHS = (Q * n) / S ** (0.5)
print('Qn/S**(.5) = ',RHS)

# Iteration for trail and error
while abs(LHS - RHS) > 0.0001:
	if LHS > RHS:
		y -= 0.000001
	else:
		y +=0.0001
	A = b * y + z * y ** 2
	P = b + 2 * y * (1 + z ** 2) ** .5
	R = A / P
	LHS = A*R ** (2/3)

# Output
print('The normal depth is %.3f ' % (y))