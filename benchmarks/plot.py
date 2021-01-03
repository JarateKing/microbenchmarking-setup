import sys
import matplotlib.pyplot as plt

inputs = []
for line in sys.stdin:
	inputs.append(line.strip())

benchmarks = []

i = 0
while i < len(inputs):
	benchmarks.append(inputs[i])
	i += 1
	x = list(map(float, inputs[i].strip().split()))
	i += 1
	y = []
	xp = []
	yp = []
	
	for j in range(i, i + len(x)):
		data = list(map(float, inputs[j].strip().split()))
		y.append(sum(data) / len(data))
		for point in data:
			xp.append(x[j-i])
			yp.append(point)
	
	i += len(x)
	plt.plot(x, y, '-', label=benchmarks[-1])
	plt.scatter(xp, yp, marker='_', alpha=0.5)

plt.yscale('log')
plt.xscale('log')
plt.legend()
plt.savefig('output.png')
plt.show()
