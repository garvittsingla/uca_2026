#include "iostream"

int bitAnd(int x, int y) {
    int negatX = ~x;
    int negatY = ~y;

    return ~(negatX | negatY);
}
int main(){
    int x = 6;
    int y = 5;

    std::cout << "And of x and y is : " << (x&y) << std::endl;
    std::cout << "And of my custom function x and y is : " << bitAnd(x,y) << std::endl;


    x = 3;
    y = 6;
    std::cout << "And of x and y is : " << (x&y) << std::endl;
    std::cout << "And of my custom function x and y is : " << bitAnd(x,y) << std::endl;

    x = 2;
    y = 1;
    std::cout << "And of x and y is : " << (x&y) << std::endl;
    std::cout << "And of my custom function x and y is : " << bitAnd(x,y) << std::endl;

}