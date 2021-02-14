def find_factors(num):
	factors = []
	div_val = 2

	while num != 1:
		if num % div_val != 0:
			div_val += 1
		else:
			num /= div_val
			factors.append(div_val)
	return factors

x = int(input('Enter num: '))
print(*find_factors(x), sep=' * ', end=' = ')
print(x)
input()