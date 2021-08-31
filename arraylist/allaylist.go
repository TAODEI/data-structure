package arraylist

import (
	"errors"
	"fmt"
)

// type List interface {
// 	Size() int
// 	Get(index int) (interface{}, error)         // 抓取第几个元素
// 	Set(index int, newcal interface{}) error    // 设置某个
// 	Append(newval interface{})                  // 追加
// 	Insert(index int, newval interface{}) error // 插入
// 	Delete(index int)
// 	Iterator() Iterator // 构造初始化接口
// 	Clear()
// }

type Arraylist struct {
	dataStore []interface{}
	theSize   int
}

func NewArrayList() *Arraylist {
	list := new(Arraylist)

	// list.dataStore = make([]interface{}, 100)
	list.theSize = 0
	return list
}

func (list *Arraylist) Clear() {
	// GOTO
	list = NewArrayList()
}

// 检测内存
func (list *Arraylist) checkIsFull() {
	if list.theSize == cap(list.dataStore) {
		var newDataStore []interface{}
		// newDataStore := make([]interface{}, 0, 2*list.theSize)
		copy(newDataStore, list.dataStore) // 有问题

		// newDataStore = append(newDataStore, list.dataStore...)
		list.dataStore = newDataStore
	}
}

func (list *Arraylist) Size() int {
	return list.theSize
}

func (list *Arraylist) Get(index int) (interface{}, error) {
	if index < 0 || index >= list.theSize {
		return nil, errors.New("索引越界")
	}
	return list.dataStore[index], nil
}

func (list *Arraylist) Append(newval interface{}) {
	list.dataStore = append(list.dataStore, newval)
	list.theSize++
}

func (list *Arraylist) String() string {
	return fmt.Sprint(list.dataStore)
}

func (list *Arraylist) Insert(index int, newval interface{}) error {
	if index < 0 || index >= list.theSize {
		return errors.New("索引越界")
	}

	list.checkIsFull()

	// tmpDataStore := make([]interface{}, 0, 2*list.theSize)
	var tmpDataStore []interface{}
	tmpDataStore = append(tmpDataStore, list.dataStore[index:]...)

	list.dataStore = append(list.dataStore[:index], newval)
	list.dataStore = append(list.dataStore, tmpDataStore...)
	return nil
}

func (list *Arraylist) Set(index int, newcal interface{}) error {
	if index < 0 || index >= list.theSize {
		return errors.New("索引越界")
	}
	list.dataStore[index] = newcal
	return nil
}

func (list *Arraylist) Delete(index int) {
	// GOTO
	list.dataStore = append(list.dataStore[:index], list.dataStore[index+1:]...)
	list.theSize--
}
