#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int fast_gcd(int a, int b)
{
  int large;
  int small;
  if(a == b)
  {
    return a;
  }
  else if(a > b)
  {
    large = a;
    small = b;
  }
  else if(a < b)
  {
    large = b;
    small = a;
  }

  int reminder;
  reminder = large % small;

  if(reminder == 0){
    return small;
  }
  else
  {
    return fast_gcd(small, reminder);
  }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << gcd_naive(a, b) << std::endl;
  std::cout << fast_gcd(a, b) << std::endl;
  return 0;
}
