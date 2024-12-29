#include <sys/time.h>
#include <cstring>
#include <limits>
#include <cstdio>
#include <set>
#include "PmergeMe.hpp"

typedef unsigned long timestamp_t;

static timestamp_t getTimestamp() {
    struct timeval now;
    gettimeofday(&now, NULL);
    return now.tv_usec;
}

bool processInput(int argc, char **argv, std::vector<int> &vector_vals, std::deque<int> &deque_vals) {
    std::set<int> unique_vals;

    for (int i = 1; i < argc; i++) {
        char* endptr = NULL;
        long value = strtol(argv[i], &endptr, 10);

        if (*endptr != '\0') {
            std::cerr << "Error: " << argv[i] << " is not a valid number" << std::endl;
            return false;
        }

        if (value < 0 || value > std::numeric_limits<int>::max()) {
            std::cerr << "Error: " << argv[i] << " exceeds numeric limit (" << std::numeric_limits<int>::max() << ")" << std::endl;
            return false;
        }

        int int_value = static_cast<int>(value);
        if (!unique_vals.insert(int_value).second) {
            std::cerr << "Error: duplicate value " << argv[i] << std::endl;
            return false;
        }

        vector_vals.push_back(int_value);
        deque_vals.push_back(int_value);
    }
    return true;
}

template <typename T>
void displayValues(const T &values, const std::string &label) {
    std::cout << label << ": ";
    for (typename T::const_iterator it = values.begin(); it != values.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n" << std::endl;
}

template <typename T>
void sortAndMeasure(std::vector<T> &container_vals, const std::string &container_name) {
    timestamp_t start = getTimestamp();

    PmergeMe<T, std::vector> merge;
    std::vector<T> sorted_vals = merge.sort(container_vals);

    timestamp_t end = getTimestamp();
    std::cout << "Time to process a range of " << container_vals.size() << " elements with " << container_name << ": " << end - start << " us" << std::endl;
    displayValues(sorted_vals, "After (" + container_name + ")");
}

template <typename T>
void sortAndMeasureDequeue(std::deque<T> &container_vals, const std::string &container_name) {
    timestamp_t start = getTimestamp();

    PmergeMe<T, std::deque> merge;
    std::deque<T> sorted_vals = merge.sort(container_vals);

    timestamp_t end = getTimestamp();
    std::cout << "Time to process a range of " << container_vals.size() << " elements with " << container_name << ": " << end - start << " us" << std::endl;
    displayValues(sorted_vals, "After (" + container_name + ")");
}

template <typename T>
bool validateSort(const std::vector<T> &sorted_vals, const std::deque<T> &deque_sorted_vals) {
    if (sorted_vals.size() != deque_sorted_vals.size()) {
        std::cerr << "Error: Bad sort - sizes do not match" << std::endl;
        return false;
    }

    for (size_t i = 0; i < sorted_vals.size(); i++) {
        if (sorted_vals[i] != deque_sorted_vals[i]) {
            std::cerr << "Error: Bad sort - values do not match" << std::endl;
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <values>" << std::endl;
        return 1;
    }

    std::vector<int> vector_vals;
    std::deque<int> deque_vals;

    if (!processInput(argc, argv, vector_vals, deque_vals)) {
        return 1;
    }

    displayValues(vector_vals, "Before");
    sortAndMeasure(vector_vals, "vector");
    sortAndMeasureDequeue(deque_vals, "deque");

    if (!validateSort(vector_vals, deque_vals)) {
        return 1;
    }
    return 0;
}
