package LinkedList

import "fmt"

type CircularLinkedList struct {
	head *Node
	n    int
	tail *Node
}

func (LL *CircularLinkedList) AddBack(data int) {
	newNode := NewNode(data)

	if LL.IsEmpty() {
		LL.head = newNode
		LL.tail = newNode
	} else {
		LL.tail.next = newNode
		LL.tail = newNode
	}

	LL.tail.next = LL.head
	LL.n++
}

func (LL *CircularLinkedList) IsEmpty() bool {
	return LL.head == nil && LL.tail == nil
}

func (LL *CircularLinkedList) Delete(cnt int) {
	curr := LL.head
	var prev *Node

	for cnt != 0 {
		prev = curr
		curr = curr.next
		cnt--
	}

	if curr == LL.head {
		LL.head = LL.head.next
		LL.tail.next = LL.head
	} else if curr == LL.tail {
		prev.next = curr.next
		LL.tail = prev
	} else {
		prev.next = curr.next
	}

	curr = nil
}

func (LL *CircularLinkedList) ShowList() {
	if LL.IsEmpty() {
		fmt.Println(-1)
	} else {
		for curr, i := LL.head, 0; i < 7; i++ {
			fmt.Print(curr.data, " ")
			curr = curr.next
		}
		fmt.Println()
	}
}
