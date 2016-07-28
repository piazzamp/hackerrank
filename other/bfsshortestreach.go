// solution to https://www.hackerrank.com/challenges/bfsshortreach/

package main

import (
	"fmt"
)

type node struct {
	dist      int
	id        int
	neighbors []*node
}

func main() {
	var t int
	fmt.Scanln(&t)
	for j := 0; j < t; j++ {
		var numNodes, numEdges int
		fmt.Scanln(&numNodes, &numEdges)
		nodes := make([]*node, numNodes+1) // add one to handle the base-1 scheme w/o adding complexity
		for i := range nodes {
			nodes[i] = &node{id: i}
		}
		var to, from int
		for i := 0; i < numEdges; i++ {
			fmt.Scanln(&to, &from)
			addEdge(nodes, from, to)
		}
		var s int
		fmt.Scanln(&s)
		dists := search(nodes, s)
		for i, d := range dists {
			if i == 0 {
				continue
			}
			if d == 0 {
				d = -1
			}
			fmt.Printf("%d ", d)
		}
		fmt.Println()
	}
}

// thanks to wikipedia's pseudocode lmao
// could be a little nicer looking I think
func search(graph []*node, from int) []int {
	// fmt.Printf("starting at node %d in a graph of size %d\n", from, len(graph))
	var queue []*node
	queue = append(queue, graph[from])
	for len(queue) > 0 {
		current := queue[0]
		queue = queue[1:]
		for _, neigh := range current.neighbors {
			if neigh.dist == 0 {
				neigh.dist = 6 + current.dist
				queue = append(queue, neigh)
			}

		}
	}
	var result []int
	for _, n := range graph {
		if n.id == from {
			continue
		}
		result = append(result, n.dist)
	}
	return result
}

// all node indices are 1-based :/
func addEdge(nodes []*node, from, to int) {
	nodes[from].neighbors = append(nodes[from].neighbors, nodes[to])
	nodes[to].neighbors = append(nodes[to].neighbors, nodes[from])
}
