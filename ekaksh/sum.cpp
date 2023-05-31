#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int n;
  float sum = 0;

  cout << "Enter a positive integer: ";
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    sum += 1.0/pow(double(i),4);
  }
  double pitest=pow(90*sum,0.25);
  cout << "Sum = " << sum;

  cout << " pitest=" << pitest << endl;
  return 0;
}
