#include "iostream"
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
// 0 & y => 0 , so y will be answer
// if calculated is zero, we add z in it otherwise we return y
int conditional(int x, int y, int z) {
    int twocomplement = ~x + 1;
    int twocomplementsign = twocomplement >> 31;
    int signbit = x >> 31;
    int mask = twocomplementsign | signbit;

    return (y & mask) | (z & ~mask);

}

int main(){
    std::cout << conditional(0,4,5) << std::endl;
}