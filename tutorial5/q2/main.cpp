// Online C++ compiler to run C++ program online
#include <iostream>

class smart
{
public:
    void print() const{
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
    };
    void set(int a, int b){
        x = a;
        y = b;
    };
    int sum(){
        return x + y;
    };
    smart():x(0), y(0){};
    smart(int a, int b):x(a), y(b){};
private:
    int x;
    int y;
    int secret();
};

class superSmart: public smart
{
public:
    void print() const{
        smart::print();
        std::cout << "z = " << z << std::endl;
    };
    void set(int a, int b, int c){
        smart::set(a, b);
        z = c;
    };
    int manipulate();
    superSmart():smart(), z(0){};
    superSmart(int a, int b, int c):smart(a, b), z(c){};
private:
    int z;
};

int main() {
    // Write C++ code here
    superSmart mySuperSmart(1, 2, 3);
    std::cout << mySuperSmart.sum() << std::endl;

    return 0;
}
