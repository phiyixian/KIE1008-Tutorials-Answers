#include <iostream>
#include <vector>

using namespace std;

class matrixType {
private:
    int x;
    int y;
    std::vector<double> matrix;
public:
    matrixType(int, int);
    matrixType operator+(const matrixType & rhs);
    matrixType operator*(const matrixType & rhs);

    int getRows(){
        return x;
    }

    int getColumns(){
        return y;
    }

    void print(){
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                std::cout << matrix[i * y + j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void update(){
        for(int i = 0; i < x; i ++){
            for(int j = 0; j < y; j ++){
                std::cout << "Enter for index " << i << "," << j << ": ";
                std::cin >> matrix[i * y + j];
                std::cout << std::endl;
            }
        }
    }

    double& operator()(int& r, int& c){
        if(r > x || c > y){
            throw std::out_of_range("Matrix index out of range.");
        }
        return matrix[r * y + c];
    }

    const double& operator()(int& r, int& c) const{
        if(r > x || c > y){
            throw std::out_of_range("Matrix index out of range.");
        }
        return matrix[r * y + c];
    }
};

matrixType::matrixType(int num1, int num2){
    if(num1 == 0 || num2 == 0){
        throw std::runtime_error("Zero is not allowed.");
    } else {
        x = num1;
        y = num2;
        matrix.resize(x * y);
    }
}

matrixType matrixType::operator+(const matrixType & rhs){
    if (x == rhs.x && y == rhs.y){
        matrixType sum(x, y);
        for(int i = 0; i < x; i ++){
            for(int j = 0; j < y; j ++){
                int index = i * y + j;
                matrix[index] = matrix[index] + rhs.matrix[index];
            }
        }
        return sum;
    }
}

matrixType matrixType::operator*(const matrixType & rhs){
    if (x == rhs.x && y == rhs.y){
        matrixType product(x, y);
        for(int i = 0; i < x; i ++){
            for(int j = 0; j < y; j ++){
                int index1 = i * y + j;
                int index2 = j * x + i;
                matrix[index1] = matrix[index1] * rhs.matrix[index2];
            }
        }
        return product;
    }
}


int main()
{
    matrixType m1(2, 2);
    m1.update();
    matrixType m2(2, 2);
    m2.update();

    m1.print();
    std::cout << std::endl;
    m2.print();
    std::cout << std::endl;

    matrixType m3(2, 2);
    m1 + m2;
    m3 = m1;
    m3.print();
    std::cout << std::endl;

    matrixType m4(2, 2);
    m1 * m2;
    m4 = m1;
    m4.print();
    std::cout << std::endl;

    return 0;
}
