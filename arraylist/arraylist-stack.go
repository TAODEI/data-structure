package arraylist

import "fmt"

type Stack struct {
	array   *Arraylist
	capSize int // maxsize
}

func NewArrayListStack() *Stack {
	return &Stack{
		NewArrayList(),
		10,
	}
}

func (stack *Stack) Clear() {
	stack.array.Clear()
	stack.capSize = 10
}

func (stack *Stack) Size() int {
	return stack.array.theSize
}

func (stack *Stack) Pop() interface{} {
	if !stack.IsEmpty() {
		// stack.array.theSize--
		last := stack.array.dataStore[stack.array.theSize-1]
		stack.array.Delete(stack.array.theSize - 1)
		// stack.array.dataStore = stack.array.dataStore[:stack.array.theSize]
		return last
	}
	return nil
}

func (stack *Stack) Push(data interface{}) {
	if !stack.IsFull() {
		stack.array.dataStore = append(stack.array.dataStore, data)
		stack.array.theSize++
	}
}

func (stack *Stack) IsFull() bool {
	return stack.array.theSize >= stack.capSize
}

func (stack *Stack) IsEmpty() bool {
	return stack.array.theSize == 0
}

func (stack *Stack) String() string {
	return fmt.Sprint(stack.array.dataStore)
}
