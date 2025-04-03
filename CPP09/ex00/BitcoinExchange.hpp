#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <stdlib.h>
#include <algorithm>

#define SUCCESS 0
#define FAILURE 1

class BtcValue {
	private:
		std::map<int, float> _dateValue;
		BtcValue();
		int convertDate(std::string& date);
		void readDataCSV(std::fstream &fs);
		BtcValue(const BtcValue &btcValue);
		BtcValue& operator=(const BtcValue &btcValue);
		void calculateAndPrintValues(std::fstream &inputCSV);
	public:
		BtcValue(const char *fileName);
		~BtcValue();

};

#endif