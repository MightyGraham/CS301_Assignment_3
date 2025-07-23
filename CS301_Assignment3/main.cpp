// CS301_Assignment3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "QueueClass.h"


//recursive linear search function

template <typename T>

int recursive_last_index(const std::vector<T>& vec, const T& target, int index) {
    if (index < 0) {
        return -1;
    }
    if (vec[index] == target) {
        return index;
    }
    return recursive_last_index(vec, target, index - 1);
}



int main() {
    Queue<int> q;

    // part a
    for (int i = 1; i <= 10; ++i) {
        q.push(i*2);
    }

    // part b
    std::cout << "Queue: ";
    int sz = q.size();
    for (int i = 0; i < sz; ++i) {
        int val = q.front();
        std::cout << val << " ";
        q.pop();
        q.push(val);
    }
    std::cout << std::endl;

    // part c
    q.move_to_rear();
    std::cout << "\n";
    std::cout << "Moving first element to the rear \n";
    sz = q.size();
    for (int i = 0; i < sz; ++i) {
        int val = q.front();
        std::cout << val << " ";    
        q.pop();
        q.push(val);
    }
  
    /*int target;
    std::cout << "\nEnter a number to find its last occurrence: ";
    std::cin >> target;

        int lastIndex = recursive_last_index(contents, target, contents.size() - 1);
    if (lastIndex != -1) {
        std::cout << "Last occurrence of " << target << " is at index " << lastIndex << "\n";
    } else {
        std::cout << target << " is not found.\n";
    }
    */

    return 0;
}
