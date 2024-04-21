package main

import "fmt"

func main() {
	arry := [10]int{4, 3, 2, 5, 9, 10, 88, 0, 67, 33}
	fmt.Println(arry)
	for i := 1; i < len(arry); i++ {
		for j := 0; j < len(arry)-1; j++ {
			if arry[j] > arry[j+1] {
				temp := arry[j+1]
				arry[j+1] = arry[j]
				arry[j] = temp
				// fmt.Println("Swaped:", arry[j+1], arry[j])
			}
		}
	}
	fmt.Println("Sorted: ", arry)
}
