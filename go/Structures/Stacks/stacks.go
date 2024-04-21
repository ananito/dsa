package main

import "fmt"

type Stack struct {
	data []int
}

// Very Stupid, could append to the end of slice and change pop to remove the end
func (stack *Stack) Push(value int) {
	stack.data = append([]int{value}, stack.data...)
}

func (stack *Stack) Pop() {
	if len(stack.data) == 0 {
		fmt.Println("There is nothing in the stack")
		return
	}
	fmt.Printf("%v was poped\n", stack.data[0])
	stack.data = stack.data[1:]
}

func main() {
	x := Stack{}

	x.Push(33)
	x.Push(32)
	x.Push(31)
	fmt.Println(x)
	x.Pop()
	x.Pop()
	x.Pop()
	x.Pop()

	fmt.Println(x)
}
