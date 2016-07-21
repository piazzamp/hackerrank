// solution to https://www.hackerrank.com/challenges/lonely-integer
// there's no way I would've figure this particular solution out if
// it weren't in the bit-manipulation category :o

package main

import "fmt"

func main() {
	var nums, current, result int
	fmt.Scanf("%d", &nums)
	for i := 0; i < nums; i++ {
		fmt.Scanf("%d", &current)
		result ^= current
	}
	fmt.Println(result)
}
