#pragma once

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

template <typename T>

class Queue {
private:

	struct Node { //creating a single linked list
		T data;
		Node* next;
	};
	Node* head;
	Node* tail;
	int num_items;

public:

	Queue() : head(nullptr), tail(nullptr), num_items(0) {}
	~Queue() {
		while (!empty()) {
			pop();
		}
	}
	//Add a new element at the end of the queue (Last in)
	void push(T value) { 
		Node* newNode = new Node{ value, nullptr };
		if (empty()) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		num_items++;
	}

	//Remove element at the front of the queue (first out)
	void pop() {
		if (!empty()) {
			Node* temp = head;
			head = head->next;
			delete temp;
			num_items--;
			if (head == nullptr) {
				tail = nullptr;
			}
		}
	}

	T front() {
		if (!empty()) {
			return head->data; 
		}
		throw std::runtime_error("The queue is empty");
	}

	int size() const {
		return num_items; //returns size of queue
	}

	bool empty() const {
		return head == nullptr;
	}
	
	void move_to_rear() { 
		/*if queue is not empty and the size is greater then one, move the element currently at
the front of the queue to the rear of the queue. */
		if (!empty() && size() > 1) { 
			T frontElement = front();
			pop();
			push(frontElement);
		}
	}

};


#endif