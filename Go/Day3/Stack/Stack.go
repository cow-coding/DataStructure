package Stack

import "fmt"

type Node struct {
	data int
	next *Node
	prev *Node
}

// Constructor
func NewNode(data int) *Node {
	return &Node{data: data, next: nil, prev: nil}
}

// Stack By LinkedList
type Stack struct {
	head     *Node
	tail     *Node
	capacity int
	size     int
}

func NewStack(capacity int) *Stack {
	return &Stack{head: nil, tail: nil, capacity: capacity, size: 0}
}

func (stack *Stack) Push(data int) {
	if !stack.IsFull() {
		newNode := NewNode(data)

		if stack.IsEmpty() {
			stack.head = newNode
			stack.tail = newNode
		} else {
			stack.tail.next = newNode
			newNode.prev = stack.tail
			stack.tail = stack.tail.next
		}
		stack.size++
	} else {
		fmt.Print("Stack is Full!")
	}
}

func (stack *Stack) Pop() int {
	if stack.IsEmpty() {
		return -1
	} else {
		delNode := stack.tail
		result := delNode.data

		stack.tail = stack.tail.prev
		delNode = nil

		stack.size--

		return result
	}
}

func (stack *Stack) Top() int { return stack.head.data }

func (stack *Stack) GetSize() int { return stack.size }

func (stack *Stack) IsEmpty() bool { return stack.size == 0 }

func (stack *Stack) IsFull() bool { return stack.size == stack.capacity }
