#include "Contact.hpp"

Contact::Contact(std::string F_name, std::string L_name, std::string N_name, int id_n, std::string P_num, std::string d_secret)
{
	darkest_secret = d_secret;
	phone_number = P_num;
	first_name = F_name;
	last_name = L_name;
	nick_name = N_name;
	id = id_n;
}

std::string Contact::get_firstname()
{
        return first_name;
}

std::string Contact::get_lastname()
{
	return last_name;
}
int Contact::get_id()
{
	return id;
}
std::string Contact::get_nickname()
{
	return nick_name;
}



