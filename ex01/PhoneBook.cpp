#include "PhoneBook.hpp"

int check_id(std::string id_s);
int is_valid(std::string str);

PhoneBook::PhoneBook():i(0){}

void PhoneBook::ADD()
{
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNum;
    std::string darkestSec;

	while(true)
	{
	    std::cout << "type your firstname: ";
	    if (!(std::getline(std::cin ,firstName)))
		    return ;
	    if (firstName.empty() || !is_valid(firstName))
	    {
		std::cout<< "invalid, try again!!"<<std::endl;
		continue ;
	    }
	    break ;
	}
	while(true)
	{
	    std::cout << "type your lastname: ";
	    if (!std::getline(std::cin ,lastName))
		    return ;
	    if (lastName.empty() || !is_valid(lastName))
	    {
		std::cout<< "invalid, try again!!"<<std::endl;
		continue ;
	    }
	    break ;
	}
	while(true)
	{
	    std::cout << "type your nickname: ";
	    if (!(std::getline(std::cin ,nickName)))
		    return ;
	    if (nickName.empty() || !is_valid(nickName))
	    {
		std::cout<< "invalid, try again!!"<<std::endl;
		continue ;
	    }
	    break ;
	}

    	while (true)
   	{
		std::cout << "type your phone number: ";
		if (!(std::getline(std::cin ,phoneNum)))
			return ;
		if (!check_id(phoneNum) || phoneNum.empty())
		{
		    std::cout<<"invalid, try again!!!"<<std::endl;
		    continue ;
		}
		break ;
   	}
    	while (true)
    	{
	    std::cout << "type your darkest secret: ";
	    if (!(std::getline(std::cin ,darkestSec)))
		    return ;
	    if (darkestSec.empty() || !is_valid(darkestSec))
	    {
		std::cout<< "empty field, sorry try again!!"<<std::endl;
		continue ;
	    }
	    break ;
    	}
    contacts[i % 8] = Contact(firstName, lastName, nickName, i%8, phoneNum, darkestSec);
    i++;
}



void PhoneBook::display()
{
	int	ind = i;
	if (ind == 0)
		return ;
    std::cout << "id        | First_name | Last_name  | Nick_name  " <<std::endl;
    for(int j = 0; j < ind && j<8;j++)
    {
        std::string NickName = contacts[j].get_nickname();
        std::string FirstName = contacts[j].get_firstname();
        std::string LastName = contacts[j].get_lastname();

        if (FirstName.length() > 10)
            FirstName = FirstName.substr(0, 9) + ".";
		else
			FirstName = FirstName.append(10 - FirstName.length(), ' ');
        if (LastName.length() > 10)
            LastName = LastName.substr(0, 9) + ".";
		else
			LastName = LastName.append(10 - LastName.length(), ' ');
        if (NickName.length() > 10)
            NickName = NickName.substr(0, 9) + ".";
		else 
			NickName = NickName.append(10 - NickName.length(), ' ');
        std::cout << j << "         | "<< FirstName << " | " <<  LastName << " | " << NickName <<std::endl;
    }
}

void PhoneBook::SEARCH()
{
    std::string id_n;
    int j = 0;
    display();
    while(true)
    {
	    std::cout << "enter contact id: " ;
	    if (!(std::getline(std::cin, id_n)))
		    return ;
	    if (!check_id(id_n) || id_n.empty())
	    {
		std::cout << "invalid, try again!!!"<< std::endl;
		continue ;
	    }
	    if (id_n.length() > 1 || id_n == "9" || id_n == "8")
	    {
		    std::cout<<"invalid, id range [0, 7]"<<std::endl;
		    continue;
	    }
	    break ;
    }
    while (j < i && j < 8)
    {
        if ((contacts[j].get_id() == std::atoi(id_n.c_str())))
        {
           	std::string NickName = contacts[j].get_nickname();
           	std::string FirstName = contacts[j].get_firstname();
           	std::string LastName = contacts[j].get_lastname();
			std::string Darkest = contacts[j].get_darkestSec();
			std::string	phoneNum = contacts[j].get_phonenumber();

          	std::cout <<"index :"<< j << std::endl;
	  		std::cout<< "First name: "<< FirstName <<std::endl;
			std::cout<<"Last name: " <<  LastName<<std::endl;
			std::cout<<"Nick name: " << NickName<<std::endl;
			std::cout<<"Darkest sec: " << Darkest<<std::endl;
			std::cout<<"call me in: " << phoneNum<<std::endl;

           break ;
        }
        j++;
    }
    if (i == j)
        std::cout << "id not found, try again!!!"<<std::endl;
}

int check_id(std::string id_s)
{
    for (unsigned long i = 0; i < id_s.length(); i++)
    {
        if (!isdigit(id_s[i]))
            return (0);
    }
    return 1;
}
int is_valid(std::string str)
{
	int	i = 0;
	while(str[i])
	{
		if (str[i] < 32 || str[i] > 126)
			return 0;
		i++;
	}
	i = 0;
	while(str[i] == ' ')
		i++;
	if(str[i] == '\0')
		return 0;
	return 1;
}


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
