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
	    std::getline(std::cin ,firstName);
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
	    std::getline(std::cin ,lastName);
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
	    std::getline(std::cin ,nickName);
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
		std::getline(std::cin ,phoneNum);
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
	    std::getline(std::cin ,darkestSec);
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
        std::cout << j << " | "<< FirstName << " | " <<  LastName << " | " << NickName <<std::endl;
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
	    std::getline(std::cin, id_n);
	    if (!check_id(id_n) || id_n.empty())
	    {
		std::cout<<"invalid, try again!!!"<<std::endl;
		continue ;
	    }
	    if (id_n.length() > 1 || id_n == "9" || id_n == "8")
	    {
		    std::cout<<"invalid, ids range [0, 7]"<<std::endl;
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

           if (FirstName.length() > 10)
               FirstName = FirstName.substr(0, 9) + ".";
	   else
	           FirstName = FirstName.append((10 - FirstName.length()), ' ');
           if (LastName.length() > 10)
               LastName = LastName.substr(0, 9) + ".";
	   else
	           LastName = LastName.append(10 - LastName.length(), ' ');
           if (NickName.length() > 10)
               NickName = NickName.substr(0, 9) + ".";
	   else
	           NickName = NickName.append(10 - NickName.length(), ' ');
           std::cout << j << " | "<< FirstName << " | " <<  LastName << " | " << NickName <<std::endl;
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
