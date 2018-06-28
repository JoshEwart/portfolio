#     Joshua Ewart, CSCI 481 Data Mining, HomeWork 1

#include libraries 
import numpy as numPy
import sys
#Need iris.data file first to be able to work with it.
#get input files and k size
centerPointsGiven = False;
dataFile = sys.argv[1]
k = int(sys.argv[2])
if len(sys.argv) > 3:
    center = sys.argv[3]
    centerPointsGiven = True;
    centroids = numPy.loadtxt(center).astype(int)

    #read in the data
temp = numPy.loadtxt(dataFile,dtype = str, delimiter= ',')
data = temp[:,0:(temp.shape[1] - 1)].astype(float)


outputFile= open('assign2-jewart.txt', 'w')
#we have the output file. We need to...
'''
1. The number of data points in the input file, the dimension, and the value of k
2. The number of iterations the program took for convergence
3. The final mean of each cluster and the SSE score (sum of square error)
4. The final cluster assignment of all the points.
5. The final size of each cluster
'''

#1. #data points, dimension, k
outputFile.write("the total number of data points: ")
outputFile.write(str(data.shape[0]))
outputFile.write("\nDimensions: ")
outputFile.write(str(data.shape[1]))
outputFile.write("\nK: ")
outputFile.write(str(k))

print("the total number of data points: ")
print(str(data.shape[0]))
print("\nDimensions: ")
print(str(data.shape[1]))
print("\nK: ")
print(str(k))

#data is now read in, we must now either
#A- work with the centroids, or B-create random centroids


#find sum(squared Error)
def sumSquareError(currentCenters, previousCenters, k):   
    difference = currentCenters - previousCenters
    squared = difference**2
    xSum = numPy.sum(squared,axis=1)
    squared = numPy.sqrt(xSum)
    total = numPy.sum(squared)
    return total

#A METHOD 1 given Centroids
def givenData(dataPoints, k, centers):
    points = dataPoints
    location = points.shape[0]
    centers = numPy.sort(centers)
    currentCenters = numPy.zeros([k,4])
    for allCenters in range(k):
        currentCenters[allCenters,:] = points[centers[allCenters],:]
    previousCenters = numPy.zeros([k,4]);


    #repeat until sum length <= E
    E = .0001

    SSE = sumSquareError(currentCenters, previousCenters, k)

    #create array to keep track of which cluster each point belongs to
    pointClusterings = [0]*points.shape[0]
    #create output for total iterations
    iterations=0

    #run until the SSE is miniscule
    while(SSE > E):

        iterations = iterations +1
        #create the cluster,
        #resets each time for new clusters being made with new centroids
        clusterS = []
        clusterSums = numPy.zeros([k,data.shape[1]])
        #create array to keep track of # points in each cluster
        totalPoints = [0]*(k)
        #get the list ready for points to be added in
        for a in range(0,k):
            clusterS.append([])
        #end for 
        #now assign points to clusters
        for row in range(points.shape[0]):
            #for each row/point
            #get closest cluster
            smallest = -1
            shortDist = 0
            for currCluster in range(k):
                #using Euclidian Distance

                #dist frm centerpoint
                distance = points[row] - currentCenters[currCluster]
                #square each point
                distance = distance**2
                #sum up each point
                distance = numPy.sum(distance)
                #take sqroot
                distance = numPy.sqrt(distance)
                #we have distance of currCluster, check for lowest
                if(smallest == -1):
                    smallest = currCluster
                    shortDist = distance
                elif(distance < shortDist):                    #we have a new shortest distance
                    smallest = currCluster
                    shortDist = distance
                #end if
                    
            #end for
            #we have shortest distance and closest cluster
            #now assign
            pointClusterings[row] = smallest
        #end for
        
        #print(pointClusterings)    
        #we have all of the points that belong to each cluster

        #now we must find the new means

        
        #sum up all the points in each cluster
        for x in range(0,points.shape[0]):
            for j in range(0,k):
                if(pointClusterings[x] == j):
                    #add the point to the total
                    clusterS[j].append(points[x])                   
                    #another point in j, add to j's total
                    totalPoints[j] = totalPoints[j] +1
                #end if
            #end for
            
        #end for

        #we now have the total of all the points,
        #and the total number of points in each cluster

        #we have our new centers ready to be made, now update the old centers   
        previousCenters = numPy.copy(currentCenters)

        #now update the new centers
        #for all clusters
        for l in range(k):         
            #we have each point in the repsective cluster.
            #add in each point to the total
            for allPoints in range(len(clusterS[l])):
                clusterSums[l] = clusterSums[l] + clusterS[l][allPoints]
            currentCenters[l] = clusterSums[l]/totalPoints[l]
            
        #end for
        SSE = sumSquareError(currentCenters, previousCenters, k)
    #end while


        
    #2. The number of iterations the program took for convergence
    outputFile.write("\nTotal Iterations: ")
    outputFile.write(str(iterations))
    print("\nTotal Iterations: ")
    print(str(iterations))
    
    #3. The final mean of each cluster and the SSE score (sum of square error)
    outputFile.write("\nFinal Mean for each Cluster: \n")
    outputFile.write(str(clusterSums))
    outputFile.write("\nSSE Score: ")
    outputFile.write(str(SSE))
    print("\nFinal Mean for each Cluster: \n")
    print(str(clusterSums))
    print("\nSSE Score: ")
    print(str(SSE))

    #4. The final cluster assignment of all the points.
    outputFile.write("\nFinal Clustering: \n")
    print("\nFinal Clustering: \n")
    for i in range(len(pointClusterings)):
        outputFile.write(str(i+1))
        outputFile.write(" => Cluster ")
        outputFile.write(str(pointClusterings[i]))
        outputFile.write("\n")
        print(str(i+1) + " => Cluster " + str(pointClusterings[i]))

    #5. The final size of each cluster
    for allMyClusters in range(k):
        outputFile.write("Cluster ")
        outputFile.write(str(allMyClusters))
        outputFile.write(": ")
        outputFile.write(str(len(clusterS[allMyClusters])))
        outputFile.write("\n")
        print("Cluster " + str(allMyClusters) + ": " + str(len(clusterS[allMyClusters])))

    return 0


