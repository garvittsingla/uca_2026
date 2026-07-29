#include "iostream"


// we want to 1 from different and 0 when they sam
int bitXor(int x, int y) {
    int detect1 = x & y;
    int detect0 = ~x & ~y;
    int notBoth1 = ~detect1;
    int notBoth0 = ~detect0;
    return notBoth1 & notBoth0;
}
int main(){
    int x = 4;
    int y = 5;

    std::cout << "Xor of x and y is : " << (x^y) << std::endl;
    std::cout << "Xor of my custom function x and y is : " << bitXor(x,y) << std::endl;


    x = 3;
    y = 6;
    std::cout << "Xor of x and y is : " << (x^y) << std::endl;
    std::cout << "Xor of my custom function x and y is : " << bitXor(x,y) << std::endl;

    x = 2;
    y = 1;
    std::cout << "Xor of x and y is : " << (x^y) << std::endl;
    std::cout << "Xor of my custom function x and y is : " << bitXor(x,y) << std::endl;

}