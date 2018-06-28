#     Joshua Ewart, CSCI 481 Data Mining, HomeWork 3

#include libraries 
import numpy as numPy
import sys
#Need the shuffled iris
#get file
file = sys.argv[1];

#create a file

fileData = numPy.loadtxt(file, dtype= 'str', delimiter= ',');
#have matrix, last element is class label.

colSize = numPy.size(fileData,1);
#create numeric data
matrix = fileData[:, 0:(colSize-1)];
matrix = matrix.astype('float');

classLbl = fileData[:, colSize-1];



#partition data by class
classLBLs = numPy.unique(classLbl);
totalClasses = len(classLBLs);
#we have all the different classes (above), now create
#a matrix to store the points for each array
classList = [];

#get priors
priors = numPy.zeros(totalClasses);
for i in range(totalClasses):
    classList.append(matrix[numPy.where(classLbl == classLBLs[i])]);
    priors[i] += numPy.size(numPy.where(classLbl == classLBLs[i]));
    priors[i] = priors[i]/numPy.size(classLbl);
    priors[i] = numPy.round_(priors[i],2);

means = [];
covariance = [];
#get means and covariance
for i in range (totalClasses):
    
    means.append(numPy.round_(numPy.mean(classList[i], axis=0),2));
    covariance.append(numPy.round_(numPy.diag(numPy.cov(classList[i],rowvar =False,bias = True)),2));
dataSize = numPy.size(matrix,1);
totalData = numPy.size(matrix,0);

#We have all the data. We need to create a model File
outputFile= open('model.txt', 'w');
#write the classes for their order
for i in range(totalClasses):
    outputFile.write(str(classLBLs[i]));
    if(i != totalClasses-1):
        outputFile.write(",");
outputFile.write("\n"); 
#now write prior
for i in range(totalClasses):
    outputFile.write(str(priors[i]));
    if(i != totalClasses-1):
        outputFile.write(",");
outputFile.write("\n")
#now write mean
for i in range(totalClasses):
    for j in range(dataSize):
        outputFile.write(str(means[i][j]));
        if(j != dataSize-1):
            outputFile.write(",");
    if(i != totalClasses-1):
        outputFile.write(";")
outputFile.write("\n")
#now write cov
for i in range(totalClasses):
    for j in range(dataSize):
        outputFile.write(str(covariance[i][j]));
        if(j != dataSize-1):
            outputFile.write(",")
    if(i != totalClasses-1):
        outputFile.write("\n");

outputFile.close()

