#include <iostream>
#include <vector>
using namespace std;

// 2. Consider the following hash functions.
// (a) h(i) =i^2 mod 10
// (b) h(i) =i^3 mod 10
// (c) h(i) = (11 ∗ i^2) mod 10
// (d) h(i) = (12 ∗ i) mod 10
// Demonstrate the distribution of keys 0 to 9 using all the hash functions. Decide which hash
// function is more effective

void analyze(const vector<int>& slots){
    int collisions = 0;
    int empty = 0;
    
    for(int count: slots){
        if(count > 1) collisions += (count - 1);
        if(count == 0) empty++;
    }
    
    cout << "Collisions: " << collisions << endl;
    cout << "Empty: " << empty << endl;
}

int main() {
    const int size = 10;
    vector<int> distA(size, 0), distB(size, 0), distC(size, 0), distD(size, 0);
    for(int i = 0; i < 10; i ++){
        distA[(i * i) % 10]++;
        distB[(i * i * i) % 10]++;
        distC[(11 * i * i) % 10]++;
        distD[(12 * i) % 10]++;
    }
    
    cout << "(a) h(i) =i^2 mod 10" << endl;
    analyze(distA);
    
    cout << "(b) h(i) =i^3 mod 10" << endl;
    analyze(distB);
    
    cout << "(c) h(i) = (11 ∗ i^2) mod 10" << endl;
    analyze(distC);
    
    cout << "(d) h(i) = (12 ∗ i) mod 10" << endl;
    analyze(distD);

    return 0;
}
