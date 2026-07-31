// ================================================================
//  PROBLEM: Divide the Hospitals
//
//  You are given n cities. city[i] has population[i] people.
//  You have k hospitals to distribute among the cities.
//
//  Rules:
//    - Every city must get at least 1 hospital.     (so k >= n)
//    - Load of a city = ceil(population[i] / hospitals given to it)
//
//  Goal: distribute the k hospitals so that the MAXIMUM load
//        across all cities is as small as possible.
//  Return: that minimized maximum load.
//
//  Example 1:
//    n = 2, k = 6, population = {50000, 20000}
//    Give 4 hospitals to city 0 -> ceil(50000/4) = 12500
//    Give 2 hospitals to city 1 -> ceil(20000/2) = 10000
//    max load = 12500
//
//  Example 2:
//    n = 4, k = 6, population = {2000, 1000, 500, 200}
//    Give hospitals {2, 2, 1, 1} -> loads {1000, 500, 500, 200}
//    max load = 1000
//
//  HINT: use a max-heap. Start with 1 hospital per city, then
//  repeatedly give the next hospital to the city that currently
//  has the HIGHEST load (it benefits the most from another one).
// ================================================================

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// ================================================================
//  IMPLEMENT THIS FUNCTION (k >= n always)
//
//  population[] : array of size n, population of each city
//  k            : total hospitals to distribute
//  return       : the minimized maximum load
// ================================================================
int divideHospitals(int n, int k, int population[]) {
    // TODO: your code here

    return 0;   // placeholder
}

// ================================================================
//  TEST HARNESS - do not change below this line
// ================================================================

struct TestCase {
    int n;
    int k;
    vector<int> population;
    int expected;
};

void printInput(const TestCase &t) {
    cout << "n=" << t.n << " k=" << t.k << " pop={";
    for (size_t i = 0; i < t.population.size(); i++) {
        if (i) cout << ", ";
        cout << t.population[i];
    }
    cout << "}";
}

int main() {
    vector<TestCase> tests = {
        // n,  k,        population,            expected
        { 2,  6,  {50000, 20000},                12500 },  // GFG example 1
        { 4,  6,  {2000, 1000, 500, 200},        1000  },  // GFG example 2
        { 1,  3,  {10},                          4    },  // single city: ceil(10/3)
        { 3,  3,  {5, 7, 3},                     7    },  // k == n, 1 hospital each
        { 3,  9,  {9, 9, 9},                     3    },  // equal split, 3 each
    };

    int passed = 0;
    for (size_t i = 0; i < tests.size(); i++) {
        TestCase &t = tests[i];
        int got = divideHospitals(t.n, t.k, t.population.data());

        if (got == t.expected) {
            cout << "Test " << i + 1 << ": PASS\n";
            passed++;
        } else {
            cout << "Test " << i + 1 << ": FAIL\n";
            cout << "     input   : "; printInput(t); cout << "\n";
            cout << "     expected: " << t.expected << "\n";
            cout << "     got     : " << got << "\n";
        }
    }

    cout << "\n" << passed << "/" << tests.size() << " tests passed\n";
    if (passed == (int)tests.size())
        cout << "All tests passed! Great job.\n";
    else
        cout << "Some tests failed. Keep trying!\n";
    return 0;
}
