#pragma once
class CDataBase
{
public:
	CDataBase();
	~CDataBase();

	void ReadFromFile(std::string const& nameOfFile);
	std::set<int> GetId(std::string const& autorName);
private:
	std::map <std::string, std::set<int>> m_data;
};

