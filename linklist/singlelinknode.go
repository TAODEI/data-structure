package linklist

// 链表节点结构
type SingleLinkNode struct {
	value interface{}
	pNext *SingleLinkNode
}

func NewSingleLinkNode(data interface{}) *SingleLinkNode {
	return &SingleLinkNode{
		data,
		nil,
	}
}

func (node *SingleLinkNode) GetValue() interface{} {
	return node.value
}

func (node *SingleLinkNode) GetPNext() *SingleLinkNode {
	return node.pNext
}
