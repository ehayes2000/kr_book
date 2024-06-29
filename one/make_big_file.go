package main

import (
	"fmt"
	"math/rand"
	"os"
	"strconv"
	"strings"
)

func main() {
	nLines, e1 := strconv.Atoi(os.Args[1])
	mxLen, e2 := strconv.Atoi(os.Args[1])
	if e1 != nil || e2 != nil {
		panic(fmt.Sprintf("error %v, %v", e1, e2))
	}
	for range nLines {
		fmt.Println(strings.Repeat("#", rand.Intn(mxLen)))
	}
	// fmt.Print(strings.Repeat("#", l))
}
