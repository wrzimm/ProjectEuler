package main

import(
	"fmt"
)

const (
	maxPrimeSearch uint = uint(1e4)
)

type primeSieve []bool 

type primeSieveError uint

func (e primeSieveError) Error() string {
	return fmt.Sprintf("ERROR: primeSieve[%d] was called, but maxPrimeSearch=%d",
		uint(e), maxPrimeSearch)
}

func (s primeSieve) populate() error {

	// first set all to true
	for i:=uint(0); i<uint(len(s)); i++ { s[i]=true }

	// first few are conventional
	s[0] = false
	s[1] = false

	// Sieve of Eratosthenes
	p := uint(2)
	for p*p < maxPrimeSearch {

		multiple := uint(2) 
		for i:=p*multiple; i<maxPrimeSearch-p; multiple++ {
			i = p*multiple
			s[i] = false
		}

		test := p + 1
		for test < maxPrimeSearch {
			
			if s[test] {
				p = test
				break
			}
			test++
		}
	}

	return nil
}

func (s primeSieve) isPrime(n uint) (bool, error) {
	if n >= maxPrimeSearch {
		return false, primeSieveError(n)
	}

	return s[n], nil
}
	
