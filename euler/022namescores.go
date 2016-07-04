package main

import (
	"fmt"
	"os"
	"sort"
)

func main() {
	var numNames int
	fmt.Scanf("%d", &numNames)
	names := make([]string, numNames)
	for i := 0; i < numNames; i++ {
		fmt.Scanf("%s", &names[i])
	}
	var numQueries int
	fmt.Scanf("%d", &numQueries)
	queries := make([]string, numQueries)
	for i := 0; i < numQueries; i++ {
		fmt.Scanf("%s", &queries[i])
	}
	answers := assemble(names)
	for _, q := range queries {
		fmt.Println(answers[q])
	}
}

func assemble(names []string) map[string]int {
	sort.Strings(names)
	results := make(map[string]int)
	for i, name := range names {
		results[name] = score(name, i)
	}
	return results
}

func score(name string, index int) int {
	total := 0
	// ranging through a string yields runes (ascii codepoints)
	for _, char := range name {
		// this assumes all the chars will be upper case
		total += int(char - 'A' + 1)
	}
	fmt.Fprintf(os.Stderr, "%s has score %d\n", name, total*(index+1))
	// problem uses base-1 indexing, but real life does not
	return total * (index + 1)
}
