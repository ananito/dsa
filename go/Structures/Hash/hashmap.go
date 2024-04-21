package main

import "fmt"

const CAPACITY int = 11

type Item struct {
	key   string
	value int
	next  *Item
}
type LinkedList struct {
	head *Item
}

type HashMap struct {
	data [CAPACITY]LinkedList
}

func hash(key string) int {
	return len(key) % CAPACITY
}

func (hmap *HashMap) Insert(key string, value int) {
	i := hash(key)
	newNode := &Item{key: key, value: value}

	if hmap.data[i].head == nil {
		hmap.data[i].head = newNode
	} else {
		current := hmap.data[i].head

		for current.next != nil {
			if current.key == key {
				current.value = value
				return
			} else if current.next.key == key {
				current.next.value = value
				return
			}
			current = current.next

		}
		current.next = newNode
	}
}

func (hmap *HashMap) Search(key string) {
	i := hash(key)
	current := hmap.data[i].head
	for current != nil {
		if current.key == key {
			fmt.Printf("%s: %d\n", current.key, current.value)
			return
		}
		current = current.next

	}
	fmt.Println("Not Found")
}

// im sure i can find a better way to do this
func (hmap *HashMap) Delete(key string) {
	i := hash(key)
	if hmap.data[i].head == nil {
		fmt.Printf("Error: \"%s\" does not exist\n", key)
		return
	} else {
		if hmap.data[i].head.key == key {
			if hmap.data[i].head.next == nil {
				fmt.Printf("key: \"%s\" with value: %d was deleted \n", hmap.data[i].head.key, hmap.data[i].head.value)
				hmap.data[i].head = nil
				return
			}

			fmt.Printf("key: \"%s\" with value: %d was deleted \n", hmap.data[i].head.key, hmap.data[i].head.value)
			hmap.data[i].head = hmap.data[i].head.next
			return
		}
		current := hmap.data[i].head
		for current.next != nil {
			if current.next.key == key {
				if current.next.next != nil {

					fmt.Printf("key: \"%s\" with value: %d was deleted \n", current.next.key, current.next.value)
					current.next = current.next.next
					return
				}
			}

			current = current.next
		}
	}
}

func main() {
	x := HashMap{}
	x.Insert("dog", 1)
	x.Insert("Boy", 3)
	x.Insert("boy", 332)
	x.Search("Boy")
	x.Insert("Potato", 1)
	x.Delete("Potato")
	x.Search("Potato")
	x.Search("Boy")
	x.Search("dog")
	x.Delete("Boy")
	x.Delete("Boy")
	x.Delete("Boy")
	fmt.Println(x.data[3].head)
}
