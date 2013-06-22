package main

import(
	"fmt"
	"math"
)

const(
	maxLychrelIterations int = 50
	maxNumberToCheck int = 10000
)


func reverseNumber( num uint64 ) uint64 {
	var reversed uint64 = 0
	reversedDigits := make( []uint8, 0 )

	for num != 0 {
		reversedDigits = append( reversedDigits, uint8(num%10) )
		num /= 10
	}

	for i,n := range reversedDigits {
		multiplier := math.Pow10( len(reversedDigits) - 1 - i )
		reversed += uint64(n) * uint64(multiplier)
	}
		
	return reversed

}

func palindromeCheck( num uint64 ) bool {
	switch reverse := reverseNumber( num ); reverse {
		case num:
			return true
		default:
			return false
	}
	return false
}

func lychrelIterate( num uint64 ) uint64 {
	return num + reverseNumber( num )
}

func lychrelCheck( num int ) bool {
	
	val := uint64( num )

	for iteration := 1; iteration < maxLychrelIterations; iteration++ {
		val = lychrelIterate( val )
		
		if palindromeCheck( val ) {
			return false
		}
	}
		
	return true
}



func main() {
	
	sum := 0 

	for i := 1; i<maxNumberToCheck; i++ {
		if lychrelCheck( i ) {
			sum++
		}
	}

	fmt.Println( sum )
}
