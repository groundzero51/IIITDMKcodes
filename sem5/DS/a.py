# RAM SUNIL 
# CS20B1020

import pandas
import matplotlib.pyplot
df=pandas.read_csv('diabetes1.csv')
print(df)

df1=df.loc[:,df.columns!='Outcome']
print("\nMean values:\n",df1.mean())
print("\nMedian values:\n",df1.median())
print("\nMode values:\n",df1.mode())
print("\nStandard Deviation values:\n",df1.std())
print("\nMinimum Values:\n",df1.min())
print("\nMaximum Values:\n",df1.max())


df2=df1.corr()
print("Age with other attribtes\n")
print(df2.drop(["Pregnancies","Glucose","BloodPressure","SkinThickness","Insulin","BMI","DiabetesPedigreeFunction"],axis=0))
print("\nBMI with other attribtes\n")
print(df2.drop(["Pregnancies","Glucose","BloodPressure","SkinThickness","Insulin","DiabetesPedigreeFunction","Age"],axis=0))



print("\nAge with other attribtes\n")
for temp in df1:
    print("Age and",temp,"Corelation Coefficient=",df1['Age'].corr(df[temp]))

print("\nBMI with other attribtes\n")
for temp in df1:
    print("BMI and",temp,"Corelation Coefficient=",df1['BMI'].corr(df[temp]))
for temp in df1:
    df1.plot(kind='scatter',x='Age',y=temp)
    matplotlib.pyplot.title("Age vs "+ temp)
    matplotlib.pyplot.show()
for temp in df1:
    df1.plot(kind='scatter',x='BMI',y=temp)
    matplotlib.pyplot.title("BMI vs "+ temp)
    matplotlib.pyplot.show()


# histogram
hist=df.hist(column=["Pregnancies","SkinThickness"])
matplotlib.pyplot.show()

# Groupby
df.groupby("Outcome")["Pregnancies"].hist()
matplotlib.pyplot.title("Pregnancies with Each Outcome")
matplotlib.pyplot.show()


# Create boxplot
matplotlib.pyplot.boxplot(df['Pregnancies'])
matplotlib.pyplot.title('Pregnancies')
matplotlib.pyplot.show()

matplotlib.pyplot.boxplot(df['Glucose'])
print("Box plot of Glucose")
matplotlib.pyplot.title('Glucose')
matplotlib.pyplot.show()

matplotlib.pyplot.boxplot(df['BloodPressure'])
print("Box plot of BloodPressure")
matplotlib.pyplot.title('BloodPressure')
matplotlib.pyplot.show()

matplotlib.pyplot.boxplot(df['SkinThickness'])
print("Box plot of SkinThickness")
matplotlib.pyplot.title('SkinThickness')
matplotlib.pyplot.show()

matplotlib.pyplot.boxplot(df['Insulin'])
print("Box plot of Insulin")
matplotlib.pyplot.title('Insulin')
matplotlib.pyplot.show()

matplotlib.pyplot.boxplot(df['BMI'])
print("Box plot of BMI")
matplotlib.pyplot.title('BMI')
matplotlib.pyplot.show()

matplotlib.pyplot.boxplot(df['DiabetesPedigreeFunction'])
print("Box plot of DiabetesPedigreeFunction")
matplotlib.pyplot.title('DiabetesPedigreeFunction')
matplotlib.pyplot.show()

matplotlib.pyplot.boxplot(df['Age'])
print("Box plot of Age")
matplotlib.pyplot.title('Age')
matplotlib.pyplot.show()


matplotlib.pyplot.boxplot(df['Outcome'])
print("Box plot of Outcome")
matplotlib.pyplot.title('Outcome')
matplotlib.pyplot.show()