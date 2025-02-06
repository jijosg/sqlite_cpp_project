#include <iostream>

int main() {
    std::cout << __cplusplus << std::endl;
    // Read a number from the user
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    printf("You entered: %02d\n", number);
}