// Matt Piazza
// 19 DEC 2015
// solution to: https://www.hackerrank.com/contests/101hack32/challenges/straight-flush

package main
import (
    "fmt"
    "sort"
)
const DEBUG bool = false

func isStraight(cards []int) bool {
    sort.Ints(cards)
    if DEBUG {
        fmt.Println("sorted cards into ", cards)
    }
    inaRow := 1
    for i := 0; i < len(cards) - 1; i++ {
        if cards[i+1] - cards[i] == 1 {
            if DEBUG {
                fmt.Printf("examining %d and %d, inaRow now = %d\n", cards[i], cards[i+1], inaRow+1)
            }
            inaRow++
        } else if inaRow < 5 {
            inaRow = 1
        }
    }
    return inaRow == 5
}

func main() {
    // read in 5 lines then print one
    var card string
    var cards []int
    var isFlush bool = true // parse card and break if we see multiple suits
    var seenSuit rune = 'x'
    for i := 0; i < 5; i++{
       fmt.Scanf("%s ", &card)
        if seenSuit == 'x'{
            // first card flag
            seenSuit = rune(card[1])
        } else if rune(card[1]) != seenSuit {
            if DEBUG{
                fmt.Printf("seen suit %d, have suit %d\n", seenSuit, card[0])
            }
            isFlush = false
        }
        // card matches expected suit
        val := card[0]
        switch{
            case val >= 49 && val <= 57:
            // is an ascii number
            num := val - 48
            cards = append(cards, int(num))
            case val == 'T':
            cards = append(cards, 10)
            case val == 'J':
            cards = append(cards, 11)
            case val == 'Q': 
            cards = append(cards, 12)
            case val == 'K':
            cards = append(cards, 13)
            case val == 'A':
            cards = append(cards, 1)
            cards = append(cards, 14)
        }
    }
    if isFlush && isStraight(cards){
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}
