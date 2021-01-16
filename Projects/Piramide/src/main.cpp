#include <iostream>

int main() {
    int entry_number;
    
    std::cout << "System is runnning ";
    std::cin >> entry_number;
    
    int repeat;
    for (int i = 1; i <= (entry_number*2-1); i++)
    {
        if (i - entry_number <= 0) {
            repeat=i;
        } else {
            repeat=2*entry_number-i;
        }
        for (int j = 0; j < repeat; j++)
        {
            std::cout << "*";
        }
        if (i != (entry_number*2-1)) {
            std::cout << std::endl;
        }
    }    
}