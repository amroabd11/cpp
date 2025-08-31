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
    void display();
    void SEARCH();
};

int check_id(std::string id_s);


void PhoneBook::ADD()
{
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNum;
    std::string darkestSec;

    std::cout << "type your firstname: ";
    std::getline(std::cin ,firstName);
    if (firstName.empty())
    {
        std::cout<< "we don't accept empty fields , sorry try again!!"<<std::endl;
        return ;
    }
    std::cout << "type your lastname: ";
    std::getline(std::cin ,lastName);
    if (lastName.empty())
    {
        std::cout<< "we don't accept empty fields , sorry try again!!"<<std::endl;
        return ;
    }
    std::cout << "type your nickname: ";
    std::getline(std::cin ,nickName);
    if (nickName.empty())
    {
        std::cout<< "we don't accept empty fields , sorry try again!!"<<std::endl;
        return ;
    }
    while (true)
    {
        std::cout << "type your phone number: ";
        std::getline(std::cin ,phoneNum);
        if (phoneNum.empty())
        {
            std::cout<< "we don't accept empty fields , sorry try again!!"<<std::endl;
            return ;
        }
        if (!check_id(phoneNum))
        {
            std::cout<<"phoneNum not valid sorry try again!!!"<<std::endl;
            continue ;
        }
        break ;
    }
    std::cout << "type your darkest secret: ";
    std::getline(std::cin ,darkestSec);
    if (darkestSec.empty())
    {
        std::cout<< "we don't accept empty fields , sorry try again!!"<<std::endl;
        return ;
    }
    contacts[i % 8] = Contact(firstName, lastName, nickName, i, phoneNum, darkestSec);
    i++;

}
void PhoneBook::display()
{
    int i = PhoneBook::i;
    for(int j = 0; j < i;j++)
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
        std::cout << j << " | "<< FirstName << " | " <<  LastName << " | " << NickName <<std::endl;
    }
}
// int check_id(std::string id_s);

void PhoneBook::SEARCH()
{
    std::string id_n;
    int j = 0;
    int i = PhoneBook::i;
    int len = 0;
    //TODO list all the available contacts before prompting the user to enter an id
    display();
    std::cout << "enter contact id: " ;
    std::getline(std::cin, id_n);
    if (!check_id(id_n))
    {
        std::cout<<"id not valid sorry try again!!!"<<std::endl;
        return ;
    }
    while (j < i)
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
            std::cout << j << " | "<< FirstName << " | " <<  LastName << " | " << NickName <<std::endl;
            break ;
        }
        // else
        //     std::cout << "> ";
        j++;
    }
    if (i == j)
        std::cout << "id not found, sorry try again!!!"<<std::endl;
}


int check_id(std::string id_s)
{
    for (int i = 0; i < id_s.length(); i++)
    {
        if (!isdigit(id_s[i]))
            return (0);
    }
    return 1;
}