#2 METHOD 2 random Centroids
def randomData(dataPoints,k):
    points = dataPoints
    location = points.shape[0]
    initCenters = numPy.random.choice(location, k, False)
    initCenters = numPy.sort(initCenters)
    currentCenters = numPy.zeros([k,4])
    for allCenters in range(0,k):
        currentCenters[allCenters,:] = points[initCenters[allCenters],:]
    previousCenters = numPy.zeros([k,4]);


    #now create the algorithm, using the given data.


    #repeat until sum length <= E
    E = .0001

    SSE = sumSquareError(currentCenters, previousCenters, k)

    #create array to keep track of which cluster each point belongs to
    pointClusterings = [0]*points.shape[0]
    #create output for total iterations
    iterations=0

    #run until the SSE is miniscule
    while(SSE > E):

        iterations = iterations +1
        #create the cluster,
        #resets each time for new clusters being made with new centroids
        clusterS = []
        clusterSums = numPy.zeros([k,data.shape[1]])
        #create array to keep track of # points in each cluster
        totalPoints = [0]*(k)
        #get the list ready for points to be added in
        for a in range(0,k):
            clusterS.append([])
        #end for 
        #now assign points to clusters
        for row in range(points.shape[0]):
            #for each row/point
            #get closest cluster
            smallest = -1
            shortDist = 0
            for currCluster in range(k):
                #using Euclidian Distance

                #dist frm centerpoint
                distance = points[row] - currentCenters[currCluster]
                #square each point
                distance = distance**2
                #sum up each point
                distance = numPy.sum(distance)
                #take sqroot
                distance = numPy.sqrt(distance)
                #we have distance of currCluster, check for lowest
                if(smallest == -1):
                    smallest = currCluster
                    shortDist = distance
                elif(distance < shortDist):                    #we have a new shortest distance
                    smallest = currCluster
                    shortDist = distance
                #end if
                    
            #end for
            #we have shortest distance and closest cluster
            #now assign
            pointClusterings[row] = smallest
        #end for
        
        #print(pointClusterings)    
        #we have all of the points that belong to each cluster

        #now we must find the new means

        
        #sum up all the points in each cluster
        for x in range(0,points.shape[0]):
            for j in range(0,k):
                if(pointClusterings[x] == j):
                    #add the point to the total
                    clusterS[j].append(points[x])                   
                    #another point in j, add to j's total
                    totalPoints[j] = totalPoints[j] +1
                #end if
            #end for
            
        #end for

        #we now have the total of all the points,
        #and the total number of points in each cluster

        #we have our new centers ready to be made, now update the old centers   
        previousCenters = numPy.copy(currentCenters)

        #now update the new centers
        #for all clusters
        for l in range(k):         
            #we have each point in the repsective cluster.
            #add in each point to the total
            for allPoints in range(len(clusterS[l])):
                clusterSums[l] = clusterSums[l] + clusterS[l][allPoints]
            currentCenters[l] = clusterSums[l]/totalPoints[l]
            
        #end for
        SSE = sumSquareError(currentCenters, previousCenters, k)

        #2. The number of iterations the program took for convergence
    outputFile.write("\nTotal Iterations: ")
    outputFile.write(str(iterations))
    print("\nTotal Iterations: ")
    print(str(iterations))
    
    #3. The final mean of each cluster and the SSE score (sum of square error)
    outputFile.write("\nFinal Mean for each Cluster: \n")
    outputFile.write(str(clusterSums))
    outputFile.write("\nSSE Score: ")
    outputFile.write(str(SSE))
    print("\nFinal Mean for each Cluster: \n")
    print(str(clusterSums))
    print("\nSSE Score: ")
    print(str(SSE))

    #4. The final cluster assignment of all the points.
    outputFile.write("\nFinal Clustering: \n")
    print("\nFinal Clustering: \n")
    for i in range(len(pointClusterings)):
        outputFile.write(str(i+1))
        outputFile.write(" => Cluster ")
        outputFile.write(str(pointClusterings[i]))
        outputFile.write("\n")
        print(str(i+1) + " => Cluster " + str(pointClusterings[i]))

    #5. The final size of each cluster
    for allMyClusters in range(k):
        outputFile.write("Cluster ")
        outputFile.write(str(allMyClusters))
        outputFile.write(": ")
        outputFile.write(str(len(clusterS[allMyClusters])))
        outputFile.write("\n")
        print("Cluster " + str(allMyClusters) + ": " + str(len(clusterS[allMyClusters])))

    return 0



#run 1, or 2, depending on if the data is given
if centerPointsGiven:
    givenData(data, k, centroids);
else:
    randomData(data,k)

outputFile.close()
