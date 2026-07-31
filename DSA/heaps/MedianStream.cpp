// ================================================================
//  PROBLEM: Find Median from Data Stream (LeetCode 295)
//
//  Design a data structure that supports two operations:
//    - void addNum(int num)  : add an integer from the data stream
//    - double findMedian()   : return the median of ALL numbers added
//                              so far (at least 1 number exists when
//                              findMedian() is called)
//
//  Median of {1,2,3} = 2.0     Median of {1,2} = (1+2)/2 = 1.5
//  Answers within 1e-5 of the actual answer are accepted.
//
//  HINT: use TWO heaps, kept balanced.
//    - a MAX-heap  for the SMALLER half  (largest of lower half on top)
//    - a MIN-heap  for the LARGER half   (smallest of upper half on top)
//  Then the median is always one or two tops away.
// ================================================================

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;


class MedianFinder {
public:
    priority_queue<int> left;  
    priority_queue<int, vector<int>, greater<int>> right;          
    MedianFinder() {
      
    }

    
    void addNum(int num) {
        if (left.empty() || num <= left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }

        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        } else if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

   
    double findMedian() {
       if(left.size() == right.size()){
        double ans = (left.top() + right.top()) / 2.0;
        return ans;
       }else{
        return left.top();
       }
    }

private:
};

// ================================================================
//  TEST HARNESS - do not change below this line
// ================================================================

struct Step {
    bool isAdd;         // true  -> call addNum(num)
                        // false -> call findMedian() and compare to expected
    int num;
    double expected;
};

struct TestCase {
    string name;
    vector<Step> steps;
};

int main() {
    vector<TestCase> tests = {
        {"LeetCode example", {
            {true,   1,   0.0},   // addNum(1)
            {true,   2,   0.0},   // addNum(2)
            {false,  0,   1.5},   // findMedian() -> 1.5
            {true,   3,   0.0},   // addNum(3)
            {false,  0,   2.0},   // findMedian() -> 2.0
        }},
        {"Duplicates", {
            {true,   1,   0.0},   // addNum(1)
            {true,   1,   0.0},   // addNum(1)
            {false,  0,   1.0},   // findMedian() -> 1.0
        }},
        {"Even count", {
            {true,   5,   0.0},   // {5}
            {true,  15,   0.0},   // {5,15}
            {true,   1,   0.0},   // {1,5,15}
            {true,   3,   0.0},   // {1,3,5,15}
            {false,  0,   4.0},   // findMedian() -> (3+5)/2 = 4.0
        }},
        {"Negatives", {
            {true,  -1,   0.0},   // {-1}
            {true,  -2,   0.0},   // {-2,-1}
            {false,  0,  -1.5},   // findMedian() -> (-2 + -1)/2 = -1.5
        }},
        {"Longer stream", {
            {true,  10,   0.0},   // {10}
            {true,  20,   0.0},   // {10,20}
            {true,  30,   0.0},   // {10,20,30}
            {true,  40,   0.0},   // {10,20,30,40}
            {true,  50,   0.0},   // {10,20,30,40,50}
            {false,  0,  30.0},   // odd count -> 30.0
            {true,  25,   0.0},   // {10,20,25,30,40,50}
            {false,  0,  27.5},   // even count -> (25+30)/2 = 27.5
        }},
    };

    const double EPS = 1e-5;
    int passed = 0;

    for (size_t t = 0; t < tests.size(); t++) {
        TestCase &tc = tests[t];
        MedianFinder mf;

        bool ok = true;
        double got = 0.0, expected = 0.0;
        size_t failStep = 0;

        for (size_t s = 0; s < tc.steps.size(); s++) {
            Step &st = tc.steps[s];
            if (st.isAdd) {
                mf.addNum(st.num);
            } else {
                got = mf.findMedian();
                expected = st.expected;
                if (fabs(got - expected) > EPS) {
                    ok = false;
                    failStep = s;
                    break;
                }
            }
        }

        if (ok) {
            cout << "Test " << t + 1 << " [" << tc.name << "]: PASS\n";
            passed++;
        } else {
            cout << "Test " << t + 1 << " [" << tc.name << "]: FAIL\n";
            cout << "     step " << failStep + 1 << " (findMedian) "
                 << "expected=" << expected << " got=" << got << "\n";
        }
    }

    cout << "\n" << passed << "/" << tests.size() << " tests passed\n";
    if (passed == (int)tests.size())
        cout << "All tests passed! Great job.\n";
    else
        cout << "Some tests failed. Keep trying!\n";
    return 0;
}
