#pragma once
#include <iostream>

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
    Contact(): id(-1){}
    Contact(std::string F_name, std::string L_name, std::string N_name, int id_n, std::string P_num, std::string d_secret)
    {
        darkest_secret = d_secret;
        phone_number = P_num;
        first_name = F_name;
        last_name = L_name;
        nick_name = N_name;
        id = id_n;
    };
    std::string get_firstname()
    {
        return first_name;
    }
    std::string get_lastname()
    {
        return last_name;
    }
    int get_id()
    {
        return id;
    }
    std::string get_nickname()
    {
        return nick_name;
    }
};