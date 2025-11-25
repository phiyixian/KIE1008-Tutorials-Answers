// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>

class employee
{
    public:
        void setData(std::string n, std::string d, int a, double p){
            name = n;
            department = d;
            age = a;
            pay = p;
        };
        
        void setName(std::string n){
            name = n;
        };
        std::string getName() const{
            return name;
        };
        void setDepartment(std::string dept){
            department = dept;
        };
        std::string getDepartment() const{
            return department;
        };
        void setAge(int a){
            age = a;
        };
        int getAge() const{
            return age;
        };
        void setPay(double p){
            pay = p;
        };
        double getPay() const{
            return pay;
        };
        employee(std::string n = "", std::string d = "", int a = 0, double p = 0):name(n), department(d), age(a), pay(p){};
        
    private:
        std::string name;
        std::string department;
        int age;
        double pay;
};

class hourlyEmployee: public employee
{
    public:
        void setData(std::string n, std::string d, int a, double p, double hrsWk, double payRate){
            employee::setData(n, d, a, p);
            hoursWorked = hrsWk;
            hourlyPayRate = payRate;
        };
        void setHoursWorked(double hrsWk){
            hoursWorked = hrsWk;
        };
        double getHoursWorked() const{
            return hoursWorked;
        };
        void setHourlyPayRate(double payRate){
            hourlyPayRate = payRate;
        };
        double getHourlyPayRate() const{
            return hourlyPayRate;
        };
        void setPay() const{
            std::cout << "Hourly Employee Pay: " << hoursWorked * hourlyPayRate << std::endl;
        };

        hourlyEmployee(std::string n = "", std::string d = "", int a = 0, double p = 0, double hrsWk = 0, double payRate = 0.0):employee(n, d, a, p), hoursWorked(hrsWk), hourlyPayRate(payRate){};

    private:
        double hoursWorked;
        double hourlyPayRate;
};

int main() {
    // Write C++ code here
    employee myEmployee("Phi", "Engineering", 20, 500);
    myEmployee.setPay(2000);
    std::cout << "Employee Pay: " << myEmployee.getPay() << std::endl;
    
    hourlyEmployee myHourlyEmployee("Phi", "Engineering", 20, 500, 7, 8);
    myHourlyEmployee.setPay();

    return 0;
}
