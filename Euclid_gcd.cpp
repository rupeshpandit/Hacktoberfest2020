// C++ program that calculates GCD of two numbers
// GCD of two numbers is the largest number that divides both of them.

#include <iostream>
using namespace std;

int gcd(int a, int b) 
{
   if (b == 0)
   return a;
   return gcd(b, a % b);
}

int main() 
{
   int a , b;
   cout<<"Enter the values of a and b: "<<endl;
   cin>>a>>b;
   cout<<"GCD of "<< a <<" and "<< b <<" is "<< gcd(a, b);
   return 0;
}

// Output be like -

// Enter the values of a and b: 48 80
// GCD of 48 and 80 is 16
