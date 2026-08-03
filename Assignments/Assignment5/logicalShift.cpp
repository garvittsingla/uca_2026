#include "iostream"


/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
 int logicalShift(int x, int n) {
    return x>>n;
  }

int main(){
    std::cout << std::hex << logicalShift(0x87654321,4) << std::endl;
}