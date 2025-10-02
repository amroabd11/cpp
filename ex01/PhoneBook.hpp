#pragma once
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int i;
public:
    PhoneBook():i(0){}
    void ADD();
    void display();
    void SEARCH();
};


