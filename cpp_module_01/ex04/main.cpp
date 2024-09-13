#include <iostream>
#include <fstream>

using namespace std;

void writeOutput(const string& s1, const string& s2, ifstream& inputFile) {
    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cerr << "Error opening file: output.txt" << endl;
    }

    string line;
    while (getline(inputFile, line)) {
        size_t pos = line.find(s1);

        if ((pos != string::npos)) {
            string replacedLine = line.substr(0, pos);
            replacedLine += s2 + line.substr(pos + s1.size());
            outputFile << replacedLine << endl;
        } else {
            outputFile << line << endl;
        }
    }
    outputFile.close();
}

int main(int ac, char **av) {
    if (ac != 4) {
        cerr << "Wrong number of parameteres!" << endl
                  << "Usage: " << av[0] << " <filename> <s1> <s2>" << endl;
        return 1;
    }

    string ifd = av[1];
    string s1 = av[2];
    string s2 = av[3];

    ifstream inputFile(ifd);
    if (!inputFile.is_open()) {
        cerr << "Error opening file: " << ifd << endl;
    }
    writeOutput(s1, s2, inputFile);
    inputFile.close();

    return 0;
}