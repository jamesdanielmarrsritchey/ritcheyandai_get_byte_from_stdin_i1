#include <iostream>
#include <string>
#include <cstdlib>

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments are passed
    if (argc != 3) {
        std::cerr << "Usage: ./program --byte byte_number\n";
        return 1;
    }

    // Extract the byte number from the argument
    std::string arg = argv[1];
    if (arg != "--byte") {
        std::cerr << "Invalid argument. Expected format: --byte number\n";
        return 1;
    }
    int byteNumber = std::stoi(argv[2]);

    // Read from stdin
    char c;
    int count = 0;
    while (std::cin.get(c)) {
        count++;
        if (count == byteNumber) {
            std::cout << c << '\n';
            return 0;
        }
    }

    // If the byte number is greater than the number of bytes in the input
    if (count < byteNumber) {
        std::cerr << "Byte number is greater than the number of bytes in the input.\n";
        return 1;
    }

    return 0;
}