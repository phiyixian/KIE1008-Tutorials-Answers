// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>

class Account{
    private:
        std::string number;
        double balance;
    public:
        Account():number(""), balance(0){};
        Account(std::string a, double b):number(a), balance(b){};
        std::string getNumber(){
            return number;
        }
        
        void setNumber(std::string n){
            number = n;
        }
        
        double getBalance(){
            return balance;
        }
        
        void setBalance(double b){
            balance = b;
        }
        
        virtual void displayInfo() = 0;
        virtual void calculateBalance() = 0;
};

class Person{
    protected:
        std::string name;
        std::string nric;
    public:
        Person():name(""), nric(""){};
        Person(std::string a, std::string b):name(a), nric(b){};
        std::string getName(){
            return name;
        }
        
        void setName(std::string n){
            name = n;
        }
        
        std::string getNric(){
            return nric;
        }
        
        void setNric(std::string n){
            nric = n;
        }
        virtual void displayInfo() = 0;
};

class Saving: public Account, public Person{
    private:
        double rate;
    public:
        Saving():Account(), Person(), rate(0){};
        Saving(std::string a, double b, std::string c, std::string d, double e):Account(a, b), Person(c, d), rate(e){};
        double getRate(){
            return rate;
        }
        
        void setRate(double a){
            rate = a;
        }
        
        void calculateBalance(){
            Account::setBalance(Account::getBalance() * rate / 100 + Account::getBalance());
        }
        
        void displayInfo(){
            std::cout << "Name: " << Person::getName() << "(NRIC: " << Person::getNric() << ")" << std::endl;
            std::cout << "Account Number: " << Account::getNumber() << std::endl;
            std::cout << "Initial Balance: " << Account::getBalance() << std::endl;
            std::cout << "Account Type: Saving" << std::endl;
            std::cout << "Monthly Interest Rate: " << rate << "%" << std::endl;
        }
};

class Current: public Account, public Person{
    private:
        double charge;
    public:
        Current():Account(), Person(), charge(0){};
        Current(std::string a, double b, std::string c, std::string d, double e):Account(a, b), Person(c, d), charge(e){};
        double getCharge(){
            return charge;
        }
        
        void setCharge(double a){
            charge = a;
        }
        
        void calculateBalance(){
            Account::setBalance(Account::getBalance() - charge);
        }
        
        void displayInfo(){
            std::cout << "Name: " << Person::getName() << "(NRIC: " << Person::getNric() << ")" << std::endl;
            std::cout << "Account Number: " << Account::getNumber() << std::endl;
            std::cout << "Initial Balance: " << Account::getBalance() << std::endl;
            std::cout << "Account Type: Current" << std::endl;
            std::cout << "Monthly Charge: " << charge << std::endl;
        }
};

int main() {
    // Write C++ code here
    Saving mySaving("123-234-345", 1000, "Phi", "01234567890", 0.15);
    mySaving.displayInfo();
    for(int i = 0; i < 12; i ++){
        mySaving.calculateBalance();
        std::cout << "Balance after " << i + 1 << "month(s):" << mySaving.getBalance() << std::endl;
    }
    
    std::cout << std::endl << std::endl;
    
    Current myCurrent("123-234-345", 2000, "Lee", "012345678991", 10);
    myCurrent.displayInfo();
    for(int i = 0; i < 12; i ++){
        myCurrent.calculateBalance();
        std::cout << "Balance after " << i + 1 << "month(s):" << myCurrent.getBalance() << std::endl;
    }
    return 0;
}

