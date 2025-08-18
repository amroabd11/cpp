#pragma once
#include "contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int i;
public:
    PhoneBook():i(0){}
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
    contacts[i % 8] = Contact(firstName, lastName, nickName, i, phoneNum, darkestSec);
    i++;

}

void PhoneBook::SEARCH()
{
    std::string id_n;
    int j = 0;
    int len = 0;
    std::cout << "enter contact id: " ;
    std::getline(std::cin, id_n);
    while (true)
    {
        if (id_n.empty())// TODO here i need to add a check to see if all the chars within id_n are digits;
        {
            std::cout << "error in id form retry !!!!!"<<std::endl;
            std::getline(std::cin, id_n);
            continue ;
        }
        else if ((contacts[j].get_id() == std::atoi(id_n.c_str())))// TODO check for the entered id
        {
            std::string NickName = contacts[j].get_nickname();
            std::string FirstName = contacts[j].get_firstname();
            std::string LastName = contacts[j].get_lastname();
            if (FirstName.length() > 10)
                FirstName = FirstName.substr(0, 9) + ".";
            if (LastName.length() > 10)
                LastName = LastName.substr(0, 9) + ".";
            if (NickName.length() > 10)
                NickName = NickName.substr(0, 9) + ".";
            std::cout << "id is: "<<j << " | "<< "name is: "<< FirstName << " | " << "lastName is: "<< LastName << " | " << "nickName is: "<<NickName <<std::endl;
            break ;
        }
        else
            std::cout << "> ";
        j++;
    }
}
