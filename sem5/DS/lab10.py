#written by gaurav cs20b1021
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("diabetes1.csv")

mean = data[['Pregnancies','Glucose','BloodPressure','SkinThickness','Insulin','BMI','DiabetesPedigreeFunction','Age']].mean()
print("\naverage : \n",mean)
median = data[['Pregnancies','Glucose','BloodPressure','SkinThickness','Insulin','BMI','DiabetesPedigreeFunction','Age']].median()
print("\nmedian : \n",median)
mode = data[['Pregnancies','Glucose','BloodPressure','SkinThickness','Insulin','BMI','DiabetesPedigreeFunction','Age']].mode()
print("\nmode : \n",mode)
min = data[['Pregnancies','Glucose','BloodPressure','SkinThickness','Insulin','BMI','DiabetesPedigreeFunction','Age']].min()
print("\nminimum : \n",min)
max = data[['Pregnancies','Glucose','BloodPressure','SkinThickness','Insulin','BMI','DiabetesPedigreeFunction','Age']].max()
print("\nmaximum : \n",max)
standarddev = data[['Pregnancies','Glucose','BloodPressure','SkinThickness','Insulin','BMI','DiabetesPedigreeFunction','Age']].std()
print("\nmaximum : \n",standarddev )

df1=data.loc[:,data.columns!='Outcome']

df2=df1.corr()
print("\n Correlation values : ")
print("\nAge with other attribtes\n")
print(df2.drop(["Pregnancies","Glucose","BloodPressure","SkinThickness","Insulin","BMI","DiabetesPedigreeFunction"],axis=0))
print("\nBMI with other attribtes\n")
print(df2.drop(["Pregnancies","Glucose","BloodPressure","SkinThickness","Insulin","DiabetesPedigreeFunction","Age"],axis=0))

# fig = plt.figure()
# f, axes = plt.subplots(nrows = 3, ncols = 3, sharex=True, sharey = True)
for temp in df1:
    df1.plot(kind='scatter',x='Age',y=temp)
    plt.title("Scatter plot of Age vs "+ temp)
    plt.show()
for temp in df1:
    df1.plot(kind='scatter',x='BMI',y=temp)
    plt.title("Scatter plot of BMI vs "+ temp)
    plt.show()

hist=data.hist(column=["Pregnancies","SkinThickness"])
plt.title("Histogram of")
plt.show()

data.groupby("Outcome")["Pregnancies"].hist()
plt.title("Pregnancies with Each Outcome")
plt.show()


for temp in df1:
    plt.boxplot(data[temp])
    plt.title("Box plot of "+temp)
    plt.show()