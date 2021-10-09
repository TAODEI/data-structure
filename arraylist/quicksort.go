package arraylist

import (
	"data/stackarray"
)

func QuickSort(l List) {
	var stack stackarray.StackArray = NewArrayListStack()
	low := 0
	high := l.Size() - 1
	for low < high || !stack.IsEmpty() {
		if low < high {
			pivotKey := l.Partition(low, high)
			if high-pivotKey > pivotKey-low {
				stack.Push(pivotKey + 1)
				stack.Push(high)
				high = pivotKey - 1 // 短的子序列留待下次排序
			} else {
				stack.Push(low)
				stack.Push(pivotKey - 1)
				low = pivotKey + 1
			}
		} else {
			// 如果当前子序列已排好序但栈中还有未排序的子序列
			// 从栈中取出一个子序列
			high = stack.Pop().(int)
			low = stack.Pop().(int)
		}

	}
}
func MiddleVal(l List) int {
	middle := l.Size() / 2
	low := 0
	high := l.Size() - 1
	for low < middle && middle < high {
		pivotKey := l.Partition(low, high)

		if middle > pivotKey {
			low = pivotKey + 1
		} else if middle < pivotKey {
			high = pivotKey - 1
		}
	}
	return l.Get(middle).(int)
}
func (l *Arraylist) Partition(low int, high int) int { // 一趟划分的算法,与书上相同
	pivotkey := l.Get(low)
	for low < high {
		for low < high && l.Get(high).(int) >= pivotkey.(int) {
			high--
		}
		l.Set(low, l.Get(high))

		for low < high && l.Get(low).(int) <= pivotkey.(int) {
			low++
		}
		l.Set(high, l.Get(low))
	}
	l.Set(low, pivotkey)
	l.Show()
	return low
}
