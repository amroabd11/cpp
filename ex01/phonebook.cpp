#include "phonebook.hpp"

int main()
{
    PhoneBook phone1;
    std::string choice;
    std::cout << "enter (ADD, SEARCH or EXIT):"<<std::endl;
    std::getline(std::cin, choice);
    while (true)
    {
        if (choice == "ADD")
            phone1.ADD();
        else if (choice == "SEARCH")
        {
            std::cout << "enter contact id: " ;
            phone1.SEARCH();
        }
        else if (choice == "EXIT")
            break ;
        std::cout << "enter (ADD, SEARCH or EXIT):"<<std::endl;
        std::cin >> choice;
    }
    
    // std::cout << "enter (ADD, SEARCH or EXIT):"<<std::endl;
    // std::cin >> choice;
    // if (choice == "ADD")
    //     phone1.ADD();
    // else if (choice == "SEARCH")
    //     phone1.display();
    // ~phone_book1;
}

/*class Example {
    int& ref;
public:
    Example(int& val) {
        ref = val;  // ❌ Error: ref must be initialized, not assigned
    }
};
Let’s understand what happens in memory and construction steps.

When you call the constructor: Example e(x);

C++ allocates memory for the object e.

It then initializes all member variables in declaration order.

For int& ref, C++ expects it to be bound to some existing int immediately during initialization.

But in your code, C++ tries to default-initialize ref, which is not possible for a reference — references must be initialized once and never changed.

By the time the constructor body { ... } runs, it’s too late. The reference should already be bound.

*/