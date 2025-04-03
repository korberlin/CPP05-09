#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Usage: ./PmergeMe 1 2 3..." << std::endl;
        return (1);
    }
    PmergeMe pmerge(argc, argv);
    return 0;
}