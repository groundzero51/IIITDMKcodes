import pandas as pd

names = ["Ram", "Sam", "Prabhu"]
accountnums = ["9893893891", "9893893898", "9893893871"]
accounttypes = ["SB", "CA", "SB"]
aadharnums = ["959389389173", "959389389179", "959389389159"]
bal = ["8989839", "7690990", "989330"]

dict = {'Name': names, 'Account Number': accountnums,
        'Account Type': accounttypes, 'Aadhar_No': aadharnums, 'Balance': bal}
df = pd.DataFrame(dict)
df.to_csv("SBIAccountHolder.csv")
print(df)
while 1:
    print("\n(1) Append record(row) of account holder\n(2) Delete the row of account holder\n(3) Credit: ask user the amount to be credited(added)\n(4) Debit: ask user the amount to be debited(removed)\n(5) Print account details of holder\n(6) Exit")
    ch = int(input("\nEnter your ch : "))
    if ch == 1:
        name = input("Please enter the Name: ")
        account_no = input("Please enter the Account Number : ")
        account_type = input("Please enter the Account Type: ")
        aadhar_no = input("Please enter the Aadhar Number: ")
        account_bal = input("Please enter the Balance: ")
        temp_dict = {'Name': name, 'Account Number': account_no,
                     'Account Type': account_type, 'Aadhar_No': aadhar_no, 'Balance': account_bal}
        ind = len(df.index)
        df.loc[ind] = temp_dict
        df.to_csv("SBIAccountHolder.csv")
        break
    elif ch == 2:
        account_no = input("Please enter the Account Number : ")
        ind = -1
        for i in range(len(df)):
            if df['Account Number'][i] == account_no:
                ind = i
                break
        if ind == -1:
            print("Record with Account Number : " + account_no +
                  " Doesn't exist. Please try again!")
        else:
            df = df.drop(ind)
            df.reset_index(inplace=True, drop=True)
        df.to_csv("SBIAccountHolder.csv")
    elif ch == 3:
        account_no = input(
            "Enter the Account Number you want to credit to: ")
        credit_amount = input("Enter the amount to be credited: ")
        ind = -1
        for i in range(len(df)):
            if df['Account Number'][i] == account_no:
                ind = i
                break
        if ind == -1:
            print("Record with Account Number : " + account_no +
                  " Doesn't exist. Please try again!")
        else:
            temp = int(df.loc[ind]["Balance"])
            temp += int(credit_amount)
            df.loc[ind]["Balance"] = temp
            df.to_csv("SBIAccountHolder.csv")
    elif ch == 4:
        account_no = input(
            "Enter the Account Number you want to debit to: ")
        debit_amount = input("Please enter the amount to be debited: ")
        ind = -1
        for i in range(len(df)):
            if df['Account Number'][i] == account_no:
                ind = i
                break
        if ind == -1:
            print("Record with Account Number : " + account_no +
                  " Doesn't exist. Please try again!")
        else:
            if df.loc[ind]["Account Type"] == "SB":
                temp = int(df.loc[ind]["Balance"])
                
                temp -= int(debit_amount)
                df.loc[ind]["Balance"] = temp
                df.to_csv("SBIAccountHolder.csv")
            else:
                temp = df.loc[ind]["Balance"]
                temp -= int(debit_amount)
                df.loc[ind]["Balance"] = temp
                df.to_csv("SBIAccountHolder.csv")
    elif ch == 5:
        account_no = input("Enter the Account Number you want print: ")
        ind = -1
        for i in range(len(df)):
            if df['Account Number'][i] == account_no:
                ind = i
                break
        if ind == -1:
            print("Account Number : " + account_no +
                  " doesn't exist.")
        else:
            print(df.loc[ind])
    elif ch == 6:
        print("Exiting the program")
        break
    else:
        print("Wrong choice! Please try again!")
