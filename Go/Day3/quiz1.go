package main

import (
	"DataStructure/Go/Day3/Stack"
	"fmt"
)

func main() {
	stack := Stack.NewStack(10001)
	var N int
	var command string

	fmt.Scan(&N)

	for i := 0; i < N; i++ {
		fmt.Scan(&command)

		if command == "empty" {
			if stack.IsEmpty() {
				fmt.Println(1)
			} else {
				fmt.Println(0)
			}
		} else if command == "top" {
			if stack.IsEmpty() {
				fmt.Println(-1)
			} else {
				fmt.Println(stack.Top())
			}
		} else if command == "push" {
			var num int
			fmt.Scan(&num)

			stack.Push(num)
		} else if command == "pop" {
			fmt.Println(stack.Pop())
		} else if command == "size" {
			fmt.Println(stack.GetSize())
		}
	}
}
