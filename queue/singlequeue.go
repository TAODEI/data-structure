package queue

import "errors"

type Queue struct {
	maxSize int
	array   [4]int
	front   int
	rear    int
}

func (q *Queue) AddQueue(val int) error {
	if q.rear == q.maxSize-1 {
		return errors.New("queue full")
	}

	q.rear++
	q.array[q.rear] = val
	return nil
}
