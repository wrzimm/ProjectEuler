package main

import (
	"fmt"
	"math"
	"flag"
)


func isPrime(n uint64) bool {
	result := true

	for i := uint64(2); i<=uint64( math.Sqrt( float64(n) ) + 1); i++ {
		if n%i==0 {
			result = false
			break
		}
	}

	return result
}




func main() {
	
	n := flag.Uint64("v", 1, "Number to factor")
	flag.Parse()


	for i := uint64(2); i<= *n / 2; i++ {
		if *n % i == 0 {
			test := *n / i
			if isPrime( test ) {
				fmt.Println( test )
				break
			}
		}
	}
}
	
	
		

