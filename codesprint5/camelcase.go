// solution to https://www.hackerrank.com/contests/world-codesprint-5/challenges/camelcase

package main

import (
	"fmt"
	"unicode"
)

func main() {
	var s string
	fmt.Scanf("%s", &s)
	numCaps := 0
	// ranging through a string yields runes
	for _, r := range s {
		if unicode.IsUpper(r) {
			numCaps++
		}
	}
	fmt.Println(numCaps + 1)
}
