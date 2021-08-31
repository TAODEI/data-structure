package main

import (
	"data/arraylist"
	"data/stackarray"
	"fmt"
)

// func arraylist_iterator_main() {
// 	var list arraylist.List = arraylist.NewArrayList()
// 	list.Append(0)
// 	list.Append(1)
// 	list.Append(2)
// 	list.Append(3)
// 	list.Append(4)
// 	list.Append(5)
// 	for it := list.NewIterator(); it.HasNext(); {
// 		item, _ := it.Next()
// 		fmt.Println(item)
// 	}
// 	for i := 20; i > 0; i-- {
// 		list.Insert(2, 9)
// 	}
// 	fmt.Println(list)
// }

func stackarray_main() {
	// stack := stackarray.NewStack()
	var stack stackarray.StackArray = stackarray.NewStack()
	for i := 0; i < 5; i++ {
		stack.Push(i)
	}
	fmt.Println(stack)
	for i := 0; i < 5; i++ {
		fmt.Println(stack.Pop())
	}
}

func arraylist_stack_main() {
	var stack stackarray.StackArray = arraylist.NewArrayListStack()
	for i := 0; i < 5; i++ {
		stack.Push(i * 10)
	}
	fmt.Println(stack)
	for i := 0; i < 5; i++ {
		stack.Pop()
		fmt.Println(stack)
	}
}

func arraylist_stack_iterator_main() {
	// var stack stackarray.StackArray = arraylist.NewArrayListStackIterator()
	stack := arraylist.NewArrayListStackIterator()
	for it := stack.It; it.HasNext(); {
		item, _ := it.Next()
		fmt.Println(item)
	}

}
func test() {
	slice := append([]byte("hello "), "world"...)
	fmt.Println(slice)
}

func main() {
	arraylist_stack_iterator_main()
}
