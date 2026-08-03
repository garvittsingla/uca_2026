#include "iostream"

/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
    int negX = ~x + 1;
    int sign = negX | x;
    int signedBit = sign >> 31;
    return signedBit+1;
}


int main(){
    std::cout << bang(3) << std::endl; //0
    std::cout << bang(0) << std::endl; //1
}