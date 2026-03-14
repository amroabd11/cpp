#include "Harl.hpp"
//A member function pointer is a special type of pointer that can point to non-static member functions.
Harl::Harl()
{

}
void Harl::debug(){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"<<std::endl;
}
void Harl::info()
{
	std::cout<< "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"<<std::endl;
}
void Harl::warning()
{
	std::cout<< "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."<<std::endl;
}
void Harl::error()
{
	std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl;
}
void Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG","ERROR","WARNING","INFO"};
	void(Harl::*funct[])(void) = {
		&Harl::debug,
		&Harl::error,
		&Harl::warning,
		&Harl::info
	};
	for(int i = 0; i < 4; i++)
	{
		if(level == levels[i]){
			(this->*funct[i])();
			//std::cout << &funct[i]<<std::endl;
			return ;
		}
	}
//	void(Harl::*deb)() = &Harl::debug;
//	void(Harl::*err)() = &Harl::error;
//	void(Harl::*warn)() = &Harl::warning;
//	void(Harl::*inf)() = &Harl::info;
//	if (level == "DEBUG")
//		(this->*deb)();
//	if (level == "INFO")
//		(this->*inf)();
//	if (level == "WARNING")
//		(this->*warn)();
//	if (level == "ERROR")
//		(this->*err)();
	
}
Harl::~Harl(){}






