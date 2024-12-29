#include "PmergeMe.hpp"

template<typename T, template <typename, typename> class Container>
PmergeMe<T, Container>::PmergeMe() {}

template<typename T, template <typename, typename> class Container>
PmergeMe<T, Container>::PmergeMe(const PmergeMe<T, Container> &src) {
    *this = src;
}

template<typename T, template <typename, typename> class Container>
PmergeMe<T, Container>::~PmergeMe() {}

template<typename T, template <typename, typename> class Container>
PmergeMe<T, Container> &PmergeMe<T, Container>::operator =(const PmergeMe<T, Container> &src) {
    if (this != &src) {
        *this = src;
    }
    return *this;
}

template <typename T>
bool reserve(T &container, typename T::size_type size) {
    (void)container;
    (void)size;
    return false;
}

template <typename T, typename U>
bool reserve(std::vector<T, U> &container, typename std::vector<T, U>::size_type size) {
    container.reserve(size);
    return true;
}

template<typename T, template <typename, typename> class Container>
Container<std::pair<T, T>, std::allocator<T> > merge(Container<std::pair<T, T>, std::allocator<T> > left, Container<std::pair<T, T>, std::allocator<T> > right) {
    Container<std::pair<T, T>, std::allocator<T> > pairs;
    reserve(pairs, left.size() + right.size());

    while (left.size() && right.size()) {
        if (left[0].first < right[0].first) {
            pairs.push_back(left[0]);
            left.erase(left.begin());
        } else {
            pairs.push_back(right[0]);
            right.erase(right.begin());
        }
    }

    while (left.size()) {
        pairs.push_back(left[0]);
        left.erase(left.begin());
    }

    while (right.size()) {
        pairs.push_back(right[0]);
        right.erase(right.begin());
    }

    return pairs;
}

template<typename T, template <typename, typename> class Container>
Container<std::pair<T, T>, std::allocator<T> > sort_pairs(Container<std::pair<T, T>, std::allocator<T> > &pairs) {
    if (pairs.size() <= 1) {
        return pairs;
    }

    Container<std::pair<T, T>, std::allocator<T> > first;
    std::copy(pairs.begin(), pairs.begin() + pairs.size() / 2, std::back_inserter(first));

    Container<std::pair<T, T>, std::allocator<T> > second;
    std::copy(pairs.begin() + pairs.size() / 2, pairs.end(), std::back_inserter(second));

    return merge(sort_pairs(first), sort_pairs(second));
}

template<typename T, template <typename, typename> class Container>
Container<T, std::allocator<T> > binary_search_insertion(Container<T, std::allocator<T> > &array, size_t start, T item) {
    if (array.size() == 0) {
        array.push_back(item);
        return array;
    }

    size_t left = start;
    size_t right = array.size() - 1;
    bool at_start = array[left] > item;

    while (left <= right && !at_start) {
        size_t middle = (left + right) / 2;
        if (left == right) {
            if (array[middle] < item) {
                left = middle + 1;
            }
            break;
        } else if (array[middle] < item) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    if (left > array.size() - 1) {
        array.insert(array.end(), item);
    } else {
        array.insert(array.begin() + left, item);
    }

    if (VERBOSE) {
        std::cout << "Inserting " << item << " at position " << left << " (after " << array[left - 1] << ")" << std::endl;
    }

    return array;
}

template<typename T, template <typename, typename> class Container>
Container<T, std::allocator<T> > PmergeMe<T, Container>::sort(const Container<T, std::allocator<T> > &array) const {
    if (array.size() < 2) {
        return array;
    }

    bool is_odd = array.size() % 2 != 0;
    Container<std::pair<T, T>, std::allocator<T> > pairs;
    reserve(pairs, array.size() / 2 + 1);

    for (typename Container<T, std::allocator<T> >::size_type i = 0; i < array.size(); i += 2) {
        if (i + 1 >= array.size()) {
            continue;
        }

        else if (array[i] > array[i + 1]) {
            pairs.push_back(std::make_pair(array[i + 1], array[i]));
        } else {
            pairs.push_back(std::make_pair(array[i], array[i + 1]));
        }
    }

    if (VERBOSE) {
        std::cout << "Pairs:   ";
        for (typename Container<T, std::allocator<T> >::size_type i = 0; i < pairs.size(); i++) {
            std::cout << "[" << pairs[i].first << ", " << pairs[i].second << "], ";
        }
        std::cout << std::endl;
    }

    Container<std::pair<T, T>, std::allocator<T> > pairs_sorted = sort_pairs(pairs);

    if (VERBOSE) {
        std::cout << "Pairs sorted:   ";
        for (typename Container<T, std::allocator<T> >::size_type i = 0; i < pairs_sorted.size(); i++) {
            std::cout << "[" << pairs_sorted[i].first << ", " << pairs_sorted[i].second << "], ";
        }
        std::cout << std::endl;
    }

    Container<T, std::allocator<T> > sorted;
    reserve(sorted, array.size());
    for (typename Container<T, std::allocator<T> >::size_type i = 0; i < pairs_sorted.size(); i++) {
        sorted.push_back(pairs_sorted[i].first);
    }

    if (VERBOSE) {
        std::cout << "Sorted: [";
        for (typename Container<T, std::allocator<T> >::size_type i = 0; i < sorted.size(); i++) {
            std::cout << sorted[i] << ", ";
        }
        std::cout << "]" << std::endl;
    }

    if (is_odd) {
        binary_search_insertion(sorted, 0, array.back());
    }

    for (typename Container<T, std::allocator<T> >::size_type i = 0; i < pairs_sorted.size(); i++) {
        binary_search_insertion(sorted, i + 1, pairs_sorted[i].second);

        if (VERBOSE) {
            std::cout << "partial: [";
            for (typename Container<T, std::allocator<T> >::size_type i = 0; i < sorted.size(); i++) {
                std::cout << sorted[i] << ", ";
            }
            std::cout << "]" << std::endl;
        }
    }

    return sorted;
}
