package stackarray

import "fmt"

type StackArray interface {
	Clear()
	Size() int
	Pop() interface{}      // 弹出
	Push(data interface{}) // 压入
	IsFull() bool
	IsEmpty() bool
	String() string
}

type Stack struct {
	dataSource  []interface{}
	capSize     int
	currentSize int
}

func NewStack() *Stack {
	return &Stack{
		// make([]interface{}, 0, 10),
		capSize:     10,
		currentSize: 0,
	}
}

func (stack *Stack) Clear() {
	stack.dataSource = make([]interface{}, 10)
	stack.capSize = 10
	stack.currentSize = 0
}

func (stack *Stack) Size() int {
	return stack.currentSize
}

func (stack *Stack) Pop() interface{} {
	if !stack.IsEmpty() {
		stack.currentSize--
		last := stack.dataSource[stack.currentSize]
		stack.dataSource = stack.dataSource[:stack.currentSize]
		return last
	}
	return nil
}

func (stack *Stack) Push(data interface{}) {
	if !stack.IsFull() {
		stack.dataSource = append(stack.dataSource, data)
		stack.currentSize++
	}
}

func (stack *Stack) IsFull() bool {
	return stack.currentSize >= stack.capSize
}

func (stack *Stack) IsEmpty() bool {
	return stack.currentSize == 0
}

func (stack *Stack) String() string {
	return fmt.Sprint(stack.dataSource)
}
