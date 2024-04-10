package main

import "fmt"

// Create Node struct

type Node struct {
	data int
	next *Node
}

type LinkedList struct {
	head *Node
}

func (list *LinkedList) Insert(value int) {
	newNode := &Node{data: value}
	if list.head == nil {
		list.head = newNode
	} else {
		current := list.head
		for current.next != nil {
			current = current.next
		}
		current.next = newNode
	}
}

func (list *LinkedList) Search(value int) {
	current := list.head
	for current != nil {
		if current.data == value {
			fmt.Println("Value found: ", current.data, *current)
			return
		} else {
			current = current.next
		}
	}
	fmt.Println("Value Not found")
}

func (list *LinkedList) Display() {
	current := list.head

	for current != nil {
		fmt.Printf("%v --> ", current.data)
		current = current.next
	}
	fmt.Println("")
}

func (list *LinkedList) Delete(value int) {
	current := list.head
	for current != nil {
		next := current.next.next
		if current.next.data == value {
			current.next = next
			return
		}
		current = current.next
	}
}

func main() {
	x := LinkedList{}

	for i := 0; i < 100; i++ {
		x.Insert(i)
	}
	x.Display()
}
