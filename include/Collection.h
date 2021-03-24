#pragma once

#include<iostream>
#include<exception>
#include<list.h>

using namespace std;

template <class T>
class ICollection {
public:
	virtual int size() const = 0;
	virtual bool empty() const = 0;

	virtual void push(const T& v) = 0;
	virtual void pop() = 0;
};

template <class T>
class Queue: public ICollection<T> {
	List<T> *lQueue;

public:
	Queue();
	Queue(const Queue<T>& q) = delete;
	Queue<T>& operator=(const Queue<T>& q) = delete;

	const T& front() const;
	const T& back() const;

	int size() const override;
	bool empty() const override;

	void push(const T& v) override;
	void pop() override;
};

template <class T>
Queue<T>::Queue() : lQueue(new List<T>) {}

template <class T>
const T& Queue<T>::front() const {
	return lQueue->front();
};

template <class T>
const T& Queue<T>::back() const {
	return lQueue->back();
}

template <class T>
int Queue<T>::size() const {
	return lQueue->getSize();
}

template <class T>
bool Queue<T>::empty() const {
	return lQueue->empty();
}

template <class T>
void Queue<T>::push(const T& v) {
	lQueue->push_back(v);
}

template <class T>
void Queue<T>::pop() {
	if (empty()) { throw logic_error("queue_is_empty"); }
	lQueue->pop_front();
}

template <class T>
class Stack: public ICollection<T> {
	List<T> *lStack;

public:
	Stack();
	Stack(const Stack<T>& s) = delete;
	Stack<T>& operator=(const Stack<T>& s) = delete;

	const T& top() const;

	int size() const override;
	bool empty() const override;

	void push(const T& v) override;
	void pop() override;
};

template <class T>
Stack<T>::Stack() : lStack(new List<T>) {}

template <class T>
const T& Stack<T>::top() const {
	return lStack->back();
}

template <class T>
int Stack<T>::size() const {
	return lStack->getSize();
}

template <class T>
bool Stack<T>::empty() const {
	return lStack->empty();
}

template <class T>
void Stack<T>::push(const T& v) {
	lStack->push_back(v);
}

template <class T>
void Stack<T>::pop() {
	if (empty()) { throw logic_error("stack_is_empty"); }
	lStack->pop_back();
}