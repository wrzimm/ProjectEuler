package main

import (
	"fmt"
	"flag"
	"runtime"
)

const (
	maxNumber      uint = uint(1e9)
	maxPrimeSearch uint = maxNumber + 1
)

type primeSieve []bool 

type wrongLengthError uint 
//{{{

func (e wrongLengthError) Error() string {
	return fmt.Sprintf("ERROR: primeSieve declared with length %d, needs to be %d",
			uint(e), maxPrimeSearch)
}//}}}

type maxPrimeTooSmallError uint
//{{{

func (e maxPrimeTooSmallError) Error() string {
	return fmt.Sprintf("ERROR: primeSieve[%d] was called, but maxPrimeSerch=%d",
			uint(e), maxPrimeSearch)
}//}}}

func (s primeSieve) populate() error {
//{{{
	if uint(len(s)) != maxPrimeSearch{
		return wrongLengthError( len(s) )
	}


	// first set all to true
	for i:=uint(0); i<uint(len(s)); i++ { s[i]=true }
	s[0] = false
	s[1] = false

	// Sieve of Eratosthenes
	p:=uint(2)
	for p*p<maxPrimeSearch {

		multiple := uint(2)
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
}//}}}

func (s primeSieve) isPrime(n uint) (bool,error) {
//{{{
	if n >= maxPrimeSearch {
		return false, maxPrimeTooSmallError(n)
	} 

	return s[n], nil
}
//}}}

func (s primeSieve) largestPrimeFactor(n uint) uint {
//{{{
	result := uint(0)

	primeTest, e := s.isPrime(n)
	if e != nil {
		fmt.Println(e)
		return result
	}

	if primeTest {
		return n
	}

	for i:=uint(2); i*i<n+1; i++ {
		
		if n%i == 0 { // i is a factor

			j := n/i
		

			
			iPrime, ei := s.isPrime(i)
			if ei != nil {
				fmt.Println(ei)
				return result
			}

			jPrime, ej := s.isPrime(j)
			if ej != nil {
				fmt.Println(ej)
				return result
			}


			if iPrime && i>result {
				result = i
			}

			if jPrime && j>result {
				result = j
			}
		}
	}

	return result
}//}}}

func (s primeSieve) testHammingNumber(n, max uint) bool {
//{{{
	if n <= max {
		return true
	}

	primeTest, e := s.isPrime(n)
	if e != nil {
		fmt.Println(e)
		return false
	}

	if primeTest {
		return false
	}

	for i:=uint(2); i*i<n+1; i++ {
		
		if n%i == 0 { // i is a factor

			j := n/i
		

			
			iPrime, ei := s.isPrime(i)
			if ei != nil {
				fmt.Println(ei)
				return false
			}

			jPrime, ej := s.isPrime(j)
			if ej != nil {
				fmt.Println(ej)
				return false
			}


			if iPrime && i>max {
				return false
			}

			if jPrime && j>max {
				return false
			}
		}
	}

	return true
}//}}}
	

type outputVector []uint

func (v outputVector) parallelTestHammingNumber(i, nMin, nMax, max uint, s primeSieve, c chan bool) {
//{{{
	var sum uint = 0
	for n:=nMin; n<=nMax; n++ {
		if s.testHammingNumber(n, max) { sum++ }
	}
	v[i] = sum
	c <- true
}//}}}

func main() {

	n := flag.Uint("n", 100, "type of Generalized Hamming number")
	flag.Parse()

	fmt.Printf("Calculating prime sieve...")
	primes := make( primeSieve, maxPrimeSearch) 
	e := primes.populate()
	if e != nil { fmt.Println( primes.populate() ) }
	fmt.Printf("...done\n")


	runtime.GOMAXPROCS(runtime.NumCPU())
	nGoRoutines := uint(runtime.NumCPU() * 1000) // multiply to get managable chunk sizes

	v := make(outputVector, nGoRoutines)
	c := make(chan bool, nGoRoutines)

	// start goroutines
	percent := nGoRoutines / 100
	for i:=uint(0); i<nGoRoutines; i++ {

		go v.parallelTestHammingNumber(i, i*(maxNumber/nGoRoutines)+1, 
						(i+1)*(maxNumber/nGoRoutines), *n, primes, c)
		if (i+1)%percent==0 {
			fmt.Printf("%d%% complete....\r",(i+1)*100/nGoRoutines)
		}
	}
	fmt.Println()

	// wait for goroutines to finish
	for i:=uint(0); i<nGoRoutines; i++ { 
		<-c 
	}
	fmt.Println()
	
	sum := uint(0)
	for i:=uint(0); i<nGoRoutines; i++ {
		sum += v[i]
	}

	fmt.Println( sum )
}
