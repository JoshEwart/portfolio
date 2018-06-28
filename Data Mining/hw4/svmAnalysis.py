#Joshua Ewart, CSCI 481 Data Mining, HomeWork 3
#include libraries 
import numpy as numPy
import sys
from sklearn import svm
from sklearn import metrics
#Get fold for train
train = sys.argv[1];
#Get folds for comparison
test1 = sys.argv[2];
test2 = sys.argv[3];
test3 = sys.argv[4];
#create data from files
#17 elements, first is class
#train
trainInfo = numPy.loadtxt(train, dtype= 'str', delimiter= ',');
#create numeric data
trainStr = trainInfo[:, 1:16];
trainData = trainStr.astype('float');
trainClasses = trainInfo[:, 0];
#test1
t1INFO = numPy.loadtxt(test1, dtype= 'str', delimiter= ',');
#create numeric data
t1STR = t1INFO[:, 1:16];
test1DATA = t1STR.astype('float');
test1CLASSES = t1INFO[:, 0];
#test2
t2INFO = numPy.loadtxt(test2, dtype= 'str', delimiter= ',');
#create numeric data
t2STR = t2INFO[:, 1:16];
test2DATA = t2STR.astype('float');
test2CLASSES = t2INFO[:, 0];
#test3
t3INFO = numPy.loadtxt(test3, dtype= 'str', delimiter= ',');
#create numeric data
t3STR = t3INFO[:, 1:16];
test3DATA = t3STR.astype('float');
test3CLASSES = t3INFO[:, 0];
#data read in. now use SVM
#first do linear
linCLASSIFY = svm.SVC(C = .25, kernel='linear');
linCLASSIFY.fit(trainData,trainClasses);
lin1Predict = linCLASSIFY.predict(test1DATA);
lin2Predict = linCLASSIFY.predict(test2DATA);
lin3Predict = linCLASSIFY.predict(test3DATA);
lin1Confusion = metrics.confusion_matrix(test1CLASSES, lin1Predict);
lin2Confusion = metrics.confusion_matrix(test2CLASSES, lin2Predict);
lin3Confusion = metrics.confusion_matrix(test3CLASSES, lin3Predict);
lin1Acc= float((lin1Confusion[0,0] +lin1Confusion[1,1]))/108;
lin2Acc= float((lin2Confusion[0,0] +lin2Confusion[1,1]))/108;
lin3Acc= float((lin3Confusion[0,0] +lin3Confusion[1,1]))/111;
LINAVG = float(lin1Acc+lin2Acc+lin3Acc)/3;
LINSD = float(numPy.sqrt((numPy.power((lin1Acc-LINAVG),2)+ numPy.power((lin2Acc-LINAVG),2)+ numPy.power(2,(lin3Acc-LINAVG)))/3));
print("LinearAvg: " + str(LINAVG));
print("LinearS.D: " + str(LINSD));
#now do Gaussian
GauCLASSIFY = svm.SVC(C = .25, kernel='rbf');
GauCLASSIFY.fit(trainData,trainClasses);
Gau1Predict = GauCLASSIFY.predict(test1DATA);
Gau2Predict = GauCLASSIFY.predict(test2DATA);
Gau3Predict = GauCLASSIFY.predict(test3DATA);
Gau1Confusion = metrics.confusion_matrix(test1CLASSES, Gau1Predict);
Gau2Confusion = metrics.confusion_matrix(test2CLASSES, Gau2Predict);
Gau3Confusion = metrics.confusion_matrix(test3CLASSES, Gau3Predict);
Gau1Acc= float((Gau1Confusion[0,0] +Gau1Confusion[1,1]))/108;
Gau2Acc= float((Gau2Confusion[0,0] +Gau2Confusion[1,1]))/108;
Gau3Acc= float((Gau3Confusion[0,0] +Gau3Confusion[1,1]))/111;
GAUAVG = float(Gau1Acc+Gau2Acc+Gau3Acc)/3;
GAUSD = float(numPy.sqrt((numPy.power((Gau1Acc-GAUAVG),2)+ numPy.power((Gau2Acc-GAUAVG),2)+ numPy.power(2,(Gau3Acc-GAUAVG)))/3));
print("GaussianAvg: " + str(GAUAVG));
print("GaussianS.D: " + str(GAUSD));

