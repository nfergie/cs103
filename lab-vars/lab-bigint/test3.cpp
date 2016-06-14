#include "bigint.h"
#include <iostream>
using namespace std;

int main() {
   BigInt a("450");
   BigInt b("78");
   b.add(a);    // increase b by a
   cout << b.to_string() << endl; // prints 55
   b.add(a);    // increase b by a
   cout << b.to_string() << endl; // prints 68
}
