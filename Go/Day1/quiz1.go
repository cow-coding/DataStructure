package main

import (
	"DataStructure/Go/Day1/Array"
	"fmt"
)

func main() {
	var M int
	var command string
	arr := Array.NewArr(1000)
	fmt.Scan(&M)

	for i := 0; i < M; i++ {
		fmt.Scan(&command)
		var num int
		var idx int

		if command == "set" {
			fmt.Scan(&idx, &num)

			arr.Set(idx, num)
		} else if command == "at" {
			fmt.Scan(&idx)

			fmt.Println(arr.At(idx))
		} else if command == "add" {
			fmt.Scan(&idx, &num)

			arr.Add(idx, num)
		} else if command == "printArray" {
			arr.PrintArray()
		} else if command == "remove" {
			fmt.Scan(&idx)

			arr.Remove(idx)
		}
	}
}
