// Solution to https://www.hackerrank.com/contests/101hack38/challenges/points-on-a-line

package main

import "fmt"

func main() {
	var points, x, y, startingx, startingy int
	fmt.Scanf("%d", &points)
	fmt.Scanf("%d %d", &x, &y)
	startingx, startingy = x, y
	for i := 1; i < points; i++ {
		fmt.Scanf("%d %d", &x, &y)
		if x != startingx && y != startingy {
			// do we really have to read all of the input if we know here that it's not a line?
			fmt.Println("NO")
			return
		}
	}

	fmt.Println("YES")
}
