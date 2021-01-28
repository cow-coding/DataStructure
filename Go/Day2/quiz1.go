package main

import (
	"DataStructure/Go/Day2/LinkedList"
	"fmt"
)

func main() {
	ll := new(LinkedList.LinkedList)
	var N int
	var command string
	fmt.Scan(&N)

	for i := 0; i < N; i++ {
		fmt.Scan(&command)

		if command == "addFront" {
			var n int
			fmt.Scan(&n)

			ll.AddFront(n)
		} else if command == "removeFront" {
			fmt.Println(ll.RemoveFront())
		} else if command == "front" {
			fmt.Println(ll.Front())
		} else if command == "empty" {
			fmt.Println(ll.IsEmpty())
		} else if command == "showList" {
			ll.ShowList()
		} else if command == "addBack" {
			var n int
			fmt.Scan(&n)

			ll.AddBack(n)
		}
	}
}
