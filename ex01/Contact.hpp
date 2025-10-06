#pragma once
#include <iostream>
#include <cstdlib>
#include <iomanip>

class Contact
{
private:
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string darkest_secret;
    int id;
public:
    Contact();
    Contact(std::string, std::string, std::string, int, std::string, std::string);
    std::string get_firstname();
    std::string get_lastname();
    int get_id();
    std::string get_nickname();
};

