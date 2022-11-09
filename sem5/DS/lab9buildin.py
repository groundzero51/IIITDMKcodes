'''
program written by gaurav r
cs20b1021
lab 9

'''

# This program is done by CS20B1044 Avinash R Changrani
# importing libraries required for this program
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import sklearn
from sklearn.cluster import KMeans
from sklearn.neighbors import KNeighborsClassifier
from sklearn import metrics
import math

data = pd.read_csv('./diabetes.csv')

end = math.ceil(0.8*len(data))

# using 80% of given data as training data
train_data = np.array(data[:end])

# other 20% of data for testing
test_data = np.array(data[end:])

# KMeans Algorithm
# Training the Model using inbuilt KMeans function and using 2 clusters and using 2 random points as centroids
km = KMeans(n_clusters=2, random_state=2).fit(train_data)


# get the predicted labels for the data
kpred = km.predict(test_data)

# printing out the predicted labels achieved using the model
print("The predicted labels from the given cluster data is: ")
print(kpred)

print('Classification report:\n', sklearn.metrics.classification_report(
    np.array(data[end:]['Outcome']), kpred))


# Minimum distance classifier

# splitting the input(other labels) and output data (outcome)
outcome_data = np.array(data[:end]['Outcome'])
train_data = np.array(data.loc[:, data.columns != 'Outcome'][:end])

# K Closest Neighbors Algorithm with k = 1
minimumDisanceClassifier = KNeighborsClassifier(
    n_neighbors=1).fit(train_data, outcome_data)

test_data = np.array(data.loc[:, data.columns != 'Outcome'][end:])

# get the predicted labels for the data
pred = minimumDisanceClassifier.predict(test_data)

# printing out the predicted labels achieved using the model
print("The predicted labels from the given cluster data is: ")
print(pred)

# Printing out the accuracy of the model
print("Accuracy of the Model is :", metrics.accuracy_score(
    np.array(data[end:]['Outcome']), pred))