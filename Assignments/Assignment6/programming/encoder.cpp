#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

class NaiveEncoder {
private:
    const std::string MAP = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    std::string convertToBinary(int integer) {
      std::string binary = "";
      while (integer != 0) {
        int remainder = integer % 2;
        binary += std::to_string(remainder);
        integer /= 2;
      }
      while (binary.size() < 8) {
        binary += "0";
      }
      reverse(binary.begin(), binary.end());
      return binary;
  }
  std::string convertToBinaryString(std::string input) {
    std::string binary = "";
    for (int i = 0; i < input.size(); i++) {
      int asciiVal = (int)input[i];
      // std::cout << "asci value is : "<< asciiVal << std::endl;
      binary += convertToBinary(asciiVal);

    }

    return binary;
  }

  int convertToDecimalInteger(std::string binaryString) {

    int decimal = 0;
    int power = 0;
    for (int i = binaryString.size() - 1; i >= 0; i--) {
      int powValue = pow(2, power++);
      decimal += (powValue * (binaryString[i] - '0'));
    }
    return decimal%63;
  }

  std::vector<int> convertToDecimalVector(std::string &binaryString) {
    std::vector<int> decimalValues;

    while(binaryString.size() % 6 != 0){
      binaryString += "0";
    }

    for (int i = 0; i < binaryString.size(); i += 6) {
      std::string singleBinary = binaryString.substr(i, 6);
      decimalValues.push_back(convertToDecimalInteger(singleBinary));
    }

    return decimalValues;
  }

  char mapToCharacter(int integer){
    return MAP[integer];
  }

  int characterToInteger(char ch){
    return MAP.find(ch);
  }

  std::vector<int> getDecimalValuesDecoded(std::string encoded,int i){
    std::vector<int> decimalValues;
    while(i >=0){
      decimalValues.push_back(characterToInteger(encoded[i--]));
     
    }
    reverse(decimalValues.begin(),decimalValues.end());
    // for(auto it:decimalValues)   std::cout << "Decimal conversion is " << it << std::endl;
    return decimalValues;
  }
  std::string convertToBinaryDecoded(int integer) {
    std::string binary = "";
    while (integer != 0) {
      int remainder = integer % 2;
      binary += std::to_string(remainder);
      integer /= 2;
    }
    while (binary.size() < 6) {
      binary += "0";
    }
    reverse(binary.begin(), binary.end());
    return binary;
}
  std::string convertToBinaryStringDecoded(std::vector<int> decimalValues) {
    std::string binary = "";
    for(auto it:decimalValues){
      binary += convertToBinaryDecoded(it);
    }
    
    return binary;
  }

  int convertToDecimalDecoded(std::string binaryString){
    int decimal = 0;
    int power = 0;
    for (int i = binaryString.size() - 1; i >= 0; i--) {
      int powValue = pow(2, power++);
      decimal += (powValue * (binaryString[i] - '0'));
    }
    return decimal;
  }

  std::string decodeOriginalString(std::string decoded){
    std::string originalString = "";
    for(int i = 0 ; i < decoded.size() ; i+=8){
      std::string singleBinary = decoded.substr(i,8);
      int decimalInteger = convertToDecimalDecoded(singleBinary);
      originalString += (char)decimalInteger;
    }

    return originalString;
  }

  

public:
  std::string encode(std::string input) {
    std::string binaryConversion = convertToBinaryString(input);
    int numberOfPadding = binaryConversion.size() % 3;
    std::vector<int> decimalValues = convertToDecimalVector(binaryConversion);
    std::string encodedString = "";
    for(auto it:decimalValues){
      encodedString += mapToCharacter(it);
    }
    while(numberOfPadding > 0){
      numberOfPadding--;
      encodedString += "=";
    }
    return encodedString;
  }

  std::string decode(std::string encoded){
    int numberOfPadding = 0;
    int i = encoded.size()-1;
    while(encoded[i] == '='){
      i--;
      numberOfPadding++;
    }

    std::vector<int> decimalValues = getDecimalValuesDecoded(encoded,i);
    std::string binaryString = convertToBinaryStringDecoded(decimalValues);

    while(binaryString.size() % 8 !=0){
      binaryString.pop_back();
    }

    
    // std::cout << "Binary string is " << binaryString << std::endl;

    std::string originalString = decodeOriginalString(binaryString);
    return originalString;


  }
};

class BitwiseEncoder{
  private:
   const std::string MAP = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

  public:
    std::string encode(std::string input){
      std::string encoded = "";
      for(int i = 0 ; i < input.size() ; i+=3){
        int remaining = input.size() - i;

        int firstAscii = (int)input[i];
        int secondAscii = i+1 < input.size() ? (int)input[i+1] : 0;
        int thirdAscii = i+2 < input.size() ? (int)input[i+2] : 0;

        int firstSixBytes = firstAscii >> 2;
        int secondSixBytes = ((firstAscii & 0x03) << 4 ) | (secondAscii >> 4);
        int thirdSixBytes = (((secondAscii & 0xf) << 2) | (thirdAscii >> 6));
        int fourSixBytes = (thirdAscii & 0x3f);

        encoded += MAP[firstSixBytes];
            encoded += MAP[secondSixBytes];

            if (remaining >= 2)
                encoded += MAP[thirdSixBytes];
            else
                encoded += '=';

            if (remaining == 3)
                encoded += MAP[fourSixBytes];
            else
                encoded += '=';
        }
      
      return encoded;
     
    }
    //TODO:Complete this function
    std::string decode(std::string encodedText){
      return "";
    }
};

int main(){
  // NaiveEncoder en;
  BitwiseEncoder en;

  std::cout << "Enter the string you want to encode: ";
  std::string input;
  std::getline(std::cin, input); 

  std::string encoded = en.encode(input);

  std::cout << "The encoded string is: " << encoded << std::endl;

  std::string decoded = en.decode(encoded);

  std::cout << "The decoded string is: " << decoded << std::endl;
}
