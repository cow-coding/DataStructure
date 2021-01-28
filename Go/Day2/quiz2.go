package main

import (
	"DataStructure/Go/Day2/LinkedList"
	"fmt"
)

func main() {
	var N int

	fmt.Scan(&N)

	for j := 0; j < N; j++ {
		LL := new(LinkedList.CircularLinkedList)

		for i := 0; i < 10; i++ {
			var num int
			fmt.Scan(&num)
			LL.AddBack(num)
		}

		var com string
		var count int

		for i := 0; i < 3; i++ {
			fmt.Scan(&com, &count)

			LL.Delete(count)
		}

		LL.ShowList()
	}
}
