#include "stdafx.h"
#include "DataBase.h"

namespace
{
	int ParseId(std::string const& line)
	{
		std::string number;
		for (int i = 0; i < line.length(); i++)
		{
			if (isdigit(line[i]))
			{
				number += line[i];
			}
			else
			{
				if (!number.empty())
				{
					return (atoi(number.c_str()));
				}
			}
		}
		return -1;
	}

	std::string ParseAuthorName(std::string const& line)
	{
		std::string name;
		int check = 0;
		bool isName = false;

		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] == ',')
			{
				check++;
				continue;
			}
			if ((check == 4) && (line[i] != '\"'))
			{

				name += line[i];

			}
			if (check == 5)
			{
				break;
			}
		}
		return name;
	}
}

CDataBase::CDataBase()
{
}


CDataBase::~CDataBase()
{
}

void CDataBase::ReadFromFile(std::string const& nameOfFile)
{
	std::ifstream input(nameOfFile);
	std::string line;
	std::string name;
	int id = -1;
	while (std::getline(input, line))
	{
		id = ParseId(line);
		if (id != -1)
		{
			name = ParseAuthorName(line);
			if (m_data.find(name) != m_data.end())
			{
				m_data.find(name)->second.insert(id);
			}
			else
			{
				m_data.insert({ name,{ id } });
			}
		}
	}
}

std::set<int> CDataBase::GetId(std::string const & authorName)
{
	if (m_data.find(authorName) != m_data.end())
	{
		return m_data.find(authorName)->second;
	}
	return std::set<int>();
}
