package main

import(
	"fmt"
	"math"
)

func createNumber(innerNumber uint64) uint64 {
	var result uint64 = 0
	resultDigits := []uint8{0,0,9,0,8,0,7,0,6,0,5,0,4,0,3,0,2,0,1}

	var j uint8 = 1
	for innerNumber != 0 {
		resultDigits[j] = uint8(innerNumber % 10)
		innerNumber /= 10
		
		j += 2
	}

	for i:=0; i<19; i++ {
		multiplier := math.Pow10(i)
		result += uint64(multiplier) * uint64(resultDigits[i])
	}
		
	return result
}

func isSquare( num uint64 ) bool {
	var result bool

	switch intRoot := uint64(math.Sqrt(float64(num))); intRoot*intRoot {
	case num:
		result = true
	default:
		result = false
	}
		
	return result
}
	

func main() {
	var i,num uint64
	for i = 0; i<=999999999; i++ {
		num = createNumber(i)
		if isSquare(num) {
			fmt.Println( "Found it!\n" )
			break
		}

	}

	fmt.Println( i )
	fmt.Println( num )
	fmt.Println( uint64(math.Sqrt(float64(num))) )
}
