n = int(input('Enter N: '))
values = [i for i in range(n+1)]
values.remove(1)

n = len(values)
i = 1

while i < n:
	if values[i] != 0:
		j = values[i]*2
		step = values[i]

		while j <= n:
			values[j-1] = 0
			j += step

	i += 1
	
values = set(values)
values.remove(0)
print(values)
input()
