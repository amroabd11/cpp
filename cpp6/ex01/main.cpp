#include "Serializer.hpp"

int main()
{
	Data data;
	data.id = 50;
	uintptr_t raw = Serializer::serialize(&data);
	Data* rec = Serializer::deserialize(raw);
	if (&data == rec )
		std::cout << "equal"<<std::endl;
}

