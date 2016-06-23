// solution to https://www.hackerrank.com/challenges/strange-grid

package main

import "fmt"

func main() {
	var col, row int64
	fmt.Scanf("%d %d", &row, &col)
	fmt.Println(compute(row, col))
	//Enter your code here. Read input from STDIN. Print output to STDOUT
}

func compute(row, col int64) int64 {
	base := int64(((row - 1) / 2) * 10)
	var offset int64
	if row%2 == 0 {
		// even rows have odd numbers
		offset = col*2 - 1

	} else {
		// odd rows have even numbers
		offset = col*2 - 2 // minus 2 since column numbers are base 1 :(
	}
	return base + offset
}
