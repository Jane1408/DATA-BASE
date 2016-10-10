// lab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "DataBase.h"

int main()
{
	CDataBase data;
	data.ReadFromFile("db.csv");

	std::set<int> result;
	std::string line;

	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "Enter username : ";
		std::getline(std::cin, line);
		result = data.GetId(line);
		if (!result.empty())
		{
			std::cout << "Record id: ";
			for(auto &it : result)
			{
				std::cout << it << ' ';
			}
		}
		std::cout << std::endl;
	}
    return 0;
}

