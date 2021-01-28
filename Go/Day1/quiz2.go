package main

import (
	"DataStructure/Go/Day1/Array"
	"fmt"
)

func main() {
	var M, N int
	fmt.Scan(&M)

	for i := 0; i < M; i++ {
		arr := Array.NewArr(3)
		kor := 0
		jap := 0
		chi := 0

		fmt.Scan(&N)

		for j := 0; j < N; j++ {
			var num int
			fmt.Scan(&num)

			if j%3 == 0 {
				if arr.At(0) == 0 {
					arr.Add(0, num)
				} else {
					arr.Set(0, arr.At(0)+num)
				}

				if num != 0 {
					kor++
				}
			} else if j%3 == 1 {
				if arr.At(1) == 0 {
					arr.Add(1, num)
				} else {
					arr.Set(1, arr.At(1)+num)
				}

				if num != 0 {
					jap++
				}
			} else {
				if arr.At(2) == 0 {
					arr.Add(2, num)
				} else {
					arr.Set(2, arr.At(2)+num)
				}

				if num != 0 {
					chi++
				}
			}
		}

		var avgk, avgj, avgc = 0, 0, 0

		if kor == 0 {
			avgk = 0
		} else {
			avgk = arr.At(0) / kor
		}

		if jap == 0 {
			avgj = 0
		} else {
			avgj = arr.At(1) / jap
		}

		if chi == 0 {
			avgc = 0
		} else {
			avgc = arr.At(2) / chi
		}

		fmt.Printf("%d %d %d\n", arr.At(0), arr.At(1), arr.At(2))
		fmt.Printf("%d %d %d\n", avgk, avgj, avgc)
	}
}
