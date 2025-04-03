#include "BitcoinExchange.hpp"

BtcValue::BtcValue() {

}

BtcValue::~BtcValue() {

}

BtcValue::BtcValue(const BtcValue& other): _dateValue(other._dateValue) {
}

BtcValue& BtcValue::operator=(const BtcValue& other) {
	if (this != & other) {
		_dateValue = other._dateValue;
	}
	return *this;
}

std::string removeWhitespace(std::string &str) {
    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
    return str;
}

int BtcValue::convertDate(std::string& date) {
	int dateVal;
	// Validate date string
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		return (-1);
	}
	int year = atoi(date.substr(0,4).c_str());
	int month = atoi(date.substr(5,2).c_str());
	int day = atoi(date.substr(8,2).c_str());
	// validate year, month, day
	if (year == 0 || month == 0 || day == 0) {
		return (-1);
	}
	if (year < 0 || month > 12 || month < 0 || day > 31 || day < 0) {
		return (-1);
	}
	if ((month == 2 || month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
		return (-1);
	}
	if (year % 4 && month == 2 && day > 28) {
		return (-1);
	}
	// Convert into int
	dateVal = year * 10000 + month * 100 + day;
	return dateVal;
}

void BtcValue::readDataCSV(std::fstream &fs) {
	std::string line;
	// skip the first line
	std::getline(fs, line);
	while (std::getline(fs, line)){
		removeWhitespace(line);
		size_t pos = line.find(',');
		if (pos == std::string::npos){
			std::cerr << "Error: comma not found in the line" << std::endl;
			fs.close();
			exit(FAILURE);
		};
		std::string date = line.substr(0, pos);
		int dateVal = convertDate(date);
		if (dateVal < 0) {
			std::cerr << "Error: bad input => " << dateVal << std::endl;
			fs.close();
			exit(FAILURE);
		}
		std::string btcVal = line.substr(pos + 1, line.length() - pos);
		float val = atof(btcVal.c_str());
		_dateValue.insert(std::make_pair(dateVal,val));
	}
	fs.close();
}

void BtcValue::calculateAndPrintValues(std::fstream &fs) {
	std::string line;
	std::getline(fs, line);
	
	while (std::getline(fs, line)) {
		removeWhitespace(line);
		size_t colon = line.find('|');
		if (colon == std::string::npos){
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string dateStr = line.substr(0, colon);
		int date = convertDate(dateStr);
		if (date < 0) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		float btcAmount = atof(line.substr(colon + 1, line.length() -1).c_str());
		if (btcAmount > 1000) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		if (btcAmount < 0) {
			std::cerr << "Error: not a positive number."  << std::endl;
			continue;
		}
		while(date > _dateValue.begin()->first){
			std::map<int,float>::iterator it = _dateValue.find(date);
			if (it != _dateValue.end()){
				std::cout << dateStr << " => " << btcAmount << " = " << btcAmount * static_cast<float>(it->second) << std::endl;
				break;
			}
			date--;
		} 
	}
	fs.close();
}

BtcValue::BtcValue(const char *fileName) {
	std::fstream dataCSV, inputCSV;
	std::string fileContent;
	std::string line;
	// Open the data.csv
	dataCSV.open("data.csv", std::fstream::in);
	inputCSV.open(fileName, std::fstream::in);
	if (!dataCSV) {
		std::cout << "data.csv does not exist or can not be opened" << std::endl;
		exit(FAILURE);
	}
	if (!inputCSV) {
		std::cout << "input csv does not exist or can not be opened" << std::endl;
		exit(FAILURE);
	}
	// start parsing
	readDataCSV(dataCSV);
	calculateAndPrintValues(inputCSV);


}
