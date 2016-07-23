// solution to https://www.hackerrank.com/contests/world-codesprint-5/challenges/string-construction

package main

import "fmt"

func main() {
	var numStrings int
	fmt.Scanf("%d", &numStrings)
	var s string
	for i := 0; i < numStrings; i++ {
		fmt.Scanf("%s\n", &s)
		fmt.Println(solve(s))
	}
}

// solve assigns a numeric value to the uniqueness of string s
func solve(s string) int {
	seen := make(map[rune]bool)
	for _, r := range s {
		seen[r] = true
	}
	return len(seen)
}
