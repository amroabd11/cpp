#include "Weapon.hpp"


class HumanB{
	private:
		std::string name;
		Weapon *weapon;
	public:
		HumanB(std::string);
		void setWeapon(Weapon &weapon);
		void attack();
		~HumanB();
};
