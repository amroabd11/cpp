#include "Array.hpp"

int main()
{
	Array<int> arr(40);
	Array<int>(arr2)= arr;
	try{
		arr[39] = 75;
		std::cout << arr[39]<<std::endl;
		std::cout << arr[390]<<std::endl;
	}
	catch(std::exception& e){
		std::cout << e.what()<<std::endl;
	}

	std::cout << arr.size() << std::endl;
	std::cout << arr2.size() << std::endl;
}



