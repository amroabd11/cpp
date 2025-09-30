#include "PhoneBook.hpp"

int main()
{
    PhoneBook phone1;
    std::string choice;
    while (true)
    {
        std::cout << "enter (ADD, SEARCH or EXIT):"<<std::endl;
        if (!(std::getline(std::cin, choice)))
            break ;
        if (choice == "ADD")
            phone1.ADD();
        else if (choice == "SEARCH")
        {
            phone1.SEARCH();
        }
        else if (choice == "EXIT")
            break ;
    }
    return (0);
}
