# written by gaurav cs20b1021
#

import pandas as pd
df = pd.read_csv("Iris.csv")
dfsetosa = df[df['Species'] == "Iris-setosa"]
dfverosa = df[df['Species'] == "Iris-versicolor"]
dfvirg = df[df['Species'] == "Iris-virginica"]
# print(dfsetosa)
# print(dfverosa)
# print(dfvirg)

############# PART A ################

#finding average sepal legth
dfm = dfsetosa["SepalLengthCm"].mean()
print("average sepal length (Iris-setosa) : ",dfm)
dfm = dfverosa["SepalLengthCm"].mean()
print("average sepal length (Iris-verosa) : ",dfm)
dfm = dfvirg["SepalLengthCm"].mean()
print("average sepal length (Iris-virginica) : ",dfm)

#avg sepal width
dfm = dfsetosa["SepalWidthCm"].mean()
print("average Sepal Width (Iris-setosa) : ",dfm)
dfm = dfverosa["SepalWidthCm"].mean()
print("average Sepal Width (Iris-verosa) : ",dfm)
dfm = dfvirg["SepalWidthCm"].mean()
print("average Sepal Width (Iris-virginica) : ",dfm)

#finding average petal legth
dfm = dfsetosa["PetalLengthCm"].mean()
print("average Petal length (Iris-setosa) : ",dfm)
dfm = dfverosa["PetalLengthCm"].mean()
print("average Petal length (Iris-verosa) : ",dfm)
dfm = dfvirg["PetalLengthCm"].mean()
print("average Petal length (Iris-virginica) : ",dfm)

#avg petal width
dfm = dfsetosa["PetalWidthCm"].mean()
print("average Petal Width (Iris-setosa) : ",dfm)
dfm = dfverosa["PetalWidthCm"].mean()
print("average Petal Width (Iris-verosa) : ",dfm)
dfm = dfvirg["PetalWidthCm"].mean()
print("average Petal Width (Iris-virginica) : ",dfm)

############# PART B ################

dfc = df.groupby('Species')['Species'].count()
print(dfc)

############# PART C ################

dfsetosa['species-id'] = dfsetosa['species-id'].fillna(0)
dfverosa['species-id'] = dfverosa['species-id'].fillna(1)
dfvirg['species-id'] = dfvirg['species-id'].fillna(2)

result = pd.merge(dfsetosa, dfverosa, dfvirg, on="Id")

############# PART D ################

result.to_csv("result.csv")  ##MODIFIED DATAFRAME IS SAVED TO result.csv