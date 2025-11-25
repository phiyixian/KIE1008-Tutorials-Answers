// Online C++ compiler to run C++ program online
#include <iostream>

class bankAccount{
    private:
        int accountNumber;
        double balance;
    public:
        bankAccount():accountNumber(0), balance(0){};
        bankAccount(int a, double b){
            accountNumber = a;
            if(b >= 0){
                balance = b;
                std::cout << "Balance: " << balance << std::endl;
            } else {
                std::cout << "Balance is invalid." << std::endl;
                balance = 0;
            }
        };
        
        void credit(int c) {
            balance = balance + c;
            std::cout << "Credited Balance: " << balance << std::endl;
            
        }
        
        void debit(int d) {
            if(d <= balance){
                balance = balance - d;
                std::cout << "Debited Balance: " << balance << std::endl;
            } else {
                std::cout << "Debit amount exceeded account balance." << std::endl;
            }
        }
        
        double getBalance() const{
            return balance;
        }
        
        void setBalance(double d){
            balance = d;
        }
        
        void printInfo() const {
            std::cout << "Account Number: " << accountNumber << std::endl;
            std::cout << "Balance: " << balance << std::endl;
            std::cout << std::endl;
        }
};

class savingsAccount: public bankAccount{
    private:
        double interestRate;
    public:
        savingsAccount():bankAccount(), interestRate(0){};
        savingsAccount(int a, double b, int c):bankAccount(a, b), interestRate(c){};
        
        void calculateInterest() {
            double interest = bankAccount::getBalance() * interestRate / 100;
            std::cout << "Interest: " << interest << std::endl;
        }
        
        double getInterest(){
            return bankAccount::getBalance() * interestRate / 100;
        }
        
        void credit(int c) {
            bankAccount::setBalance(bankAccount::getBalance() + c);
            std::cout << "Credited Balance: " << bankAccount::getBalance() + getInterest() << std::endl;
            
        }
};

int main() {
    // Write C++ code here
    bankAccount myBank(123, 20);
    myBank.credit(10);
    myBank.debit(5);
    myBank.printInfo();
    
    savingsAccount mySaving(123, 50, 5);
    mySaving.calculateInterest();
    mySaving.credit(30);

    return 0;
}
