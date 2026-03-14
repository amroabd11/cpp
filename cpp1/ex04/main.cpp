#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4 )
	{
		std::cout << "<executable file search replace_word>"<<std::endl;
		return 1;
	}
	std::ifstream inputFile;
	inputFile.open(argv[1]);
	if (!inputFile.is_open())
		return 1;
	std::ofstream outputFile;

	std::string rep = argv[1];
	outputFile.open(rep + ".replace");
	if(!outputFile.is_open())
		return 1;

	std::string search = argv[2];
	std::string replace;
	replace = argv[3];

	std::string line;
	while(std::getline(inputFile, line))
	{
		std::string result;
		size_t pos = 0;
		size_t found_position;
		while((found_position = line.find(search, pos)) != std::string::npos)
		{
			result.append(line, pos, found_position - pos);
			result.append(replace);
			pos = found_position + search.length();
		}
		result.append(line, pos, line.length() - pos);
		outputFile << result << std::endl;
	}
	inputFile.close();
	outputFile.close();
}
