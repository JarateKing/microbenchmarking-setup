import sys
import matplotlib.pyplot as plt

inputs = []
for line in sys.stdin:
    inputs.append(line.strip())

lindex = 0
datasetCount = int(inputs[lindex].split()[0])
algorithmCount = int(inputs[lindex].split()[1])
lindex += 1

algorithmNames = []
for a in range(algorithmCount):
    algorithmNames.append(inputs[lindex])
    lindex += 1

datasetN = list(map(float, inputs[lindex].split()))
lindex += 1

for d in range(datasetCount):
    datasetName = inputs[lindex]
    lindex += 1
    
    plt.figure()
    for a in range(algorithmCount):
        averageY = []
        pointsX = []
        pointsY = []
    
        for n in datasetN:
            runtimes = list(map(float, inputs[lindex].split()))
            average = sum(runtimes) / len(runtimes)
            lindex += 1
            
            for runtime in runtimes:
                pointsX.append(n)
                pointsY.append(runtime)
            
            averageY.append(average)
        
        plt.plot(datasetN, averageY, '-')
        plt.scatter(pointsX, pointsY, marker='_', alpha=0.5)
    
    plt.title(datasetName)
    plt.yscale('log')
    plt.xscale('log')
    plt.ylabel('rate per second')
    plt.xlabel('n')
    plt.legend(algorithmNames)
    plt.show(block=False)

plt.show()
