#include "iostream"



/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
 int sign(int x) {
    int leftmostbit = x >> 31;
    int ans = 1&leftmostbit ? -1 : (x&1 ? 1 : 0);
    return ans;
     
}

int main(){
    std::cout << "Expected for my solution 1 => " << sign(130)  << std::endl;
    std::cout << "Expected for my solution -1 => " <<  sign(-23)   << std::endl;
    std::cout << "Expected for my solution 0 => " <<  sign(0)   << std::endl;
}