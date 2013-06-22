#include <iostream> 
#include <bitset> 

#define MAX 2000000

using namespace std; 

int main() 
{ 
  bitset<MAX> Sieve; 
  unsigned long long sum = 0; 
  //__int64 sum = 0; 

  Sieve.flip();    // Set all bits to 1 
  Sieve[0].flip();  // Set 0 and 1 to not prime 
  Sieve[1].flip(); 

  // Check all nos from 2 to 1 million 
  for(long i = 2; i < MAX; ++i) 
  { 
    if( Sieve[i] == 0 )  // If marked not prime 
    //if( ! Sieve )  // If marked not prime 
      continue;    // return to head of loop 
    else 
      // Set all multiples as not prime 
      for(long j = 2*i; j < MAX; j += i) 
        Sieve[j] = 0; 
  } 

  for(long i = 2; i < MAX; ++i) 
    if( Sieve[i] )  // Add all nos with bit set 
      sum += i; 

  cout << "\nThe sum is : " << sum << endl; 

  return 0; 
} 
