#include "BitcoinExchange.hpp"

bool BitcoinExchange::checkDateFormat(std::string str) {
	std::string test_length = str;
	char *ptr;
	ptr = strtok((char *)test_length.c_str(), "-");

	int i = 0;
	while (ptr != NULL) {
		if (i == 0 && strlen(ptr) != 4) {
			return false;
        } else if (i > 0 && strlen(ptr) != 2) {
			return false;
        }
		ptr = strtok(NULL, "-");
		i++;
	}
	if (i != 3) {
        std::cerr << "error: Incorrect date format (" << str << ")" << std::endl;
		return false;
    }
	struct tm result;
	if (strptime(str.c_str(), "%Y-%m-%d", &result) == NULL) {
        std::cerr << "error: Incorrect date format (" << str << ")" << std::endl;
		return false;
    }
	return true;
}

bool BitcoinExchange::checkValue(std::string str) {
	std::stringstream s(str);
	float f;

	if (!(s >> f) || !s.eof()) {
		return false;
    }
	if (f < 0) {
		return false;
    }
	return true;
}

float BitcoinExchange::strToFloat(std::string str) {
	std::stringstream s(str);
	float f;

	if (!(s >> f) || !s.eof()) {
		return -1;
    }
	return f;
}

BitcoinExchange::BitcoinExchange(void) : _database("data.csv") {}

BitcoinExchange::BitcoinExchange(std::string db_path) : _database(db_path) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _database(copy._database) {
	this->_db = copy._db;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {
	this->_database = copy._database;

	std::map<std::string, float>::iterator it;
	for (it = this->_db.begin(); it != this->_db.end(); ++it) {
		this->_db[it->first] = it->second;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(void) {}

std::string BitcoinExchange::dbPath(void) const {
	return this->_database;
}

void BitcoinExchange::initializeDatabase(void) {
	std::string line;
	std::ifstream dbfile(this->_database.c_str());

	if (!dbfile.is_open()) {
		throw BitcoinExchange::CantReadDataFile();
    }
	this->_db.clear();
	int ctr = -1;
	while (getline(dbfile,line)) {
		ctr++;
		if (ctr == 0)
			continue;

		bool ignore = false;
		char *ptr = strtok((char *)line.c_str(), ",");
		std::string date;
		std::string value;

		while (ptr != NULL) {
			if (date.empty()) {
				date = ptr;
            } else if (value.empty()) {
				value = ptr;
            } else {
				ignore = true;
            }
			ptr = strtok (NULL, ",");
		}
		if (!checkDateFormat(date) && !ignore) {
			std::cerr << "Error: Incorrect date format (" << date << ")" << std::endl;
			ignore = true;
		}
		if (!checkValue(value) && !ignore) {
			std::cerr << "Error: Incorrect value format (" << value << ")" << std::endl;
			ignore = true;
		}
		if (!ignore) {
			this->_db[date] = strToFloat(value);
		}
	}
	dbfile.close();
	return;
}

float BitcoinExchange::getRate(std::string date) {
    if (this->_db.size() == 0)
        return 0;
    if (this->_db.find(date) != this->_db.end()) {
        return this->_db[date];
    }

    std::map<std::string, float>::iterator it = this->_db.lower_bound(date);
    if (it == this->_db.begin()) {
        return it->second;
    } else if (it == this->_db.end()) {
        --it;
        return it->second;
    } else {
        --it;
        return it->second;
    }
}

const char*	BitcoinExchange::CantReadDataFile::what(void) const throw() {
	return ("Error: could not open file");
}
