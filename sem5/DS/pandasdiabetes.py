# written by gaurav cs20b1021
#

import pandas as pd    #importing pandas
df = pd.read_csv("diabetes.csv")    #reading csv

while(1):
    choice = int(input("\n1. Probability of diabetes with age group\n2. Proabability of diabetes with glucose above 120, BMI above 25, ....\n3. Exit\n Enter your choice  :  "))
        ################ Part - 1 ###################
    if(choice == 1):
        dfabove50 = df.query("(Age >=50 )")   #making a new dataframe for all ages above 50
        df40to50 = df.query("(Age >=40 ) and (Age < 50)")   # doiing the same as above for all required age groups
        df30to40 = df.query("(Age >=30 ) and (Age < 40)")   #
        dfbelow30 = df.query("(Age < 30)")                  #

        pb30 = dfbelow30['Outcome'].mean()                  # mean  = probability as the values of diabetes is 1 and not having diabetes is 0
        print("\nProbability of diabetes below 30 : ",pb30)
        pb30to40 = df30to40['Outcome'].mean()
        print("Probability of diabetes from 30 to 40 : ",pb30to40)
        pb40to50 = df40to50['Outcome'].mean()
        print("Probability of diabetes from 40 to 50 : ",pb40to50)
        pb50 = dfabove50['Outcome'].mean()
        print("Probability of diabetes above 50 : ",pb50)

        ################ Part - 2 ###################
    elif(choice == 2):
        dfF = df.query("(Glucose > 120 ) and (BloodPressure > 90 ) and (SkinThickness > 30 ) and (Insulin > 150 ) and (BMI > 25 )")
        print("\nProbability of diabetes with a glucose level of more than 120 + blood pressure of more than 90 + skin thickness of more than 30 + insulin above 150 + BMI above 25 : ",dfF['Outcome'].mean())

    elif(choice == 3):
        break