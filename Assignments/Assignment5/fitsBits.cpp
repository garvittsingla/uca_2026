#include <cassert>
#include<iostream>

/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
// we can also do one more thing, if we shift 1 left shift the x times other than the n like all bits be 1 rather than that n bits
int fitsBits(int x, int n) {
    // int mask = (~0) << n;
    // int somenum = mask & x;
    // if(somenum !=0) return 0;
    // return 1;

    //could not do it, will ask in class
}
int main(){


    std::cout << "Testcase 1 fitsBits(5,3) \nExpected => 0" << std::endl;
    std::cout << "Output : " << fitsBits(5,3) << std::endl << std::endl;
    
    std::cout << "Testcase 2 fitsBits(-4,3) \nExpected => 1" << std::endl;
    std::cout << "Output : " << fitsBits(-4,3) << std::endl << std::endl;
    
    std::cout << "Testcase 3 fitsBits(7,4) \nExpected => 1" << std::endl;
    std::cout << "Output : " << fitsBits(7,4) << std::endl << std::endl;
    
    std::cout << "Testcase 4 fitsBits(8,4) \nExpected => 0" << std::endl;
    std::cout << "Output : " << fitsBits(8,4) << std::endl << std::endl;
    
    std::cout << "Testcase 5 fitsBits(-8,4) \nExpected => 1" << std::endl;
    std::cout << "Output : " << fitsBits(-8,4) << std::endl << std::endl;
    

    


}