#include "iostream"
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
   int minusOne = x + ~0;
   int isZero = !x;
   return !(isZero | (minusOne & x));
}
int main(){
    std :: cout << isPower2(5) << std::endl; //0
    std :: cout << isPower2(8) << std::endl; //1
    std :: cout << isPower2(0) << std::endl; //0
    std :: cout << isPower2(-1) << std::endl; //0

}