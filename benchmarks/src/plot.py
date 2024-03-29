import sys
import matplotlib.pyplot as plt
import math

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
    
    lindex2 = lindex
    baselineY = []
    for n in datasetN:
        runtimes = list(map(float, inputs[lindex2].split()))
        average = sum(runtimes) / len(runtimes)
        baselineY.append(average)
        lindex2 += 1
    
    for a in range(algorithmCount):
        averageY = []
        pointsX = []
        pointsY = []
        standardDeviations = []
    
        for n in datasetN:
            runtimes = list(map(float, inputs[lindex].split()))
            average = sum(runtimes) / len(runtimes)
            adjusted = average / baselineY[len(averageY)]
            
            variance = 0
            for r in runtimes:
                variance += ((r / baselineY[len(averageY)]) - adjusted)**2 / len(runtimes)
            standardDeviation = math.sqrt(variance)
            
            lindex += 1
            
            for runtime in runtimes:
                pointsX.append(n)
                pointsY.append(runtime / baselineY[len(averageY)])
            
            averageY.append(adjusted)
            standardDeviations.append(standardDeviation)
        
        line, = plt.plot(datasetN, averageY, '-')
        #plt.scatter(pointsX, pointsY, marker='_', alpha=0.25, color=line.get_color())
        plt.errorbar(datasetN, averageY, standardDeviations, linestyle='None', marker=' ', ecolor=line.get_color(), capsize=5)
        
    
    plt.title(datasetName)
    #plt.yscale('log')
    plt.xscale('log')
    plt.ylabel('relative throughput')
    plt.xlabel('n')
    plt.legend(algorithmNames)
    plt.show(block=False)

plt.show()
