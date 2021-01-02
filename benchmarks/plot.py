import sys

inputs = []
for line in sys.stdin:
    inputs.append(line.strip())

labels = []
datapoints = []
for i in range(0, len(inputs), 2):
    labels.append(inputs[i])
    datapoints.append(list(map(int, inputs[i+1].split())))

print(labels)
print(datapoints)