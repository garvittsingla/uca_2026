#include "iostream"

/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
   int twocomplement = ~x+1;
   int complementSignedBit = twocomplement >> 31;
   int  signedBit = x >> 31;
   return ((signedBit | complementSignedBit)) + 1;
}


int main(){
    std::cout << bang(3) << std::endl; //0
    std::cout << bang(0) << std::endl; //1
    std::cout << bang(-1) << std::endl; //0
}