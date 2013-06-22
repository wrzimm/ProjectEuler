package main

import (
	"fmt"
)

func buildArray(n int) []int {
	
	result := make( []int, 0, 1000 )
	
	for i:=1; i<=n; i++ {

		piece := make([]int, 0, 100)

		number := i
		for number>0 {
			digit := number%10
			number /= 10
			piece = append(piece, digit)
		}

		for i:=len(piece)-1; i>=0; i-- {
			result = append(result, piece[i])
		}

		//fmt.Println( piece )
	}

	return result
}


func main() {
	
	const n int = 1000000

	d := buildArray( n )

	value := uint64(1)

	//fmt.Println( )
	//fmt.Println( d )

	dvals := []int{10, 100, 1000, 10000, 100000, 1000000}
	//dvals := []int{10, 100, 1000, 10000, 1000000, 10000000}

	fmt.Println()
	fmt.Println()
	for _,v := range dvals {
		value *= uint64( d[v-1] )
		fmt.Println(d[v-1], value)
	}
	
	fmt.Println()
	fmt.Println(value)

}
