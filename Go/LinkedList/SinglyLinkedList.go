package main

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

func NewLinkedList() *LinkedList {
	return &LinkedList{head: nil, tail: nil, n: 0}
}

func (LL *LinkedList) addFront(data int) {
	newNode := NewNode(data)

	if LL.isEmpty() {
		LL.head = newNode
		LL.tail = newNode
	} else {
		newNode.next = LL.head
		LL.head = newNode
	}

	LL.n++
}

func (LL *LinkedList) removeFront() int {
	if LL.isEmpty() {
		return -1
	} else {
		delNode := LL.head
		ret := delNode.data

		LL.head = LL.head.next

		delNode = nil
		return ret
	}
}

func (LL *LinkedList) addBack(data int) {
	newNode := NewNode(data)

	if LL.isEmpty() {
		LL.head = newNode
		LL.tail = newNode
	} else {
		LL.tail.next = newNode
		LL.tail = newNode
	}

	LL.n++
}

func (LL *LinkedList) isEmpty() bool {
	return LL.n == 0
}

func (LL *LinkedList) front() int {
	if LL.isEmpty() {
		return -1
	}

	return LL.head.data
}

func (LL *LinkedList) showList() {
	if LL.isEmpty() {
		fmt.Println(-1)
	} else {
		for curr := LL.head; curr != nil; curr = curr.next {
			fmt.Print(curr.data, " ")
		}
		fmt.Println()
	}
}

func main() {
	ll := NewLinkedList()
	var N int
	var command string
	fmt.Scanf("%d", &N)

	for i := 0; i < N; i++ {
		fmt.Scanf("%s", &command)

		if command == "addFront" {
			var n int
			fmt.Scanf("%d", &n)

			ll.addFront(n)
		} else if command == "removeFront" {
			fmt.Println(ll.removeFront())
		} else if command == "front" {
			fmt.Println(ll.front())
		} else if command == "empty" {
			fmt.Println(ll.isEmpty())
		} else if command == "showList" {
			ll.showList()
		} else if command == "addBack" {
			var n int
			fmt.Scanf("%d", &n)

			ll.addBack(n)
		}
	}
}
