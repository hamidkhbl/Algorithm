#include <iostream>

int get_change(int m) {
  //write your code here
  int n = 0;
  int n_10s = m / 10;
  int n_5s = (m%10) / 5;
  int n_1s = (m%10)%5;
  n = n_10s + n_5s + n_1s ;
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
