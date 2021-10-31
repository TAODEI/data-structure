package stackarray

func Knapsack(w []int, T int) {
	stack := NewStack()
	for k := 0; !stack.IsEmpty() || k < len(w); k++ {
		for T > 0 && k < len(w) {
			if T-w[k] >= 0 {
				stack.Push(k)
				T -= w[k]
			}
			k++
		}
		if T == 0 {
			stack.Show(w)
		}
		k = stack.Pop().(int)
		T += w[k]
	}
}
