package main

import(
	"fmt"
	"math"
)

const(
	maxNumber uint = 1e7
)

func iterateChain( num uint) uint {
	var result uint = 0

	for num != 0 {
		result += uint(math.Pow(float64(num % 10), 2))
		num /= 10
	}
	
	return result
}

func arrives89( num uint ) bool {

	for {
		if num==1 {
			return false
		} else if num==89 {
			return true
		}

		num = iterateChain( num );
	}

	return false
}


func main() {

	var sum uint = 0
	for i := uint(1); i<maxNumber; i++ {
		if arrives89( i ) {
			sum++
		}
	}

	fmt.Println( sum )
		
}
