package main

import (
    "fmt"
    "math/rand"
    "time"
)

func generator(out chan<- int) {
    defer close(out)
    for i := 0; i < 5; i++ {
        time.Sleep(time.Duration(rand.Intn(200)+100) * time.Millisecond)
        out <- rand.Intn(100)
    }
}

func doubler(in <-chan int, out chan<- int) {
    defer close(out)
    for value := range in {
        out <- value * 2
    }
}

func main() {
    rand.Seed(time.Now().UnixNano())
    stage1 := make(chan int)
    stage2 := make(chan int)

    go generator(stage1)
    go doubler(stage1, stage2)

    for value := range stage2 {
        fmt.Println("Processed value:", value)
    }
}
