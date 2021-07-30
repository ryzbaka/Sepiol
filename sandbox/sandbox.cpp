#include <iostream>
using namespace std;

int main() {
  int x = getchar();
  cout << x << "\n";
  cout << isspace(x) << "\n";
  string something = "1.234";
  string somethingElse = "1.23.4.4";
  double somethingD = strtod(something.c_str(), 0);
  double somethingElseD = strtod(somethingElse.c_str(), 0);
  cout << somethingD << "\t" << somethingElseD << "\n";
  return 0;
}