import sys
import matplotlib.pyplot as plt

inputs = []
for line in sys.stdin:
	inputs.append(line.strip())

labels = []
for i in range(0, len(inputs), 3):
	labels.append(inputs[i])
	x = list(map(int, inputs[i+1].split()))
	y = list(map(int, inputs[i+2].split()))
	plt.plot(x, y, 'r-s')

plt.yscale('log')
plt.xscale('log')
plt.show()
