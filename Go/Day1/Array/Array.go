package Array

import "fmt"

type Array struct {
	n         int
	arraySize int
	arr       []int
}

// constructor
func NewArr(arraySize int) *Array {
	a := Array{}
	a.n = 0
	a.arraySize = arraySize
	a.arr = make([]int, arraySize)

	for i := 0; i < arraySize; i++ {
		a.arr[i] = 0
	}

	return &a
}

// return data
func (a *Array) At(index int) int {
	return a.arr[index]
}

// data change function
func (a *Array) Set(index int, data int) {
	if a.arr[index] != 0 {
		a.arr[index] = data
	} else {
		fmt.Println(0)
	}
}

// add data function
func (a *Array) Add(index int, data int) {
	if a.arr[index] == 0 {
		a.arr[index] = data
		a.n++
	} else {
		for i := a.n; i > index; i-- {
			a.arr[i] = a.arr[i-1]
		}
		a.n++
		a.arr[index] = data
	}
}

// remove data function
func (a *Array) Remove(index int) {
	if a.arr[index] == 0 {
		fmt.Println(0)
	} else {
		ret := a.arr[index]

		for i := index; i < a.n; i++ {
			a.arr[i] = a.arr[i+1]
		}

		a.arr[a.n] = 0
		a.n--

		fmt.Println(ret)
	}
}

func (a *Array) PrintArray() {
	if a.n == 0 {
		fmt.Println(0)
	} else {
		for i := 0; i < a.n; i++ {
			fmt.Print(a.arr[i], " ")
		}
		fmt.Println("")
	}
}
