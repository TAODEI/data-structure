package linklist

type SingleLink interface {
	GetHead() *SingleLinkNode
	InsertNodeFront(node *SingleLinkNode) // 头部插入
	InsertNodeBack(node *SingleLinkNode)  // 尾部插入

	GetNodeByIndex(index int) *SingleLinkNode
	DeleteNode(destNode *SingleLinkNode) bool
	DeleteNodeByIndex(index int)
	String() string
}

// 链表结构
type SingleLinkList struct {
	head   *SingleLinkNode // 头指针
	length int
}

// 创建链表
func NewSingleLinkList() *SingleLinkList {
	return &SingleLinkList{
		NewSingleLinkNode(nil),
		0,
	}
}

func (list *SingleLinkList) GetHead() *SingleLinkNode
func (list *SingleLinkList) InsertNodeFront(node *SingleLinkNode) {

}
func (list *SingleLinkList) InsertNodeBack(node *SingleLinkNode)
func (list *SingleLinkList) GetNodeByIndex(index int) *SingleLinkNode
func (list *SingleLinkList) DeleteNode(destNode *SingleLinkNode) bool
func (list *SingleLinkList) DeleteNodeByIndex(index int)
func (list *SingleLinkList) String() string
