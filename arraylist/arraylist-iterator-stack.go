package arraylist

import "fmt"

type StackIterator struct {
	array *Arraylist
	It    Iterator
}

func NewArrayListStackIterator() *StackIterator {
	stack := new(StackIterator)
	stack.array = NewArrayList()
	stack.It = stack.array.NewIterator()
	return stack
}

func (stack *StackIterator) Clear() {
	stack.array.Clear()
	stack.It = stack.array.NewIterator()
}

func (stack *StackIterator) Size() int {
	return stack.array.theSize
}

func (stack *StackIterator) Pop() interface{} {
	if !stack.IsEmpty() {
		// stack.array.theSize--
		last := stack.array.dataStore[stack.array.theSize-1]
		stack.array.Delete(stack.array.theSize - 1)
		// stack.array.dataStore = stack.array.dataStore[:stack.array.theSize]
		return last
	}
	return nil
}

func (stack *StackIterator) Push(data interface{}) {
	if !stack.IsFull() {
		stack.array.dataStore = append(stack.array.dataStore, data)
		stack.array.theSize++
	}
}

func (stack *StackIterator) IsFull() bool {
	return stack.It.HasNext()
}

func (stack *StackIterator) IsEmpty() bool {
	return stack.array.theSize == 0
}

func (stack *StackIterator) String() string {
	return fmt.Sprint(stack.array.dataStore)
}
