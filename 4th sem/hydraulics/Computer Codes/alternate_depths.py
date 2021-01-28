# Given a specific energy, two flow depths are possible; one corresponds to super-critical flow (y1), and anothe to sub-critical flow (y2)
# y1 < yc < y2; where, yc = depth at critical flow

# Receiving Inputs
print('\n \n------- Determination of normal depth -------')
print('   ------- Enter data in SI unit -------')
b = float(input('Enter the bed width \n'))
E = float(input('Enter the specific energy \n'))
Q = float(input('Enter the discharge \n'))

# Defining Quantities
g = 9.81					# Acceleration due to gravity
yc = (Q ** 2 / (b ** 2 * g)) ** (1/3)		# Depth at critical flow
y = yc						# Dummy variable for iteration
RHS = y + Q ** 2 / (b ** 2 * y ** 2 * 2 * g)

# Iteration for super-critical flow
while abs(E - RHS) > 0.01:
	y -= 0.0001
	RHS = y + Q ** 2 / (b ** 2 * y ** 2 * 2 * g)
	if abs(y) > 15 * abs(yc):
		break		

# Iteration for sub-critical flow
y1 = y 					# super-critical depth
y = yc
while abs(E - RHS) > 0.01:
	y += 0.0001
	RHS = y + Q ** 2 / (b ** 2 * y ** 2 * 2 * g)
	if abs(y) > 15 * abs(yc):
		break		
y2 = y					# sub-critical depth	
print('\n \nyc = %.3f' %(yc))
print('super-critical depth = %.3f \nsub-critical depth = %.3f' %(y1, y2))
