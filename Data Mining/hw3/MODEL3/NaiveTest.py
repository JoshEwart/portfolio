#     Joshua Ewart, CSCI 481 Data Mining, HomeWork 3

#include libraries
import numpy as numPy
import sys


def readData(modelFile, testFile):
    model=[];
    #get the info from the files
    with open(modelFile, 'r') as myfile:
        model = myfile.read().splitlines();
    testData = numPy.loadtxt(testFile, dtype = 'str', delimiter=',');
    #now create varS for the model data

    #1 Class order
    classLbls = model[0].split(",");

    #2 prior order
    temPriors = model[1].split(",");
    #convert to float
    priors = [float(k) for k in temPriors];

    #3 mean order
    means = [];
    strMeans =[];
    tempMeans = model[2].split(";");
    totalClasses = len(tempMeans);
    for i in range(totalClasses):
        strMeans = tempMeans[i].split(",");
        means.append([float(k) for k in strMeans]);
    #get the dataSize
    dataSize = numPy.size(means,1);

    #4 covariance order
    #cov has totalClasses ammount of matrices.
    #one matrix per row
    tempCov = [];
    strCov =[];
    cov = [];
    for lines in range(totalClasses):
        #for all remaining lines...
        #start at line 3
        curLine = model[lines+3];
        tempCov = curLine.split(";");
        #add into the cov
        cov.append([]);
        for i in range(len(tempCov)):
            strCov = tempCov[i].split(",");
            floatOut = [float(k) for k in strCov];
            #we have numeric output list. now set it to cov
            cov[lines] = floatOut;
    print(cov);
    #segment and catagorize the test file
    testMatrix = testData[:,0:(dataSize)];
    testMatrix = testMatrix.astype('float');
    #store data class location
    dataClassList = testData[:,dataSize];
    return priors, means, cov, testMatrix, dataClassList, classLbls;
'''
Data has now been read in.
Now we must create the predicted label and confusion matrix.
'''



#create predicted label (for a single data point)
def dataPredict(givenPoint, prior, U, cov, classLblz):
    dataPoint = givenPoint;
    results = [];
    for i in range(len(classLblz)):
        #we have the prior probability, now calc posterior probability for each class.
        results.append(calcLikely(dataPoint, U[i], cov[i]));
        results[i] = results[i] * prior[i];
    
    #find largest results, return
    mostLikely = results.index(max(results));
    lbl = classLblz[mostLikely];
    return lbl;

def calcLikely(dataPoint, avg, curCov):
    #find the likelyhood of point being current class
    tempResults = numPy.zeros(len(dataPoint));
    for j in range(len(dataPoint)):
        firstDenominator = float(1/(2*numPy.pi));
        firstDenominator = firstDenominator/(numPy.sqrt(curCov[j]));
        #second half
        exponent = dataPoint[j]-avg[j];
        exponent = numPy.power(exponent,2);
        exponent = -exponent/(2*curCov[j]);
        secondHalf = numPy.exp(exponent);
        tempResults[j] = firstDenominator*secondHalf;
    finalResults = numPy.prod(tempResults);
    return finalResults;


def main():
    #read in data
    #Need the shuffled iris
    #get files
    inputModel = sys.argv[1];
    inputTest = sys.argv[2];    
    priorData,U,cov,dataMatrix,allClasses, classLBLz = readData(inputModel, inputTest);

    #calculate most likely class for each point.
    bayesPredict = [];
    for i in range(numPy.size(dataMatrix,0)):
        curPoint = dataMatrix[i,:]
        bayesPredict.append(dataPredict(curPoint, priorData, U, cov, classLBLz));
    #now add to Precision

    #convert data to compare
    bayesPredict = numPy.asarray(bayesPredict)
    classLBLz = numPy.asarray(classLBLz);
    allClasses = numPy.asarray(allClasses);
    #go through and make confusion matrix.
    confusingMatrix = numPy.zeros((len(classLBLz),len(classLBLz)));
    for i in range(len(classLBLz)):
        #get the predict it is in
        for j in range(len(classLBLz)):#for the current
            #for all points added to Class Accuracy
            tempArray = numPy.where((bayesPredict == classLBLz[i])&(allClasses == classLBLz[j]));
            confusingMatrix[i,j] = numPy.size(tempArray,1);
    print(confusingMatrix);
    
    #2 complete, we have BayesPredic, and ConfusingMatrix.

    #3 we need:

    '''accuracy, precision, recall, and F-score'''
    precision = [];
    recal = [];
    fMeasure = [];
    accuracy = [];
    for i in range(len(classLBLz)):
        #need TP, FP, TN, FN
        tp = confusingMatrix[i,i];#diag
        tpFP = numPy.sum(confusingMatrix[i,:]);
        tpFN = numPy.sum(confusingMatrix[:,i]);
        tmpMatrix = numPy.copy(confusingMatrix);
        tmpMatrix = numPy.delete(tmpMatrix, i, 0);
        tmpMatrix = numPy.delete(tmpMatrix, i, 1);
        TN = numPy.sum(tmpMatrix);
        #precision = TP/(TP + FP)
        precision.append(tp/tpFP);
        #recall = TP/(TP + FN)
        recal.append(tp/tpFN);
        #F Measure
        fMeasure.append((2*precision[i]*recal[i])/(precision[i] + recal[i]));
        #accuracy = (TP+ TN)/(TP+TN+FP+FN)
        accuracy.append((tp + TN)/(numPy.sum(confusingMatrix)));
    print("precision: ");
    print(precision);
    print("\n"+"recall: ");
    print(recal);
    print("\n"+"F Measure: ");
    print(fMeasure);
    print("\n" + "accuracy: ");
    print(accuracy);
    
        
main();
