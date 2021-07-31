#pragma once
//const int MAX = 10;
template<typename T=int, int MAX=10>
class Stack
{
private:
	T items[MAX];
	int top;
public:
	Stack();
	~Stack();
	bool isEmpty() const;
	bool isFull() const;
	bool push(const T& item);
	bool pop(T& item);
};

template<typename T, int MAX>
Stack<T, MAX>::Stack():top(0){}

template<typename T, int MAX>
Stack<T, MAX>::~Stack(){}

template<typename T, int MAX>
bool Stack<T, MAX>::isEmpty() const {
	return top == 0;
}

template<typename T, int MAX>
bool Stack<T, MAX>::isFull() const {
	return top == MAX;
}

template<typename T, int MAX>
bool Stack<T, MAX>::push(const T& item) {
	if (!isFull()) {
		items[top++] = item;
		return true;
	}
	else {
		return false;
	}
}

template<typename T, int MAX>
bool Stack<T, MAX>::pop(T& item) {
	if (!isEmpty()) {
		item = items[--top];
		return true;
	}
	else {
		return false;
	}
}