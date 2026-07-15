#include <bits/stdc++.h>

int fib(int n, std::vector<int> &dp) {
  if (n <= 1)
    return n;

  if (dp[n] != -1)
    return dp[n];

  int one = fib(n - 1, dp);
  int two = fib(n - 2, dp);
  int result = one + two;

  dp[n] = one + two;
  return dp[n];
}

int fib(int n) {
  if (n <= 1)
    return n;
  return fib(n - 1) + fib(n - 2);
}
int bruteForce(int n) {
  int sum = 0;
  for (int i = 0;; i++) {
    int f = fib(i);
    if (f > n)
      break;
    if (f % 2 == 0)
      sum += f;
  }
  return sum;
}
// optimal
int optimal(int n) {
  int sum = 0;
  std::vector<int> dp(1000, -1);

  for (int i = 0;; i++) {
    int f = fib(i, dp);
    if (f > n)
      break;
    if (f % 2 == 0)
      sum += f;
  }
  return sum;
}

int main() {
  int n;
  std::cout << "Enter the value of n: ";
  std::cin >> n;

  std::cout << "The answer from brute force is : " << bruteForce(n)
            << std::endl;
  std::cout << "the answer from the optimal is : " << optimal(n) << std::endl;
}
