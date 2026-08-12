#include <iostream>
#include <vector>
using namespace std;

/*
 * Problem:
 * Every number appears exactly 3 times, except one number
 * which appears exactly 4 times.
 *
 * Expected:
 * Time:  O(n)
 * Space: O(1)
 *
 * Implement ONLY this function.
 */
int findFourTimesNumber(const vector<int>& arr) {
    //Approach: if we see every number occurs 3 times, so every bit will also be in pair of 3 but only one bit will remain unset of that integer
    //so just finding that bit and making the answer from it
    int ans = 0;
    for(int i = 31 ; i >= 0 ; i--){
        
        int totalSetBits = 0;
        for(auto x:arr){
            totalSetBits += ((x >> i) & 1);
        }
        if(totalSetBits%3 != 0){
            ans = ans | (1 << i );
        }
    }
    return ans;
}

void runTest(const vector<int>& arr, int expected, int testNo) {
    int result = findFourTimesNumber(arr);

    if (result == expected) {
        cout << "Test " << testNo << ": PASS (got " << result << ")\n";
    } else {
        cout << "Test " << testNo
             << ": FAIL (expected " << expected
             << ", got " << result << ")\n";
    }
}

int main() {

    // Test 1: 3 appears 4 times
    vector<int> test1 = {
        1, 2, 3, 4, 1, 2, 4,
        1, 2, 3, 4, 3, 3
    };

    // Test 2: 7 appears 4 times
    vector<int> test2 = {
        5, 7, 2, 5, 2, 7, 9,
        5, 2, 9, 7, 9, 7
    };

    // Test 3: 10 appears 4 times
    vector<int> test3 = {
        3, 6, 10, 3, 6, 10, 8,
        3, 6, 8, 10, 8, 10
    };

    // Test 4: 1 appears 4 times
    vector<int> test4 = {
        4, 4, 1, 2, 2, 3, 3,
        1, 4, 2, 3, 1, 1
    };

    // Test 5: 42 appears 4 times
    vector<int> test5 = {
        11, 42, 8, 11, 8, 42, 19,
        11, 8, 19, 42, 19, 42
    };

    runTest(test1, 3, 1);
    runTest(test2, 7, 2);
    runTest(test3, 10, 3);
    runTest(test4, 1, 4);
    runTest(test5, 42, 5);

    return 0;
}