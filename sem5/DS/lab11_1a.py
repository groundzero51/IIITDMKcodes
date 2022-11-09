import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
df=pd.read_csv('landslide_data3_miss.csv')
nanc = {} #nan count (missing count)
for i in df.columns:
    nanc[i]=df[i].isnull().sum()
#print(nanc)
plt.bar(nanc.keys(),nanc.values());
print("\nquestion 1A plot : ")
plt.show()   
print("\nquestion 1B : ")
df=df.dropna(axis=0,subset=['stationid'])
print(df)
init_len = len(df)
print("Number of Tuples Deleted From StationID: "+str(nanc['stationid']))
df=df.dropna(axis=0,thresh=7)
final_len = len(df)
print(df)
print("The Number Of rows deleted with nulls 3 and more are: "+str(init_len-final_len))
print("\nquestion 1C : ")
for i in df.columns:
    nanc[i]=df[i].isnull().sum()
print(nanc)
plt.bar(nanc.keys(),nanc.values())
plt.show()
print("The Total Number Of Missing Values is: "+str(sum(nanc.values())))