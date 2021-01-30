package main

import (
	"DataStructure/Go/Day3/Stack"
	"fmt"
)

func main() {
	var N int
	var postfix string

	fmt.Scan(&N)

	for i := 0; i < N; i++ {
		stack := Stack.NewStack(10001)
		fmt.Scan(&postfix)

		for j := 0; j < len(postfix); j++ {
			if postfix[j]-'0' >= 0 && postfix[j]-'0' <= 9 {
				// postfix is num
				var num int
				num = int(postfix[j] - '0')
				stack.Push(num)
			} else {
				switch postfix[j] {
				case '+':
					num1 := stack.Pop()
					num2 := stack.Pop()
					num := num1 + num2
					stack.Push(num)
				case '-':
					num1 := stack.Pop()
					num2 := stack.Pop()
					num := num2 - num1

					stack.Push(num)
				case '*':
					num1 := stack.Pop()
					num2 := stack.Pop()
					num := num1 * num2
					stack.Push(num)
				}
			}
		}

		fmt.Println(stack.Pop())
	}
}
