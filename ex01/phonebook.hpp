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
    std::string id;
public:
    Contact(){}
    Contact(std::string F_name, std::string L_name, std::string N_name, int id_n, std::string P_num, std::string d_secret)
    {
        darkest_secret = d_secret;
        phone_number = P_num;
        first_name = F_name;
        last_name = L_name;
        nick_name = N_name;
        id = id_n;
    };
    // void set_firstname(std::string firstName)
    // {
    //     first_name = firstName;
    // }
    std::string get_firstname()
    {
        return first_name;
    }
    // void set_lastname(std::string lastName)
    // {
    //     last_name = lastName;
    // }
    std::string get_lastname()
    {
        return last_name;
    }
    // void set_id(int id_n)
    // {
    //     id = id_n;
    // }
    std::string get_id()
    {
        return id;
    }
    // void set_nickname(std::string nickName)
    // {
    //     nick_name = nickName;
    // }
    std::string get_nickname()
    {
        return nick_name;
    }
};

class PhoneBook
{
private:
    Contact contacts[8];//here it needs the default constructor
    // in order to initialize this array since i may creat other constructors;
    int i;
public:
    std::string id_n;
    PhoneBook() : i(0) {}
    void ADD();
    void SEARCH();
};

void PhoneBook::ADD()
{
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNum;
    std::string darkestSec;

    if (i < 8)
    {
        std::cout << "type your firstname: ";
        std::getline(std::cin ,firstName);
        std::cout << "type your lastname: ";
        std::getline(std::cin ,lastName);
        std::cout << "type your nickname: ";
        std::getline(std::cin ,nickName);
        std::cout << "type your phone number: ";
        std::getline(std::cin ,phoneNum);
        std::cout << "type your darkest secret: ";
        std::getline(std::cin ,darkestSec);
        contacts[i] = Contact(firstName, lastName, nickName, i, phoneNum, darkestSec);
        i++;
    }
    else
        std::cout << "full book" << std::endl;
}

void PhoneBook::SEARCH()
{
    int j = 0;
    std::getline(std::cin, id_n);
    while (true)
    {
        if (contacts[j].get_id() == id_n)
        {
            std::cout << "name is: "<< contacts[j].get_firstname() << "|" << "lastName is: "<< contacts[j].get_lastname();
            break ;
        }
        j++;
    }
}
// void PhoneBook::display()
// {
//     int j = 0;
//     int id_n;
//     std::cin >> id_n;
//     while (contacts[j].get_firstname() != "NULL")
//     {

//         if (contacts[j].get_id() == id_n)
//         {
//             std::cout << "name is: " << contacts[j].get_firstname() << "|" << contacts[j].get_lastname();
//             break ; 
//         }
//         j++;
//     }
// }
