#include <iostream>
#include <fstream>

static std::string	replaceLine( std::string line, std::string s1, std::string s2 )
{
	size_t		found;
	size_t		currPos = 0;
	std::string	res = "";

	if (s1.empty())
		return (line);
	while ((found = line.find(s1, currPos)) != std::string::npos)
	{
		res += line.substr(currPos, found - currPos);
		res += s2;
		currPos = found + s1.length();
	}
	res += line.substr(currPos, line.length());
	return (res);
}

static void	replace( char *argv[], std::ifstream &inFile, std::ofstream &outFile )
{
	std::string	line;
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	
	while (std::getline(inFile, line))
		outFile << replaceLine(line, s1, s2) << std::endl;
}

int		main( int argc, char *argv[] )
{
	if (argc != 4)
	{
		std::cout << "Usage : ./replace <filename> <search> <replace>" << std::endl;
		return (EXIT_FAILURE);
	}

	// open file from argument
	std::ifstream	inFile(argv[1]);
	if (!inFile.is_open())
	{
		std::cout << "[ERROR] Could not open input file: " << argv[1] << std::endl;
		return (EXIT_FAILURE);
	}

	// creates new clear file with .replace
	std::string		outFileName = std::string(argv[1]) + ".replace";
	std::ofstream	outFile(outFileName.c_str());
	if (!outFile.is_open())
	{
		std::cout << "[Error] Could not create output file: " << outFileName << std::endl;
		inFile.close();
		return (EXIT_FAILURE);
	}

	replace(argv, inFile, outFile);

	inFile.close();
	outFile.close();
	return (EXIT_SUCCESS);
}
