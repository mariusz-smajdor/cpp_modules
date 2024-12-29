#include "BitcoinExchange.hpp"

void handleArgumentErrors(int argc) {
    if (argc != 2) {
        if (argc > 2) {
            std::cerr << "error: too many arguments" << std::endl;
        } else {
            std::cerr << "error: no file provided" << std::endl;
        }
        std::exit(1);
    }
}

void initializeBitcoinExchange(BitcoinExchange &btc) {
    try {
        btc.initializeDatabase();
    } catch (BitcoinExchange::CantReadDataFile &e) {
        std::cerr << e.what() << " (" << btc.dbPath() << ")" << std::endl;
        std::exit(1);
    }
}

void openInputFile(const char *filePath, std::ifstream &inputFile) {
    inputFile.open(filePath);
    if (!inputFile.is_open()) {
        std::cerr << "error: could not open file (" << filePath << ")" << std::endl;
        std::exit(1);
    }
}

void processLine(const std::string &line, BitcoinExchange &btc) {
    bool ignore = false;
    char *ptr = std::strtok(const_cast<char *>(line.c_str()), " | ");
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
        ptr = std::strtok(NULL, " | ");
    }

    if (!btc.checkDateFormat(date) && !ignore) {
        std::cerr << "error: incorrect date format (" << date << ")" << std::endl;
        ignore = true;
    }
    if (!btc.checkValue(value) && !ignore) {
        std::cerr << "error: incorrect value format (" << value << ")" << std::endl;
        ignore = true;
    }
    if (!ignore && btc.strToFloat(value) > 1000) {
        std::cerr << "error: too large a number (" << value << ")" << std::endl;
        ignore = true;
    }
    if (!ignore) {
        // Get the rate for the date
        float rate = btc.getRate(date);

        // Calculate the result
        float result = btc.strToFloat(value) * rate;

        // Output without scientific notation
        std::cout << std::fixed << std::setprecision(2);  // Set the fixed format and precision
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
}


void processInputFile(std::ifstream &inputFile, BitcoinExchange &btc) {
    std::string line;

    while (std::getline(inputFile, line)) {
        processLine(line, btc);
    }
}

int main(int argc, char *argv[]) {
    handleArgumentErrors(argc);

    BitcoinExchange btc("data.csv");
    initializeBitcoinExchange(btc);

    std::ifstream inputFile;
    openInputFile(argv[1], inputFile);
    processInputFile(inputFile, btc);
    inputFile.close();

    return 0;
}
