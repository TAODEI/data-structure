package arraylist

import "errors"

// 迭代器
type Iterator interface {
	HasNext() bool // 是否有下一个
	Next() (interface{}, error)
	Remove()       // 删除
	GetIndex() int // 得到索引
}

// type Iterable interface {
// 	Iterator() Iterator // 构造初始化接口
// }

// 构造指针访问数组
type ArraylistIterator struct {
	list         *Arraylist // 数组指针
	currentIndex int        // 当前索引
}

func (list *Arraylist) NewIterator() Iterator {
	it := new(ArraylistIterator) // 构造迭代器
	it.currentIndex = 0
	it.list = list
	return it
}

func (it *ArraylistIterator) HasNext() bool {
	return it.currentIndex < it.list.theSize
}

func (it *ArraylistIterator) Next() (interface{}, error) {
	if !it.HasNext() {
		return nil, errors.New("can't find the next one")
	}
	it.currentIndex++
	return it.list.Get(it.currentIndex - 1)
}

func (it *ArraylistIterator) Remove() {
	it.currentIndex--
	it.list.Delete(it.currentIndex)
}

func (it *ArraylistIterator) GetIndex() int {
	return it.currentIndex
}
