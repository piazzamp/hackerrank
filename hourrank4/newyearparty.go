package main
import (
    "fmt"
    "sort"
)
func main() {
    // I guess make a histogram of entry times
    var guests, entryTime int
    fmt.Scanf("%d\n", &guests)
    hist := make(map[int]int) // map entry times to number of guests
                    // entry times are guaranteed to be in non-descending order
    for i := 0; i < guests; i++ {
        fmt.Scanf("%d", &entryTime)
        hist[entryTime] += 1
    }
    fmt.Println(lastTime(hist))
}

func lastTime(arrivalTimes map[int]int) int {
    // get the arrival times in order
    // is there a better way to do this? maybe read it in as a linked list of structs
    var times []int
    for k, _ := range arrivalTimes {
        times = append(times, k)
    }
    sort.Ints(times)
    
    queued := 0 // how many people are waiting to enter
    // the result will be queued + last entry time
    previousArrivalTime := 0 // the last time someone arrived 
    var timeElapsed int
    for _, time := range times {
        guests := arrivalTimes[time]
        timeElapsed = time - previousArrivalTime // assumed that they were in order :(
        // fmt.Printf("time elapsed: %d\n", timeElapsed)
        previousArrivalTime = time
        // first dequeue all the people waiting
        if queued >= timeElapsed {
            queued -= timeElapsed
            // all the people who just arrived go on the end of the queue
            // fmt.Printf("adding %d people onto the queue(%d) at time %d\n", guests, queued, time)
            queued += guests
        } else {
            // one person who just arrived enters and the rest go on the queue
            // fmt.Printf("adding %d people to the queue(%d) at time %d\n", guests - 1, queued, time)
            queued = guests - 1
        }
    }
    // fmt.Printf("previous arrival time: %d + %d people in the queue\n", previousArrivalTime, queued)
    return previousArrivalTime + queued
}
