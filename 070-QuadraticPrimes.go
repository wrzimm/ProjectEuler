package main

import (
	"fmt"
)

const (
	maxPrimeSearch int = 100000
)

type primeSieve []bool

type wrongLengthError int

func (e wrongLengthError) Error() string {
	return fmt.Sprintf("ERROR: primeSieve declared with length %d, needs to be %d",
			int(e), maxPrimeSearch)
}

type maxPrimeTooSmallError int

func (e maxPrimeTooSmallError) Error() string {
	return fmt.Sprintf("ERROR: primeSieve[%d] was called, but maxPrimeSerch=%d",
			int(e), maxPrimeSearch)
}


func (s primeSieve) populate() error {
	if int(len(s)) != maxPrimeSearch{
		return wrongLengthError( len(s) )
	}


	// first set all to true
	for i:=0; i<len(s); i++ { s[i]=true }
	s[0] = false
	s[1] = false

	// Sieve of Eratosthenes
	p:=2
	for p*p<maxPrimeSearch {

		multiple := 2
		for i := p*multiple; i<maxPrimeSearch-p; multiple++ {
			i = p*multiple
			s[i]=false
		}
		
		test := p+1
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

func (s primeSieve) isPrime(n int) (bool,error) {
	if n >= maxPrimeSearch {
		return false, maxPrimeTooSmallError(n)
	} 

	return s[n], nil
}


func (s primeSieve) checkCoefficients( a, b int ) int {

	var n int
	
	for n=0; n<maxPrimeSearch; n++ {
		check := n*n + a*n + b
		if check <= 0 { break }
		prime, e := s.isPrime( check )
		if e != nil { 
			fmt.Println(e)
			break
		} else if !prime {
			break
		}
	}

	return n-1
}

	



func main() {

	primes := make( primeSieve, maxPrimeSearch) 
	
	e := primes.populate()
	if e != nil { fmt.Println( primes.populate() ) }

	nMax := 0
	aMax := 0
	bMax := 0
	
	for a:=-999; a<1000; a++ {
		for b:=-999; b<1000; b++ {
			nCheck := primes.checkCoefficients( a, b ) 
			if( nCheck > nMax ) { 
				nMax = nCheck 
				aMax = a
				bMax = b
			}
		}
	}

	fmt.Printf("n=%d\ta=%d\tb=%d\ta*b=%d\n", nMax, aMax, bMax, aMax*bMax )


}
