#ifndef SCALAR_CONVERTER_HPP
#define

class ScalarConverter
{
	protected:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
	public:
		static void convert(std::string& _str);
};

#endif
