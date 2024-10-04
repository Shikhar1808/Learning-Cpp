#include <iostream>
using namespace std;

class BackAccount{
    private:
        int accNumber;
        string accHolderName;
        double accBalance;

        static int totalAccounts;

    public:
        BackAccount(int accNumber, string accHolderName, double accBalance){
            this->accNumber = accNumber;
            this->accHolderName = accHolderName;
            this->accBalance = accBalance;
            totalAccounts++;
        }

        static int getTotalAccounts(){
            return totalAccounts;
        }

        void display(){
            cout<<"Account Number: "<<accNumber<<endl;
            cout<<"Account Holder Name: "<<accHolderName<<endl;
            cout<<"Account Balance: "<<accBalance<<endl;
        }

        void deposit(double amount){
            accBalance += amount;
            cout<<"Amount "<<amount<<" deposited successfully."<<endl;
        }

        void withdraw(double amount){
            if(accBalance - amount >= 0){
                accBalance -= amount;
                cout<<"Amount "<<amount<<" withdrawn successfully."<<endl;
            }else{
                cout<<"Insufficient balance."<<endl;
            }
        }
};

int BackAccount::totalAccounts = 0;

int main(){
    BackAccount acc1(101, "HIHI", 5000);
    acc1.display();
    acc1.deposit(2000);
    acc1.withdraw(1000);

    BackAccount acc2(102, "HAHA", 6000);
    acc2.display();
    acc2.deposit(3000);
    acc2.withdraw(4000);

    cout<<"Total Accounts: "<<BackAccount::getTotalAccounts()<<endl;
    return 0;
}