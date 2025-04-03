#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){

}

PmergeMe::~PmergeMe(){

}

int PmergeMe::checkDuplicate(int val) {
    for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); it++) {
        if (*it == val) {
            return (1);
        }
    }
    return (0);
}

double PmergeMe::gettime() {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    return tp.tv_sec * 1000000.0 + tp.tv_usec;
}

void PmergeMe::printValues(int argc, char **argv) {
    long int before = gettime();
    sortContainer(_vector);
    long int vectorTime = gettime() - before;
    before = gettime();
    sortContainer(_deque);
    long int dequeTime = gettime() - before;
    std::cout << "Before: ";
    for (int i = 1; i < argc; i++) {
        std::cout << argv[i] << " ";
    }
    std::cout << "\n";
    std::cout << "After: ";
    for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++) {
        std::cout <<  *it << " ";
    }
    std::cout << "\n";
    std::cout << "Time to process a range of " << argc - 1 
              << " elements with std::vector: " 
              << std::fixed << std::setprecision(5) << vectorTime 
              << " us" << std::endl;
              
    std::cout << "Time to process a range of " << argc - 1 
              << " elements with std::deque: " 
              << std::fixed << std::setprecision(5) << dequeTime 
              << " us" << std::endl;
}

PmergeMe::PmergeMe(int argc,char **argv){
    for (int i = 1; i < argc; i++) {
        for (size_t j = 0; j < strlen(argv[i]); j++){
            if (!isdigit(argv[i][j])) {
                std::cerr << "Error: All the input must be positive integers" << std::endl;
                exit(1);
            }
        }
        if (checkDuplicate(atoi(argv[i]))) {
            std::cerr << "No duplicate values are allowed" << std::endl;
            exit(1);
        }
        if (atol(argv[i]) > INT_MAX) {
            std::cerr << "Numbers can not be bigger than INT_MAX" << std::endl;
            exit(1);  
        }
        _vector.push_back(atoi(argv[i]));
        _deque.push_back(atoi(argv[i]));
    }
    printValues(argc, argv);
}

PmergeMe::PmergeMe(const PmergeMe &other): _vector(other._vector), _deque(other._deque) {

}
PmergeMe& PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        _vector = other._vector;
        _deque = other._deque;
    }
    return *this;
}
