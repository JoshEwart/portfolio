#     Joshua Ewart, CSCI 481 Data Mining, HomeWork 3

#include libraries 
import numpy as numPy
import sys
from sklearn import svm
from sklearn import metrics

f = open("house-votes-84.data","r")
lines = f.readlines()
for line in lines:
    strpline = line.rstrip()
    arr = strpline.split(",")
    newline = [];
    for i in range(len(arr)):
        if arr[i] == "y":
            newline.append(i)
    if arr[0] == "republican":
        newline.append(100)
    else:
        newline.append(200)
    print(*newline, sep=",")
