#pragma once
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int i;
public:
    PhoneBook();
    void ADD();
    void display();
    void SEARCH();
};


