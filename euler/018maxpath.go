package main

import (
	"fmt"
	"os"
)

type node struct {
	value        int // the original element in the triangle
	bestSolution int // the best solution up to this point
}

func main() {
	var cases, rows int
	fmt.Scanf("%d", &cases)
	for i := 0; i < cases; i++ {
		fmt.Scanf("%d", &rows)
		triangle := make([][]*node, 0, rows)
		for rowNum := 1; rowNum <= rows; rowNum++ {
			// each row has row number of elements
			row := make([]*node, 0, rowNum)
			var element int
			for j := 0; j < rowNum; j++ {
				fmt.Scanf("%d", &element)
				row = append(row, &node{value: element})
			}
			// after reading in each row we also know that row's largest value
			// fmt.Fprintf(os.Stderr, "got row %v\n", row)
			triangle = append(triangle, row)
		}
		fmt.Println(compute(triangle))
	}
}

func compute(triangle [][]*node) int {
	if len(triangle) == 0 {
		return 0
	}
	// by here we know there's at least one row
	// and row 0's max is always its value
	triangle[0][0].bestSolution = triangle[0][0].value
	lastRow := triangle[0]
	for _, row := range triangle[1:] {
		nextRow(lastRow, row)
		lastRow = row
		// fmt.Fprintf(os.Stderr, "row %d's max is at index %d: %v\n", i + 1, lastIndex, row)
	}
	max := 0
	for _, element := range triangle[len(triangle)-1] {
		if element.bestSolution > max {
			max = element.bestSolution
		}
	}
	for _, row := range triangle {
		fmt.Fprintf(os.Stderr, "%v\n", row)
	}
	return max
}

// nextRow takes in two rows and uses lastRow to compute the best possible
// solutions for the row and fills in the bestValue fields in each node of row
// it does this by grabbing the most lucrative option from the previous row
// based on the bestSolutions available to it
func nextRow(lastRow, row []*node) {
	// 1 2
	// 3 4 5
	// 5 6 7 8
	// each element can use idx, idx -1, & idx + 1 from the row above
	fmt.Fprintf(os.Stderr, "row\t%v\nlastRow\t%v\n", row, lastRow)
	for i, element := range row {
		// fmt.Fprintf(os.Stderr, "i = %d: bestInRange(%d, %d, %v)\n", i, i, i+1, lastRow)
		element.bestSolution = element.value + bestInRange(i-1, i, lastRow)
	}
}

// TODO: make bestInRange do the bounds checking so we can get rid of the switch statement above
func bestInRange(low, high int, row []*node) int {
	max := -1
	for i := low; i <= high; i++ {
		if i < 0 || i > len(row)-1 {
			continue
		}
		if row[i].bestSolution > max {
			max = row[i].bestSolution
		}
	}
	fmt.Fprintf(os.Stderr, "bestInRange(%d, %d, %v) = %d\n", low, high, row, max)
	return max
}

func (n *node) String() string {
	return fmt.Sprintf("{%d, %d}", n.value, n.bestSolution)
}
