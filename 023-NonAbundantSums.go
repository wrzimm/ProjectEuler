package main

import (
	"fmt"
	"runtime"
	"math"
)

type Vector []uint



func abundantNumber(n uint) bool {
	
	if n<12 {return false}
	
	sum := uint(1)


	for i:=uint(2); i*i<=n+1; i++ {
		if n%i==0 {
			sum += n/i + i
		}
	}

	squareCheck := uint( math.Sqrt( float64(n) ) )
	if squareCheck * squareCheck == n {
		sum -= squareCheck
	}

	return sum>n
}

func sumNumber(n uint) bool {

	if n<24 {return false}

	
	for i:=uint(12); i<=n-12; i++ {
		if abundantNumber(i) && abundantNumber(n-i) {
			return true
		}
	}
	
	return false
}

func (v Vector) parallelSumNumber(cpu, min, max uint, c chan int)  {

	if max < min {
		v[cpu] = 0
		c <- 1
		return
	}

	
	sum := uint(0)
	for n:=min; n<=max; n++ {
		if !sumNumber(n) {
			sum += n
		}
	}
	//fmt.Printf("Calculating %d to %d --> %d\n", min, max, sum)
	
	v[cpu] = sum

	c <- 1
}


func main() {
	

	const max uint = 28123
	
	runtime.GOMAXPROCS(runtime.NumCPU())
	NCPU := uint(runtime.NumCPU() * 40) // multiply to get managable chunk sizes

	c := make(chan int, NCPU)
	v := make( Vector, NCPU)

	for i:=uint(0); i<NCPU; i++ {
		go v.parallelSumNumber(i, i*max/NCPU+1, (i+1)*max/NCPU, c)

	}

	for i:=uint(0); i<NCPU; i++ {
		//fmt.Printf("Waiting for %d to finish...", i)
		<-c
		//fmt.Printf("...done\n")
	}
	
	sum := uint(0)
	//fmt.Println("Summing...")
	for i:=uint(0); i<NCPU; i++ {
		//fmt.Println( v[i] )
		sum += v[i]
	}


	fmt.Println( sum )

}
