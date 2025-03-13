#include <bits/stdc++.h>
using namespace std;
class BankAccount{
    private:
        string name;
        int accountNum;
        double balance;
    public:
        BankAccount(string n,int ac,double bal){
            name=n;
            accountNum=ac;
            balance=bal;
        }
        string getName(){
            return name;
        }
        int getaccountNum(){
            return accountNum;
        }
        double getBalance(){
            return balance;
        }
        void deposit(double amt){
            balance+=amt;
            cout<<"\t\t\t\t Amount Deposit Successfully"<<endl;
        }
        void withdraw(double amt){
            if(balance>= amt){
                balance-=amt;
                cout<<"\t\t\t\t Amount Withdraw Successfully"<<endl;
            }
            else{
                cout<<"\t\t\t\t Insufficient Bank Balance"<<endl;
            }
        }
};
class BankManagement{
    private:
        vector<BankAccount> accounts;
    public:
        void AddAccount(string name,int accountNum,double balance){
            accounts.push_back(BankAccount(name,accountNum,balance));
        }
        void showALLAccount(){
            cout<<"\t\t All Account Holders"<<endl;
            for(int i=0;i<accounts.size();i++){
                cout<<"\t\t\t\t Name : "<<accounts[i].getName()<<endl;
                cout<<"\t\t\t\t Account Number : "<<accounts[i].getaccountNum()<<endl;
                cout<<"\t\t\t\t Balance : "<<accounts[i].getBalance()<<endl;
            }
        }
        void searchAccount(int account){
            cout<<"\t\t Account Holder "<<endl;
            for(int i=0;i<accounts.size();i++){
                if(accounts[i].getaccountNum()==account){
                    cout<<"\t\t\t\t Name : "<<accounts[i].getName()<<endl;
                    cout<<"\t\t\t\t Account Number : "<<accounts[i].getaccountNum()<<endl;
                    cout<<"\t\t\t\t Balance : "<<accounts[i].getBalance()<<endl;
                }
            }
        }
        BankAccount* findAccount(int accountNum){
            for(int i=0;i<accounts.size();i++){
                if(accounts[i].getaccountNum()==accountNum){
                    return &accounts[i];
                }
            }
        }

};
int main() {
    BankManagement bank;
    int choice;
    char op;

    do{
        cout<<"\t\t Bank Management System"<<endl;
        cout<<endl;
        cout<<"\t\t\t Main Menu"<<endl;
        cout<<endl;
        cout<<"\t\t 1. Create New Account"<<endl;
        cout<<"\t\t 2. Show All Account"<<endl;
        cout<<"\t\t 3. Search Account"<<endl;
        cout<<"\t\t 4. Deposit Money"<<endl;
        cout<<"\t\t 5. Withdraw Money"<<endl;
        cout<<"\t\t 6. Exit"<<endl;
        cout<<"\t\t -----------------------"<<endl;
        cout<<endl;
        cout<<"\t\t Enter Your Choice :";
        cin>>choice;
        switch(choice){
            case 1:{
                string name;
                int accountNum;
                double balance;
                cout<<"\t\t Enter Name:";
                cin>>name;
                cout<<"\t\t Enter Acount Number:";
                cin>>accountNum;
                cout<<"\t\t Enter Initial Balance:";
                cin>>balance;
                bank.AddAccount(name,accountNum,balance);
                cout<<"\t\t Account Created Succesfully........"<<endl;
                break;
            }
            case 2:{
                bank.showALLAccount();
                break;
            }
            case 3:{
                int accountNumber;
                cout<<"\t\t\t\t Enter Account Number :";
                cin>>accountNumber;
                bank.searchAccount(accountNumber);
                break;
            }
            case 4:{
                int accountNumber;
                double amount;
                cout<<"\t\t Enter Account Number to Deposit Money";
                cin>>accountNumber;
                BankAccount* account=bank.findAccount(accountNumber);
                if(account!=NULL){
                    cout<<"\t\t Enter Amount to Deposit";
                    cin>>amount;
                    account->deposit(amount);
                    cout<<"\t\t"<<amount<<"\t\t Deposit Successully ...."<<endl;
                }
                else{
                    cout<<"\t\t\t\t Account Not Found ..."<<endl;
                }
                break;
            }
            case 5:{
                int accountNumber;
                double amount;
                cout<<"\t\t Enter Account Number to Withdraw Money";
                cin>>accountNumber;
                BankAccount* account=bank.findAccount(accountNumber);
                if(account!=NULL){
                    cout<<"\t\t Enter Amount to Withdraw";
                    cin>>amount;
                    account->withdraw(amount);
                    cout<<"\t\t"<<amount<<"\t\t Withdraw Successully ...."<<endl;
                }
                else{
                    cout<<"\t\t\t\t Account Not Found ..."<<endl;
                }
                break;
            }
            case 6:{
                exit(1);
                break;
            }
            default:{
                cout<<"\t\t You have Entered wrong value"<<endl;
            }
        }
        cout<<"\t\t Do You want to Continue or Exit [Y/N]";
        cin>>op;
    
    } 
    while(op=='y' || op=='Y');
    return 0;
}