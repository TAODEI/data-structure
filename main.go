package main

import (
	"data/arraylist"
	"data/stackarray"
	"fmt"
	"io/ioutil"
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
		item := it.Next()
		fmt.Println(item)
	}
}

func getAllFile(path string, files []string) ([]string, error) {
	reader, err := ioutil.ReadDir(path)
	if err != nil {
		return nil, err
	}
	for _, fi := range reader {
		fullDir := path + "/" + fi.Name()
		if fi.IsDir() {
			files = append(files, fullDir) // 追加路径
			files, err = getAllFile(fullDir, files)
		} else {
			files = append(files, fullDir)
		}
	}
	return files, err
}

func getAllFile_main() {
	path := "/home/taodei/Desktop/go_practise"
	files := []string{}
	var err error
	files, err = getAllFile(path, files)
	if err != nil {
		panic(err)
	}
	for _, file := range files {
		fmt.Println(file)
	}
}

func getFileStack_main() {
	path := "/home/taodei/Desktop/data-structure"
	files := []string{}
	var stack stackarray.StackArray = stackarray.NewStack()
	stack.Push(path)
	for !stack.IsEmpty() {
		newPath := stack.Pop().(string)
		files = append(files, newPath)
		reader, err := ioutil.ReadDir(newPath)
		if err != nil {
			panic(err)
		}
		for _, fi := range reader {
			fullDir := newPath + "/" + fi.Name()
			if fi.IsDir() {
				stack.Push(fullDir)
			} else {
				files = append(files, fullDir) // 追加路径
			}
		}
	}
	for _, file := range files {
		fmt.Println(file)
	}
}

func arraylist_stack_quicksort_main() {
	var list arraylist.List = arraylist.NewArrayList()
	array := []int{500, 256, 301, 751, 129, 937, 863, 742, 694, 076, 438}
	for _, ele := range array {
		list.Append(ele)
	}
	list.Show()

	fmt.Println(arraylist.MiddleVal(list))

	// arraylist.QuickSort(list)

}

func test() {

}

func main() {
	// arraylist_stack_quicksort_main()
	w := []int{1, 8, 4, 3, 5, 2}
	stackarray.Knapsack(w, 10)
}
