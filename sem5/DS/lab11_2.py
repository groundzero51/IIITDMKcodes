#written by gaurav r
#cs20b1021
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

print("Question 2 A & B : ")

miss_df = pd.read_csv("landslide_data3_miss.csv")
original_df = pd.read_csv("landslide_data3_original.csv")
replaced_mean_df=miss_df.fillna(miss_df.mean())
print("Dataframe with replaced values : ")
print(replaced_mean_df)
interpolate_df=miss_df.interpolate()
print("Dataframe with replaced values (interpolate) : ")
print(interpolate_df)

print("Mean Of The Replaced csv file is : ")
print(replaced_mean_df.mean())
print("Mean Of The Replaced csv file is (interpolate) : ")
print(interpolate_df.mean())
print("Mean Of The Original csv file is : ")
print(original_df.mean())

print("Median Of The Replaced csv file is ; ")
print(replaced_mean_df.median())
print("Median Of The Replaced csv file is (interpolate) ; ")
print(interpolate_df.median())
print("Median Of The Original csv file is : ")
print(original_df.median())

print("Mode Of The Replaced csv file is : ")
print(replaced_mean_df.mode())
print("Mode Of The Replaced csv file is (interpolate) : ")
print(interpolate_df.mode())
print("Mode Of The Original csv file is : ")
print(original_df.mode())

print("Standard Deviation Of The Replaced csv file is ; ")
print(replaced_mean_df.std())
print("Standard Deviation Of The Replaced csv file is (interpolate) ; ")
print(interpolate_df.std())
print("Standard Deviation Of The Original csv file is : ")
print(original_df.std())

original_dict = {}
replacedmean_dict = {}
interpolate_dict = {}
for i in original_df.columns:
    if i == "dates" or i=="stationid":
        continue
    original_dict[i]=original_df.loc[miss_df[i].isnull()][i]
    replacedmean_dict[i]=replaced_mean_df.loc[miss_df[i].isnull()][i]
    interpolate_dict[i]=interpolate_df.loc[miss_df[i].isnull()][i]
    rmse_dict1 = {}
    rmse_dict2 = {}
for i in original_dict:
    original_array = np.array(original_dict[i])
    replaced_array = np.array(replacedmean_dict[i])
    interpolate_array = np.array(interpolate_dict[i])
    rmse_dict1[i] = (np.sum((original_array-replaced_array)**2)/len(original_array))**0.5
    rmse_dict2[i] = (np.sum((original_array-interpolate_array)**2)/len(original_array))**0.5

print("plot for Question 2A : ")
plt.bar(rmse_dict1.keys(),rmse_dict1.values())
plt.title("RMSE plot for 2A (fillna) : ")
plt.show() #q2a

print("plot for Question 2B : ")
plt.bar(rmse_dict2.keys(),rmse_dict2.values())
plt.title("RMSE plot for 2B (interpolate) : ")
plt.show() #q2b