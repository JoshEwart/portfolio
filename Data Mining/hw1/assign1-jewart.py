#     Joshua Ewart, CSCI 481 Data Mining, HomeWork 1

#include libraries 
import numpy as numPy
import sys
#Need the data first to be able to work with it.
#get input file
file = sys.argv[1]
#unUsed, after reading in from command line and writing
#print("please give the file data")
#print("")
#userFile = input("")
#create a file

outputFile= open('assign1-jewart.txt', 'w')

matrix = numPy.loadtxt(file, delimiter= ',', usecols=(0,1,2,3,4,5,6,7,8,9))


#1.
#create function to find covariance matrix with inner products
def covariance(magicMatrix):
    #we have the matrix, how find the mean of the columns.
    u =numPy.mean(magicMatrix, axis=0)
    z = magicMatrix
    #to make z, we need to subtract u (the vector of the mean of each 10 columns of the matrix)
    rowSize = numPy.size(magicMatrix,0)
    colSize = numPy.size(magicMatrix,1)
    for i in range(rowSize):
        z[i] = z[i] - u
    # we have all of z, get the transpose
    zTranspose = z.transpose()
    #now that we have both, use the formula to find the covariance Matrix
    covarianceMatrix = numPy.zeros((colSize,colSize))
    for n in range(rowSize):
        covarianceMatrix += (numPy.outer(z[n],zTranspose[:,n])/rowSize)
    return covarianceMatrix

#run the method by creating the covariance matrix
outputFile.write("1. Show that the covariance matrices are the same.\n")
covMatrix = covariance(matrix)
outputFile.write("Calculated covariance matrix:\n")
outputFile.write(str(covMatrix))
outputFile.write("\nCovariance Function from NumPy:\n")
covarianceMatrixNumPyCommand = numPy.cov(matrix, rowvar=False, bias=True)
outputFile.write(str(covarianceMatrixNumPyCommand))
outputFile.write("\n")


#2.
#find the eigenVectors.
eigValues,eigVectors = numPy.linalg.eig(covMatrix)

domEigVector = eigVectors[:,0:2]

#reduce the matrix
reductionMatrix = numPy.dot(matrix, domEigVector)
covarianceReduced = covariance(reductionMatrix)
variance = numPy.trace(covarianceReduced)
valueSum= eigValues[0] + eigValues[1]

outputFile.write("\n  \n 2. Verify equal variance results\n")
outputFile.write("Variance:     ")
outputFile.write(str(variance))
outputFile.write("\nSum of Dominant EigenValues:     ")
outputFile.write(str(valueSum))
outputFile.write("\n")            

#3.
#Compute Projection Matrix using eigenVectors from 2.
#get origional points in standard basis
#(x' == (Pr)*x) | r= #eigenVectors. Pr = Ur * (Ur)^t
tempProject = numPy.dot(domEigVector, numPy.transpose(domEigVector))
#create the projection, X'
projectionMatrix = numPy.dot(matrix, tempProject)
#find the quantity(error)
error = matrix - projectionMatrix
#get the covariance
covarianceError = covariance(error)

outputFile.write("\n  \n 3. Error Difference Comparison:")
outputFile.write("\nCovariance Error:     \n")
outputFile.write(str(numPy.trace(covarianceError)))
outputFile.write("\nLast 8 eigenValues:     \n")
outputFile.write(str(numPy.sum(eigValues[2:10])))
outputFile.write("\n")


#4.
#find diagonal Matrix of EigenValues
diagEigenValues = numPy.diag(eigValues)
#show covariance Matrix in eigenDecomp form
outputFile.write("\n  \n 4. UAU^T\n")
outputFile.write("U:\n")
outputFile.write(str(eigValues))
outputFile.write("\nA:\n")
outputFile.write(str(diagEigenValues))
outputFile.write("\nU Transpose\n")
outputFile.write(str(numPy.transpose(diagEigenValues)))
outputFile.write("\n")
#5.
#create a function for PCA Algorithm


def pcaAlgorithm(magicMatrix):
    #A get mean
    avg = numPy.mean(magicMatrix, axis=0)
    #B Center Data
    centeredData = magicMatrix
    rowSize = numPy.size(magicMatrix,0)
    colSize = numPy.size(magicMatrix,1)
    for i in range(rowSize):
        centeredData[i] = centeredData[i] - avg
    #C Compute Covariance Matrix
    dataTranspose = centeredData.transpose()
    covariance = numPy.zeros((colSize, colSize))
    for j in range(rowSize):
        covariance += (numPy.outer(centeredData[j],dataTranspose[:,j])/rowSize)

        
    #D Compute EigenValues and EigenVectors
    eigValues,eigVectors = numPy.linalg.eig(covariance)

    #E fraction total Variance

    #create variable for temp percentage of current sum/total sum;
    division = 0
    #create variable for number of eignValues, r
    r = 0
    for count in range(eigValues.size):
        division += numPy.sum(eigValues[count])/numPy.sum(eigValues)
        #if current total/ total >.9, at correct length
        if division >= .9 and r ==0:
            r = count


    #F choose Dimensionality
        #r = dimensionallity
    #G Reduce basis
    reducedVectors = eigVectors[:,0:r+1]
    #H reduce dimensionality data
    a = numPy.dot(matrix, reducedVectors)
    outputFile.write("\n  \n 6. 10 rows of A: \n")
    outputFile.write(str(a[0:10,:]))

    return a
#test to see if correct
pcaAlgorithm(matrix)

outputFile.close()
