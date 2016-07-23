// solution to https://www.hackerrank.com/challenges/cut-the-sticks

package main

import (
	"fmt"
	"sort"
)

func main() {
	var numSticks int
	fmt.Scanf("%d\n", &numSticks)
	sticks := make([]int, numSticks)
	for i := 0; i < numSticks; i++ {
		fmt.Scanf("%d", &sticks[i])
	}
	sort.Ints(sticks)
	for len(sticks) > 0 {
		min := sticks[0]
		cutIndex := 0
		for i, stick := range sticks {
			if stick-min <= 0 {
				cutIndex = i
			} else {
				sticks[i] = stick - min
			}
		}
		fmt.Println(len(sticks))
		sticks = sticks[cutIndex+1:]
	}
}
