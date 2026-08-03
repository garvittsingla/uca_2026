#include "iostream"
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */

int getByte(int x, int n) {
    int shiftNumber = n << 3;
    int mask = 0xFF << shiftNumber;
    return (x & mask) >> shiftNumber;
}

int main(){
    std::cout << std::hex << getByte(0x12345678,1) << std::endl;
}
