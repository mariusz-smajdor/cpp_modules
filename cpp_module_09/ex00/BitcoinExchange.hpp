#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <map>
#include <ctime>
#include <sstream>
#include <utility>
#include <iomanip>

class BitcoinExchange {
    private:
        std::string _database;
        std::map<std::string, float> _db;

    public:
        // Constructors and destructor
        BitcoinExchange(void);
        BitcoinExchange(const std::string db_path);
        BitcoinExchange(const BitcoinExchange &copy);
        ~BitcoinExchange(void);

        // Operator overloads
        BitcoinExchange	&operator=(const BitcoinExchange &copy);

        // Member functions
        void initializeDatabase(void);
        std::string dbPath(void) const;
        float getRate(std::string date);
		bool checkDateFormat(std::string str);
		bool checkValue(std::string str);
		float strToFloat(std::string str);

        // Exceptions
        class CantReadDataFile: public std::exception {
            public:
                virtual const char* what(void) const throw();
        };
};
