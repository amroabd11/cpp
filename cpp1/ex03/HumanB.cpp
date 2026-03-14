#include "HumanB.hpp"

HumanB::HumanB(std::string name){
this->name = name;
}
void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;	
}


//void HumanB::setType(Weapon &weap){
//	this->Weapon = &weap;
//}

void HumanB::attack(){
	std::cout<< this->name << " attacks with their weapon " << (*weapon).getType()<<std::endl;
}

HumanB::~HumanB(){}
