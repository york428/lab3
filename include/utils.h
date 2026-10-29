template <class T>
class Stack
{
private:
	int top;
	size_t sz;
	T* pMem;
public:
	Stack(int n = 1) :sz(n), pMem(new T[n]);
	~Stack() { 
		delete[] pMem;
	}
	void Push(const T& val);
	void Pop();
	T Top();
	T Stack<T>::Top()
	{
		T tmp = pMem[top];
		return tmp;
	}
	void Stack<T>::Push() {
		if (!IsFull()) {
			pMem[++top] = val;
		}
	}
	
	void Stack<T>::Pop() {
		if (!IsEmpty()) {
			--top;
		}
	}
	T Stack<T>::Top() {
		if (IsEmpty) {
			throw - 1;
		}
		T tmp = pMem[top];
		return tmp;
	}
};