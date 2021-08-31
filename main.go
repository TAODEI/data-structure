package main

import (
	"data/arraylist"
	"fmt"
)

func main() {
	var list arraylist.List = arraylist.NewArrayList()
	list.Append(0)
	list.Append(1)
	list.Append(2)
	list.Append(3)
	list.Append(4)
	list.Append(5)
	// test()
	for it := list.Iterator(); it.HasNext(); {
		item, _ := it.Next()
		fmt.Println(item)
	}
	for i := 20; i > 0; i-- {
		list.Insert(2, 9)
	}
	fmt.Println(list)
}

func test() {
	slice := append([]byte("hello "), "world"...)
	fmt.Println(slice)
}
