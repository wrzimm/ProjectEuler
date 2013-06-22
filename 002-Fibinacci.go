package main

import(
	"fmt"
)


func main() {

	currentValue  := 2
	previousValue := 1
	sum := 2

	for true {
		newValue := currentValue + previousValue
		previousValue = currentValue
		currentValue = newValue

		if currentValue > 4000000 {
			break
		} else if currentValue%2 == 0 {
			sum += currentValue
		}

  	}


	fmt.Printf("%d\n", sum)
}
		
	
