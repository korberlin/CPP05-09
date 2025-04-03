#include "BitcoinExchange.hpp"

int main(int argc, char **argv){
	(void) argv;
	if (argc != 2) {
		std::cerr << "Usage: ./btc `Filename`" << std::endl;
		return FAILURE;
	}
	BtcValue btc(argv[1]);
	return SUCCESS;
}
