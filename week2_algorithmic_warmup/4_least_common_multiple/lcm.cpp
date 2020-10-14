#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
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

long long fast_lcm(int a, int b)
{
  return (long long) a*b/fast_gcd(a,b);

}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << fast_lcm(a, b) << std::endl;
  return 0;
}
