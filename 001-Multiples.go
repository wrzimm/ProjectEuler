package main

import (
	"fmt"
	"flag"
	"strconv"
)

func goodMultiple(val int) bool {
	if val%3 == 0 {
		return true
	} else if val%5 == 0{
		return true
	}

	return false
}

func calculateSum(val int) int {

	var sum int = 0
	
	for i:=1; i<val; i++ {
		if goodMultiple(i) {
			sum += i
		}
	}

	return sum
}

func main() {
	flag.Parse()

	value, e := strconv.Atoi( flag.Arg(0) )
	if e != nil {
		fmt.Println(e)
	}

	fmt.Printf("Calculating sum all multiples of 3 and 5 below %d\n", value)

	sum := calculateSum( value )

	fmt.Println( sum )

}
