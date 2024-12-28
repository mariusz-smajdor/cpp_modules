#include "Serializer.hpp"

int main() {
    Data data;
    data.type = "int";
    data.value = 42;

    std::cout << "Original data:\n";
	std::cout << "Type: " << data.type << "\n";
	std::cout << "Value: " << data.value << "\n";

	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << "\nSerialized data: " << serialized << "\n";

	Data *deserialized = Serializer::deserialize(serialized);
	std::cout << "\nDeserialized data:\n";
	std::cout << "Type: " << deserialized->type << "\n";
	std::cout << "Value: " << deserialized->value << "\n";

	return 0;
}
