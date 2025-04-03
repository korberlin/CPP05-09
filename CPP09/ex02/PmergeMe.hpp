#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <sstream>
#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <stdlib.h>
#include <limits.h>
#include <ctime>
#include <sys/time.h>
#include <iomanip>

class PmergeMe {
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe& operator=(const PmergeMe &other);
        template <typename T>
        void sortContainer(T &container);
        template <typename T>
        void insertionSort(T &container);
        double gettime();
        void printValues(int argc, char **argv);
    public:
        PmergeMe(int argc, char **argv);
        ~PmergeMe();
        int checkDuplicate(int val);
};

template <typename T>
void PmergeMe::insertionSort(T &container) {
    if (container.size() <= 1)
        return;
    for (typename T::iterator current = ++container.begin(); current != container.end(); ++current) {
        int temp = *current;
        typename T::iterator position = current;
        while (position != container.begin() && *(position - 1) > temp) {
            *position = *(position - 1);
            --position;
        }
        *position = temp;
    }
}

template <typename T>
void PmergeMe::sortContainer(T &container) {
    // Split container into two halves
    T main;
    T pend;
    
    // Remove the increment in the for loop declaration
    for (typename T::iterator it = container.begin(); it != container.end();) {
        typename T::iterator it_next = it;
        ++it_next;
        
        if (it_next != container.end()) {
            *it < *it_next ? pend.push_back(*it) : pend.push_back(*it_next);
            *it < *it_next ? main.push_back(*it_next) : main.push_back(*it);
            it = ++it_next;
        } else {
            pend.push_back(*it);
            ++it;
        }
    }
    // Apply insertion sort to both containers
    insertionSort(main);
    insertionSort(pend);
    // Clear the container to merge main and pending containers
    container.clear();
    // Merge the containers into original one
    typename T::iterator it_main = main.begin();
    typename T::iterator it_pend = pend.begin();
    while (it_main != main.end() && it_pend != pend.end()) {
        *it_main < *it_pend ? container.push_back(*it_main++) : container.push_back(*it_pend++);
    }
    while (it_pend != pend.end()) {
        container.push_back(*it_pend++);
    }
    while (it_main != main.end()) {
        container.push_back(*it_main++);
    }
}
#endif