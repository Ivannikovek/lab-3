#ifndef _MY_QUEUE_HPP_

#define _MY_QUEUE_HPP_

#include "Queue.h"

template <typename T>
Queue<T>::Queue() :_front(nullptr), _back(nullptr) {

}

template <typename T>
Queue<T>::Queue(const Queue& other) {
	_copy(other);
}

template <typename T>
void Queue<T>::_copy(const Queue& other) {
	if (other._front == nullptr)
		_front = _back = nullptr;
	else {
		_front = new element{ other._front->value, nullptr };

		element* last_added = _front;
		element* temp = other._front->next;

		while (temp != nullptr) {
			last_added->next = new element{ temp->value, nullptr };

			last_added = last_added->next;
			temp = temp->next;
		}

		_back = last_added;
	}
}

template <typename T>
Queue<T>::~Queue() {
	_clear();
}

template <typename T>
void Queue<T>::_clear() {
	while (_front != nullptr) {
		element* removing = _front;

		_front = _front->next;

		delete removing;
	}

	_back = nullptr;
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other) {
	if (this != &other) {
		_clear();
		_copy(other);
	}

	return *this;
}

template <typename T>
T Queue<T>::pop() {
	if (_front == nullptr)
		throw std::runtime_error("Queue is empty.");
	T popping_value = _front->value;

	element* removing = _front;

	_front = _front->next;
	if (_front == nullptr) //if last element was popped, back is null
		_back = nullptr;

	delete removing;

	return popping_value;
}

template <typename T>
T Queue<T>::front() const {
	if (_front == nullptr)
		throw std::runtime_error("Queue is empty.");

	return _front->value;
}

template <typename T>
void Queue<T>::push(T value) {
	if (_front == nullptr) //if queue is empty
		_front = _back = new element{ value, nullptr };
	else {
		_back->next = new element{ value, nullptr };
		_back = _back->next;
	}
}

template <typename T>
bool Queue<T>::is_empty() const {
	return _front == nullptr;
}

#endif //! _MY_QUEUE_HPP_