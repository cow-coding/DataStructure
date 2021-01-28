package LinkedList

import "fmt"

type Node struct {
	data int
	next *Node
}

func NewNode(data int) *Node {
	return &Node{data: data, next: nil}
}

type LinkedList struct {
	head *Node
	n    int
	tail *Node
}

func (LL *LinkedList) AddFront(data int) {
	newNode := NewNode(data)

	if LL.IsEmpty() {
		LL.head = newNode
		LL.tail = newNode
	} else {
		newNode.next = LL.head
		LL.head = newNode
	}

	LL.n++
}

func (LL *LinkedList) RemoveFront() int {
	if LL.IsEmpty() {
		return -1
	} else {
		delNode := LL.head
		ret := delNode.data

		LL.head = LL.head.next

		delNode = nil
		return ret
	}
}

func (LL *LinkedList) AddBack(data int) {
	newNode := NewNode(data)

	if LL.IsEmpty() {
		LL.head = newNode
		LL.tail = newNode
	} else {
		LL.tail.next = newNode
		LL.tail = newNode
	}

	LL.n++
}

func (LL *LinkedList) IsEmpty() bool {
	return LL.head == nil && LL.tail == nil
}

func (LL *LinkedList) Front() int {
	if LL.IsEmpty() {
		return -1
	}

	return LL.head.data
}

func (LL *LinkedList) ShowList() {
	if LL.IsEmpty() {
		fmt.Println(-1)
	} else {
		for curr := LL.head; curr != nil; curr = curr.next {
			fmt.Print(curr.data, " ")
		}
		fmt.Println()
	}
}
